#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"


void getInput(int& minRange, int& maxRange);
bool isPrime_KSI(int number);
void getAllThePrime(int minRange, int maxRange, vector<int>& primeNumbersArr);
void writeThePrimes(vector<int> primeNumbersArr);
void MAIN_LOOP_SIEVE();

void EXIT_MENU_LOOP(int& tryAgainFlag, int& input);
