#include <sys/time.h>
#include "nr3.h"

int main()
{
    // If you don't declare the array to be volatile, the
    // compiler may optimize away some of the access statements
    volatile double A1[3];

    //
    // The compiler won't optimize away access to a VecDoub
    // since access involves calling the overloaded [] operator
    // and function calls are not optimized away.
    // 
    VecDoub A(3);
    //std::vector<double> A(3);

    struct timeval tv1;
    struct timeval tv2;
    unsigned long elapsed;
    double sum;

    cout << "Loop1 uses an array." << endl;

    sum = 0.0;

    gettimeofday(&tv1, NULL);
    for (int i = 0; i < 999999999; i++) {
        A1[0] = 43;
        A1[1] = A1[0] * 2.142;
        A1[2] = A1[1] / 5.31;
        sum += A1[2] + A1[1] + A1[0];
    }
    gettimeofday(&tv2, NULL);

    elapsed = (tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec);

    //Print out the sum so that the compiler won't optimize away all
    // of the calculations
    cout << "End of loop 1: sum = " << sum << endl;
    cout << "Elapsed time = " << elapsed/1000000.0 << " seconds" << endl << endl;

    cout << "Loop 2 uses the VecDoub" << endl;
    sum = 0.0;

    gettimeofday(&tv1, NULL);
    for (int i = 0; i < 999999999; i++) {
        A[0] = 43;
        A[1] = A[0] * 2.142;
        A[2] = A[1] / 5.31;
        sum += A[2] + A[1] + A[0];
    }
    gettimeofday(&tv2, NULL);

    elapsed = (tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec);
    cout << "End of loop 2: sum = " << sum << endl;
    cout << "Elapsed time = " << elapsed/1000000.0 << " seconds" << endl;

    return 0;
}
