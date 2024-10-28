#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class Fibbonaci : SieveOfErathosthenes
{
	public:
		void MAIN_LOOP()
		{
			int a, input = -1, tryAgainFlag = -1;

			while (tryAgainFlag == -1 || tryAgainFlag == 2)
			{
				cout << "*********FIBBONACI CALCULATOR*********" << endl;
				cout << "Input Range:"; cin >> a;

				display_fib(a);

				//RESET BUFFER
					a = 0;
				//RESET BUFFER

				tryAgainFlag = -1;
				SieveOfErathosthenes::EXIT_MENU_LOOP(tryAgainFlag, input);
			}
		}

	protected:
		int fib(int n)
		{
			if (n <= 1)
			{
				return n;
			}

			return fib(n - 1) + fib(n - 2);
		}
		void display_fib(int n)
		{

			cout << "Answer: " << endl;
			for (int i = 0; i < n + 1; i++)
			{

				cout << "Fib" << "(" << i << ")" << " = " << fib(i);
				if (i > 1)
				{
					cout << " (" << fib(i - 1) << " + " << fib(i - 2) << ")";
				}
				cout << endl;
			}
		}
};
