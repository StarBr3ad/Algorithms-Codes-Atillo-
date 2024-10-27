#include "Bitwise.h"

//YAWA MAO NI PINAKAHUGAW NA CODE

//SEPARATE THE DECIMAL AND FRACTION
void Bitwise::fixInputLength_Str(string binString, string& wholeNumber, string& fraction, int& dPlace)
{
	dPlace = binString.find('.');
	wholeNumber = binString.substr(0, dPlace);

	if (dPlace > 0)
	{
		fraction = binString.substr(dPlace + 1);
	}
}

//PADD THE NUMBER IF NOT SAME SIZE TO ITS COUNTERPART
void Bitwise::fixBothInputsSize(string& wholeNumber1, string& fraction1, string& wholeNumber2, string& fraction2)
{
	if (wholeNumber1.size() != wholeNumber2.size())
	{
		if (wholeNumber1.size() > wholeNumber2.size())
		{
			wholeNumber2.insert(0, wholeNumber1.size() - wholeNumber2.size(), '0');
		}
		else
		{
			wholeNumber1.insert(0, wholeNumber2.size() - wholeNumber1.size(), '0');
		}
	}

	if (fraction1.size() != fraction2.size())
	{
		if (fraction1.size() > fraction2.size())
		{
			fraction2.insert(fraction2.size(), fraction1.size() - fraction2.size(), '0');
		}
		else
		{
			fraction1.insert(fraction1.size(), fraction2.size() - fraction1.size(), '0');
		}
	}
}

//DO THE OPERATION IN BITSET, TRANSLATE TO STRING, ERASE THE TRAILING ZEROS, DISPLAY THE FIXED_2_INPUT_STRING, DISPLAY THE ANSWER
void Bitwise::doYourThing(int input, int dplace1, int dplace2, string decimalString1, string fractionString1, string decimalString2, string fractionString2)
{
	bitset<100>	binaryDec1(decimalString1),
		binaryFrac1(fractionString1),

		binaryDec2(decimalString2),
		binaryFrac2(fractionString2);

	bitset<100>	resultDec,
		resultFrac;

	string		resultDec_Str,
		resultFrac_Str;

	switch (input)
	{
	case 1:
		resultDec = binaryDec1 & binaryDec2;
		resultFrac = binaryFrac1 & binaryFrac2;

		resultDec_Str = resultDec.to_string();
		resultDec_Str.erase(0, resultDec_Str.find_first_not_of('0'));

		resultFrac_Str = resultFrac.to_string();
		resultFrac_Str.erase(0, resultFrac_Str.size() - fractionString1.size());

		cout << "\n\nBITWISE OPERATION: AND" << endl;
		break;

	case 2:
		resultDec = ~binaryDec1;
		resultFrac = ~binaryFrac1;

		resultDec_Str = resultDec.to_string();
		resultDec_Str.erase(0, resultDec_Str.find_first_not_of('1'));

		resultFrac_Str = resultFrac.to_string();
		resultFrac_Str.erase(0, resultFrac_Str.size() - fractionString1.size());

		cout << "\n\nBITWISE OPERATION: NOT" << endl;
		break;

	case 3:
		resultDec = binaryDec1 | binaryDec2;
		resultFrac = binaryFrac1 | binaryFrac2;

		resultDec_Str = resultDec.to_string();
		resultDec_Str.erase(0, resultDec_Str.find_first_not_of('0'));

		resultFrac_Str = resultFrac.to_string();
		resultFrac_Str.erase(0, resultFrac_Str.size() - fractionString1.size());

		cout << "\n\nBITWISE OPERATION: OR" << endl;
		break;

	case 4:
		resultDec = binaryDec1 ^ binaryDec2;
		resultFrac = binaryFrac1 ^ binaryFrac2;

		resultDec_Str = resultDec.to_string();
		resultDec_Str.erase(0, resultDec_Str.find_first_not_of('0'));

		resultFrac_Str = resultFrac.to_string();
		resultFrac_Str.erase(0, resultFrac_Str.size() - fractionString1.size());

		cout << "\n\nBITWISE OPERATION: XOR" << endl;
		break;

	default:
		cout << "WTF YU BROKE MAIN MENU ITS IMPOSSIBLE" << endl;
		break;
	}

	if (input != 2)
	{
		fixBothInputsSize(resultDec_Str, resultFrac_Str, decimalString1, decimalString2);
		cout << "***************************" << endl;
		if (dplace1 > 0 || dplace2 > 0)
		{
			cout << "Binary 1: " << decimalString1 + "." + fractionString1 << endl;
			cout << "Binary 2: " << decimalString2 + "." + fractionString2 << endl;
			cout << "  Answer: " << resultDec_Str + "." + resultFrac_Str << endl;
		}
		else
		{
			cout << "Binary 1: " << decimalString1 << endl;
			cout << "Binary 2: " << decimalString2 << endl;
			cout << "  Answer: " << resultDec_Str << endl;
		}
	}
	else
	{
		cout << "***************************" << endl;
		if (dplace1 > 0)
		{
			cout << "Binary 1: " << decimalString1 + "." + fractionString1 << endl;
			cout << "  Answer: " << resultDec_Str + "." + resultFrac_Str << endl;
		}
		else
		{
			cout << "Binary 1: " << decimalString1 << endl;
			cout << "  Answer: " << resultDec_Str << endl;
		}
	}
}

