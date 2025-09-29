#include<iostream>

using namespace std ;

int main(){

    int n = 5;

    // CHECK IF N IS POWER OF 2
    bool isPower = n > 0 && (n & (n - 1)) == 0;
    cout << "Is n power of 2? " << isPower << endl;

    // COUNT SET BITS (BRIAN KERNIGHAN'S ALGORITHM)
    int temp = n, count = 0;
    while(temp) {
        temp = temp & (temp - 1);
        count++;
    }
    cout << "The number of set bits are " << count << endl;

    // FAST MULTIPLICATION BY 2^k
    int k = 2;
    int mult = (n << k);
    cout << "Multiplying n by 2^k = " << mult << endl;

    // CLEAR LOWEST SET BIT
    int cleared = n & (n - 1);
    cout << "n after clearing lowest set bit = " << cleared << endl;

    // GET LOWEST SET BIT
    int lowest = n & (-n);
    cout << "Lowest set bit of n = " << lowest << endl;

    return 0 ;
}