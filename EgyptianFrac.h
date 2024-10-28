#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class NiggasFraction : SieveOfErathosthenes
{
	public:
		void MAIN_LOOP()
		{
			int numerator, denominator, input = -1, tryAgainFlag = -1;

			while (tryAgainFlag == -1 || tryAgainFlag == 2)
			{
				cout << "*********FIBBONACI CALCULATOR*********" << endl;
				cout << "Numerator  : "; cin >> numerator;
				cout << "Denominator: "; cin >> denominator;

				doTheNiggaShit(numerator, denominator);

				//RESET BUFFER
					numerator = 0; 
					denominator = 0;
				//RESET BUFFER

				tryAgainFlag = -1;

				SieveOfErathosthenes::EXIT_MENU_LOOP(tryAgainFlag, input);
			}
		}

	protected:
		void doTheNiggaShit(int numerator, int denominator)
		{

			newLineMaker(0); 
			cout << "Answer: " << endl;
			cout << numerator << "/" << denominator << " = ";
			while (numerator > 0)
			{
				int x = (denominator + numerator - 1) / numerator;

				cout << "1/" << x;

				numerator = numerator * x - denominator;
				denominator = denominator * x;

				if (numerator > 0) 
				{
					cout << " + ";
				}
			}
		}
};