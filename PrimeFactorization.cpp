#include "PrimeFactorization.h"

void PrimeFactorization::MAIN_LOOP()
{
	int input = -1, tryAgainFlag = -1;

	while (tryAgainFlag == -1 || tryAgainFlag == 2)
	{
		cout << "*********PRIME FACTORIZATION*********" << endl;
		cout << "Your Input: "; cin >> a;

		getThePrimes(a, primeNumbersArr);
		startDividing(a, primeNumbersArr, divisorArr_Prime, dividendArr_Prime, quotientArr);
		displayTheAnswer(a, dividendArr_Prime, divisorArr_Prime, quotientArr);

		clearBuffer();

		tryAgainFlag = -1;
		EXIT_MENU_LOOP(tryAgainFlag, input);
	}
	

}


inline void PrimeFactorization::getThePrimes(int a, vector<int>& primeNumbersArr)
{
	getAllThePrime(0, a, primeNumbersArr);
}
inline void PrimeFactorization::startDividing(int a, vector<int> primeNumbersArr, vector<int>& divisorArr_Prime, vector<int>& dividendArr_Prime, vector<int>& quotientArr)
{
	for (int i = 0; i < primeNumbersArr.size(); i++)
	{
		if (a % primeNumbersArr[i] == 0)
		{
			divisorArr_Prime.push_back(primeNumbersArr[i]);
			quotientArr.push_back(a / primeNumbersArr[i]);

			dividendArr_Prime.push_back(a);
			a = quotientArr[quotientArr.size() - 1];

			if (isPrime_KSI(a))
			{
				cout << "True" << endl;
				divisorArr_Prime.push_back(a);
				divisorArr_Prime.push_back(1);
				break;
			}
			if (a == 1) { break; }
			i = -1;
		}
	}
}
inline void PrimeFactorization::displayLongDivision(vector<int> dividendArr_Prime, vector<int> divisorArr_Prime, vector<int> quotientArr)
{
	cout << "Long Division Method: " << endl;
	for (int i = 0; i < dividendArr_Prime.size(); i++)
	{
		cout << dividendArr_Prime[i] << " / " << divisorArr_Prime[i] << " = " << quotientArr[i] << endl;
	}
}
inline void PrimeFactorization::displayTreeMethod(vector<int> dividendArr_Prime, vector<int> divisorArr_Prime, vector<int> quotientArr)
{
	cout << "Tree Method: " << endl;
	for (int i = 0; i < dividendArr_Prime.size(); i++)
	{
		//cout << dividendArr_Prime[i] << " = " << divisorArr_Prime[i] << " * " << quotientArr[i] << endl;
		cout << dividendArr_Prime[i] << endl;
		cout << "\/ \\" << endl;
		cout << divisorArr_Prime[i] << " " << quotientArr[i] << endl;
	}
}
inline void PrimeFactorization::displayPrimeFactors(int a, vector<int> divisorArr_Prime)
{
	string answer;

	for (int i = 0; i < divisorArr_Prime.size(); i++)
	{
		answer += to_string(divisorArr_Prime[i]) + " X ";
	}
	eraseLastCharInString(answer, 2);

	cout << "Factors of " << a << ": " << answer << endl;
}
inline void PrimeFactorization::displayTheAnswer(int a, vector<int> dividendArr_Prime, vector<int> divisorArr_Prime, vector<int>& quotientArr)
{
	newLineMaker(1);
	displayLongDivision(dividendArr_Prime, divisorArr_Prime, quotientArr);
	newLineMaker(1);
	displayTreeMethod(dividendArr_Prime, divisorArr_Prime, quotientArr);
	cout << "************************************" << endl;
	displayPrimeFactors(a, divisorArr_Prime);
}
inline void PrimeFactorization::clearBuffer()
{
	primeNumbersArr.clear();
	quotientArr.clear();
	dividendArr_Prime.clear();
	divisorArr_Prime.clear();
}
