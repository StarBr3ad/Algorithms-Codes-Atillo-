#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class CaesarCipher
{
	public:
		void MAIN_LOOP()
		{
			string	input, result, 
				int shiftVal;
			cout << "*********CAESAR CIPHER*********" << endl;
			cout << "Input Text : "; cin >> input;
			cout << "Shift Value: "; cin >> shiftVal;

			encryptDecrypt(input, shiftVal, result);
		}

	protected:
		void encryptDecrypt(string& input, int shift, string& result)
		{
			for (int i = 0; i < input.size(); i++)
			{
				if (isupper(input[i]))
				{
					result += static_cast<int>(input[i]) + shift;
				}
			}
		}
};
