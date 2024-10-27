#include "Operation.h"
#include "Converter.h"
#include "RecyclableMethods.h"

void Operation::MAIN_LOOP()
{
	int input = -1;
	int tryAgainFlag = -1;

	while (tryAgainFlag == -1 || tryAgainFlag == 2)
	{
		//WRITE THE FIRST MAIN MENU AND LOOPS IF WRONG AND RETURNS INPUT
		input = FIRST_MAIN_MENU(input);
		
		//USE THE 4 INPUTS DEPENDING ON input
		switch (input)
		{
			case 1:
				BIN_Input_Converter();
				break;

			case 2:
				OCT_Input_Converter();
				break;

			case 3:
				DEC_Input_Operation();
				break;

			case 4:
				HEX_Input_Operation();
				break;

			default:
				cout << "WTF YU BROKE MAIN MENU ITS IMPOSSIBLE" << endl;
				break;
		}

		//RESET THE TRYAGAINFLAG TO AVOID DIRECTLY LOOPING THE ENTIRE WHILE LOOP
		tryAgainFlag = -1;
		EXIT_MENU_LOOP(tryAgainFlag, input);
	}
	
	WRITE_LAST_GOODBYE();
}



//MAIN LOOP UI
int Operation::FIRST_MAIN_MENU(int input)
{		
	cout << "Choose your input:" << endl;
	cout << "[ 1 ] Binary " << endl;
	cout << "[ 2 ] Octal " << endl;
	cout << "[ 3 ] Decimal " << endl;
	cout << "[ 4 ] Hexadecimal " << endl;

	while (input <= 0 || input > 4)
	{
		cout << "\nInput: "; cin >> input;
	}

	return input;
}
void Operation::EXIT_MENU_LOOP(int& tryAgainFlag, int& input)
{
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
void Operation::WRITE_LAST_GOODBYE()
{
	cout << "NIGGER" << endl;
}



//INPUTS
void Operation::BIN_Input_Converter()
{
	int check1 = -1;
	int check2 = -1;

	cout << "Enter your binary numbers, and the operation will be performed once you proceed!\n";
	cout << "\nNote: \nInput 1 = divisor\nInput 2 = dividend";
	cout << "\n\n\n(0, 1)\n";

	//INPUT CHECKER
	//FOR INPUT 1
	while (check1 != 0)
	{
		cout << "Your Binary Input 1: "; cin >> input1;

		check1 = checkIfBinaryInput(input1);
		writeErrorForInput(check1);
	}
	//FOR INPUT 2
	while (check2 != 0)
	{
		cout << "Your Binary Input 2: "; cin >> input2;

		check2 = checkIfBinaryInput(input2);
		writeErrorForInput(check2);
	}

	//WRITES THE OPERATION MENU AND WAIT FOR INPUT AND BASED ON INPUT DO THE CASE
	switch (operationHandler())
	{
	case 1:
		//REMOVE THE DECIMALPOINT AND GET TOTALDECIMALPOINT FOR ANSWER
		cleanInput_And_GetTotalDecimalPlace(input1, input2, false, false, false, 1);

		//ADD BOTH BINARY INPUT
		//ADD BOTH BINARY AS DECIMAL AND GET A DECIMAL RESULT
		//TRANSLATE DECIMAL INPUT TO BINARY AND ADD DECIMAL POINT IF NECESSARY
		//INCLUDES: MAIN CLASS METHOD
		BIN_Operation('+');
		break;

	case 2:
		//FLIP INPUT1 AND INPUT2 (IF TRUE)
		checkMinuend(2, input1, input2);

		//REMOVE THE DECIMALPOINT AND GET TOTALDECIMALPOINT FOR ANSWER
		cleanInput_And_GetTotalDecimalPlace(input1, input2, false, false, false, 1);

		//SAME AS ABOVE BUT SUBTRACT
		BIN_Operation('-');
		break;

	case 3:
		//REMOVE THE DECIMALPOINT AND GET TOTALDECIMALPOINT FOR ANSWER
		cleanInput_And_GetTotalDecimalPlace(input1, input2, true, false, false, 1);

		//SAME AS ABOVE BUT MULTIPLY
		BIN_Operation('*');
		break;

	case 4:
		//RETURN TRUE AND AN ERROR (IF TRUE)
		divisorLessThanDividend = checkDivisor(2, input1, input2);

		if (!divisorLessThanDividend)
		{
			//REMOVE THE DECIMALPOINT AND GET TOTALDECIMALPOINT FOR ANSWER
			cleanInput_And_GetTotalDecimalPlace(input1, input2, false, true, true, 1);

			if (canProceedFlag)
			{
				//SAME AS ABOVE BUT DIVISION
				BIN_Operation('/');
			}
		}
		break;

	default:
		cout << "WTF U ENTERED 4TH DIMENSION?" << endl;
		break;
	}

	resetAllVariable();//FOR MAIN CLASS
	resetAllBuffer_Operation();//FOR CURRENT CLASS
}
void Operation::OCT_Input_Converter()
{
	//TURNED INTO BINARY
	string	translatedInput1, translatedInput2;
	int		check1 = -1;
	int		check2 = -1;

	cout << "Enter your octal numbers, and the operation will be performed once you proceed!\n";
	cout << "\nNote: \nInput 1 = divisor\nInput 2 = dividend";
	cout << "\n\n\n(0, 1)\n";

	//INPUT CHECKER
	//FOR INPUT 1
	while (check1 != 0)
	{
		cout << "Your Octal Input 1: "; cin >> input1;

		check1 = checkIfOctalInput(input1);
		writeErrorForInput(check1);
	}
	//FOR INPUT 2
	while (check2 != 0)
	{
		cout << "Your Octal Input 2: "; cin >> input2;

		check2 = checkIfOctalInput(input2);
		writeErrorForInput(check2);
	}

	//TURN INPUT TO BINARY (INPUT IS OCTAL)
	Operation_OCT_TO_BIN(translatedInput1, translatedInput2);

	//WRITES THE OPERATION MENU AND WAIT FOR INPUT AND BASED ON INPUT DO THE CASE
	switch (operationHandler())
	{
	case 1:
		cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, false, false, 3);

		OCT_Operation('+');
		break;

	case 2:
		//FLIP INPUT1 AND INPUT2 (IF TRUE)
		checkMinuend(8, translatedInput1, translatedInput2);

		cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, false, false, 3);

		OCT_Operation('-');
		break;

	case 3:
		cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, true, false, false, 3);

		OCT_Operation('*');
		break;

	case 4:
		divisorLessThanDividend = checkDivisor(8, translatedInput1, translatedInput2);

		if (!divisorLessThanDividend)
		{
			cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, true, true, 3);

			if (canProceedFlag)
			{
				OCT_Operation('/');
			}
		}
		break;

	default:
		cout << "WTF U ENTERED 4TH DIMENSION?" << endl;
		break;
	}
	//RESETER
	resetAllVariable();//FOR MAIN CLASS
	resetAllBuffer_Operation();//FOR CURRENT CLASS
}
void Operation::DEC_Input_Operation()
{
	string		input1Dec_str, input2Dec_str;
	long double input1Dec, input2Dec;
	int			check1 = -1;
	int			check2 = -1;

	cout << "Enter your octal numbers, and the operation will be performed once you proceed!\n";
	cout << "\nNote: \nInput 1 = divisor\nInput 2 = dividend";
	cout << "\n\n\n(0, 1)\n";

	//INPUT CHECKER
	//FOR INPUT 1
	while (check1 != 0)
	{
		cout << "Your Decimal Input 1: "; cin >> input1Dec_str;

		check1 = checkIfDecimalInput(input1Dec_str);
		writeErrorForInput(check1);
	}
	//MAKE THE STRING INPUT TO LONG DOUBLE
	input1Dec = stold(input1Dec_str);
	//FOR INPUT 2
	while (check2 != 0)
	{
		cout << "Your Decimal Input 2: "; cin >> input2Dec_str;

		check2 = checkIfDecimalInput(input2Dec_str);
		writeErrorForInput(check2);
	}
	//MAKE THE STRING INPUT TO LONG DOUBLE
	input2Dec = stold(input2Dec_str);



	//DISPLAY THE MENU AND CHECK INPUTS (INCLUDE WHILE LOOP)
	switch (operationHandler())
	{
	case 1:
		cout << "***************************" << endl;
		cout << "\nAnswer: " << input1Dec + input2Dec << endl;
		break;

	case 2:
		if (input1Dec > input2Dec)
		{
			long double temp;

			temp = input1Dec;
			input1Dec = input2Dec;
			input2Dec = temp;

			cout << "\n\nWe want to subtract a larger number from a smaller one. To find the answer, switch \nthe numbers, do the calculation and attach a minus sign in front of the result.\n" << endl;
			cout << input1Dec << " - " << input2Dec << endl;

			cout << "***************************" << endl;
			cout << "\nAnswer: " << input1Dec - input2Dec << endl;
		}
		else
		{
			cout << "***************************" << endl;
			cout << "\nAnswer: " << input1Dec - input2Dec << endl;
		}
		break;

	case 3:
		cout << "***************************" << endl;
		cout << "\nAnswer: " << input1Dec * input2Dec << endl;
		break;

	case 4:
		if (input1Dec > input2Dec)
		{
			cout << "\n\nERROR: Enter a divisor less than the dividend.\n" << endl;
		}
		else
		{
			cout << "***************************" << endl;
			cout << "\nAnswer: " << input1Dec / input2Dec << endl;
		}
		break;

	default:
		cout << "WTF U ENTERED 4TH DIMENSION?" << endl;
		break;
	}
	//RESETER
	resetAllVariable();//FOR MAIN CLASS
	resetAllBuffer_Operation();//FOR CURRENT CLASS
}
void Operation::HEX_Input_Operation()
{
	//TURNED INTO BINARY
	string	translatedInput1, translatedInput2;
	int		check1 = -1;
	int		check2 = -1;

	cout << "Enter your octal numbers, and the operation will be performed once you proceed!\n";
	cout << "\nNote: \nInput 1 = divisor\nInput 2 = dividend";
	cout << "\n\n\n(0, 1)\n";

	//INPUT CHECKER
	//FOR INPUT 1
	while (check1 != 0)
	{
		cout << "Your Octal Input 1: "; cin >> input1;

		check1 = checkIfHexadecimalInput(input1);
		writeErrorForInput(check1);
	}
	//FOR INPUT 2
	while (check2 != 0)
	{
		cout << "Your Octal Input 2: "; cin >> input2;

		check2 = checkIfHexadecimalInput(input2);
		writeErrorForInput(check2);
	}
	

	//TURN INPUT TO BINARY (INPUT IS OCTAL)
	Operation_HEX_TO_BIN(translatedInput1, translatedInput2);

	//WRITES THE OPERATION MENU AND WAIT FOR INPUT AND BASED ON INPUT DO THE CASE
	switch (operationHandler())
	{
		case 1:
			cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, false, false, 4);
			HEX_Operation('+');
			break;

		case 2:
			//FLIP INPUT1 AND INPUT2 (IF TRUE)
			checkMinuend(16, translatedInput1, translatedInput2);

			cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, false, false, 4);
			HEX_Operation('-');
			break;

		case 3:
			cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, false, false, 4);
			HEX_Operation('*');
			break;

		case 4:
			cleanInput_And_GetTotalDecimalPlace(translatedInput1, translatedInput2, false, false, false, 4);
			HEX_Operation('/');
			break;

		default:
			cout << "WTF U ENTERED 4TH DIMENSION?" << endl;
			break;
	}
	//RESETER
	resetAllVariable();//FOR MAIN CLASS
	resetAllBuffer_Operation();//FOR CURRENT CLASS
}





