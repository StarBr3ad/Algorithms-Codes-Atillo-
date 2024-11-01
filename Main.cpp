#include "Converter.h"
#include "Operation.h"
#include "RecyclableMethods.h"
#include "Bitwise.h"
#include "Sieve.h"
#include "PrimeFactorization.h"
#include "Euclidean.h"
#include "GCDandLCM.h"
#include "Fibbonaci.h"
#include "EgyptianFrac.h"
#include "ModArithmetic.h"
#include "CaesarCipher.h"
#include "AES.h"

using namespace std;

void writeWarning();

int main()
{
    Converter numSystemConverter;
    Operation numSystemCalculator;
    Bitwise BIN_BitwiseOperator;
    SieveOfErathosthenes SOECalculator;
    PrimeFactorization primeFactorFinder;
    Euclidean GCDCalculator;
    GCDandLCMCalc GCDandLCMCalculator;
    Fibbonaci fib;
    NiggasFraction egyptianFrac;
    ModArithmetic modArithCalc;
    CaesarCipher caesarCipher;

    writeWarning();


    //CONVERTER
    //numSystemConverter.MAIN_LOOP();

    //OPERATION
    //numSystemCalculator.MAIN_LOOP();

    //BITWISE
    //BIN_BitwiseOperator.MAIN_LOOP();

    //SIEVE OF ERATHOSTHENES
    //SOECalculator.MAIN_LOOP_SIEVE();

    //PRIME FACTORIZATION
    //primeFactorFinder.MAIN_LOOP();

    //GCD AND LCM CALCULATOR
    //GCDandLCMCalculator.MAIN_LOOP();

    //EUCLIDEAN ALGORITHM
    //GCDCalculator.MAIN_LOOP();

    //FIBBONACI SEQUENCE
    //fib.MAIN_LOOP();

    //EGYPTIAN FRACTION
    //egyptianFrac.MAIN_LOOP();

    //MODULAR ARITHMETHIC
    //modArithCalc.MAIN_LOOP();

    //GREEDY ALGOS




    //ENCRYPTION
    //CAESAR CIPHER
    //caesarCipher.MAIN_LOOP();

    //DIFFIE HELLMAN


    //AES
    //PT    
        //cout << "Plain Text : " << endl;
        Matrix_2S PlaintText(4, 4);
        vector<string>  PlaintText_row1 = { "20","7A","00","44" },
                        PlaintText_row2 = { "23","BB","11","55" },
                        PlaintText_row3 = { "03","CC","22","66" },
                        PlaintText_row4 = { "53","DD","33","77" };

        PlaintText.pushRow(PlaintText_row1, 0);
        PlaintText.pushRow(PlaintText_row2, 1);
        PlaintText.pushRow(PlaintText_row3, 2);
        PlaintText.pushRow(PlaintText_row4, 3);
        //PlaintText.displayMatrix();
    //PT

    newLineMaker(0);

    //KEY
        //cout << "Key : " << endl;
        Matrix_2S Key(4, 4);
        vector<string>  Key_row1 = { "0F","47","0C","AF" },
                        Key_row2 = { "15","D9","B7","7F" },
                        Key_row3 = { "71","E8","AD","67" },
                        Key_row4 = { "E9","59","D6","98" };

        Key.pushRow(Key_row1, 0);
        Key.pushRow(Key_row2, 1);
        Key.pushRow(Key_row3, 2);
        Key.pushRow(Key_row4, 3);
        //Key.displayMatrix();
    //KEY
    
    //S-BOX
        //cout << "S-BOX : " << endl;
        Matrix_2S S_BOX(16, 16);
        vector<string>  S_BOX_row0 = { "63","7C","77","7B","F2","6B","6F","C5","30","01","67","2B","FE","D7","AB","76" },
                        S_BOX_row1 = { "CA","82","C9","7D","FA","59","47","F0","AD","D4","A2","AF","9C","A4","72","C0" },
                        S_BOX_row2 = { "B7","FD","93","26","36","3F","F7","CC","34","A5","E5","F1","71","D8","31","15" },
                        S_BOX_row3 = { "04","C7","23","C3","18","96","05","9A","07","12","80","E2","EB","27","B2","75" },
                        S_BOX_row4 = { "09","83","2C","1A","1B","6E","5A","A0","52","3B","D6","B3","29","E3","2F","84" },
                        S_BOX_row5 = { "53","D1","00","ED","20","FC","B1","5B","6A","CB","BE","39","4A","4C","58","CF" },
                        S_BOX_row6 = { "D0","EF","AA","FB","43","4D","33","85","45","F9","02","7F","50","3C","9F","A8" },
                        S_BOX_row7 = { "51","A3","40","8F","92","9D","38","F5","BC","B6","DA","21","10","FF","F3","D2" },
                        S_BOX_row8 = { "CD","0C","13","EC","5F","97","44","17","C4","17","7E","3D","64","5D","19","73" },
                        S_BOX_row9 = { "60","81","4F","DC","22","2A","90","88","46","EE","B8","14","DE","5E","0B","DB" },
                        S_BOX_rowA = { "E0","32","3A","0A","49","06","24","5C","C2","D3","AC","62","91","95","E4","79" },
                        S_BOX_rowB = { "E7","C8","37","6D","BD","D5","4E","A9","6C","56","FA","EA","65","7A","AE","08" },
                        S_BOX_rowC = { "BA","78","25","2E","1C","A6","B4","C6","E8","DD","74","1F","4B","BD","8B","8A" },
                        S_BOX_rowD = { "70","3E","B5","66","48","03","46","OE","61","35","57","B9","86","C1","1D","9E" },
                        S_BOX_rowE = { "E1","F8","98","11","69","D9","8E","94","9B","1E","87","E9","CE","55","28","DF" },
                        S_BOX_rowF = { "8C","A1","89","0D","BF","E6","42","68","41","99","2D","0F","B0","54","BB","16" };
        S_BOX.pushRow(S_BOX_row0, 0);
        S_BOX.pushRow(S_BOX_row1, 1);
        S_BOX.pushRow(S_BOX_row2, 2);
        S_BOX.pushRow(S_BOX_row3, 3);
        S_BOX.pushRow(S_BOX_row4, 4);
        S_BOX.pushRow(S_BOX_row5, 5);
        S_BOX.pushRow(S_BOX_row6, 6);
        S_BOX.pushRow(S_BOX_row7, 7);
        S_BOX.pushRow(S_BOX_row8, 8);
        S_BOX.pushRow(S_BOX_row9, 9);
        S_BOX.pushRow(S_BOX_rowA, 10);
        S_BOX.pushRow(S_BOX_rowB, 11);
        S_BOX.pushRow(S_BOX_rowC, 12);
        S_BOX.pushRow(S_BOX_rowD, 13);
        S_BOX.pushRow(S_BOX_rowE, 14);
        S_BOX.pushRow(S_BOX_rowF, 15);
        //S_BOX.displayMatrix();
    //S-BOX

    AES aes(PlaintText, Key, S_BOX);
    aes.MAIN_LOOP();

}

void writeWarning()
{
    cout << "DONT FUCKING TRY TO FUCKING FIND BUGS CUNT NO ERROR CATCHER IN INPUTING VALUES" << endl;
    cout << "BUT NO BUGS IN SOLVING THE PROBLEMS\n" << endl;
}
