#include "Converter.h"
#include "RecyclableMethods.h"



void GRP_VALUE_2D::clear()
{
    GRP_Str.clear();
    GRP_Val = 0;
}

void Converter::MAIN_LOOP()
{
    int input = -1;
    int tryAgainFlag = -1;

    //INPUT: 
    //-1 = DEFAULT (NONE CHOOSEN)
    // 1 = BINARY INPUT
    // 2 = OCTAL INPUT
    // 3 = DECIMAL INPUT
    // 4 = HEXADECIMAL 

    //MAIN LOOP
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
                DEC_Input_Converter();
                break;

            case 4:
                HEX_Input_Converter();
                break;

            default:
                cout << "WTF YU BROKE MAIN MENU ITS IMPOSSIBLE" << endl;
                break;
        }
        //RESET ALL THE VARIABLE
        resetAllVariable();


        //RESET THE TRYAGAINFLAG TO AVOID DIRECTLY LOOPING THE ENTIRE WHILE LOOP
        tryAgainFlag = -1;
        EXIT_MENU_LOOP(tryAgainFlag, input);
    }

    WRITE_LAST_GOODBYE();
}

int Converter::FIRST_MAIN_MENU(int input)
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

void Converter::EXIT_MENU_LOOP(int& tryAgainFlag, int& input)
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

void Converter::WRITE_LAST_GOODBYE()
{
    cout << "NIGGER" << endl;
}







//REUSABLE METHODS
//SEPARATE THE VALUES (G1) //AND GET DECIMAL PLACE
void Converter::valueSeparator_DecimalTaker(int valueStringLength)
{
    for (int i = 0; i < valueStringLength; i++)
    {
        if (valueString[i] == '.')
        {
            decimalPlace = i;
        }
        else
        {
            Binary_G1.push_back(static_cast<int>(valueString[i] - '0'));
        }
    }
}
//SAME SHIT BUT U CAN ASSIGN THE STRING(BINARY_G1_STRING) TO BE TURN INTO VECTOR
void Converter::valueSeparator_DecimalTaker(string groupedBinary, vector<int>& Binary_G1_Temp, int& decimalPlaceReturn) 
{
    int groupedBinaryLength = groupedBinary.size();
    
    for (int i = 0; i < groupedBinaryLength; i++)
    {
        if (groupedBinary[i] == '.')
        {
            decimalPlaceReturn = i;
        }
        else
        {
            Binary_G1_Temp.push_back(static_cast<int>(groupedBinary[i] - '0'));
        }
    }
    //IF NO DECIMAL
    if (decimalPlaceReturn < 0)
    {
        decimalPlaceReturn = 0;
    }
}
//TURNS HEXAVALUE TO INT
void Converter::valueSeparator_DecimalTaker(int valueStringLength, bool ifHexa_Value)
{
    if (ifHexa_Value)
    {
        for (int i = 0; i < valueStringLength; i++)
        {
            if (valueString[i] == '.')
            {
                decimalPlace = i;
            }
            else
            {
                Binary_G1.push_back(HEX_to_DEC_Value(valueString[i]));
            }
        }
    }
}
//ifHexa_Value is useless its speedrun baby
void Converter::valueSeparator_DecimalTaker(string groupedBinary, vector<int>& Binary_G1_Temp, int& decimalPlaceReturn, bool ifHexa_Value)
{
    int groupedBinaryLength = groupedBinary.size();

    for (int i = 0; i < groupedBinaryLength; i++)
    {
        if (groupedBinary[i] == '.')
        {
            decimalPlaceReturn = i;
        }
        else
        {
            Binary_G1_Temp.push_back(HEX_to_DEC_Value(groupedBinary[i]));
        }
    }

    //IF NO DECIMAL
    if (decimalPlaceReturn < 0)
    {
        decimalPlaceReturn = 0;
    }
}