//BUFFER RESETTER
void Operation::resetAllBuffer_Operation()
{
	input1.clear(); input2.clear();
	clearBinG1_1(); clearBinG1_2();
	cleanInput1.clear(); cleanInput2.clear();
	decimalPointPlace = 0;

	minuendLessThanSubtrahend = false; divisorLessThanDividend = false;
	answerIsTooLong = false;
}

void Operation::clearBinG1_1()
{
	binG1_1.clear();
}

void Operation::clearBinG1_2()
{
	binG1_2.clear();
}





//RECYCLABLE METHODS (IMPORTANT)

//MAKE THE PARAMETER(DEC_Sum) into BIN_G1 
//INCLUDES: MAIN CLASS METHOD
void Operation::make_BIN_G1(double DEC_Sum)
{
	//ASSIGN VALUESTRING(DECIMAL VALUE) AND VALUESTRING LENGTH TO MAIN CLASS 
	valueString = to_string(static_cast<int>(DEC_Sum)); // ( DEC_Sum ) ACT AS AN INPUT
	valueStringLength = valueString.length();

	//(MAIN CLASS METHOD) TURN TO BINARY G1 
	valueSeparator_DecimalTaker(valueStringLength);
}

//REMOVE THE DECIMALPOINT AND GET TOTALDECIMALPOINT FOR ANSWER (ONLY ACCEPTS BINARY!!) 
//Will total the decimalPoint of inputs (getTotalDecimalPlace) else
//will get the highest fractionDecimal
void Operation::cleanInput_And_GetTotalDecimalPlace(string input1, string input2, bool getTotalDecimalPlace, bool ifDivision, bool makeFractionIllegal, int totalDecPlace_Divisor)
{
	//getTotalDecimalPlace: If its multiplication turn this to true; TOTAL ALL THE DECIMAL PLACE AND TURN IT INTO CURRENT DECIMAL PLACE
	//ifDivision: if its division turn this to true: FIX THE INPUT LENGTHS TO AVOID ERRORS IN GETTING THE ANSWERS (RELATED TO MAKEFRACTION ILLEGAL)
	//makeFractionIllegal: If its division turn this to true (IF THERE IS A FRACTION THEN FUCK EVERYTHING) 
	//totalDecPlace_Divisor: if hexa = 4; if octal = 3: (HOW THE BINARY ARE GROUPED)

	//DECIMAL PLACE OF BOTH INPUT
	int dPlace1,
		dPlace2;

	//(MAIN CLASS METHOD)
	//GET THE BIN_G1 AND DECIMALPLACE (FOR BOTH INPUTS)
	//DECIMAL REMOVED!!!!
	valueSeparator_DecimalTaker(input1, binG1_1, dPlace1);
	valueSeparator_DecimalTaker(input2, binG1_2, dPlace2);

	//ERROR CODE BELOW
	//GLOBAL VARIABLE AND A STUPID REASON BELOW 
	if (makeFractionIllegal)
	{
		if (dPlace1 > 0 || dPlace2 > 0)
		{
			//FOR makeFractionIllegal IF THERE IS DECIMAL; THIS = FALSE 
			//I MADE THIS GLOBAL BECAUSE IM USING VOID (YAWA KAPOY USOB DIVISION RAPUD BITAW MO GAMIT (FAMOUS LAST WORD IK))
			canProceedFlag = false;
			cout << "\n\nNO FRACTION IN DIVISION USE THE INTERNET LOL" << endl;
			cout << "\nWEBSITE:\nhttps://madformath.com/" << endl;

			cout << "\n\nI CAN GET THE ANSWER BUT THE RADIX POINT IS WRONG SINCE THE RADIX POINT AND THE ANSWER ARE SEPARATED(TO AVOID HALLUCINATION OF THE ANSWER) I WILL NOT BE FIXING IT\nAND SOLVING THIS WOULD BE A WASTE OF TIME THE NUMBER SYSTEM TRANSLATION W/ SOLUTION IS ENOUGH TO PROVE THAT IM GOOD AT CODING" << endl;
		}
	}

	if(canProceedFlag)
	{
		//NORMALIZED LENGTH OF INPUT 1 AND 2 (WHOLE AND DECIMAL)
		string	wholeNumber1, fraction1,
			wholeNumber2, fraction2;


		//FIX THE LENGTH OF THE BINARY
		if (ifDivision)
		{
			fixInputLength_Operation_Division(input1, input2, dPlace1, dPlace2,
				wholeNumber1, wholeNumber2, fraction1, fraction2);
		}
		else
		{
			fixInputLength_Operation(input1, input2, dPlace1, dPlace2,
				wholeNumber1, wholeNumber2, fraction1, fraction2);
		}


		//COMPILE CLEANINPUT
		cleanInput1 = wholeNumber1 + fraction1;
		cleanInput2 = wholeNumber2 + fraction2;

		//CHANGE THE CODE BELOW TO USE THE NEW WHOLENUMBER AND FRACTION
		//getTotalDecimalPlace NOT CHANGE YET (WILL FIND OUT LATER)

		if (dPlace1 > 0 || dPlace2 > 0)
		{
			//IF PARAMETER(getTotalDecimalPlace) IS TRUE
			//USED IN ALL OPERATIONS EXCEPT MULTIPLICATION
			if (getTotalDecimalPlace)
			{
				//ALSO DIVIDE HERE OR DECIMALPLACE WILL EXCEED
				//GET TOTAL DECIMALPLACE OF BOTH INPUT
				if (dPlace1 > 0)
				{
					decimalPointPlace += ((binG1_1.size() / totalDecPlace_Divisor) - (dPlace1 / totalDecPlace_Divisor));
				}
				if (dPlace2 > 0)
				{
					decimalPointPlace += ((binG1_2.size() / totalDecPlace_Divisor) - (dPlace2 / totalDecPlace_Divisor));
				}
			}
			//IF PARAMETER(getTotalDecimalPlace) IS FALSE
			//IF INPUT HAVE BIGGER😏 FRACTION PART
			//THEN GET ITS DECIMALPOINTPLACE 
			else
			{
				//FRACTION 1 AND 2 ARE THE SAME SIZE (LENGTH ARE FIXED ABOVE (fixInputLength_Operation))

				//OCTAL AND HEXADECIMAL ARE GROUPED TO 3 AND 4 SO THAT'S WHY THE DIVISOR
				//IF NOT DIVIDED THE DECIMALPOINTPLACE WILL EXCEED (EXCEPT IF IT COMES FROM A BINARY INPUT (THE FIRST INPUT (CIN >> INPUT1)))
				decimalPointPlace = fraction2.size() / totalDecPlace_Divisor;
			}
		}
	}
}

