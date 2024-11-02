#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class AES
{
	protected:
		//PREDEFINED
		Matrix_2S plainText, key, S_BOX, mixColumnMatrix;

		//RESULTS
		Matrix_2S addroundKey,
				  subByte_ShiftRow,  //SUBBYTE AND SHIFTROW 
				  mixColumn;

	public:
		//CONSTRUCTOR 
		//ASSIGN EVERY PREQUISITE MATRIX TO LOCAL MATRIX 
		AES(Matrix_2S plainText, Matrix_2S key, Matrix_2S S_BOX, Matrix_2S mixColumnMatrix)
			: addroundKey(4, 4), subByte_ShiftRow(4, 4), mixColumnMatrix(4, 4), mixColumn(4, 4)
		{
			this->plainText.directlyAssignMatrix(plainText);
			this->key.directlyAssignMatrix(key);
			this->S_BOX.directlyAssignMatrix(S_BOX);
			this->mixColumnMatrix.directlyAssignMatrix(mixColumnMatrix);
		}

		void MAIN_LOOP()
		{
			int a;
			writeWarning(); newLineMaker(0);
			cout << "******************ADVANCE ENCRYPTION SYSTEM******************" << endl;
			//displayAllMatrixData(a);

			ADDROUNDKEY();
			SUBBYTES();
			SHIFTROWS();
			MIXCOLUMN();
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
						eraseWhiteSpace(binary1_str);
						bitset<8> binary1(binary1_str);
					

						eraseWhiteSpace(binary2_str);
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
					/// <SEPARATE THE 2 CHAR>
					bin1 = addroundKey.getMatrixElements(i, j)[0];
					bin2 = addroundKey.getMatrixElements(i, j)[1];
					
					/// <GET THE THE SBOX USING THE SEPARATED CHAR AS INDEX>
					answer = S_BOX.getMatrixElements(turnStringToIndex_SUBBYTES(bin1), turnStringToIndex_SUBBYTES(bin2));

					
					/// <ASSIGN THE SBOX VALUE TO SBOX MATRIX>
					subByte_ShiftRow.setMatrixElements(i, j, answer);
				}
			}
			subByte_ShiftRow.displayMatrix();
			cout << "******************************************************" << endl;
		}
		void SHIFTROWS()
		{
			cout << "\n\n\SHIFTROWS: " << endl;
			cout << "******************************************************" << endl;

			/// <LEFTSHIFT EVERY COLUMN>
				for (int i = 0, j = 0; i < subByte_ShiftRow.columns; i++)
				{
					leftShift(subByte_ShiftRow.matrix[i], j);
					j++;
				}
			/// <LEFTSHIFT EVERY COLUMN>

			subByte_ShiftRow.displayMatrix();
			cout << "******************************************************" << endl;
		}
		void MIXCOLUMN()
		{
			vector<string> SHIFTROWS_Val, productBinary_vec, mixColumRow;
			string binary1, binary2, productBinary_str;

			cout << "\n\n\MIXCOLUMN: " << endl;
			cout << "******************************************************";

			for (int a = 0; a < 4; a++)
			{
				cout << "\nCOLUMN " << a + 1 << " : " << endl;
				cout << "******************************************************" << endl;

				///CLEAR AND GET SHIFTROW ENTIRE COLUMN
					SHIFTROWS_Val.clear();
					subByte_ShiftRow.getMatrixColumns(SHIFTROWS_Val, (a));
				///CLEAR AND GET SHIFTROW ENTIRE COLUMN

				///MIXCOLUMN MATRIX LOOP
					for (int i = 0; i < mixColumnMatrix.columns; i++)
					{
						for (int j = 0; j < mixColumnMatrix.rows; j++)
						{
							///TURN HEXA STRING TO BINARY STRING
								binary1 = translateToBinary(j, SHIFTROWS_Val);
								binary2 = translateToBinary(i, j, mixColumnMatrix);
							///TURN HEXA STRING TO BINARY STRING

							///MULTIPLY THE 4 BINARY AND ASSIGN IT TO A VECTOR 
								productBinary_str = multiplyBinaryString_MAIN(binary1, binary2);
								productBinary_vec.push_back(productBinary_str);
							///MULTIPLY THE 4 BINARY AND ASSIGN IT TO A VECTOR

							//WRITE THE FIRST 4 OUTPUT (BIN1 X BIN2 = BINRESULT)
							cout << SHIFTROWS_Val[j] << " X " << mixColumnMatrix.getMatrixElements(i, j) << " = " << binary1 << " X " << binary2 << " = " << productBinary_str << endl;

							if ((j + 1) % 4 == 0 && j != 0)
							{
								///BITWISE THE 4 PRODUCTS AND DISPLAY THE RESULT BOTH BINARY AND HEX; AND ASSIGN THE HEXVALUE TO VECTOR
									mixColumRow.push_back(doBitWise_MAIN(productBinary_vec));
									productBinary_vec.clear();
								///BITWISE THE 4 PRODUCTS AND DISPLAY THE RESULT BOTH BINARY AND HEX; AND ASSIGN THE HEXVALUE TO VECTOR

								// END OF COLUMN
								if (i < 3 || j < 3)
								{
									newLineMaker(0);
								}
							}
						}
					}
				///MIXCOLUMN MATRIX LOOP

				cout << "******************************************************" << endl;
				
				///WITH THE VECTOR OF PRODUCTS ASSING IT BY COLUMN AND CLEAR IT FOR NEXT INDEX USE
					mixColumn.setMatrixColumns(mixColumRow, a);
					mixColumRow.clear();
				///WITH THE VECTOR OF PRODUCTS ASSING IT BY COLUMN AND CLEAR IT FOR NEXT INDEX USE
			}
			//DISPLAY MIX COLUMN
			cout << "\nMIXCOLUMN MATRIX :" << endl;
			mixColumn.displayMatrix();
			cout << "******************************************************" << endl;
		}

		//ADDROUNDKEY FUNCTION
			void eraseWhiteSpace(string& str)
			{
				str.erase(remove(str.begin(), str.end(), ' '), str.end());
			}
			//RETURN STRING HEX TO BINARY STRING WITH SPACE
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
			string translateToBinary(int index, vector<string> arr_1D)
			{
				//INDEX CHECKER
				if (index > arr_1D.size())
				{
					cout << "NA LAPAW KA SA INDEX BOSS" << endl;
				}

				string bin1, bin2;

				//ERROR CATCHER
				if (arr_1D[index].size() > 2)
				{
					cout << "IN PLAINTEXT arr_1d ONLY INPUT 2 CHAR OR NUM" << endl;
				}
				//SEPARATING THE CHARACTERS
				else
				{
					bin1 = turnCharToBinary_GR4(arr_1D[index][0]);
					bin2 = turnCharToBinary_GR4(arr_1D[index][1]);
				}

				return bin1 + " " + bin2;
			}
		//ADDROUNDKEY FUNCTION

		//SHIFTROW FUNCTION
			void leftShift(vector<string>& vec, int shift)
		{
			vector<string> tempVec;

			for (int i = 0; i < vec.size(); i++)
			{
				tempVec.push_back(vec[ (i + shift) % vec.size() ]);
			}

			vec = tempVec;
		}
		//SHIFTROW FUNCTION
		
		//MIXCOLUMN FUNCTION
			//MAIN
			string multiplyBinaryString_MAIN(string binary1, string binary2)
			{		
				uint8_t num1, num2, product;
				string product_str, first4, last4;

				eraseWhiteSpace(binary1);
				eraseWhiteSpace(binary2);

				num1 = binaryStringToUint8(binary1);
				num2 = binaryStringToUint8(binary2);

				product = galoisFieldMultiply(num1, num2);

				product_str = uint8ToBinaryString(product);

				first4 = product_str.substr(0, 4); //FIRST 4
				last4 = product_str.substr(4);    //SECOND 4

				return first4 + " " + last4;
			}

			uint8_t binaryStringToUint8(string binaryStr) 
			{
				return static_cast<uint8_t>(bitset<8>(binaryStr).to_ulong());
			}
			string uint8ToBinaryString(uint8_t value) 
			{
				return bitset<8>(value).to_string();
			}
			uint8_t galoisFieldMultiply(uint8_t a, uint8_t b) 
			{
				uint8_t result = 0;
				const uint8_t modulus = 0x1b;

				while (b > 0) 
				{
					if (b & 1) 
					{
						result ^= a;
					}

					bool overflow = a & 0x80;
					a <<= 1;
					if (overflow) 
					{
						a ^= modulus;
					}

					b >>= 1;
				}

				return result;
			}
			int bitwiseMultiply(int a, int b) 
			{
				int result = 0;
				while (b > 0) 
				{
					if (b & 1) 
					{
						result += a;
					}
					a <<= 1;
					b >>= 1;
				}
				return result;
			}

			//MAIN
			string doBitWise_MAIN(vector<string> vec)
			{
				bitset<8> result;
				string result_str, result1, result2, hexVal;

				///XOR THE FIRST 2 VALUES (FOR PREP IN LOOP)
					eraseWhiteSpace(vec[0]); 
					bitset<8> bin1(vec[0]);

					eraseWhiteSpace(vec[1]);
					bitset<8> bin2(vec[1]);

					result = bitwise(bin1, bin2);
				///XOR THE FIRST 2 VALUES (FOR PREP IN LOOP)

				///XOR THE REMAINING VALUES
					for (int i = 2; i < vec.size(); i++)
					{
						eraseWhiteSpace(vec[i]);
						bitset<8> tempBin2(vec[i]);

						result = bitwise(result, tempBin2);
					}
				///XOR THE REMAINING VALUES

				///GET AND WRITE THE OUTPUT (BINARY(SEPARATED) AND HEX)
					//BINARY PART
					result_str = result.to_string();

					result1 = result_str.substr(0, 4); //FIRST 4
					result2 = result_str.substr(4);    //SECOND 4

					cout << "                            XOR = " << result1 + " " + result2 << " = ";

					//HEX PART
					hexVal += turnBinary_G4ToHex(result1);
					hexVal += turnBinary_G4ToHex(result2);

					cout << hexVal << endl;
				///GET AND WRITE THE OUTPUT

				return hexVal;
			}
			bitset<8> bitwise(bitset<8> bin1, bitset<8> bin2)
			{
				bitset<8> temp;
				temp = bin1 ^ bin2;
				return temp;
			}
		//MIXCOLUMN FUNCTION

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

				cout << "S-BOX : " << endl;
				S_BOX.displayMatrix();

				newLineMaker(0);

				cout << "Predefined Matrix : " << endl;
				mixColumnMatrix.displayMatrix();

				newLineMaker(0);
			}
		}
		void writeWarning()
		{
			cout << "YOU CAN'T INPUT SHIT HERE ADJUST THE CODE MANUALLY AND READ THE INSTRUCTIONS WITH IT (COMMENTS)" << endl;
		}
};