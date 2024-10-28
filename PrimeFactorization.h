#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"
#include "Sieve.h"

class PrimeFactorization : SieveOfErathosthenes
{
	public:
		void MAIN_LOOP();

	protected:
		int a;
		vector<int> primeNumbersArr, quotientArr, dividendArr_Prime, divisorArr_Prime;

		void getThePrimes(int a, vector<int>& primeNumbersArr);
		void startDividing(int a, vector<int> primeNumbersArr, vector<int>& divisorArr_Prime, vector<int>& dividendArr_Prime, vector<int>& quotientArr);
		void displayLongDivision(vector<int> dividendArr_Prime, vector<int> divisorArr_Prime, vector<int> quotientArr);
		void displayTreeMethod(vector<int> dividendArr_Prime, vector<int> divisorArr_Prime, vector<int> quotientArr);
		void displayPrimeFactors(int a, vector<int> divisorArr_Prime);
		void displayTheAnswer(int a, vector<int> dividendArr_Prime, vector<int> divisorArr_Prime, vector<int>& quotientArr);
		void clearBuffer();
};