//ADD O TO BOTH OF THE INTEGER DECIMAL PART (TO NORMALIZE BINARY LENGTHS)
//RETURNS CHANGED VALUE
void Operation::fixInputLength_Operation(string input1, string input2, int dplace1,  int dplace2,
	string& wholeNumber1, string& wholeNumber2, string& fraction1, string& fraction2)
{
	int	difference = 0;

	//SEPARATE BOTH DECIMAL AND FRACTION FOR BOTH INPUTS
	separateDecimalAndFraction(input1, dplace1, wholeNumber1, fraction1);
	separateDecimalAndFraction(input2, dplace2, wholeNumber2, fraction2);

	//WHOLE INTEGER PART
	//COMPARING WHO IS BIGGER
	if (wholeNumber1.size() != wholeNumber2.size())
	{
		//IF INPUT1.SIZE() IS BIGGER THAN INPUT2
		if (wholeNumber1.size() > wholeNumber2.size())
		{
			//KWAON ANG KULANG NA 0 (NOT SAME BELOW)
			difference = wholeNumber1.size() - wholeNumber2.size();

			//INSERT 0 AT THE START
			while (wholeNumber1.size() != wholeNumber2.size())
			{
				wholeNumber2.insert(0, 1, '0');
			}
		}
		//IF INPUT2.SIZE() IS BIGGER THAN INPUT2
		else if (wholeNumber2.size() > wholeNumber1.size())
		{
			difference = wholeNumber2.size() - wholeNumber1.size();

			while (wholeNumber1.size() != wholeNumber2.size())
			{
				wholeNumber1.insert(0, 1, '0');
			}
		}
	}


	//DONT PERFORM THIS IF THERE IS NO DECIMAL
	if (dplace1 > 0 || dplace2 > 0)
	{
		//DECIMAL PART
		//COMPARING WHO IS BIGGER (SAME CODE AS ABOVE)
		if (fraction1.size() != fraction2.size())
		{
			//RESET THE DIFFERENCE BUFFER
			difference = 0;

			if (fraction1.size() > fraction2.size())
			{
				difference = fraction1.size() - fraction2.size();

				while (fraction1.size() != fraction2.size())
				{
					fraction2.insert(fraction2.end(), 1, '0');
				}
			}

			else if (fraction2.size() > fraction1.size())
			{
				difference = fraction2.size() - fraction1.size();

				while (fraction1.size() != fraction2.size())
				{
					fraction1.insert(fraction1.end(), 1, '0');
				}
			}
		}
	}

}

