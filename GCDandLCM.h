#pragma once
#include "Euclidean.h"

class GCDandLCMCalc : Euclidean
{
    public:
	    void MAIN_LOOP()
	    {
            int a, b, GCD;
            cout << "*********GCD AND LCM CALCULATOR*********" << endl;
            cout << "Input First Number: "; cin >> a;
            cout << "Input Second Number: "; cin >> b;

            newLineMaker(0);
        
            //WRITE AND SOLVE GCD
            doAndWriteTheAnswerNigger(a, b, GCD);
            cout << "GCD = " << GCD << endl;

            newLineMaker(0);
            getLCMandDisplayGCD(a, b, GCD);
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
            cout << "Answer: " << endl;
            cout << "GCD: " << GCD << endl;
            cout << "LCM: " << answer << endl;
        }
};