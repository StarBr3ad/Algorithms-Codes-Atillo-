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

    //ENCRYPTION
    //CAESAR CIPHER


    //GREEDY ALGOS


    
    
}

void writeWarning()
{
    cout << "DONT FUCKING TRY TO FUCKING FIND BUGS CUNT NO ERROR CATCHER IN INPUTING VALUES" << endl;
    cout << "BUT NO BUGS IN SOLVING THE PROBLEMS\n" << endl;
}
