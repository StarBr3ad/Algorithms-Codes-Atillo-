#include "RecyclableMethods.h"



//(USED IN FORMATING THE SOLUTIONS) GOOFYAHH METHODS(FROM THE IMTERMNENT) 
//REMOVE TRAILING DECIMALS
string formatFloat(float valueString, int precision) 
{
    stringstream ss;
    ss << fixed << setprecision(precision) << valueString;  // Fixed-point notation
    string str = ss.str();

    // Remove trailing zeros
    str.erase(str.find_last_not_of('0') + 1, string::npos);

    // Remove trailing decimal point if no digits follow
    if (str.back() == '.') {
        str.pop_back();
    }

    return str;
}
void eraseLastCharInString(string& strInput, int eraseScalar)
{
    strInput.erase(strInput.length() - eraseScalar);
}
//ENDL IN DISGUISE
void newLineMaker(int newLineNumber)
{
    string temp;
    for (int i = 0; i < newLineNumber; i++)
    {
        temp += "\n";
    }

    cout << temp << endl;
}




//TRANSLATORS
//GENIUS WAY(SWITCH hehe) (USED BY BINARY TRANSLATOR)
string turnToBinary(int decimalvalue, int returnNumber)
{
    if (returnNumber == 3)
    {
        switch (decimalvalue)
        {
        case 0:
            return "000";
            break;
        case 1:
            return "001";
            break;
        case 2:
            return "010";
            break;
        case 3:
            return "011";
            break;
        case 4:
            return "100";
            break;
        case 5:
            return "101";
            break;
        case 6:
            return "110";
            break;
        case 7:
            return "111";
            break;
        case 8:
            return "1000";
            break;
        case 9:
            return "1001";
            break;
        default:
            break;
        }
    }
    if (returnNumber == 4)
    {
        switch (decimalvalue)
        {
        case 0:
            return "0000";
            break;
        case 1:
            return "0001";
            break;
        case 2:
            return "0010";
            break;
        case 3:
            return "0011";
            break;
        case 4:
            return "0100";
            break;
        case 5:
            return "0101";
            break;
        case 6:
            return "0110";
            break;
        case 7:
            return "0111";
            break;
        case 8:
            return "1000";
            break;
        case 9:
            return "1001";
            break;
        case 10:
            return "1010";
            break;
        case 11:
            return "1011";
            break;
        case 12:
            return "1100";
            break;
        case 13:
            return "1101";
            break;
        case 14:
            return "1110";
            break;
        case 15:
            return "1111";
            break;
        default:
            break;
        }
    }

}

//TO BINARY
void octalToBinary(vector<int> value_G1, vector<GRP_VALUE_2D>& Binary_G3)
{
    GRP_VALUE_2D temp;

    //TURN OCTAL T0 BINARY1
    for (int i = 0, j = 0; i < value_G1.size(); i++)
    {
        temp.GRP_Val = value_G1[i];
        temp.GRP_Str = turnToBinary(value_G1[i], 3);

        Binary_G3.push_back(temp);
    }
}
void hexadecimalToBinary(vector<int> vectorAddrs_G1, vector<GRP_VALUE_2D>& Binary_G4)
{
    GRP_VALUE_2D temp;

    //TURN HEXA T0 BINARY1
    for (int i = 0, j = 0; i < vectorAddrs_G1.size(); i++)
    {
        temp.GRP_Val = vectorAddrs_G1[i];
        temp.GRP_Str = turnToBinary(vectorAddrs_G1[i], 4);

        Binary_G4.push_back(temp);
    }
}

//TO DECIMAL (GENIUS WAY)
int HEX_to_DEC_Value(char& charAddrs)
{
    switch (charAddrs)
    {
    case 'a':
    case 'A':
        return 10;
        break;

    case 'b':
    case 'B':
        return 11;
        break;

    case 'c':
    case 'C':
        return 12;
        break;

    case 'd':
    case 'D':
        return 13;
        break;

    case 'e':
    case 'E':
        return 14;
        break;

    case 'f':
    case 'F':
        return 15;
        break;

    default:
        return static_cast<int>(charAddrs - '0');
        break;
    }
}

