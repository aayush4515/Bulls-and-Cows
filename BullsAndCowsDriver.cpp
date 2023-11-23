// P02: Bulls and Cows
// Aayush Acharya
// Plays the traditional Bulls and Cows game

#include <iostream>
#include <vector>
#include "Functions.h"

using namespace std;

int main()
{

    cout << "*** P02 Bulls and Cows ***" << endl
         << endl;

    char inp = 'y';

    while (inp == 'y')
    {

        vector<int> answerVec = generateAnswer(4); // this answerVec contains the number to be guessed
        vector<int> guessVec;

        play(answerVec, guessVec);

        cout << endl;
        cout << "Enter y to play again(anything else to end):  ";
        cin >> inp;
        cout << endl;
    }

    return 0;
}