//DAPAT NA GROUP NA ANG BINARY_1 
//(ASLO AUTOMATICALLY GROUP INTEGER AND FRACTION PART SEPARATELY 
//(ALSO FOLLOWING THE DIRECTION OF THE STARTING GROUPING)(IK IM A GENIUS))
void Converter::valueGrouper(int numberToGroup, vector<GRP_VALUE_2D>& vectorAddress, int& vectorDecimalPlace)
{
    GRP_VALUE_2D GRP_VAL_TEMP;
    int startOfLoop = 0;

    //BINARY GROUPER (BIN_G1 TO J)
    //IF NO DECIMAL 
    //THEN START LOOPING FROM THE END OF THE LENGTH OF THE INPUT( STRING )
    //ELSE START BEFORE THE DECIMAL
    if (decimalPlace == -1)
    {
        startOfLoop = valueStringLength - 1;
    }
    else
    {
        startOfLoop = decimalPlace - 1;
    }

    //GROUP BINARY_1 TO BINARY_3 AND PUT TO VECTOR
    //START DEPENDING TO IF ELSE CODE ABOVE
    //START FROM END TO BEGGINING
    if (decimalPlace != 0)
    {
        //YAWA KABALO KO DLI MUGANA NANG ILALOM BISAG WALA PANI NA CODE PANIGURADO MAMEN COOGAD
        for (int i = startOfLoop, j = 0; i >= 0; i--, j++)
        {
            //PUSH_BACK THE RESULT(BINARY_3) TO THE VECTOR IF ITS COMPLETE
            //( VALUE = RIGHT => LEFT )
            //J = NUMBER OF CHAR OF THE BINARY
            if (j == numberToGroup)
            {
                j = 0;

                vectorAddress.push_back(GRP_VAL_TEMP);

                GRP_VAL_TEMP.clear();
            }

            //GROUP THE SINGLE BINARY TO BINARY_3 
            //(FLIPPED) INSERT BINARY_1 TO BEGGINING[0]
            GRP_VAL_TEMP.GRP_Val = 0;
            GRP_VAL_TEMP.GRP_Str.insert(0, to_string(Binary_G1[i]));

            //LAST PART OF THE LOOP
            //(BIG BRAIN MOVE) PUT THE DECIMAL BINARY_3 TO THE BEGGINING OF THE VECTOR 
            if (i == 0)
            {
                GRP_VAL_TEMP.GRP_Val = 0;
                fixBinaryLength(true, GRP_VAL_TEMP.GRP_Str, numberToGroup);
                vectorAddress.push_back(GRP_VAL_TEMP);

                //IF THERE IS A DECIMAL
                if (decimalPlace >= 0)
                {
                    //IDENTIFY WHERE TO PUT THE DECIMAL FOR FUTURE USE
                    vectorDecimalPlace = vectorAddress.size();

                    GRP_VAL_TEMP.clear();
                    //GROUP THE DECIMAL PART
                    for (int i = decimalPlace, j = 0; i < Binary_G1.size(); i++, j++)
                    {
                        //PUT BINARY_3 TO THE BEGGINING IF COMPLETE
                        if (j == numberToGroup)
                        {
                            j = 0;

                            vectorAddress.insert(vectorAddress.begin(), GRP_VAL_TEMP);

                            GRP_VAL_TEMP.clear();
                        }

                        //GROUP THE SINGLE BINARY TO BINARY_3 
                        GRP_VAL_TEMP.GRP_Val = 0;
                        GRP_VAL_TEMP.GRP_Str += to_string(Binary_G1[i]);

                        //PUSH BACK THE LAST ARRAY ITS DECIMAL NIGGAEKIM AND FIX ITS LENGTH OF BINARY_3
                        if (i >= Binary_G1.size() - 1)
                        {
                            fixBinaryLength(false, GRP_VAL_TEMP.GRP_Str, numberToGroup);

                            vectorAddress.insert(vectorAddress.begin(), GRP_VAL_TEMP);
                        }
                    }
                }
            }

        }
    }
    else//IF DECIMAL IS IN THE BEGGINING
    {
        //FOR DECIMAL POINT AT THE BEGGINING
        vectorDecimalPlace = vectorAddress.size();

        //( VALUE = LEFT => RIGHT )
        for (int i = 0, j = 0; i < Binary_G1.size(); i++, j++)
        {
            if (j == numberToGroup)
            {
                j = 0;

                vectorAddress.push_back(GRP_VAL_TEMP);

                GRP_VAL_TEMP.clear();
            }

            GRP_VAL_TEMP.GRP_Val = 0;
            GRP_VAL_TEMP.GRP_Str += to_string(Binary_G1[i]);

            if (i == Binary_G1.size() - 1)
            {
                GRP_VAL_TEMP.GRP_Val = 0;
                fixBinaryLength(false, GRP_VAL_TEMP.GRP_Str, numberToGroup);
                vectorAddress.push_back(GRP_VAL_TEMP);
            }
        }
    }
}
void Converter::valueGrouper(int numberToGroup, string groupedString, vector<GRP_VALUE_2D>& vectorAddress, int& vectorDecimalPlace)
{
    vector<int> bG1_Temp;
    GRP_VALUE_2D GRP_VAL_TEMP;
    int startOfLoop = 0, decimalPlace = -1;

    //MAKE CUSTOM BINARY_G1
    valueSeparator_DecimalTaker(groupedString, bG1_Temp, decimalPlace);

    //DEBUG
    /*for (int i = 0; i < bG1_Temp.size(); i++)
    {
        cout << "bG1_Temp: " << bG1_Temp[i] << endl;
    }*/
    
    //BINARY GROUPER (BIN_G1 TO J)
    //IF NO DECIMAL 
    //THEN START LOOPING FROM THE END OF THE LENGTH OF THE INPUT( STRING )
    //ELSE START BEFORE THE DECIMAL
    if (decimalPlace == -1)
    {
        startOfLoop = groupedString.size() - 1;
    }
    else
    {
        startOfLoop = decimalPlace - 1;
    }

    //GROUP BINARY_1 TO BINARY_3 AND PUT TO VECTOR
    //START DEPENDING TO IF ELSE CODE ABOVE
    //START FROM END TO BEGGINING
    if (decimalPlace != 0)
    {
        //YAWA KABALO KO DLI MUGANA NANG ILALOM BISAG WALA PANI NA CODE PANIGURADO MAMEN
        for (int i = startOfLoop, j = 0; i >= 0; i--, j++)
        {
            //PUSH_BACK THE RESULT(BINARY_3) TO THE VECTOR IF ITS COMPLETE
            //( VALUE = RIGHT => LEFT )
            //J = NUMBER OF CHAR OF THE BINARY
            if (j == numberToGroup)
            {
                j = 0;

                vectorAddress.push_back(GRP_VAL_TEMP);

                GRP_VAL_TEMP.clear();
            }

            //GROUP THE SINGLE BINARY TO BINARY_3 
            //(FLIPPED) INSERT BINARY_1 TO BEGGINING[0]
            GRP_VAL_TEMP.GRP_Val = 0;
            GRP_VAL_TEMP.GRP_Str.insert(0, to_string(bG1_Temp[i]));

            //LAST PART OF THE LOOP
            //(BIG BRAIN MOVE) PUT THE DECIMAL BINARY_3 TO THE BEGGINING OF THE VECTOR 
            if (i == 0) 
            {
                GRP_VAL_TEMP.GRP_Val = 0;
                fixBinaryLength(true, GRP_VAL_TEMP.GRP_Str, numberToGroup);
                vectorAddress.push_back(GRP_VAL_TEMP);

                //IF THERE IS A DECIMAL
                if (decimalPlace >= 0)
                {
                    //IDENTIFY WHERE TO PUT THE DECIMAL FOR FUTURE USE(DAGO-OC)
                    vectorDecimalPlace = vectorAddress.size();

                    GRP_VAL_TEMP.clear();
                    //GROUP THE DECIMAL PART
                    for (int i = decimalPlace, j = 0; i < bG1_Temp.size(); i++, j++)
                    {
                        //PUT BINARY_3 TO THE BEGGINING IF COMPLETE
                        if (j == numberToGroup)
                        {
                            j = 0;

                            vectorAddress.insert(vectorAddress.begin(), GRP_VAL_TEMP);

                            GRP_VAL_TEMP.clear();
                        }

                        //GROUP THE SINGLE BINARY TO BINARY_3 
                        GRP_VAL_TEMP.GRP_Val = 0;
                        GRP_VAL_TEMP.GRP_Str += to_string(bG1_Temp[i]);

                        //PUSH BACK THE LAST ARRAY ITS DECIMAL NIGGA AND FIX ITS LENGTH OF BINARY_3(MIKE)
                        if (i >= bG1_Temp.size() - 1)
                        {
                            fixBinaryLength(false, GRP_VAL_TEMP.GRP_Str, numberToGroup);

                            vectorAddress.insert(vectorAddress.begin(), GRP_VAL_TEMP);
                        }
                    }
                }
            }

        }
    }
    else//IF DECIMAL IS IN THE BEGGINING
    {
        //FOR DECIMAL POINT AT THE BEGGINING
        vectorDecimalPlace = vectorAddress.size();

        //( VALUE = LEFT => RIGHT )
        for (int i = 0, j = 0; i < bG1_Temp.size(); i++, j++)
        {
            if (j == numberToGroup)
            {
                j = 0;

                vectorAddress.push_back(GRP_VAL_TEMP);

                GRP_VAL_TEMP.clear();
            }

            GRP_VAL_TEMP.GRP_Val = 0;
            GRP_VAL_TEMP.GRP_Str += to_string(bG1_Temp[i]);

            if (i == bG1_Temp.size() - 1)
            {
                GRP_VAL_TEMP.GRP_Val = 0;
                fixBinaryLength(false, GRP_VAL_TEMP.GRP_Str, numberToGroup);
                vectorAddress.push_back(GRP_VAL_TEMP);
            }
        }
    }

}

//DAPAT NA GROUP NA ANG TARGET VECTOR
void Converter::calculateGroupedVectorValue_2D(vector<GRP_VALUE_2D>& vectorAddress, int multiplier)
{
    int value;
    int stringSize = vectorAddress[0].GRP_Str.length();

    //CALCULATE THE VALUE OF ALL THE BINARY_3 IN THE VECTOR
    for (int i = 0; i < vectorAddress.size(); i++)
    {
        value = 0;

        //CALCULATE THE VALUE OF BINARY_3
        //IF CURRENT STRING EQUAL TO '1' ADD THE VALUE
        for (int j = stringSize - 1, n = 0; j >= 0; j--, n++)
        {
            if (vectorAddress[i].GRP_Str[j] == '1')
            {
                value += pow(multiplier, n);
            }
        }
        vectorAddress[i].GRP_Val = value;
    }
}