//NOT SAME AS ABOVE PUT 0 TO THE LEFT OF FIRST INPUT
void Operation::fixInputLength_Operation_Division(string input1, string input2, int dplace1, int dplace2,
	string& wholeNumber1, string& wholeNumber2, string& fraction1, string& fraction2)
{
	//SEPARATE BOTH DECIMAL AND FRACTION FOR BOTH INPUTS
	separateDecimalAndFraction(input1, dplace1, wholeNumber1, fraction1);
	separateDecimalAndFraction(input2, dplace2, wholeNumber2, fraction2);

	if (wholeNumber1.size() != wholeNumber2.size() + fraction2.size())
	{
		//IF INPUT1.SIZE() IS LESS THAN INPUT2 THEN ADD ALL THE 0 TO WHOLE NUMBER (FOR 0 TO BE ADDED TO THE LEFTSIDE)
		if (wholeNumber1.size() < wholeNumber2.size())
		{
			//INSERT 0 AT THE START
			while (wholeNumber1.size() != (wholeNumber2.size() + fraction2.size()) - fraction1.size())
			{
				wholeNumber1.insert(0, 1, '0');
			}
		}
		else if (wholeNumber1.size() > wholeNumber2.size())
		{
			cout << "BACKEND ERROR(fixInputLength_Operation_Division): YOU FORGOR ABOUT THIS METHOD USAGE: (DIVISOR > DIVIDEND) THIS SHOULD NOT HAPPEN!!! " << endl;
		}
	}

	//DONT PERFORM THIS IF THERE IS NO DECIMAL
	if (dplace1 > 0 || dplace2 > 0)
	{
		//CHECK IF(A PART OF) INPUT1(wholeNumber1.size()) IS THE SAME LENGTH OF INPUT2 - fraction1.size
		if (wholeNumber1.size() < (wholeNumber2.size() + fraction2.size()) - fraction1.size())
		{
			//DECIMAL PART
			//COMPARING WHO IS BIGGER (SAME CODE AS ABOVE)
			if (fraction1.size() != fraction2.size())
			{
				if (fraction1.size() > fraction2.size())
				{
					while (fraction1.size() != fraction2.size())
					{
						fraction2.insert(fraction2.end(), 1, '0');
					}
				}
				else if (fraction2.size() > fraction1.size())
				{
					while (fraction1.size() != fraction2.size())
					{
						fraction1.insert(fraction1.end(), 1, '0');
					}
				}
			}
		}
	}
}

