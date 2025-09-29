#include<iostream>

using namespace std ;

int main(){

    int n = 5 ;
    int k = 2 ;

    // CHECKING IF THE KTH BIT IS SET IN A GIVEN NUMBER 
    // CONSIDER THE OPERATION OF BITS STARTS FROM THE VERY 0TH INDEX 
    bool isSet = (n & (1<<k)) != 0 ;

    // SET A BIT ( MAKE IT 1)
    n = n | (1<<k) ;

    cout << n << endl ;

    // CLEAR A BIT 
    n = n & ~(1<<k) ;
    cout << n << endl ;

    // TOGGLE A BIT ( flip between 0 and 1 )
    n = n ^ (1<<k) ;
    cout << n << endl ;

    return 0 ;
}