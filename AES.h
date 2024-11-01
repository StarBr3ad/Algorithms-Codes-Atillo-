#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class AES
{
	protected:
		Matrix_2S plainText, key, S_BOX;
		Matrix_2S addroundKey, shiftRowsAndARK;

	public:
		//CONSTRUCTOR 
		//ASSIGN EVERY PREQUISITE MATRIX TO LOCAL MATRIX 
		AES(Matrix_2S plainText, Matrix_2S key, Matrix_2S S_BOX) : addroundKey(4, 4), shiftRowsAndARK(4, 4)
		{
			this->plainText.directlyAssignMatrix(plainText);
			this->key.directlyAssignMatrix(key);
			this->S_BOX.directlyAssignMatrix(S_BOX);
		}

		void MAIN_LOOP()
		{
			int a;
			writeWarning(); newLineMaker(0);
			cout << "******************ADVANCE ENCRYPTION SYSTEM******************" << endl;
			//displayAllMatrixData(a);

			ADDROUNDKEY();
			SUBBYTES();
		}

	protected:
		void ADDROUNDKEY()
		{
			string binary1_str, binary2_str;
			bitset<8> result;
			string resultInString;
			string result1, result2, hex;

		
			cout << "\n\n\nADDROUNDKEY SOLUTIONS: " << endl;
			cout << "******************************************************" << endl;

			for (int i = 0; i < plainText.columns; i++ )
			{
				cout << "COLUMN " <<  i + 1 <<  " : " << endl;
				cout << "************************************" << endl;
				for (int j = 0; j < plainText.rows; j++)
				{
					//GET THE TRANSLATED BINARY STRING
						binary1_str = translateToBinary(i, j, plainText);
						binary2_str = translateToBinary(i, j, key);
					//GET THE TRANSLATED BINARY STRING

					//DISPLAY IT
						cout << plainText.getMatrixElements(i, j)	<< "     = " << binary1_str << endl;
						cout << key.getMatrixElements(i, j)			<< "     = " << binary2_str << endl;
					//DISPLAY IT
					
					//REMOVE THE SPACES AND TURN TO BITSET
						binary1_str.erase(remove(binary1_str.begin(), binary1_str.end(), ' '), binary1_str.end());
						bitset<8> binary1(binary1_str);
					

						binary2_str.erase(remove(binary2_str.begin(), binary2_str.end(), ' '), binary2_str.end());
						bitset<8> binary2(binary2_str);
					//REMOVE THE SPACES AND TURN TO BITSET

					//DO THE XOR
						result = binary1 ^ binary2;
						resultInString = result.to_string();
					//DO THE XOR				

					//SEPARATE THE BINARY TO 2 AND WRITE RESULT (NO ENDL)
						result1 = resultInString.substr(0, 4); //FIRST 4
						result2 = resultInString.substr(4);    //SECOND 4
						cout << "Result = " << result1 + " " + result2;
					//SEPARATE THE BINARY TO 2  AND WRITE RESULT (NO ENDL)
					

					//TURN THE BINARY TO HEXA AGAIN AND DISPLAY IT BESIDE TO RESULT
						hex = turnBinary_G4ToHex(result1) + turnBinary_G4ToHex(result2);
						cout << " = " << hex << endl;
					//TURN THE BINARY TO HEXA AGAIN AND DISPLAY IT BESIDE TO RESULT

					if (j < plainText.rows - 1)
					{
						newLineMaker(0);
					}
						

					//ASSIGN THE HEX
						addroundKey.setMatrixElements(i, j, hex);
					//ASSIGN THE HEX
				}
				cout << "************************************\n" << endl;
			}
			cout << "ADDROUNDKEY MATRIX :" << endl;
			addroundKey.displayMatrix();
			cout << "******************************************************" << endl;
		}
		void SUBBYTES()
		{
			char bin1, bin2; string answer;

			cout << "\n\n\SUBBYTES: " << endl;
			cout << "******************************************************" << endl;

			for (int i = 0; i < addroundKey.columns; i++)
			{
				for (int j = 0; j < addroundKey.rows; j++)
				{
					bin1 = addroundKey.getMatrixElements(i, j)[0];
					bin2 = addroundKey.getMatrixElements(i, j)[1];

					answer = S_BOX.getMatrixElements(turnStringToIndex_SUBBYTES(bin1), turnStringToIndex_SUBBYTES(bin2));
					
					shiftRowsAndARK.setMatrixElements(i, j, answer);
				}
			}
			shiftRowsAndARK.displayMatrix();
			cout << "******************************************************" << endl;
		}
		void SHIFTROWS()
		{
			for ()
			{

			}
		}

		string translateToBinary(int column, int row, Matrix_2S matrix)
		{
			//ROW AND COLUMN CHECKER
			if (column > matrix.columns)
			{
				cout << "NA LAPAW KA SA COLUMN BOSS" << endl;
			}
			if (row > matrix.rows)
			{
				cout << "NA LAPAW KA SA ROW BOSS" << endl;
			}

			string bin1, bin2;

			//ERROR CATCHER
			if (matrix.getMatrixElements(column, row).size() > 2)
			{
				cout << "IN PLAINTEXT MATRIX ONLY INPUT 2 CHAR OR NUM" << endl;
			}
			//SEPARATING THE CHARACTERS
			else 
			{
				bin1 = turnCharToBinary_GR4(matrix.matrix[column][row][0]);
				bin2 = turnCharToBinary_GR4(matrix.matrix[column][row][1]);
			}

			return bin1 + " " + bin2;
		}
		void leftShift(vector<string>& vec, int shift)
		{
			vector<string> tempVec;

			for (int i = 0; i < vec.size(); i++)
			{
				tempVec.push_back(vec[ (i + shift) % vec.size() ]);
			}

			vec = tempVec;
		}

		void displayAllMatrixData(int& a)
		{
			while (a > 2 || a < 0 || cin.fail())
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				cout << "Display the matrices? (Note: Its gonna be long) " << endl;
				cout << "[ 1 ] Display " << endl;
				cout << "[ 2 ] Hide " << endl;
				cout << "Input: ";  cin >> a;
				newLineMaker(0);
			}
			
			//DISPLAY ALL THE MATRIX
			if (a == 1)
			{
				newLineMaker(0);
				cout << "Plain Text : " << endl;
				plainText.displayMatrix();

				newLineMaker(0);

				cout << "Key : " << endl;
				key.displayMatrix();
				newLineMaker(0);
			}
		}
		void writeWarning()
		{
			cout << "YOU CAN'T INPUT SHIT HERE ADJUST THE CODE MANUALLY AND READ THE INSTRUCTIONS WITH IT (COMMENTS)" << endl;
		}
};