//(MINUEND - SUBTRAHEND) IF SUBTRAHEND > MINUEND = NEGATIVE NUMBER (FIXED)
void Operation::checkMinuend(int baseNumberSystem, string& binaryInput1, string& binaryInput2)
{
	double input1_DEC_value = 0, input2_DEC_value = 0;
	string octalToBin1, octalToBin2;

	//FOR MINUEND AND SUBTRAHEND COMPARISON

	switch (baseNumberSystem)
	{
	case 2:
		//TURN BINARY STRING(INPUT1) TO DECIMAL
		Operation_BIN_TO_DEC(input1);
		input1_DEC_value = DEC_Value;//DEC_Value IS A FIELD TO MAIN CLASS 

		//BECAUSE DEC_VALUE IS BEING += (SO DEC_VALUE PREVIOUS VALUE WILL BE ALSO ADDED)
		//CLEAR THE BUFFER
		resetAllVariable();
		Operation_BIN_TO_DEC(input2);
		input2_DEC_value = DEC_Value;
		break;

	case 8:
		//TRANSLATE BOTH INPUTS(OCTAL) TO BINARY
		Operation_OCT_TO_BIN(octalToBin1, octalToBin2);

		//GET THE VALUE OF BOTH TRANSLATED BINARY
		Operation_BIN_TO_DEC(octalToBin1);
		input1_DEC_value = DEC_Value;

		//CLEAR THE BUFFER
		resetAllVariable();

		Operation_BIN_TO_DEC(octalToBin2);
		input2_DEC_value = DEC_Value;

		break;

	case 10:
		break;

	case 16:
		//GET THE VALUE OF BOTH TRANSLATED BINARY
		Operation_BIN_TO_DEC(binaryInput1);
		input1_DEC_value = DEC_Value;

		//CLEAR THE BUFFER
		resetAllVariable();

		Operation_BIN_TO_DEC(binaryInput2);
		input2_DEC_value = DEC_Value;
		break;

	default:
		cout << "BACKEND ERROR(checkMinuend): PARAMETER INPUT SHOULD ONLY BE (2, 8, 10, 16) " << endl;
		break;
	}
	

	//FLIP INPUT 1 AND 2 (BECAUSE (METHOD COMMENT!!))
	if (input2_DEC_value > input1_DEC_value)
	{
		minuendLessThanSubtrahend = true;
		//WARNING 
		cout << "\n\nWe want to subtract a larger number from a smaller one. To find the answer, switch \nthe numbers, do the calculation and attach a minus sign in front of the result.\n" << endl;

		//FLIP THE INPUT 1 AND 2
		string temp;
		temp = binaryInput1;
		binaryInput1 = binaryInput2;
		binaryInput2 = temp;

		//WRITE THE CORRECTED FORMAT
		cout << input2 + " - " + input1 << endl;
	}
	
}

