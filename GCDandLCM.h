#pragma once
#include "Euclidean.h"
#include "Sieve.h"

class GCDandLCMCalc : Euclidean, SieveOfErathosthenes
{
    public:
	    void MAIN_LOOP()
	    {
            int a, b, GCD, input = -1, tryAgainFlag = -1;

            while (tryAgainFlag == -1 || tryAgainFlag == 2)
            {
                cout << "*********GCD AND LCM CALCULATOR*********" << endl;
                cout << "Input First Number: "; cin >> a;
                cout << "Input Second Number: "; cin >> b;

                newLineMaker(0);

                cout << "***************************" << endl;
                //WRITE AND SOLVE GCD
                doAndWriteTheAnswerNigger(a, b, GCD);
                cout << "GCD = " << GCD << endl;

                newLineMaker(0);
                cout << "***************************" << endl;
                getLCMandDisplayGCD(a, b, GCD);

                //RESET BUFFER
                    a = 0; b = 0; GCD = 0;
                //RESET BUFFER
                tryAgainFlag = -1;
                SieveOfErathosthenes::EXIT_MENU_LOOP(tryAgainFlag, input);
            }
            
	    }

    protected:
        //GENUS FOMRULA BY GPT
        void getLCMandDisplayGCD(int a, int b, int GCD)
        {
            int answer = (a / GCD) * b;
            cout << "LCM Solution: " << endl;
            cout << "LCM = " << "(input1 / GCD) * input2" << endl;
            cout << "    = " << "(" << a << " / " << GCD << ")" << " * " << b << endl;
            cout << "LCM = " << answer << endl;

            newLineMaker(0);
            cout << "***************************" << endl;
            newLineMaker(0);
            cout << "Answer: " << endl;
            cout << "GCD: " << GCD << endl;
            cout << "LCM: " << answer << endl;
        }
};