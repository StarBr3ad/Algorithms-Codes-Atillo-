#include "Libraries.h"

void MAIN_LOOP()
{
	int a, b;
	cout << "*********EUCLIDEAN ALGORITHM*********" << endl;
	cout << "Input First Number: "; cin >> a;
	cout << "Input Second Number: "; cin >> b;

	doAndWriteTheAnswerNigger(a, b);
}

void doAndWriteTheAnswerNigger(int a, int b)
{
	while (b != 0) {
		int temp = b;
		cout << a << " mod( " << b << " )" << endl;
		b = a % b;
		a = temp;
	}
	
	cout << "GCD: " << a << endl;
}