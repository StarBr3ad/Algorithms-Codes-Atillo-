#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class ModArithmetic
{
	vector<int> numbers;
	vector<char> operations;
	int modular; 
	float arithmeticResult;
	string input;
	bool stopOperation = false;

	public:
		void MAIN_LOOP()
		{
			WriteWarning();
			cout << "*********ARITHMETIC CALCULATOR*********" << endl;
			cout << "Modulus: "; cin >> modular; cin.ignore(numeric_limits<streamsize>::max(), '\n'); //CLEARS THE INPUT BUFFER

			newLineMaker(0);
			WriteWarning2();
			cout << "Input: "; getline(cin, input);

			storeAllData();
			if (!stopOperation)
			{
				doTheArithmetic();
				doTheModulusAndDisplayAnswer();
			}
			else
			{
				cout << "KILL YOURSELF NEGAE" << endl;
			}
			//TEST_display();
		}

	protected:
		void storeAllData()
		{
			string tempNum; 
			bool operatorNotYetRepeated = 1, SpaceNotYetRepeated = 0, digitFound = 0;

			//cout << "input: " << input << " input.size(): " << input.size() << endl;
			for (int i = 0; i < input.size(); i++)
			{
				//cout << "\ni: " << i << " stopOperation: " << stopOperation << " operatorNotYetRepeated: " << operatorNotYetRepeated << " digitFound: " << digitFound << endl;
				if (isdigit(input[i]))
				{
					digitFound = true;

					//cout << "DIGIT FOUND " << endl;
					tempNum += input[i];

					operatorNotYetRepeated = false;
					SpaceNotYetRepeated = false;
					if (i == input.size() - 1)
					{
						pushNumber(tempNum);
					}
				}
				if (isOperator(input[i]))
				{
					//cout << "OPERATOR FOUND " << endl;
					if (!operatorNotYetRepeated)
					{
						pushNumber(tempNum);

						if (digitFound)
						{
							pushOperator(input[i]);
						}
						operatorNotYetRepeated = true;
						SpaceNotYetRepeated = false;
					}
					else
					{
						if (input[i] == '-')
						{
							//cout << "NEGATIVE NUMBER" << endl;
							tempNum += '-';
						}
						else
						{
							stopOperation = true;
							cout << "KILL YOURSELF NIGGAE" << endl;
							break;
						}
					}
				}
				if (isspace(input[i]))
				{
					//cout << "SPACE FOUND " << endl;
					if (!SpaceNotYetRepeated)
					{
						pushNumber(tempNum);

						SpaceNotYetRepeated = true;
					}
				}
			}
		}
		void doTheArithmetic()
		{
			float T_result;
			int timesOfOperation= (numbers.size() - 2);

			T_result = operationToBeDone(operations[0], numbers[0], numbers[1]);

			if (timesOfOperation > 0)
			{
				for (int i = 1, j = 2; i < timesOfOperation; i++, j++)
				{
					T_result = operationToBeDone(operations[i], T_result, numbers[j]);
				}
			}
			else if(numbers.size() == 1)
			{
				T_result = numbers[0];
			}

			arithmeticResult = T_result;
			//cout << "\nArithmeticResult: " << arithmeticResult << endl;
		}
		void doTheModulusAndDisplayAnswer()
		{
			int answer = static_cast<int>(arithmeticResult) % modular;

			newLineMaker(0);
			cout << "Solution: " << endl;
			cout << "= " << "(" << input << ") " << "mod " << modular << endl;
			cout << "= " << "(" << arithmeticResult << ") " << "mod " << modular << endl;
			cout << "= " << answer << " mod " << modular << endl;

			newLineMaker(0);
			cout << "Answer: " << endl;
			cout << "= " << answer << " mod " << modular << endl;
		}

		void pushNumber(string& tempNum)
		{
			if (!tempNum.empty())
			{
				//cout << "NUMBERS PUSH" << endl;
				numbers.push_back(stoi(tempNum));

				tempNum.clear();
			}
		}
		void pushOperator(char tempOperator)
		{
			//cout << "OPERATIONS PUSH" << endl;
			operations.push_back(tempOperator);
		}
		bool isOperator(char temp)
		{
			switch (temp)
			{
				case '+': return true; break;
				case '-': return true; break;
				case '*': return true; break;
				case '/': return true; break;
				case '^': return true; break;
				default: return false; break;
			}
		}
		float operationToBeDone(char operation, float num1, int num2)
		{
			switch (operation)
			{
				case '+': return num1 + num2;
				case '-': return num1 - num2;
				case '*': return num1 * num2;
				case '/': return num1 / num2;
				case '^': return pow(num1, num2);
				default: cout << "WTF BRO I DONT KNOW WHAT YOU DID, AND ALSO FUCK YOU << endl" << endl; break;
			}
		}

		void WriteWarning()
		{
			cout << "NO PRECEDENCE BTW IM TIRED" << endl;
		}
		void WriteWarning2()
		{
			cout << "OPERATORS AVAILABLE: (+, -, *, /, ^)" << endl;
		}

		void TEST_display()
		{
			//cout << "\n\nnumbers: " << endl;
			for (int i = 0; i < numbers.size(); i++)
				cout << "number " << i << ": " << numbers[i] << endl;

			//cout << "\n\noperations: " << endl;
			for (int i = 0; i < operations.size(); i++)
				cout << "operations " << i << ": " << operations[i] << endl;
		}
};
