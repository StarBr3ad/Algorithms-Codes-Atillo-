#pragma once
#include "Libraries.h"
#include "Operation.h"
#include "RecyclableMethods.h"

class Bitwise : Converter
{
	private:
		void INPUT_MAIN_MENU(string & a, string & b, int input);
		int OPERATION_MAIN_MENU(int input);
		void EXIT_MENU_LOOP(int& tryAgainFlag, int& input);
		void fixInputLength_Str(string binString, string & wholeNumber, string & fraction, int& dPlace);
		void fixBothInputsSize(string & wholeNumber1, string & fraction1, string & wholeNumber2, string & fraction2);
		void doYourThing(int input, int dplace1, int dplace2, string decimalString1, string fractionString1, string decimalString2, string fractionString2);

	public:
		void MAIN_LOOP();
};

//PROBLEMS
//SAYOP ANG XOR SA FRACTION NA PART PREV CODE: resultFrac_Str.erase(0, resultFrac_Str.find_first_not_of('0'));
//SAYOP RA ANG DISPLAY