//TO HEXADECIMAL (GENIUS WAY)
void turnDecimalToHexadecimalValue(int decimalvalue, string& hexString)
{
    switch (decimalvalue)
    {
    case 10:
        hexString += "A";
        break;
    case 11:
        hexString += "B";
        break;
    case 12:
        hexString += "C";
        break;
    case 13:
        hexString += "D";
        break;
    case 14:
        hexString += "E";
        break;
    case 15:
        hexString += "F";
        break;
    default:
        hexString += to_string(decimalvalue);
        break;
    }
}




//BACKEND (IMPORTANT SHITS)
//USED IN VALUEGROUPER (BIN_G1 TO BIN_G(INPUT))
//YAWA NAA DIAY HAHAHA (ADD 0 TO THE LEFT OR RIGHT (TO FIX THE BINARY LENGTH))
void fixBinaryLength(bool ifLeft, string& binary, int targetLength)
{
    int lengthDifference = targetLength - binary.size();

    if (ifLeft)
    {
        const int valueToAdd = 0;

        for (int i = 0; i < lengthDifference; i++)
        {
            binary.insert(0, to_string(valueToAdd));
        }
    }
    else
    {
        string fixedBinary;
        for (int i = 0; i < lengthDifference; i++)
        {
            fixedBinary += to_string(0);
        }

        binary += fixedBinary;
    }
}

//DECIMAL TRANSFORMATIONS
//SEPARATE THE WHOLE NUMBER AND FRACTION
//CHANGES THE 2 VALUE PASSED (LAST 2)
//LAST CHANGES: RETURNS PRECISION SIZE (BECAUSE OF FLOATING POINT BUG)
void BIN_G1_SeparateValue_DecimalAndFraction(vector<int> bin_G1, int decimalPlace, float& WholeNumber, float& Fraction, int& precision)
{
    string wholeNumber, fraction = "0.";

    if (decimalPlace != -1)
    {
        for (int i = 0; i < decimalPlace; i++)
        {
            wholeNumber += to_string(bin_G1[i]);
        }

        for (int i = decimalPlace; i < bin_G1.size(); i++)
        {
            fraction += to_string(bin_G1[i]);
        }
        
    }
    else
    {
        for (int i = 0; i < bin_G1.size(); i++)
        {
            wholeNumber += to_string(bin_G1[i]);
        }
    }

    if (decimalPlace != 0)
    {
        WholeNumber = stoi(wholeNumber);
    }


    if (decimalPlace != -1)
    {
        precision = fraction.size() - 2;
        Fraction = stof(fraction);
    }
}
void BIN_G1_SeparateValue_DecimalAndFraction(vector<int> bin_G1, int decimalPlace, double& WholeNumber, double& Fraction, int& precision)
{
    string wholeNumber, fraction = "0.";

    if (decimalPlace != -1)
    {
        for (int i = 0; i < decimalPlace; i++)
        {
            wholeNumber += to_string(bin_G1[i]);
        }

        for (int i = decimalPlace; i < bin_G1.size(); i++)
        {
            fraction += to_string(bin_G1[i]);
        }

    }
    else
    {
        for (int i = 0; i < bin_G1.size(); i++)
        {
            wholeNumber += to_string(bin_G1[i]);
        }
    }

    if (decimalPlace != 0)
    {
        WholeNumber = stod(wholeNumber);
    }


    if (decimalPlace != -1)
    {
        precision = fraction.size() - 2;
        Fraction = stod(fraction);
    }
}
//GET THE DECIMAL PART NIGGA (DECIMAL TRANSFORMATION)
float getDecimalPart(float number) {
    return fabs(number) - static_cast<int>(fabs(number));
}