void Bitwise::MAIN_LOOP()
{
	int		input = -1;
	int		tryAgainFlag = -1;

	string	binaryString1 = "0",
			binaryString2 = "0";

	string	wholeNumber1, fraction1,
			wholeNumber2, fraction2;
	int		dplace1 = -1, dplace2 = -1;				// IF -1 NO DECIMAL

	while (tryAgainFlag == -1 || tryAgainFlag == 2)
	{
		//CHOOSE YOUR INPUT
		input = OPERATION_MAIN_MENU(input);

		//GETTING BINARYSTR1 AND BINARYSTR2
		INPUT_MAIN_MENU(binaryString1, binaryString2, input);

		//INPUTFIX
			if (input != 2)
			{
				//SEPARATE THE DECIMAL AND FRACTION
				fixInputLength_Str(binaryString1, wholeNumber1, fraction1, dplace1);
				fixInputLength_Str(binaryString2, wholeNumber2, fraction2, dplace2);

				//PADD THE NUMBER IF NOT SAME SIZE TO ITS COUNTERPART
				fixBothInputsSize(wholeNumber1, fraction1, wholeNumber2, fraction2);
			}
			else
			{
				fixInputLength_Str(binaryString1, wholeNumber1, fraction1, dplace1);
			}
		//INPUTFIX


		doYourThing(input, dplace1, dplace2, wholeNumber1, fraction1, wholeNumber2, fraction2);


		//RESSETER
			binaryString1 = "0"; binaryString2 = "0";

			wholeNumber1 = "0"; fraction1 = "0";
			wholeNumber2 = "0"; fraction2 = "0";

			dplace1 = -1; dplace2 = -1;
		//RESETTER

		//EXIT_LOOP
			tryAgainFlag = -1;
			EXIT_MENU_LOOP(tryAgainFlag, input);
		//EXIT_LOOP
	}
	
}

//CHOOSE YOUR INPUT
void Bitwise::INPUT_MAIN_MENU(string& a, string& b, int input)
{
	int check1 = -1;
	int check2 = -1;

	cout << "\n\n***************************" << endl;
	cout << "ONLY INPUT 1 AND 0 (BINARY)\n" << endl;
	if (input == 2)
	{
		cout << "INPUT 1 BINARY NUMBERS" << endl;
		while (check1 != 0)
		{
			cout << "Binary 1: "; cin >> a;
			check1 = checkIfBinaryInput(a);
			writeErrorForInput(check1);
		}
	}
	else
	{
		cout << "INPUT 2 BINARY NUMBERS" << endl;
		while (check1 != 0)
		{
			cout << "Binary 1: "; cin >> a;
			check1 = checkIfBinaryInput(a);
			writeErrorForInput(check1);
		}
		while (check2 != 0)
		{
			cout << "Binary 2: "; cin >> b;
			check2 = checkIfBinaryInput(b);
			writeErrorForInput(check2);
		}

	}
}

//GETTING BINARYSTR1 AND BINARYSTR2
int Bitwise::OPERATION_MAIN_MENU(int input)
{
	cout << "Choose your operation:" << endl;
	cout << "[ 1 ] AND " << endl;
	cout << "[ 2 ] NOT " << endl;
	cout << "[ 3 ] OR " << endl;
	cout << "[ 4 ] XOR " << endl;

	while (input <= 0 || input > 4)
	{
		cout << "\nInput: "; cin >> input;
	}

	return input;
}

void Bitwise::EXIT_MENU_LOOP(int& tryAgainFlag, int& input)
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