//WORKS WITH 1 AND O ONLY (BINARY)
//GET THE DECIMAL AND ITS SOLUTION NEEDED FOR WRITING
void Converter::calculateVectorValueAndGetSolution(vector<double>& solutionVecAddrs, int multiplier, double& calculatedTotal)
{
    //IF THERE IS A DECIMAL
    if (decimalPlace != -1)
    {
        //FRACTION
        //START FROM FRACTION TO LAST (DECIMALPLACE)
        //PUSH BACK FROM THE VECTOR
        for (int i = decimalPlace, j = -1; i < Binary_G1.size(); i++, j--)
        {
            if (Binary_G1[i] == 1)
            {
                solutionVecAddrs.push_back(pow(multiplier, j));
            }
            else if (Binary_G1[i] == 0)
            {
                solutionVecAddrs.push_back(0);
            }
            else
            {
                cout << "yawa manka" << endl;
            }
        }

        //WHOLE NUMBER
        //START FROM FIRST WHOLE NUMBER ON THE RIGHT (DECIMAL PLACE - 1)
        //INSERT FROM THE START OF THE VECTOR
        for (int i = decimalPlace - 1, d = 0; i >= 0; i--, d++)
        {
            if (Binary_G1[i] == 1)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), pow(multiplier, d));
            }
            else if (Binary_G1[i] == 0)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), 0);
            }
            else
            {
                cout << "yawa manka" << endl;
            }
        }
    }
    //IF THERE IS NO DECIMAL
    else
    {
        //STARTS FROM THE END OF BINARY_G1 (NOT SAME CODE ABOVE)
        for (int i = Binary_G1.size() - 1, d = 0; i >= 0; i--, d++)
        {
            if (Binary_G1[i] == 1)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), pow(multiplier, d));
            }
            else if (Binary_G1[i] == 0)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), 0);
            }
            else
            {
                cout << "yawa manka" << endl;
            }
        }
    }

    //CALCULATE TOTAL VALUE
    for (int i = 0; i < solutionVecAddrs.size(); i++)
    {
        calculatedTotal += solutionVecAddrs[i];
    }
}
//U CAN ASSIGN UR OWN BINARYSTRING (NOT BIN_G1)
void Converter::calculateVectorValueAndGetSolution(string binaryString, vector<double>& solutionVecAddrs, int multiplier, double& calculatedTotal)
{
    vector<int> LOCAL_BIN_G1;
    int LOCAL_decimalPlace = -1;

    valueSeparator_DecimalTaker(binaryString, LOCAL_BIN_G1, LOCAL_decimalPlace);

    //IF THERE IS A DECIMAL
    if (LOCAL_decimalPlace != -1 && LOCAL_decimalPlace > 0)
    {
        //FRACTION
        //START FROM FRACTION TO LAST (DECIMALPLACE)
        //PUSH BACK FROM THE VECTOR
        for (int i = LOCAL_decimalPlace, j = -1; i < LOCAL_BIN_G1.size(); i++, j--)
        {
            if (LOCAL_BIN_G1[i] == 1)
            {
                solutionVecAddrs.push_back(pow(multiplier, j));
            }
            else if (LOCAL_BIN_G1[i] == 0)
            {
                solutionVecAddrs.push_back(0);
            }
            else
            {
                cout << "yawa manka" << endl;
            }
        }

        //WHOLE NUMBER
        //START FROM FIRST WHOLE NUMBER ON THE RIGHT (DECIMAL PLACE - 1)
        //INSERT FROM THE START OF THE VECTOR
        for (int i = LOCAL_decimalPlace - 1, d = 0; i >= 0; i--, d++)
        {
            if (LOCAL_BIN_G1[i] == 1)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), pow(multiplier, d));
            }
            else if (LOCAL_BIN_G1[i] == 0)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), 0);
            }
            else
            {
                cout << "yawa manka" << endl;
            }
        }
    }

    //IF THERE IS NO DECIMAL
    else
    {
        //STARTS FROM THE END OF BINARY_G1 (NOT SAME CODE ABOVE)
        for (int i = LOCAL_BIN_G1.size() - 1, d = 0; i >= 0; i--, d++)
        {
            if (LOCAL_BIN_G1[i] == 1)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), pow(multiplier, d));
            }
            else if (LOCAL_BIN_G1[i] == 0)
            {
                solutionVecAddrs.insert(solutionVecAddrs.begin(), 0);
            }
            else
            {
                cout << "yawa manka" << endl;
            }
        }
    }

    //CALCULATE TOTAL VALUE
    for (int i = 0; i < solutionVecAddrs.size(); i++)
    {
        calculatedTotal += solutionVecAddrs[i];
    }
    

}

void Converter::getValueMultiplier(vector<double>& vectorAddrs, int multiplier)
{
    if (decimalPlace != -1)
    {
        for (int i = decimalPlace, j = 0; i > 0; i--, j++)
        {
            vectorAddrs.insert(vectorAddrs.begin(), pow(multiplier, j));
        }

        for (int i = decimalPlace, j = -1; i < Binary_G1.size(); i++, j--)
        {
            vectorAddrs.push_back(pow(multiplier, j));
        }
    }
    else
    {
        for (int i = valueStringLength, j = 0; i > 0; i--, j++)
        {
            vectorAddrs.insert(vectorAddrs.begin(), pow(multiplier, j));
        }
    }
}





