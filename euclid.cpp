//University of Washington Bothell - CSSE
// CSS342C : Proffesor Munehiro Fukuda
// Created by Eyas Rashid on 1/25/2019
//
// Purpose: this program empirically analyzes worst-case performance of
// the Euclidean Algorithm for finding the GCD of two non-negative integers.

#include <iostream>
#include <vector>
#include <math.h>
#include <sys/time.h>
#include <fstream>

using namespace std;

//implementation of Euclidean Algorithm
int gdc(int a, int b, int &cost) {
    if (b == 0) {
        return a;
    }
    // counts the number of modulus operations
    cost++;
    // usage of euclidean algorithm logic to find gcd of a and b till b = 0
    // were a is the gcd
    return gdc(b, a % b, cost);
}

int main() {
// output stream to operate on file sieve.dat
    ofstream file("euclid.dat");

    int n; // number of iterations selected by user
    int maxA; // value of a for present iteration
    int maxB; // value of b for present iteration
    int maxModulus;  // maximum modulus for iterations
    int tempMaxModulus; // temporarily saves maximum modulus to be compared to previous iterations of j
    int maxAns; // value of gcd for maximum modulus of iteration
    int tempMaxAns; // temporary gcd for present iteration

    // starts timer for runtime of the program
    struct timeval startTime, endTime;

    while (n < 8) {
        cout << "Enter n (n must be >= 8)" << endl;
        cin >> n;

    }
    // begin timer in milli seconds
    gettimeofday(&startTime, NULL);
    for (int i = 8; i <= n; i++) {

        for (int j = 1; j <= i; j++) {

            tempMaxModulus = 0;

            tempMaxAns = gdc(i, j, tempMaxModulus);

            if (tempMaxModulus > maxModulus) {

                maxA = j;
                maxB = i;
                maxModulus = tempMaxModulus;
                maxAns = tempMaxAns;
            }
        }
        // ends timer for each iteration of n
        gettimeofday(&endTime, NULL);

        cout << "At n = " << i << " gcd( " << maxA
             << ", " << maxB << " ) = " << maxAns << " took "
             << maxModulus << " modulus operations"
             << " ...time required = "
             << (endTime.tv_sec - startTime.tv_sec) * 1000000 +
                (endTime.tv_usec - startTime.tv_usec) << endl;
        // writes i and cost to gdc.dat
        file << i << " " << maxModulus << endl;
    }
    file.close();
    return 0;
}