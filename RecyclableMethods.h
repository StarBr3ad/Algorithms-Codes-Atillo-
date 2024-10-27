#pragma once
#include "Converter.h"

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



class databaseStyleTable
{
	public:
		void createTable(vector<string> header, vector<string> rows);
		void createTable(vector<string> header, vector<string> rows, vector<string> column);

		void drawTable();
		void drawTable(int rows);



	private:
		int				rows = 0,				//PA RIGHT
						columns = 0,			//PA ILALOM
						spacesInBetween = 0,
						cIDX_RowData = 0;

		vector<string>	rowHeaderData,
						columnHeaderData,
						rowData;

		void insertHeaderData_Row(vector<string> header);
		void insertRowData(vector<string> rowData);

		void insertHeaderData_Column(vector<string> column);

	void printDivider();
	void printHeader();
	void printRows();
};



