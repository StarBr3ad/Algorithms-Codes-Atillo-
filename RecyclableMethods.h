#pragma once
#include "Converter.h"
#include "Matrix.h"
#include "DatabaseStyleTable.h"

string formatFloat(float valueString, int precision = 50);
void eraseLastCharInString(string& strInput, int eraseScalar);
void newLineMaker(int newLineNumber);

string turnToBinary(int decimalvalue, int returnNumber);
void octalToBinary(vector<int> value_G1, vector<GRP_VALUE_2D>& Binary_G3);
void hexadecimalToBinary(vector<int> vectorAddrs_G1, vector<GRP_VALUE_2D>& Binary_G4);
int HEX_to_DEC_Value(char& charAddrs);


void turnDecimalToHexadecimalValue(int decimalvalue, string& hexString);
void fixBinaryLength(bool ifLeft, string& binary, int targetLength);
void BIN_G1_SeparateValue_DecimalAndFraction(vector<int> bin_G1, int decimalPlace, float& WholeNumber, float& Fraction, int& precision);
void BIN_G1_SeparateValue_DecimalAndFraction(vector<int> bin_G1, int decimalPlace, double& WholeNumber, double& Fraction, int& precision);
float getDecimalPart(float number);



void separateDecimalAndFraction(string input, int dplace, string& wholeNumber, string& fraction);


//ENCRYPTION
//SWITCH CASE YAWA KAPOY NA
string turnCharToBinary_GR4(char& charAddrs);
string turnBinary_G4ToHex(string& charAddrs);
int turnStringToIndex_SUBBYTES(char input);
