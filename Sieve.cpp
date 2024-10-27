#include "Sieve.h"

void getInput(int& minRange, int & maxRange)
{
	cout << "NO INPUT CHECKER ON THIS ONE BRO IM NOW WASTING SHIT JUST INPUT NUMBERS\n\n\n" << endl;
	cout << "Input Range:" << endl;
	cout << "Min: "; cin >> minRange;
	cout << "Max: "; cin >> maxRange;
}

bool isPrime_KSI(int number)
{
	if (number < 2) return false;

	if (number == 2) return true;
	if (number % 2 == 0) return false;

	for (int i = 3; i <= sqrt(number); i += 2)
	{
		if (number % i == 0) {
			return false; 
		}
	}

	return true;
}

void getAllThePrime(int minRange, int maxRange, vector<int>& primeNumbersArr)
{
	bool temp = false;
	for (int i = minRange; i < maxRange; i++)
	{
		temp = isPrime_KSI(i);

		if (temp)
		{
			primeNumbersArr.push_back(i);
		}
	}
}

void writeThePrimes(vector<int> primeNumbersArr)
{
	databaseStyleTable SieveTable;

	vector<string> header, rows;
	header.push_back("h1"); header.push_back("h2"); header.push_back("h3"); header.push_back("h4"); header.push_back("h5"); header.push_back("h6");

	cout << "\n\n\nTHE PRIME NUMBERS: " << endl;
	for (int i = 0; i < primeNumbersArr.size(); i++)
	{
		rows.push_back(to_string(primeNumbersArr[i]));
	}

	SieveTable.createTable(header, rows);
	SieveTable.drawTable();
}

void MAIN_LOOP_SIEVE()
{
	int minRange = 0,
		maxRange = 0,
		input = -1,
		tryAgainFlag = -1;

	vector<int> primeNumbersArr;

	cout << "*********SIEVE OF ERATHOSTHENES*********" << endl;

	while (tryAgainFlag == -1 || tryAgainFlag == 2)
	{
		getInput(minRange, maxRange);
		getAllThePrime(minRange, maxRange, primeNumbersArr);
		writeThePrimes(primeNumbersArr);

		//CLEAR BUFFER
			minRange = 0;
			maxRange = 0;
		//CLEAR BUFFER
		
		//EXIT LOOP
			tryAgainFlag = -1;
			EXIT_MENU_LOOP(tryAgainFlag, input);
		//EXIT LOOP
	}
	
}

void EXIT_MENU_LOOP(int& tryAgainFlag, int& input)
{
	//TRYAGAINFLAG:
	//-1 = DEFAULT (WILL REFRESH)
	// 1 = WILL QUIT THE LOOP (EXIT)
	// 2 = WILL REFRESH THE ENTIRE LOOP (TRY AGAIN)
	// 3 = CLEAR CONSOLE (WILL REFRESH)
	while (tryAgainFlag == 3 || tryAgainFlag == -1 || tryAgainFlag <= 0 || tryAgainFlag > 3)
	{
		cout << "\n\n\nTry Again?" << endl;
		cout << "[ 1 ] Exit " << endl;
		cout << "[ 2 ] Again " << endl;
		cout << "[ 3 ] Clear console " << endl;

		cout << "Input: "; cin >> tryAgainFlag;

		// CLEAR THE CONSOLE
		if (tryAgainFlag == 3)
		{
			system("cls");
		}
	}

	newLineMaker(4);

	//IF YOU EXIT (1)
	if (tryAgainFlag == 1)
	{
		tryAgainFlag = 0;
	}
	//(IF YOU DONT (-1 OR 2))
	else
	{
		tryAgainFlag = 2;
		input = -1;
	}
}