//INPUT CHECKER 
//-1 = DEFAULT INPUT
//0 = YOU PASSED!!
//1 = MORE THAN ONE DECIMAL
//2 = IF INPUTTED THE UNDESIRED INPUT 
//3 = IF THERE IS A DECIMAL AT THE END
//4 = IF THERE IS A WHITESPACE
int Converter::checkIfBinaryInput()
{
    bool decimalChecked = false, 
        loopFlag = false;

    if (valueString[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (valueString[i])
        {
            case '0':
            case '1':
                break;

            case '.':
                if (decimalChecked)
                {
                    return 1;
                }
                decimalChecked = true;
                break;

            case ' ':
                return 4;
                break;

            default:
                return 2;
                break;
        }
    }

    return 0;
}
int Converter::checkIfBinaryInput(string input)
{
    bool    decimalChecked = false,
            loopFlag = false;
    int     valueStringLength = input.length();

    if (input[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (input[i])
        {
        case '0':
        case '1':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }
            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}

int Converter::checkIfOctalInput()
{
    bool decimalChecked = false,
        loopFlag = false;

    if (valueString[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (valueString[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }
            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}
int Converter::checkIfOctalInput(string input)
{
    bool    decimalChecked = false,
            loopFlag = false;
    int     valueStringLength = input.length();

    if (input[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (input[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }
            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}

int Converter::checkIfDecimalInput()
{
    bool decimalChecked = false,
        loopFlag = false;

    if (valueString[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (valueString[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }
            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}
int Converter::checkIfDecimalInput(string input)
{
    bool    decimalChecked = false,
            loopFlag = false;
    int     valueStringLength = input.length();

    if (input[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (input[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }
            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}

int Converter::checkIfHexadecimalInput()
{
    bool decimalChecked = false,
        loopFlag = false;

    if (valueString[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (valueString[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':

        case 'a':
        case 'A':

        case 'b':
        case 'B':

        case 'c':
        case 'C':

        case 'd':
        case 'D':

        case 'e':
        case 'E':

        case 'f':
        case 'F':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }

            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}
int Converter::checkIfHexadecimalInput(string input)
{
    bool    decimalChecked = false,
            loopFlag = false;
    int     valueStringLength = input.length();

    if (input[valueStringLength - 1] == '.')
    {
        return 3;
    }

    for (int i = 0; i < valueStringLength; i++)
    {
        switch (input[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':

        case 'a':
        case 'A':

        case 'b':
        case 'B':

        case 'c':
        case 'C':

        case 'd':
        case 'D':

        case 'e':
        case 'E':

        case 'f':
        case 'F':
            break;

        case '.':
            if (decimalChecked)
            {
                return 1;
            }

            decimalChecked = true;
            break;

        case ' ':
            return 4;
            break;

        default:
            return 2;
            break;
        }
    }

    return 0;
}

void Converter::writeErrorForInput(int errorCode)
{
    switch (errorCode)
    {
    case 0:
        break;

    case 1:
        cout<< "ONE DECIMAL IS ENOUGH\n\n" << endl;
        emptyInput();
        break;

    case 2:
        cout << "READ THE INSTRUCTIONS FUCKER\n\n" << endl;
        emptyInput();
        break;

    case 3:
        cout << "NO DECIMAL AT THE END (MY GOFY AH CODE WILL CRY)\n\n" << endl;
        emptyInput();
        break;

    case 4:
        cout << "NO FUCKING SPACE PLSS\n\n" << endl;
        emptyInput();
        break;

    default:
        cout << "CONGRATULATION YOU BROKE THE 4TH DIMENSION \N AND YOUR BALLS WILL EXPLODE\n\n" << endl;
        emptyInput();
        break;
    }   
}
void Converter::emptyInput()
{
    valueString.clear();
}











//INPUTS
void Converter::BIN_Input_Converter()
{
    const int binary = 2;
    int check = -1;

    //INPUT LOOP
    while (check != 0)
    {
        //DLI PWEDE BULAGON
        cout << "(0, 1)\n"; cout << "Your Binary Input: "; cin >> valueString;
        valueStringLength = valueString.length();

        //CHECK THE INPUT AND WRITE THE ERROR
        check = checkIfBinaryInput();
        writeErrorForInput(check);
    }
    

    //SEPARATE THE VALUES (G1) //AND GET DECIMAL PLACE
    valueSeparator_DecimalTaker(valueStringLength);

    //GET (OCTAL)
    BIN_To_OCT();

    newLineMaker(2);

    //GET (DECIMAL)
    BIN_To_DEC(binary);

    newLineMaker(2);

    //GET (HEXADECIMAL)
    BIN_TO_HEX();
}
void Converter::OCT_Input_Converter()
{
    int check = -1;

    //INPUT LOOP
    while (check != 0)
    {
        //DLI PWEDE BULAGON
        cout << "(0 - 7)\n"; cout << "Your Octal Input: "; cin >> valueString;
        valueStringLength = valueString.length();

        //CHECK THE INPUT AND WRITE THE ERROR
        check = checkIfOctalInput();
        writeErrorForInput(check);
    }

    //SEPARATE THE VALUES (G1) //AND GET DECIMAL PLACE
    valueSeparator_DecimalTaker(valueStringLength);

    //GET (BINARY) USED: Binary_G3
    OCT_TO_BIN();

    newLineMaker(2);

    //GET (DECIMAL) USED: DEC_forSolution, OCT_To_DECIMAL_forSolution
    OCT_TO_DECIMAL();

    newLineMaker(2);

    //GET (HEXADECIMAL) USED: OCT_TO_HEX_Binary_G3, Binary_G4
    OCT_TO_HEX();
}
void Converter::DEC_Input_Converter()
{
    int check = -1;

    //INPUT LOOP
    while (check != 0)
    {
        cout << "(0 - 9)\n"; cout << "Your Decimal Input: "; cin >> valueString;
        valueStringLength = valueString.length();

        //CHECK THE INPUT AND WRITE THE ERROR
        check = checkIfDecimalInput();
        writeErrorForInput(check);
    }

    //SEPARATE THE VALUES (G1) //AND GET DECIMAL PLACE
    valueSeparator_DecimalTaker(valueStringLength);

    //GET (BINARY)
    DEC_TO_BIN();

    newLineMaker(3);

    //GET (OCTAL)
    DEC_TO_OCT();

    newLineMaker(3);

    //GET (HEXADECIMAL)
    DEC_TO_HEX();
}
void Converter::HEX_Input_Converter()
{
    int check = -1;

    //INPUT LOOP
    while (check != 0)
    {
        //DLI PWEDE BULAGON
        cout << "(0 - 9, A - F)\n"; cout << "Your Hexadecimal Input: "; cin >> valueString;
        //CHECT THE STRING VALUE BEFORE PASSING
        valueStringLength = valueString.length();

        //CHECK THE INPUT AND WRITE THE ERROR
        check = checkIfHexadecimalInput();
        writeErrorForInput(check);
    }
    

    

    //SEPARATE THE VALUES (G1) //AND GET DECIMAL PLACE
    valueSeparator_DecimalTaker(valueStringLength, true);

    //GET (BINARY)
    HEX_TO_BIN();

    newLineMaker(3);

    //GET (OCTAL)
    HEX_TO_OCT();

    newLineMaker(3);

    //GET (DECIMAL)
    HEX_TO_DEC();
}





//BINARY TRANSFORMATIONS
void Converter::BIN_To_DEC(int numberType)
{
    calculateVectorValueAndGetSolution(BIN_To_DEC_forSolution, 2, DEC_Value);

    DEC_SolutionAndAnswer(numberType);
}
void Converter::DEC_SolutionAndAnswer(int numberType)
{
    //FOR DEBUGGING
    //INSIDE SOLUTION VECTOR
    /*for (int i = 0; i < forSolution.size(); i++)
    {
        cout << "Solution: " << forSolution[i] << endl;
    }*/

    string solution1, solution2;

    //DEBUG
    //cout << "G1_SIZE: " << Binary_G1.size() << endl;

    cout << "\n\n**************************************************************" << endl;
    cout << "               BINARY TO DECIMAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\n";

    //PREPARE THE STRING FOR SOLUTION 1
    for (int i = BIN_To_DEC_forSolution.size() - 1, j = 1, d = 1; i >= 0; i--, j++)
    {
        if (decimalPlace == -1) //IF THERE IS NO DECIMAL
        {
            solution1 += to_string(2) + "^" + to_string(i) + " + ";
        }
        else
        {
            if (j <= decimalPlace)
            {
                solution1 += to_string(2) + "^" + to_string(i - (Binary_G1.size() - decimalPlace)) + " + ";
            }
            else //DECIMAL PART
            {
                solution1 += to_string(1) + "/" + formatFloat(pow(numberType, d)) + " + ";
                d++;
            }
        }

        //ERASE THE LAST "+"
        if (i == 0)
        {
            eraseLastCharInString(solution1, 2);
        }
    }

    //WRITE SOLUTION 1
    cout << "Solution: " << solution1 << endl;

    //PREPARE THE STRING FOR SOLUTION 2 AND WRITE IT (COUT BELOW)
    for (int i = 0; i < BIN_To_DEC_forSolution.size(); i++)
    {
        solution2 += formatFloat(BIN_To_DEC_forSolution[i]) + " + ";
    }
    eraseLastCharInString(solution2, 2);

    //WRITE SOLUTION 1 AND ANSWER
    cout << "Solution: " << solution2 << endl;
    cout << "Decimal: " << setprecision(50) << DEC_Value << endl;
    cout << "**************************************************************" << endl;
}


void Converter::BIN_To_OCT()
{
    valueGrouper(3, Binary_G3, DEC_DecimalPlace_G3);

    calculateGroupedVectorValue_2D(Binary_G3, 2);
    BIN_To_OCT_SolutionAndAnswer();
}
void Converter::BIN_To_OCT_SolutionAndAnswer()
{
    string calculatedVal;

    cout << "\n\n**************************************************************" << endl;
    cout << "               BINARY TO OCTAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nGrouped Binary(3) With Value:\n" << endl;
    cout << "Solution: " << endl;
    cout << "Whole Number:" << endl;

    //ARRANGE AND DISPLAY THE BINARY_3 AND ITS VALUE (FLIPPED VALUE)
    for (int i = Binary_G3.size() - 1, j = 1; i >= 0; i--, j++)
    {
        //IF THERE IS DECIMAL PUT "DECIMAL: "
        if (DEC_DecimalPlace_G3 != -1)
        {
            if (i == ((Binary_G3.size() - 1) - DEC_DecimalPlace_G3))
            {
                cout << "\nDecimal: " << endl;
            }
        }

        cout << "Group " + to_string(j) + ": " << Binary_G3[i].GRP_Str << " Value: " << Binary_G3[i].GRP_Val << endl;
    }

    //MAKE(ARRANGE IN DESCENDING ORDER) THE CALCULATEDVALUE TO BE DISPLAYED
    for (int i = 0; i < Binary_G3.size(); i++)
    {
        calculatedVal.insert(0, to_string(Binary_G3[i].GRP_Val));
    }

    //IT PUTS DECIMAL TO THE ANSWER
    //-1 MEANS NO DECIMAL
    if (DEC_DecimalPlace_G3 != -1)
    {
        calculatedVal.insert(DEC_DecimalPlace_G3, ".");
    }

    //DISPLAY THE ANSWER (OCTAL VALUE)
    cout << "\nOctal: " << calculatedVal << endl;
    cout << "**************************************************************" << endl;
}


void Converter::BIN_TO_HEX()
{
    //GROUP THE VALUE TO 4
    valueGrouper(4, Binary_G4, DEC_DecimalPlace_G4);

    //GET VALUE OF GROUPED VECTOR
    calculateGroupedVectorValue_2D(Binary_G4, 2);
    //WRITE THE SHIT OUT
    BIN_To_HEX_SolutionAndAnswer();
}
void Converter::BIN_To_HEX_SolutionAndAnswer()
{
    string calculatedAnswer;

    cout << "\n\n**************************************************************" << endl;
    cout << "               BINARY TO HEXADECIMAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nGrouped Binary(4) With Value:\n" << endl;
    cout << "Solution: " << endl;
    cout << "Whole Number:" << endl;

    //ARRANGE AND DISPLAY THE BINARY_4 AND ITS VALUE (FLIPPED VALUE)
    for (int i = Binary_G4.size() - 1, j = 1; i >= 0; i--, j++)
    {
        cout << "Group " + to_string(j) + ": " << Binary_G4[i].GRP_Str << " Value: " << Binary_G4[i].GRP_Val << endl;

        //IF THERE IS DECIMAL PUT "DECIMAL: "
        if (DEC_DecimalPlace_G4 != -1)
        {
            if (i == ((Binary_G4.size()) - DEC_DecimalPlace_G4))
            {
                cout << "\nDecimal: " << endl;
            }
        }

        turnDecimalToHexadecimalValue(Binary_G4[i].GRP_Val, calculatedAnswer);

    }

    //IT PUTS DECIMAL TO THE ANSWER
    //-1 MEANS NO DECIMAL
    if (DEC_DecimalPlace_G4 != -1)
    {
        calculatedAnswer.insert(DEC_DecimalPlace_G4, ".");
    }

    cout << "\nHexadecimal: " << calculatedAnswer << endl;
    cout << "**************************************************************" << endl;
}





//OCTAL TRANSFORMATIONS
void Converter::OCT_TO_BIN()
{
    GRP_VALUE_2D temp;

    octalToBinary(Binary_G1, Binary_G3);

    OCT_TO_BIN_SolutionAndAnswer();
}
void Converter::OCT_TO_BIN_SolutionAndAnswer()
{
    string answer;

    cout << "\n\n**************************************************************" << endl;
    cout << "               OCTAL TO BINARY W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nGrouped Binary(3) With Value(Your Input):\n" << endl;
    cout << "Solution:" << endl;
    cout << "Whole Number:" << endl;

    for (int i = 0; i < Binary_G3.size(); i++)
    {
        //IF THERE IS DECIMAL PUT "DECIMAL: "
        if (decimalPlace != -1 && i == decimalPlace)
        {
            cout << "\nDecimal: " << endl;
        }

        cout << "Group " + to_string(i + 1) + ": " << Binary_G3[i].GRP_Str << " Value: " << Binary_G3[i].GRP_Val << endl;
    }

    //PUT DECIMAL TO THE ANSWER
    for (int i = 0; i < Binary_G3.size(); i++)
    {
        if (decimalPlace != -1 && i == decimalPlace)
        {
            answer += ".";
        }
        answer += Binary_G3[i].GRP_Str;
    }

    cout << "\nBinary: " << answer << endl;
    cout << "**************************************************************" << endl;
}


void Converter::OCT_TO_DECIMAL()
{
    //GET MULTIPLE OF 8 (8^N)
    getValueMultiplier(BIN_To_DEC_forSolution, 8);

    //MULTIPLY THE VALUES AND SAVE FOR SOLUTION
    for (int i = 0; i < BIN_To_DEC_forSolution.size(); i++)
    {
        OCT_To_DECIMAL_forSolution.push_back(Binary_G1[i] * BIN_To_DEC_forSolution[i]);
    }

    OCT_TO_DECIMAL_SolutionAndAnswer(8);
}
void Converter::OCT_TO_DECIMAL_SolutionAndAnswer(int multiplier)
{
    string solution1;
    string solution2;
    string solution3;
    double totalValue = 0.0;

    cout << "\n\n**************************************************************" << endl;
    cout << "               OCTAL TO DECIMAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;

    //GET THE SQUARED NUMBER EG:(1/8)
    if (decimalPlace != -1)
    {
        for (int i = decimalPlace, j = 0; i > 0; i--, j++)
        {
            solution1.insert(0,to_string(static_cast<int>(pow(multiplier, j))) + ", ");
        }

        for (int i = decimalPlace, j = -1; i < Binary_G1.size(); i++, j--)
        {
            solution1 += (formatFloat(pow(multiplier, j)) + ", ");
        }
    }
    else
    {
        for (int i = valueStringLength, j = 0; i > 0; i--, j++)
        {
            solution1.insert(0, formatFloat(pow(multiplier, j)) + ", ");
        }
    }
    eraseLastCharInString(solution1, 2);
    cout << "Solution 1: " << solution1 << endl;

    //(64 * 3) (SQUARE NUMBER * BINARY_G1)
    for (int i = 0; i < BIN_To_DEC_forSolution.size(); i++)
    {
        solution2 += formatFloat(BIN_To_DEC_forSolution[i]) + "*" + formatFloat(Binary_G1[i]) + " + ";
    }
    eraseLastCharInString(solution2, 3);
    cout << "Solution 2: " << solution2 << endl;

    //DISPLAY ADDING SOLUTION
    for (int i = 0; i < OCT_To_DECIMAL_forSolution.size(); i++)
    {
        totalValue += static_cast<double>(OCT_To_DECIMAL_forSolution[i]);
        solution3 += formatFloat(OCT_To_DECIMAL_forSolution[i]) + " + ";
    }
    eraseLastCharInString(solution3, 3);
    cout << "Solution 3: "<< setprecision(50) << solution3 << endl;

    cout << "\nDecimal: " << totalValue << endl;
    cout << "**************************************************************" << endl;
}


void Converter::OCT_TO_HEX()
{
    //USED IN VALUEGROUPER AND FUCKING USELESS (ITS FOR FUTURE PROOFING)
    int compiledString_DecPlace;

    //TURN OCTAL VALUE TO BINARY (EG. 001)
    octalToBinary(Binary_G1, OCT_TO_HEX_G3);

    //GROUP BINARY_3 TO SINGLE STRING AND PUT DECIMAL
    for (int i = 0; i < OCT_TO_HEX_G3.size(); i++)
    {
        if (decimalPlace != -1 && i == decimalPlace)
        {
            compiledString += ".";
        }

        compiledString += OCT_TO_HEX_G3[i].GRP_Str;
    }

    //GROUPED THE COMPILED STRING INTO BINARY_G4 
    valueGrouper( 4, compiledString, Binary_G4, compiledString_DecPlace);

    //GET THE VALUE OF THE BINARY_G4
    calculateGroupedVectorValue_2D(Binary_G4, 2);

    //TURN THE VALUE
    OCT_TO_HEX_SolutionAndAnswer();
}
void Converter::OCT_TO_HEX_SolutionAndAnswer()
{
    string bin_G3_val, bin_G4_val, hexValueAnswer, hexValue;

    cout << "\n\n**************************************************************" << endl;
    cout << "               OCTAL TO HEXADECIMAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;


    //MAKE THE STRING FOR BINARY_G3 (SOLUTION) AND WRITE IT
    for (int i = 0; i < OCT_TO_HEX_G3.size(); i++)
    {
        bin_G3_val += OCT_TO_HEX_G3[i].GRP_Str + ", ";
    }
    eraseLastCharInString(bin_G3_val, 2);
    cout << "   Turn to binary value: " << bin_G3_val << endl;


    //WRITE THE COMPILEDSTRING
    cout << " Group the binary value: " << compiledString << endl;


    //MAKE THE STRING FOR BINARY_G4 (SOLUTION) AND WRITE IT
    for (int i = Binary_G4.size() - 1; i >= 0; i--)
    {
        bin_G4_val += Binary_G4[i].GRP_Str + ", ";
    }
    eraseLastCharInString(bin_G4_val, 2);
    cout << "  Group the binary in 4: " << bin_G4_val << endl;


    //RECORD 2 HEXVALUE (FOR THE SOLUTION AND ANSWER) AND WRITE THE SOLUTION
    for (int i = Binary_G4.size() - 1; i >= 0; i--)
    {
        turnDecimalToHexadecimalValue(Binary_G4[i].GRP_Val, hexValueAnswer);
        turnDecimalToHexadecimalValue(Binary_G4[i].GRP_Val, hexValue);
        hexValue += ", ";
    }
    eraseLastCharInString(hexValue, 2);
    cout << " Translate to HEX value: " << hexValue << endl;

    //IF THERE IS A DECIMAL PLACE PUT DECIMAL PLACE TO ITS RIGHT PLACE
    if (decimalPlace != -1)
    {
        hexValueAnswer.insert(decimalPlace, ".");
    }

    //WRITE THE ANSWER RECORDED ABOVE
    cout << "\n            Hexadecimal: " << hexValueAnswer << endl;
    cout << "**************************************************************" << endl;
}





//DECIMAL TRANSFORMATIONS (SHARE THE SAME VARIABLES)

//EXTRA VECTOR WITH EMPTY VALUES IN FRACTION PART
void Converter::GetRemainder(int multiplier, float wholeNumber, float fraction, 
    vector<float>& dividendAddrs, vector<float>& quotientsAddrs, vector<int>& remainderAddrs,
    vector<float>& F_dividendAddrs, vector<float>& F_quotientsAddrs, vector<int>& F_remainderAddrs)
{
    string temp;

    //LEFT SIDE DIVIDER
    dividendAddrs.push_back(wholeNumber);

    //RESULT OF DIVISION
    quotientsAddrs.push_back(dividendAddrs[dividendAddrs.size() - 1] / multiplier);

    //REMAINDER
    remainderAddrs.push_back(static_cast<int>(wholeNumber) % multiplier);

    //IF QUOTIENT (RESULT) IS > 0 SPAM
    while (static_cast<int>(quotientsAddrs[quotientsAddrs.size() - 1]) > 0)
    {
        //LEFT SIDE DIVIDER
        dividendAddrs.push_back(static_cast<int>(quotientsAddrs[quotientsAddrs.size() - 1]));

        //RESULT OF DIVISION
        quotientsAddrs.push_back(dividendAddrs[dividendAddrs.size() - 1] / multiplier);

        //REMAINDER
        remainderAddrs.push_back(static_cast<int>(dividendAddrs[dividendAddrs.size() - 1]) % multiplier);
    }

    //FOR DECIMAL PART
    if (fraction > 0.0)
    {
        //LEFT SIDE DIVIDER
        F_dividendAddrs.push_back(fraction);

        //RESULT OF DIVISION
        F_quotientsAddrs.push_back(F_dividendAddrs[F_dividendAddrs.size() - 1] * multiplier);

        //REMAINDER
        F_remainderAddrs.push_back(static_cast<int>(F_quotientsAddrs[F_quotientsAddrs.size() - 1]));

        //IF > 0 (ALSO INCLUDE THE FRACTION PART) THEN SPAM
        while (F_quotientsAddrs[F_quotientsAddrs.size() - 1] > 0)
        {
            //LEFT SIDE DIVIDER
            F_dividendAddrs.push_back(getDecimalPart(F_quotientsAddrs[F_quotientsAddrs.size() - 1]));

            //RESULT OF DIVISION
            F_quotientsAddrs.push_back(F_dividendAddrs[F_dividendAddrs.size() - 1] * multiplier);

            //REMAINDER
            F_remainderAddrs.push_back(static_cast<int>(F_quotientsAddrs[F_quotientsAddrs.size() - 1]));
        }
    }
}

//EMPTY THE VECTORS FOR OTHER USES (OTHER DECIMAL TRANSFORMATION)
void Converter::emptyVariable_GetRemainder()
{
    Whole_Dividend.clear();
    Whole_Quotients.clear();
    Whole_Remainder.clear();

    Fraction_Dividend.clear();
    Fraction_Quotients.clear();
    Fraction_Remainder.clear();
}

void Converter::DEC_TO_BIN()
{
    //SEPARATE THE DECIMAL AND FRACTION
    BIN_G1_SeparateValue_DecimalAndFraction(Binary_G1, decimalPlace, wholeNumber, fraction, precisionLimiter_For_FractionValue);

    //GET REMAINDER (MAIN ANSWER), GET DIVIDEND, QUOTIENTS, AND REMAINDER (FOR SOLUTION)
    GetRemainder(2, wholeNumber, fraction, 
        Whole_Dividend, Whole_Quotients, Whole_Remainder,
        Fraction_Dividend, Fraction_Quotients, Fraction_Remainder);

    //WRITE THE SOLUTION AND ANSWER
    DEC_TO_BIN_SolutionAndAnswer();

    //EMPTY THE 6 VARIABLES FOR OTHER TRANSFORMATION USES
    emptyVariable_GetRemainder();
}
void Converter::DEC_TO_BIN_SolutionAndAnswer()
{
    string integerBinary, fractionBinary;
    cout << "\n\n**************************************************************" << endl;
    cout << "               DECIMAL TO BINARY W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;


    cout << "***************************" << endl;
    cout << "Dividing the integer part and getting its remainder:" << endl;

    for (int i = 0; i < Whole_Dividend.size(); i++)
    {
        cout<< formatFloat(Whole_Dividend[i]) + "/2 = " << formatFloat(Whole_Quotients[i]) + " = " << to_string(Whole_Remainder[i]) << endl;
    }

    for (int i = Whole_Dividend.size() - 1; i >= 0; i--)
    {
        integerBinary += to_string(Whole_Remainder[i]);
    }

    cout << "\nInteger Binary: " << integerBinary << endl;
    cout << "***************************\n" << endl;

    

    if (decimalPlace != -1)
    {
        cout << "***************************" << endl;
        cout << "Dividing the fraction part and getting its remainder:" << endl;

        for (int i = 0; i < Fraction_Dividend.size() - 1; i++)
        {
            fractionBinary += to_string(Fraction_Remainder[i]);
            cout << formatFloat(Fraction_Dividend[i], precisionLimiter_For_FractionValue) + "x2 = " << formatFloat(Fraction_Quotients[i], precisionLimiter_For_FractionValue) + " = " << to_string(Fraction_Remainder[i]) << endl;
        }

        cout << "\nFraction Binary: " << fractionBinary << endl;
        cout << "***************************" << endl;

        cout << "\nAnswer (Binary):: " << integerBinary + "." + fractionBinary << endl;
        cout << "**************************************************************" << endl;
    }
    else
    {
        cout << "\nAnswer (Binary):: " << integerBinary << endl;
        cout << "**************************************************************" << endl;
    }
}


void Converter::DEC_TO_OCT()
{
    //SEPARATE THE DECIMAL AND FRACTION
    BIN_G1_SeparateValue_DecimalAndFraction(Binary_G1, decimalPlace, wholeNumber, fraction, precisionLimiter_For_FractionValue);

    //GET REMAINDER (MAIN ANSWER), GET DIVIDEND, QUOTIENTS, AND REMAINDER (FOR SOLUTION)
    GetRemainder(8, wholeNumber, fraction,
        Whole_Dividend, Whole_Quotients, Whole_Remainder,
        Fraction_Dividend, Fraction_Quotients, Fraction_Remainder);

    //MATH GOD KO
    DEC_TO_OCT_SolutionAndAnswer();

    //EMPTY THE 6 VARIABLES FOR OTHER TRANSFORMATION USES
    emptyVariable_GetRemainder();
}
void Converter::DEC_TO_OCT_SolutionAndAnswer()
{
    string integerBinary, fractionBinary;
    cout << "\n\n**************************************************************" << endl;
    cout << "               DECIMAL TO OCTAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;


    cout << "***************************" << endl;
    cout << "Dividing the integer part and getting its remainder:" << endl;

    for (int i = 0; i < Whole_Dividend.size(); i++)
    {
        cout << formatFloat(Whole_Dividend[i]) + "/8 = " << formatFloat(Whole_Quotients[i]) + " = " << to_string(Whole_Remainder[i]) << endl;
    }

    for (int i = Whole_Dividend.size() - 1; i >= 0; i--)
    {
        integerBinary += to_string(Whole_Remainder[i]);
    }

    cout << "\nInteger Octal: " << integerBinary << endl;
    cout << "***************************\n" << endl;

    if (decimalPlace != -1)
    {
        cout << "***************************" << endl;
        cout << "Dividing the fraction part and getting its remainder:" << endl;
        for (int i = 0; i < Fraction_Dividend.size() - 1; i++)
        {
            fractionBinary += to_string(Fraction_Remainder[i]);
            cout << formatFloat(Fraction_Dividend[i], precisionLimiter_For_FractionValue) + "x8 = " << formatFloat(Fraction_Quotients[i], precisionLimiter_For_FractionValue) + " = " << to_string(Fraction_Remainder[i]) << endl;
        }

        cout << "\nFraction Octal: " << fractionBinary << endl;
        cout << "***************************" << endl;

        cout << "\nAnswer (Octal):: " << integerBinary + "." + fractionBinary << endl;
        cout << "**************************************************************" << endl;
    }
    else
    {
        cout << "\nAnswer (Octal):: " << integerBinary << endl;
        cout << "**************************************************************" << endl;
    }
}


void Converter::DEC_TO_HEX()
{
    //SEPARATE THE DECIMAL AND FRACTION
    BIN_G1_SeparateValue_DecimalAndFraction(Binary_G1, decimalPlace, wholeNumber, fraction, precisionLimiter_For_FractionValue);

    //GET REMAINDER (MAIN ANSWER), GET DIVIDEND, QUOTIENTS, AND REMAINDER (FOR SOLUTION)
    GetRemainder(16, wholeNumber, fraction,
        Whole_Dividend, Whole_Quotients, Whole_Remainder,
        Fraction_Dividend, Fraction_Quotients, Fraction_Remainder);

    //MATH GOD KO
    DEC_TO_HEX_SolutionAndAnswer();

    //EMPTY THE 6 VARIABLES FOR OTHER TRANSFORMATION USES
    emptyVariable_GetRemainder();
}
void Converter::DEC_TO_HEX_SolutionAndAnswer()
{
    string temp1;
    vector<string> WholeRemainder_str, FractionRemainder_str;

    //MAKE THE DECIMAL VALUE TO LETTERS (HEXADECIMAL)
    for (int i = 0; i < Whole_Remainder.size(); i++)
    {
        turnDecimalToHexadecimalValue(Whole_Remainder[i], temp1);
        WholeRemainder_str.push_back(temp1);
        temp1.clear();
    }

    for (int i = 0; i < Fraction_Remainder.size(); i++)
    {
        turnDecimalToHexadecimalValue(Fraction_Remainder[i], temp1);
        FractionRemainder_str.push_back(temp1);
        temp1.clear();
    }

    string integerBinary, fractionBinary;
    cout << "\n\n**************************************************************" << endl;
    cout << "               DECIMAL TO HEXADECIMAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;


    cout << "***************************" << endl;
    cout << "Dividing the integer part and getting its remainder:" << endl;

    for (int i = 0; i < Whole_Dividend.size(); i++)
    {
        cout << formatFloat(Whole_Dividend[i]) + "/16 = " << formatFloat(Whole_Quotients[i]) + " = " << WholeRemainder_str[i] << endl;
    }

    for (int i = Whole_Dividend.size() - 1; i >= 0; i--)
    {
        integerBinary += WholeRemainder_str[i];
    }

    cout << "\nInteger Hexadecimal: " << integerBinary << endl;
    cout << "***************************\n" << endl;

    if (decimalPlace != -1)
    {
        cout << "***************************" << endl;
        cout << "Dividing the fraction part and getting its remainder:" << endl;
        for (int i = 0; i < Fraction_Dividend.size() - 1; i++)
        {
            fractionBinary += FractionRemainder_str[i];
            cout << formatFloat(Fraction_Dividend[i], precisionLimiter_For_FractionValue) + "x16 = " << formatFloat(Fraction_Quotients[i], precisionLimiter_For_FractionValue) + " = " << FractionRemainder_str[i] << endl;
        }

        cout << "\nFraction Hexadecimal: " << fractionBinary << endl;
        cout << "***************************" << endl;

        cout << "\nAnswer (Hexadecimal):: " << integerBinary + "." + fractionBinary << endl;
        cout << "**************************************************************" << endl;
    }
    else
    {
        cout << "\nAnswer (Hexadecimal):: " << integerBinary << endl;
        cout << "**************************************************************" << endl;
    }
}





//HEXADECIMAL TRANSFORMATIONS (SHARE THE SAME VARIABLES)

//EMPTY THE VECTORS FOR OTHER USES (OTHER HEXADECIMAL TRANSFORMATION)
void Converter::emptyVariable_Decimal()
{
    Binary_G4.clear();
    compiledString.clear();
}

void Converter::HEX_TO_BIN()
{
    //TURN HEXADECIMAL TO BINARY
    hexadecimalToBinary(Binary_G1, Binary_G4);

    HEX_TO_BIN_SolutionAndAnswer();

    //CLEAR THE BUFFER
    emptyVariable_Decimal();
}
void Converter::HEX_TO_BIN_SolutionAndAnswer()
{
    string solution1 = "", solution2 = "";
    cout << "\n\n**************************************************************" << endl;
    cout << "               HEXADECIMAL TO BINARY W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;

    for (int i = 0; i < Binary_G4.size(); i++)
    {
        solution1 += Binary_G4[i].GRP_Str + ", ";

        if (i == decimalPlace)
        {
            solution2 += ".";
        }
        solution2 += Binary_G4[i].GRP_Str;
    }

    eraseLastCharInString(solution1, 2);
    cout << "Turned To Binary: " << solution1 << endl;
    
    cout << "\nAnswer: " << solution2 << endl;

    cout << "**************************************************************" << endl;

}

void Converter::HEX_TO_OCT()
{
    //DECIMAL PLACE FOR GROUPED BINARY_3
    int compiledString_DecPlace;

    //TURN HEXADECIMAL TO BINARY
    hexadecimalToBinary(Binary_G1, Binary_G4);

    //GROUP BINARY_4 TO SINGLE STRING AND PUT DECIMAL
    for (int i = 0; i < Binary_G4.size(); i++)
    {
        if (decimalPlace != -1 && i == decimalPlace)
        {
            compiledString += ".";
        }

        compiledString += Binary_G4[i].GRP_Str;
    }

    //GROUPED THE COMPILED STRING INTO BINARY_G4 AND GET ITS DECIMALPLACE
    valueGrouper(3, compiledString, Binary_G3, compiledString_DecPlace);

    //GET THE VALUE OF THE RESULT ABOVE (BINARY_G3)
    calculateGroupedVectorValue_2D(Binary_G3, 2);

    //WRITE THE SOLUTION AND ANSWER
    HEX_TO_OCT_SolutionAndAnswer(compiledString_DecPlace);

    //CLEAR THE BUFFER
    emptyVariable_Decimal();
}
void Converter::HEX_TO_OCT_SolutionAndAnswer(int compiledString_DecPlace)
{
    string bin_G4_val, bin_G3_val, OCT_ANSWER;

    cout << "\n\n**************************************************************" << endl;
    cout << "               HEXADECIMAL TO OCTAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;


    //MAKE THE STRING FOR BINARY_G4 (SOLUTION) AND WRITE IT
    for (int i = 0; i < Binary_G4.size(); i++)
    {
        bin_G4_val += Binary_G4[i].GRP_Str + ", ";
    }
    eraseLastCharInString(bin_G4_val, 2);
    cout << "    Turn to binary value: " << bin_G4_val << endl;

    //WRITE THE COMPILEDSTRING
    cout << "  Group the binary value: " << compiledString << endl;

    // IF THERE IS A DECIMAL
    if (decimalPlace != -1)
    {
        //MAKE THE STRING FOR BINARY_G3 (SOLUTION) AND WRITE IT
        for (int i = Binary_G3.size() - 1; i >= 0; i--)
        {
            bin_G3_val += Binary_G3[i].GRP_Str + ", ";
        }

        //GET THE OCTAL VALUE
        for (int i = Binary_G3.size() - 1; i >= 0; i--)
        {
            OCT_ANSWER += to_string(Binary_G3[i].GRP_Val);

            if (i == Binary_G3.size() - compiledString_DecPlace)
            {
                OCT_ANSWER += ".";
            }
        }
    }
    else
    {
        /*cout << "EXEC" << endl;*/
        //MAKE THE STRING FOR BINARY_G3 (SOLUTION) AND WRITE IT
        for (int i = 0; i < Binary_G3.size(); i++)
        {
            bin_G3_val += Binary_G3[i].GRP_Str + ", ";
        }

        //GET THE OCTAL VALUE
        for(int i = Binary_G3.size() - 1; i >= 0; i--)
        {
            OCT_ANSWER += to_string(Binary_G3[i].GRP_Val);
        }
    }
    
    eraseLastCharInString(bin_G3_val, 2);
    cout << "   Group the binary in 3: " << bin_G3_val << endl;

    //WRITE THE ANSWER RECORDED ABOVE
    cout << "Translate to Octal Value: " << stod(OCT_ANSWER) << endl;

    cout << "\nAnswer: " << stod(OCT_ANSWER) << endl;
    cout << "**************************************************************" << endl;
}

void Converter::HEX_TO_DEC()
{
    //RECYCLE THE FUCKING VARIABLES
    //GET MULTIPLE OF 8 (8^N)
    getValueMultiplier(BIN_To_DEC_forSolution, 16);

    //MULTIPLY THE VALUES AND SAVE FOR SOLUTION
    for (int i = 0; i < BIN_To_DEC_forSolution.size(); i++)
    {
        OCT_To_DECIMAL_forSolution.push_back(Binary_G1[i] * BIN_To_DEC_forSolution[i]);
    }
    
    HEX_TO_DEC_SolutionAndAnswer(16);

    //CLEAR THE BUFFER
    emptyVariable_Decimal();
}
void Converter::HEX_TO_DEC_SolutionAndAnswer(int multiplier)
{
    string solution1;
    string solution2;
    string solution3;
    double totalValue = 0.0;

    cout << "\n\n**************************************************************" << endl;
    cout << "               HEXADECIMAL TO DECIMAL W/ SOLUTION" << endl;
    cout << "Input: " << valueString << endl;
    cout << "\nSolution: " << endl;

    //GET THE SQUARED NUMBER EG:(1/8)
    if (decimalPlace != -1)
    {
        for (int i = decimalPlace, j = 0; i > 0; i--, j++)
        {
            solution1.insert(0, to_string(static_cast<int>(pow(multiplier, j))) + ", ");
        }

        for (int i = decimalPlace, j = -1; i < Binary_G1.size(); i++, j--)
        {
            solution1 += (formatFloat(pow(multiplier, j)) + ", ");
        }
    }
    else
    {
        for (int i = valueStringLength, j = 0; i > 0; i--, j++)
        {
            solution1.insert(0, formatFloat(pow(multiplier, j)) + ", ");
        }
    }
    eraseLastCharInString(solution1, 2);
    cout << "Solution 1: " << solution1 << endl;

    //(64 * 3) (SQUARE NUMBER * BINARY_G1)
    for (int i = 0; i < BIN_To_DEC_forSolution.size(); i++)
    {
        solution2 += formatFloat(BIN_To_DEC_forSolution[i]) + "*" + formatFloat(Binary_G1[i]) + " + ";
    }
    eraseLastCharInString(solution2, 3);
    cout << "Solution 2: " << solution2 << endl;

    //DISPLAY ADDING SOLUTION
    for (int i = 0; i < OCT_To_DECIMAL_forSolution.size(); i++)
    {
        totalValue += static_cast<double>(OCT_To_DECIMAL_forSolution[i]);
        solution3 += formatFloat(OCT_To_DECIMAL_forSolution[i]) + " + ";
    }
    eraseLastCharInString(solution3, 3);
    cout << "Solution 3: " << setprecision(50) << solution3 << endl;

    cout << "\nDecimal: " << totalValue << endl;
    cout << "**************************************************************" << endl;
}





//RESET ALL VARIABLE
void Converter::resetAllVariable()
{
    valueString.clear();
    valueStringLength = 0;

    Binary_G1.clear();
    decimalPlace = -1;
    BIN_To_DEC_forSolution.clear();
    DEC_Value = 0;

    Binary_G3.clear();
    DEC_DecimalPlace_G3 = -1;

    Binary_G4.clear();
    DEC_DecimalPlace_G4 = -1;

    OCT_To_DECIMAL_forSolution.clear();

    OCT_TO_HEX_G3.clear();
    compiledString.clear();

    wholeNumber = 0;
    fraction = 0;

    emptyVariable_GetRemainder();
    emptyVariable_Decimal();
}