//(DIVISOR - DIVIDEND) IF DIVISOR > DIVIDEND = RETURN TRUE AND AN ERROR
bool Operation::checkDivisor(int baseNumberSystem, string& binaryInput1, string& binaryInput)
{
	double input1_DEC_value, input2_DEC_value;
	string octalToBin1, octalToBin2;

	//FOR DIVISOR AND DIVIDEND COMPARISON
	
	switch (baseNumberSystem)
	{
	case 2:
		//TURN BINARY STRING(INPUT1) TO DECIMAL
		Operation_BIN_TO_DEC(input1);
		input1_DEC_value = DEC_Value;//DEC_Value IS A FIELD TO MAIN CLASS 

		//BECAUSE DEC_VALUE IS BEING += (SO DEC_VALUE PREVIOUS VALUE WILL BE ALSO ADDED)
		//CLEAR THE BUFFER
		resetAllVariable();
		Operation_BIN_TO_DEC(input2);
		input2_DEC_value = DEC_Value;
		break;

	case 8:
		//GET THE VALUE OF BOTH TRANSLATED BINARY
		Operation_BIN_TO_DEC(binaryInput1);
		input1_DEC_value = DEC_Value;

		//CLEAR THE BUFFER
		resetAllVariable();

		Operation_BIN_TO_DEC(binaryInput);
		input2_DEC_value = DEC_Value;
		break;

	case 10:

		break;

	case 16:

		break;

	default:
		cout << "BACKEND ERROR(checkDivisor): PARAMETER INPUT SHOULD ONLY BE (2, 8, 10, 16) " << endl;
		break;
	}

	if (input1_DEC_value > input2_DEC_value)
	{
		cout << "\n\nERROR: Enter a divisor less than the dividend.\n" << endl;
		return true;
	}

	return false;
}




//INPUT CHECKERS (return)(1 = add, 2 = minus, 3 = multiply, 4 = divide) 
int Operation::operationHandler()
{
	bool loopFlag = false;
	int operation;

	while (!loopFlag)
	{
		cout << "\nNote: When using division the divisor should not have a decimal" << endl;
		cout << "Input your operation:" << endl;
		cout << "[ 1 ] Addition " << endl;
		cout << "[ 2 ] Subtraction " << endl;
		cout << "[ 3 ] Multiplication " << endl;
		cout << "[ 4 ] Division " << endl;
		cout << "Input: "; cin >> operation;

		switch (operation)
		{
		case 1:
			return 1;
			loopFlag = true;
			break;

		case 2:
			return 2;
			loopFlag = true;
			break;

		case 3:
			return 3;
			loopFlag = true;
			break;

		case 4:
			return 4;
			loopFlag = true;
			break;

		default:
			cout << "Read The instructions nigga!! \n\n\n" << endl;
			loopFlag = false;
			break;
		}
	}
}



//MAIN OPERATION

//OPERATION ONLY (+, -, *, /)!!!
void Operation::BIN_Operation(char operation)
{
	long double answer;

	//CALCULATE BOTH BINARY DEPENDING TO OPERATION(CHAR) (+, -, *, /)
	answer = operateBinary_ReturnDecimal(cleanInput1, cleanInput2, operation);

	if (answer < 0)
	{
		cout << setprecision(50) << "\n\nDEC_VALUE_OPERATED: " << answer << endl;
		cout << "THE ANSWER IS TOO FUCKING LONG I AINT USING OTHER LIBRARY TO MAKE THE PRECISION MORE BIGGER USE THE INTERNET LOL \nDATA TYPE CURRENTLY USED: DOUBLE FLOAT " << endl;
	}
	else
	{
		//MAKE BIN_G1 (SEPARATE THE VALUE FOR DECIMAL TO BINARY(ANSWER))
		make_BIN_G1(answer);

		//CALCULATE THE BINARY VALUE (LOCAL)
		Operation_DEC_TO_BIN();

		//ALSO PUT NEGATIVE IF MINUEND IS LESS THAN SUBTRAHEND (SUBTRACTION)
		BIN_Input_WriteSolution();
	}
}
void Operation::BIN_Input_WriteSolution()
{
	string answer;

	for (int i = Whole_Dividend.size() - 1; i >= 0; i--)
	{
		answer += to_string(Whole_Remainder[i]);
	}
	
	if (decimalPointPlace > 0)
	{
		answer.insert((answer.size() - decimalPointPlace), ".");
	}
	
	//INSERT NEGATIVE IF BELOW TRUE (FOR SUBTRACTION)
	if (minuendLessThanSubtrahend)
	{
		answer.insert(0, "-");
	}
	cout << "***************************\n" << endl;
	cout << "\nAnswer: " << answer << endl;
}

