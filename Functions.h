#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

vector<int> generateAnswer(int maxDigits);
bool isUnique(const vector<int> &v);
bool hasOnlyDigits(const string s);
void getGuesses(vector<int> &answerVec, int maxDigits);
void getvalidGuess(int maxDigits, vector<int> &guessVec);
void play(vector<int> answerVec, vector<int> guessVec);

#endif
