#pragma once
#include "Converter.h"

class Operation : Converter
{
	public:
		//MAIN LOOP
		void MAIN_LOOP();

	private:
		string input1, input2;
		vector<int> binG1_1, binG1_2;
		string cleanInput1, cleanInput2; //THIS IS IN BINARY
		int decimalPointPlace;

		bool minuendLessThanSubtrahend = false;
		bool divisorLessThanDividend = false;
		bool answerIsTooLong = false;
		bool canProceedFlag = true; //THIS IS FOR DIVISION; IF THERE IS DECIMAL THIS WILL FALSE

		//BUFFER RESETER
		void resetAllBuffer_Operation();
		void clearBinG1_1();
		void clearBinG1_2();



		//MAIN LOOP UI
		int FIRST_MAIN_MENU(int input);
		void EXIT_MENU_LOOP(int& tryAgainFlag, int& input);
		void WRITE_LAST_GOODBYE();



		//INPUTS
		void BIN_Input_Converter();
		void OCT_Input_Converter();
		void DEC_Input_Operation();
		void HEX_Input_Operation();
		//(OPERATION PIPELINE):
		//(TURN CURRENT TARGET SYSTEM TO BINARY)
		//GET THE BINARY VALUE OF EVERYTHING 
		// 
		//DO THE OPERATION IN BINARY (operateBinary_ReturnDecimal)
		// 
		//TURN THE BINARY TO TARGET NUMBER SYSTEM
		//CURRENTLY MADE:
		//(BIN_TO_DEC)



		//RECYCLABLE METHODS
		void make_BIN_G1(double DEC_Sum);
		void cleanInput_And_GetTotalDecimalPlace(string input1, string input2, bool getTotalDecimalPlace, bool ifDivision, bool makeFractionIllegal, int totalDecPlace_Divisor);
		void fixInputLength_Operation(string input1, string input2, int dplace1, int dplace2,
			string& wholeNumber1, string& wholeNumber2, string& fraction1, string& fraction2);
		void fixInputLength_Operation_Division(string input1, string input2, int dplace1, int dplace2, string& wholeNumber1, string& wholeNumber2, string& fraction1, string& fraction2);
		void checkMinuend(int baseNumberSystem, string& binaryInput1, string& binaryInput2);
		bool checkDivisor(int baseNumberSystem, string& binaryInput1, string& binaryInput);




		//INPUT CHECKERS
		int operationHandler();



		//BINARY MAIN OPERATIONS
		void BIN_Operation(char operation);
		void BIN_Input_WriteSolution();

		void OCT_Operation(char operation);
		void OCT_Input_WriteSolution();

		void HEX_Operation(char operation);
		void HEX_Input_WriteSolution();



		//FROM INPUTTED NUMBER SYSTEM TO BINARY (FOR OPERATION PREPARATION)
		void Operation_DEC_TO_BIN();
		void Operation_DEC_TO_OCT();
		void Operation_DEC_TO_HEX();


		void Operation_OCT_TO_BIN(string& octalTranslatedToBinary1, string& octalTranslatedToBinary2);
		void Operation_HEX_TO_BIN(string& hexTranslatedToBinary1, string& hexTranslatedToBinary2);


		//FROM BINARY TO TARGET NUMBER SYSTEM (FINAL DISPLAY OF OPERATED INPUTS)
		void Operation_BIN_TO_DEC(string binaryString);
		void Operation_BIN_TO_OCT();



		//BINARY OPERATIONS (RETURNS DECIMAL)
		int operateBinary_ReturnDecimal(string input1, string input2, char operation);
};
//PROBLEMS
// 
// CHECKMINUEND IS NOT WORKING IN OCTAL
// 
//ANOTHER DEEP PROBLEM:
//calculateVectorValueAndGetSolution
//IT MIGHT BE WRONG 
//IF THERE IS DECIMAL IT RETURNS O BUT CONDITION IS if (decimalPlace != -1) SO IT WILL BE CONSIDERED TO BE DECIMAL

//MULTIPLICATION OCTAL:
//CANT HANDLE BIG NUMBERS HEHE

//SUBTRACTION PROBLEM (BINARY)
//101.1010 - 101.1 (SWAPPED)