void Operation::OCT_Operation(char operation)
{
	double answer;
	//CALCULATE BOTH BINARY DEPENDING TO OPERATION(CHAR) (+, -, *, /)
	answer = operateBinary_ReturnDecimal(cleanInput1, cleanInput2, operation); 

	if (answer < 0)
	{
		cout << setprecision(100) << "\n\DEC_VALUE_OPERATED: \n" << answer << endl;
		cout << "THE ANSWER IS TOO FUCKING LONG I AINT USING OTHER LIBRARY TO MAKE THE PRECISION MORE BIGGER USE THE INTERNET LOL \n\nWEBSITE:\nhttps://madformath.com/calculators/digital-systems/octal-arithmetic/octal-multiplication-calculator-with-steps/octal-multiplication-calculator-with-steps\n\n\nDATA TYPE CURRENTLY USED: DOUBLE FLOAT " << endl;
	}
	else
	{
		//MAKE BIN_G1 (SEPARATE THE VALUE FOR DECIMAL TO BINARY(ANSWER))
		make_BIN_G1(answer);

		//CALCULATE THE OCTAL VALUE OF ANSWER((LOCAL)
		Operation_DEC_TO_OCT();

		//ALSO PUT NEGATIVE IF MINUEND IS LESS THAN SUBTRAHEND (SUBTRACTION)
		OCT_Input_WriteSolution();
	}
}
void Operation::OCT_Input_WriteSolution()
{
	string answer;

	for (int i = Whole_Dividend.size() - 1; i >= 0; i--)
	{
		answer += to_string(Whole_Remainder[i]);
	}

	if (decimalPointPlace > 0)
	{
		answer.insert((answer.size() - decimalPointPlace), ".");
	}

	//INSERT NEGATIVE IF BELOW TRUE (FOR SUBTRACTION)
	if (minuendLessThanSubtrahend)
	{
		answer.insert(0, "-");
	}

	cout << "***************************\n" << endl;
	cout << "\nAnswer: " << answer << endl;
}

void Operation::HEX_Operation(char operation)
{
	double answer;
	//CALCULATE BOTH BINARY DEPENDING TO OPERATION(CHAR) (+, -, *, /)
	answer = operateBinary_ReturnDecimal(cleanInput1, cleanInput2, operation);
	cout << "answer" << answer << endl;

	if (answer < 0)
	{
		cout << setprecision(100) << "\n\DEC_VALUE_OPERATED: \n" << answer << endl;
		cout << "THE ANSWER IS TOO FUCKING LONG I AINT USING OTHER LIBRARY TO MAKE THE PRECISION MORE BIGGER USE THE INTERNET LOL \n\nWEBSITE:\nhttps://madformath.com/calculators/digital-systems/octal-arithmetic/octal-multiplication-calculator-with-steps/octal-multiplication-calculator-with-steps\n\n\nDATA TYPE CURRENTLY USED: DOUBLE FLOAT " << endl;
	}
	else
	{
		//MAKE BIN_G1 (SEPARATE THE VALUE FOR DECIMAL TO BINARY(ANSWER))
		make_BIN_G1(answer);

		//CALCULATE THE HEXA VALUE OF ANSWER(LOCAL)
		Operation_DEC_TO_HEX();

		//ALSO PUT NEGATIVE IF MINUEND IS LESS THAN SUBTRAHEND (SUBTRACTION)
		HEX_Input_WriteSolution();
	}
}
void Operation::HEX_Input_WriteSolution()
{
	string answer;

	for (int i = Whole_Dividend.size() - 1; i >= 0; i--)
	{
		turnDecimalToHexadecimalValue(Whole_Remainder[i], answer);
	}

	if (decimalPointPlace > 0)
	{
		answer.insert((answer.size() - decimalPointPlace), ".");
	}

	//INSERT NEGATIVE IF BELOW TRUE (FOR SUBTRACTION)
	if (minuendLessThanSubtrahend)
	{
		answer.insert(0, "-");
	}

	cout << "***************************\n" << endl;
	cout << "\nAnswer: " << answer << endl;
}


//THE OPERATION IS DONE IN BINARY AND RESULT TO DECIMAL (TURN THIS DECIMAL TO THE FINAL OUTPUT)
void Operation::Operation_DEC_TO_BIN()
{
	//SEPARATE THE DECIMAL AND FRACTION
	BIN_G1_SeparateValue_DecimalAndFraction(Binary_G1, decimalPlace, wholeNumber, fraction, precisionLimiter_For_FractionValue);

	//GET REMAINDER (MAIN ANSWER), GET DIVIDEND, QUOTIENTS, AND REMAINDER (FOR SOLUTION)
	GetRemainder(2, wholeNumber, fraction,
		Whole_Dividend, Whole_Quotients, Whole_Remainder,
		Fraction_Dividend, Fraction_Quotients, Fraction_Remainder);
}
void Operation::Operation_DEC_TO_OCT()
{
	//SEPARATE THE DECIMAL AND FRACTION
	BIN_G1_SeparateValue_DecimalAndFraction(Binary_G1, decimalPlace, wholeNumber, fraction, precisionLimiter_For_FractionValue);

	//GET REMAINDER (MAIN ANSWER), GET DIVIDEND, QUOTIENTS, AND REMAINDER (FOR SOLUTION)
	GetRemainder(8, wholeNumber, fraction,
		Whole_Dividend, Whole_Quotients, Whole_Remainder,
		Fraction_Dividend, Fraction_Quotients, Fraction_Remainder);
}
void Operation::Operation_DEC_TO_HEX()
{
	//SEPARATE THE DECIMAL AND FRACTION
	BIN_G1_SeparateValue_DecimalAndFraction(Binary_G1, decimalPlace, wholeNumber, fraction, precisionLimiter_For_FractionValue);

	//GET REMAINDER (MAIN ANSWER), GET DIVIDEND, QUOTIENTS, AND REMAINDER (FOR SOLUTION)
	GetRemainder(16, wholeNumber, fraction,
		Whole_Dividend, Whole_Quotients, Whole_Remainder,
		Fraction_Dividend, Fraction_Quotients, Fraction_Remainder);
}



