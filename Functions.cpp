#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <vector>
#include <string>

#include "Functions.h"

using namespace std;

bool isUnique(const vector<int> &v)
{

    bool isTrue = true;
    vector<int> tempVec = v;

    sort(tempVec.begin(), tempVec.end());

    for (int i = 1; i < tempVec.size(); i++)
    {
        if (tempVec.at(i) == tempVec.at(i - 1))
        {
            cout << "\t\tError: Digits can not be repeated -- try again!" << endl
                 << endl;
            // this clears the vector elements so that a fresh input wouldn't overwrite the previous vector
            tempVec.resize(0);
            isTrue = false;
            break;
        }
    }
    return isTrue;
}

bool hasOnlyDigits(const string s)
{
    bool allDigits = (s.find_first_not_of("0123456789") == string::npos);

    if (!allDigits)
    {
        cout << "\t\tError: Guess can only contain digits -- try again!" << endl
             << endl;
    }
    return allDigits;
}

void getGuesses(vector<int> &answerVec, int maxDigits)
{
    // this answerVec is different from the one created in main()
    // this function inputs the guesses from a user and checks if the input has only digits
    // if yes, it passes the input as a vector of ints(by reference) to the getValidGuess function

    string guess;

    bool tempBool = false;
    do
    {
        cout << "\tEnter guess: ";
        cin >> guess;

        tempBool = hasOnlyDigits(guess);

        if (tempBool == true)
        {
            for (char c : guess)
            {
                int digit = c - '0';
                answerVec.push_back(digit);
            }
        }
    } while (!tempBool);
}

void getvalidGuess(int maxDigits, vector<int> &guessVec)
{
    // this functions checks if the vector passed by getGuesses has
    // size 4 and no repetitions of digits

    bool tempBool = false;

    do
    {

        getGuesses(guessVec, maxDigits);

        if (guessVec.size() == maxDigits)
        {
            if (isUnique(guessVec))
            {
                tempBool = true;
                break;
            }
            else
            {
                guessVec.resize(0);
                continue;
            }
        }
        else
        {
            cout << "\t\tError: Guess must be 4 digits -- try again!" << endl
                 << endl;
            guessVec.resize(0);
            continue;
        }
    } while (guessVec.size() != maxDigits && !tempBool);
}

vector<int> generateAnswer(int maxDigits)
{

    vector<int> answer{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    srand(static_cast<unsigned int>(time(nullptr)));
    random_shuffle(answer.begin(), answer.end());
    answer.resize(4);

    return answer;
}

// creating this function for extra readability in the main function

void play(vector<int> answerVec, vector<int> guessVec)
{

    int numBulls = 0;
    int numCows = 0;
    int numGuesses = 0;

    cout << "************ New Game ************" << endl
         << endl;
    cout << "Number to guess: ";

    for (int i : answerVec)
    {
        cout << i;
    }
    cout << endl
         << endl;
    cout << "\tGuesses entered must be digits 0-9, 4 digits long, no repetition." << endl
         << endl;

    while (numBulls < 4)
    {
        numBulls = 0;
        numCows = 0;
        getvalidGuess(4, guessVec);

        numGuesses++;

        // checking for Bulls
        for (int i = 0; i < 4; i++)
        {
            if (answerVec.at(i) == guessVec.at(i))
            {
                numBulls++;
            }
        }

        // checking for cows
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if ((i != j) && (answerVec.at(i) == guessVec.at(j)))
                {
                    numCows++;
                }
            }
        }
        cout << "\t\tGuess #" << numGuesses << ": Bulls " << numBulls << " Cows " << numCows << endl
             << endl;
        guessVec.resize(0);
    }
    cout << endl
         << "\t*** YOU WIN ***" << endl;
}