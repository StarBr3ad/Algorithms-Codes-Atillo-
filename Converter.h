#pragma once
#include "Libraries.h"

struct GRP_VALUE_2D
{
    public:
        string GRP_Str;
        int GRP_Val;
        
        void clear();
};



class Converter
{
    public:
    //MAIN LOOP
    void MAIN_LOOP();



    public:
        string valueString;
        int valueStringLength;

        vector<int> Binary_G1;
        int decimalPlace = -1;
        vector<double> BIN_To_DEC_forSolution;
        double DEC_Value;

        vector<GRP_VALUE_2D> Binary_G3;
        int DEC_DecimalPlace_G3 = -1;

        vector<GRP_VALUE_2D> Binary_G4;
        int DEC_DecimalPlace_G4 = -1;

        vector<float> OCT_To_DECIMAL_forSolution;

        vector<GRP_VALUE_2D> OCT_TO_HEX_G3;
        string compiledString;

        //DECIMAL TRANSFORMATION 
        float wholeNumber;
        float fraction;
        int precisionLimiter_For_FractionValue;

        vector<float> Whole_Dividend;
        vector<float> Whole_Quotients;
        vector<int> Whole_Remainder;

        vector<float> Fraction_Dividend;
        vector<float> Fraction_Quotients;
        vector<int> Fraction_Remainder;

        void emptyVariable_GetRemainder();
        void emptyVariable_Decimal();
        void resetAllVariable();



        //MAIN LOOP UI
        int FIRST_MAIN_MENU(int input);
        void EXIT_MENU_LOOP(int& tryAgainFlag, int& input);
        void WRITE_LAST_GOODBYE();
        


        //RECYCLABLE METHODS
        void valueSeparator_DecimalTaker(int valueStringLength);
        void valueSeparator_DecimalTaker(string groupedBinary, vector<int>& Binary_G1_Temp, int& decimalPlaceReturn);
        void valueSeparator_DecimalTaker(int valueStringLength, bool ifHexa_Value);
        void valueSeparator_DecimalTaker(string groupedBinary, vector<int>& Binary_G1_Temp, int& decimalPlaceReturn, bool ifHexa_Value);


        void valueGrouper(int numberToGroup, vector<GRP_VALUE_2D>& vectorAddress, int& vectorDecimalPlace);
        void valueGrouper(int numberToGroup, string groupedString, vector<GRP_VALUE_2D>& vectorAddress, int& vectorDecimalPlace);


        void calculateGroupedVectorValue_2D(vector<GRP_VALUE_2D>& vectorAddress, int multiplier);
        void calculateVectorValueAndGetSolution(vector<double>& solutionVecAddrs, int multiplier, double& calculatedTotal);
        void calculateVectorValueAndGetSolution(string binaryString, vector<double>& solutionVecAddrs, int multiplier, double& calculatedTotal);


        void getValueMultiplier(vector<double>& vectorAddrs, int multiplier);

        //INPUT CHECKER
        int checkIfBinaryInput();
        int checkIfBinaryInput(string input);

        int checkIfOctalInput();
        int checkIfOctalInput(string input);

        int checkIfDecimalInput();
        int checkIfDecimalInput(string input);

        int checkIfHexadecimalInput();
        int checkIfHexadecimalInput(string input);

        void writeErrorForInput(int errorCode);
        void emptyInput();





        //INPUTS
        void BIN_Input_Converter();
        void OCT_Input_Converter();
        void DEC_Input_Converter();
        void HEX_Input_Converter();


        //BINARY TRANSFORMATIONS
        void BIN_To_DEC(int numberType);
        void DEC_SolutionAndAnswer(int numberType);

        void BIN_To_OCT();
        void BIN_To_OCT_SolutionAndAnswer();

        void BIN_TO_HEX();
        void BIN_To_HEX_SolutionAndAnswer();
    


        //OCTAL TRANSFORMATIONS
        void OCT_TO_BIN();
        void OCT_TO_BIN_SolutionAndAnswer();

        void OCT_TO_DECIMAL();
        void OCT_TO_DECIMAL_SolutionAndAnswer(int multiplier);

        void OCT_TO_HEX();
        void OCT_TO_HEX_SolutionAndAnswer();



        //DECIMAL TRANSFORMATIONS
        void GetRemainder(int multiplier, float wholeNumber, float fraction,
            vector<float>& dividendAddrs, vector<float>& quotientsAddrs, vector<int>& remainderAddrs,
            vector<float>& F_dividendAddrs, vector<float>& F_quotientsAddrs, vector<int>& F_remainderAddrs);

        void DEC_TO_BIN();
        void DEC_TO_BIN_SolutionAndAnswer();

        void DEC_TO_OCT();
        void DEC_TO_OCT_SolutionAndAnswer();

        void DEC_TO_HEX();
        void DEC_TO_HEX_SolutionAndAnswer();





        //HEXADECIMAL TRANSFORMATIONS
        void HEX_TO_BIN();
        void HEX_TO_BIN_SolutionAndAnswer();

        void HEX_TO_OCT();
        void HEX_TO_OCT_SolutionAndAnswer(int compiledString_DecPlace);

        void HEX_TO_DEC();
        void HEX_TO_DEC_SolutionAndAnswer(int multiplier);





        //DEBUG
        void DEBUG_displayDecimal();
        void DEBUG_display_BIN_To_DEC_forSolution();
        void DEBUG_displayBinary_G1();

        void DEBUG_displayBinary_G3();
        void DEBUG_displayDecimalPlace_G3();

        void DEBUG_displayBinary_G4();
        void DEBUG_displayDecimalPlace_G4();

        void DEBUG_display_OCT_To_DECIMAL_forSolution();

        void DEBUG_display_OCT_TO_HEX_Binary_G3();
        void DEBUG_display_OCT_TO_HEX_compiledString();

        void DEBUG_display_wholeNumberAndFraction();
        void DEBUG_display_Whole_Dividend();
        void DEBUG_display_Whole_Quotients();
        void DEBUG_display_Whole_Remainder();

        void DEBUG_display_Fraction_Dividend();
        void DEBUG_display_Fraction_Quotients();
        void DEBUG_display_Fraction_Remainder();
};

