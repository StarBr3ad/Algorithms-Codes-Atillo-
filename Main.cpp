#include "Converter.h"
#include "Operation.h"
#include "RecyclableMethods.h"
#include "Bitwise.h"
#include "Sieve.h"
#include "PrimeFactorization.h"

using namespace std;

void writeWarning();

int main()
{
    Converter numSystemConverter;
    Operation numSystemCalculator;
    Bitwise BIN_BitwiseOperator;
    SieveOfErathosthenes SOECalculator;
    PrimeFactorization primeFactorFinder;

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
    primeFactorFinder.MAIN_LOOP();

    //GREEDY ALGOS


    //ENCRYPTION
    
}

void writeWarning()
{
    cout << "DONT FUCKING TRY TO FUCKING FIND BUGS CUNT NO ERROR CATCHER IN INPUTING VALUES" << endl;
    cout << "BUT NO BUGS IN SOLVING THE PROBLEMS\n" << endl;
}
