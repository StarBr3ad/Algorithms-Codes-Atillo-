#pragma once
#include "Libraries.h"
#include "RecyclableMethods.h"

class Euclidean : SieveOfErathosthenes
{
    public:
        void MAIN_LOOP()
        {
            int a, b, input = -1, tryAgainFlag = -1;

            while (tryAgainFlag == -1 || tryAgainFlag == 2)
            {
                cout << "*********EUCLIDEAN ALGORITHM*********" << endl;
                cout << "Input First Number: "; cin >> a;
                cout << "Input Second Number: "; cin >> b;

                newLineMaker(0);
                doAndWriteTheAnswerNigger(a, b);

                //RESET BUFFER
                    a = 0; b = 0;
                //RESET BUFFER

                tryAgainFlag = -1;
		        EXIT_MENU_LOOP(tryAgainFlag, input);
            }
        }

    protected:
        void doAndWriteTheAnswerNigger(int a, int b)
        {
            cout << "Solution: " << endl;
            while (b != 0) 
            {
                int temp = b;
                cout << "= " << a << " mod(" << b << ")" << endl;
                b = a % b;
                a = temp;
            }
            cout << "= " << a << " mod(" << b << ")" << endl;

            newLineMaker(0); 
            cout << "Answer: " << endl;
            cout << "GCD: " << a << endl;
        }
        void doAndWriteTheAnswerNigger(int a, int b, int& c)
        {
            cout << "GCD Solution: " << endl;
            while (b != 0)
            {
                int temp = b;
                cout << "    = " << a << " mod(" << b << ")" << endl;
                b = a % b;
                a = temp;
            }
            cout << "    = " << a << " mod(" << b << ")" << endl;

            c = a;
        }
};