//INPUT2 BUFFER IS NOT REFRESHED HERE, EXCEPT TO INPUT1 (REFRESHED)
//CHANGES THE FIELDS INPUT1 AND 2 (ALSO TAKEN AS AN INPUT)
void Operation::Operation_OCT_TO_BIN(string& octalTranslatedToBinary1, string& octalTranslatedToBinary2)
{
	int				dPlace1,
					dPlace2;

	//MAKE BIN_G1 FOR OCTAL TO BINARY METHOD (MAIN CLASS METHOD)
	valueSeparator_DecimalTaker(input1, binG1_1, dPlace1);
	valueSeparator_DecimalTaker(input2, binG1_2, dPlace2);

	//MAKE BIN_G3 (FOR BIN_G1)
	octalToBinary(binG1_1, Binary_G3);

	//GET INPUT1 BINARY (TRANSLATED)
	for (int i = 0; i < Binary_G3.size(); i++)
	{
		if (dPlace1 > 0)
		{
			if (dPlace1 != -1 && i == dPlace1)
			{
				octalTranslatedToBinary1 += ".";
			}
		}
		octalTranslatedToBinary1 += Binary_G3[i].GRP_Str;
	}

	//RESET THE BUFFER TO CLEAR BINARY_G3
	resetAllVariable();

	//MAKE BIN_G3 (UPDATED FOR INPUT 2)
	octalToBinary(binG1_2, Binary_G3);

	//GET INPUT2 BINARY (TRANSLATED)
	for (int i = 0; i < Binary_G3.size(); i++)
	{
		if (dPlace2 > 0)
		{
			if (dPlace2 != -1 && i == dPlace2)
			{
				octalTranslatedToBinary2 += ".";
			}
		}
		octalTranslatedToBinary2 += Binary_G3[i].GRP_Str;
	}

	//CLEAR THE BUFFER
	clearBinG1_1();
	clearBinG1_2();
}
void Operation::Operation_HEX_TO_BIN(string& hexTranslatedToBinary1, string& hexTranslatedToBinary2)
{
	int				dPlace1,
					dPlace2;
	vector<GRP_VALUE_2D>	bin_G4_temp1,
							bin_G4_temp2;

	//MAKE BIN_G1 FOR HEXA TO BINARY METHOD (MAIN CLASS METHOD)
	valueSeparator_DecimalTaker(input1, binG1_1, dPlace1, true);
	valueSeparator_DecimalTaker(input2, binG1_2, dPlace2, true);



	hexadecimalToBinary(binG1_1, bin_G4_temp1);
	for (int i = 0; i < bin_G4_temp1.size(); i++)
	{
		if (dPlace1 > 0)
		{
			if (dPlace1 != -1 && i == dPlace1)
			{
				hexTranslatedToBinary1 += ".";
			}
		}

		hexTranslatedToBinary1 += bin_G4_temp1[i].GRP_Str;
	}


	hexadecimalToBinary(binG1_2, bin_G4_temp2);
	for (int i = 0; i < bin_G4_temp2.size(); i++)
	{
		if (dPlace2 > 0)
		{
			if (dPlace2 != -1 && i == dPlace2)
			{
				hexTranslatedToBinary2 += ".";
			}
		}

		hexTranslatedToBinary2 += bin_G4_temp2[i].GRP_Str;
	}
	//CLEAR THE BUFFER
	clearBinG1_1();
	clearBinG1_2();
}

//FROM BINARY TO TARGET NUMBER SYSTEM (FINAL DISPLAY OF OPERATED INPUTS)
void Operation::Operation_BIN_TO_DEC(string binaryString)
{
	//PROBLEM: IT REFERS TO BINARY_G1
	//FIX: MAKE METHOD OVERLOADING THAT USE A STRING AND TURN IT INTO BINARY G1 INSIDE (MAKE IT LOCAL!!)
	calculateVectorValueAndGetSolution(binaryString, BIN_To_DEC_forSolution, 2, DEC_Value);
}
void Operation::Operation_BIN_TO_OCT()
{

}



//BINARY OPERATION METHOD (RETURNS DECIMAL)
//ADD 2 BINARY(10101) AND RETURN DECIMAL (DIVISION IS FLIPPED)
int Operation::operateBinary_ReturnDecimal(string input1, string input2, char operation)
{
	bitset<64>	BIN1(input1),
				BIN2(input2);

	//to ullong (64 bit precision) vs double (53 bit precision)
	switch (operation)
	{
	case '+':
		return static_cast<double>(BIN1.to_ullong() + BIN2.to_ullong());
		break;

	case '-':
		return static_cast<double>(BIN1.to_ullong() - BIN2.to_ullong());
		break;

	case '*':
		return static_cast<double>(BIN1.to_ullong() * BIN2.to_ullong());
		break;

	//DIVISION IS FLIIPPED
	case '/':
		return static_cast<double>(BIN2.to_ullong() / BIN1.to_ullong());
		break;

	default:
		cout << "BACKEND: operateBinary_ReturnDecimal only accepts (+, -, *, /) " << endl;
		break;
	}
}



