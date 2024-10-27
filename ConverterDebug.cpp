#include "Converter.h"
#include "RecyclableMethods.h"

//FOR DEBUGGING
void Converter::DEBUG_displayDecimal()
{
    cout << "DecimalPlace: " << decimalPlace << endl;
}
void Converter::DEBUG_display_BIN_To_DEC_forSolution()
{
    for (int i = 0; i < BIN_To_DEC_forSolution.size(); i++)
    {
        cout << to_string(i) << ".) ForSolution: " << BIN_To_DEC_forSolution[i] << endl;
    }
}
void Converter::DEBUG_displayBinary_G1()
{
    for (int i = 0; i < Binary_G1.size(); i++)
    {
        cout << to_string(i) << ".) SeparatedVal: " << Binary_G1[i] << endl;
    }
}

void Converter::DEBUG_displayBinary_G3()
{
    for (int i = 0; i < Binary_G3.size(); i++)
    {
        cout << "Binary_G3: " << Binary_G3[i].GRP_Str << " Value: " << Binary_G3[i].GRP_Val << endl;
    }
}
void Converter::DEBUG_displayDecimalPlace_G3()
{
    cout << "DecimalPlace_G3: " << DEC_DecimalPlace_G3 << endl;
}

void Converter::DEBUG_displayBinary_G4()
{
    for (int i = 0; i < Binary_G4.size(); i++)
    {
        cout << to_string(i) << ".) Binary_G4: " << Binary_G4[i].GRP_Str << " Value: " << Binary_G4[i].GRP_Val << endl;
    }
}
void Converter::DEBUG_displayDecimalPlace_G4()
{
    cout << "DecimalPlace_G4: " << DEC_DecimalPlace_G4 << endl;
}

void Converter::DEBUG_display_OCT_To_DECIMAL_forSolution()
{
    for (int i = 0; i < OCT_To_DECIMAL_forSolution.size(); i++)
    {
        cout << to_string(i) << ".) OCT_To_DECIMAL_forSolution: " << OCT_To_DECIMAL_forSolution[i] << endl;
    }
}

void Converter::DEBUG_display_OCT_TO_HEX_Binary_G3()
{
    for (int i = 0; i < OCT_TO_HEX_G3.size(); i++)
    {
        cout << to_string(i) << ".) OCT_TO_HEX_Binary_G3: " << OCT_TO_HEX_G3[i].GRP_Str << endl;
    }
}
void Converter::DEBUG_display_OCT_TO_HEX_compiledString()
{
    cout << "CompiledString: " << compiledString << endl;
}

void Converter::DEBUG_display_wholeNumberAndFraction()
{
    cout << setprecision(50) << "Whole Number: " << wholeNumber << "\nFraction: " << fraction << endl;
}

void Converter::DEBUG_display_Whole_Dividend()
{
    cout << "\n";
    for (int i = 0; i < Whole_Dividend.size(); i++)
    {
        cout << to_string(i) << ".) Dividend: " << Whole_Dividend[i] << endl;
    }
}
void Converter::DEBUG_display_Whole_Quotients()
{
    cout << "\n";

    for (int i = 0; i < Whole_Quotients.size(); i++)
        cout << to_string(i) << ".) Quotients: " << Whole_Quotients[i] << endl;

}
void Converter::DEBUG_display_Whole_Remainder()
{
    cout << "\n";

    for (int i = 0; i < Whole_Remainder.size(); i++)
        cout << to_string(i) << ".) Remainder: " << Whole_Remainder[i] << endl;
}

void Converter::DEBUG_display_Fraction_Dividend()
{
    cout << "\n";

    for (int i = 0; i < Fraction_Dividend.size(); i++)
        cout << to_string(i) << ".) F_Dividend: " << Fraction_Dividend[i] << endl;
}
void Converter::DEBUG_display_Fraction_Quotients()
{
    cout << "\n";

    for (int i = 0; i < Fraction_Quotients.size(); i++)
        cout << to_string(i) << ".) F_Quotients: " << Fraction_Quotients[i] << endl;
}
void Converter::DEBUG_display_Fraction_Remainder()
{
    cout << "\n";

    for (int i = 0; i < Fraction_Remainder.size(); i++)
        cout << to_string(i) << ".) F_Remainder: " << Fraction_Remainder[i] << endl;
}