//NEW SHITS (OPERATION)
//NOT THE SAME AS ABOVE (THIS SHIT IS MORE SIMPLER) (NEED INPUT STRING)
//RETURN 2 STRING (WHOLENUMBER AND FRACTION)
void separateDecimalAndFraction(string input, int dplace, string& wholeNumber, string& fraction)
{

    if (dplace > 0)
    {
        //GETTING THE INTEGER PART
        for (int i = dplace - 1; i >= 0; i--)
        {
            wholeNumber.insert(0, 1, input[i]);
        }

        //GETTING THE FRACTION PART
        for (int i = dplace + 1; i < input.size(); i++)
        {
            fraction += input[i];
        }
    }
    //NO DECIMAL
    else
    {
        for (int i = 0; i < input.size(); i++)
        {
            wholeNumber += input[i];
        }
        fraction = "";
    }
   
}

//ENCRYPTION
//SWITCH CASE YAWA KAPOY NA
string turnCharToBinary_GR4(char& charAddrs)
{
    switch (charAddrs)
    {
        case '0':
            return "0000";
            break;
        case '1':
            return "0001";
            break;
        case '2':
            return "0010";
            break;
        case '3':
            return "0011";
            break;
        case '4':
            return "0100";
            break;
        case '5':
            return "0101";
            break;
        case '6':
            return "0110";
            break;
        case '7':
            return "0111";
            break;
        case '8':
            return "1000";
            break;
        case '9':
            return "1001";
            break;

        case 'a':
        case 'A':
            return "1010";
            break;

        case 'b':
        case 'B':
            return "1011";
            break;

        case 'c':
        case 'C':
            return "1100";
            break;

        case 'd':
        case 'D':
            return "1101";
            break;

        case 'e':
        case 'E':
            return "1110";
            break;

        case 'f':
        case 'F':
            return "1111";
            break;

        default:
            cout << "A-F OG 0-9 RA ANIMAL" << endl;
            break;
    }
}

//YAWAA AHAHAHAHAHAHAHAHAHAHAHAHAHAHA😭😭😭 SHIT SO DISGUSTING 😭
string turnBinary_G4ToHex(string& charAddrs)
{
    if (charAddrs == "0000")
    {
        charAddrs = "0";
    }
    else if (charAddrs == "0001")
    {
        charAddrs = "1";
    }
    else if (charAddrs == "0010")
    {
        charAddrs = "2";
    }
    else if (charAddrs == "0011")
    {
        charAddrs = "3";
    }
    else if (charAddrs == "0100")
    {
        charAddrs = "4";
    }
    else if (charAddrs == "0101")
    {
        charAddrs = "5";
    }
    else if (charAddrs == "0110")
    {
        charAddrs = "6";
    }
    else if (charAddrs == "0111")
    {
        charAddrs = "7";
    }
    else if (charAddrs == "1000")
    {
        charAddrs = "8";
    }
    else if (charAddrs == "1001")
    {
        charAddrs = "9";
    }

    else if (charAddrs == "1010")
    {
        charAddrs = "A";
    }
    else if (charAddrs == "1011")
    {
        charAddrs = "B";
    }
    else if (charAddrs == "1100")
    {
        charAddrs = "C";
    }
    else if (charAddrs == "1101")
    {
        charAddrs = "D";
    }
    else if (charAddrs == "1110")
    {
        charAddrs = "E";
    }
    else if (charAddrs == "1111")
    {
        charAddrs = "F";
    }
    else
    {
        cout << "HAHAHAHAHA SHIT CODE GO AHHHH (turnCharToBinary_GR4)" << endl;
    }
    return charAddrs;
}

int turnStringToIndex_SUBBYTES(char input)
{
    switch (input)
    {
    case 'A':
        return 10;
        break;

    case 'B':
        return 11;
        break;

    case 'C':
        return 12;
        break;

    case 'D':
        return 13;
        break;

    case 'E':
        return 14;
        break;

    case 'F':
        return 15;
        break;

    default:
        return static_cast<int>(input) - static_cast<int>('0');
        break;
    }
}






