#include<iostream>
using namespace std ;

int main(){

// This file covers all the basics opertaions under the bit manipulation 

// Bit-wise AND operation 
int a , b , c ;
cin >> a  >> b ;
c = a & b ;

cout << " no. first is " << a << " no. second is "<< b << " the AND of these numbers is " << c << endl ;

// Bit-wise OR operation
c = a | b ;

cout << " no. first is " << a << " no. second is "<< b << " the OR of these numbers is " << c << endl ;

// Bit-wise XOR operation
c = a ^ b ;

cout << " no. first is " << a << " no. second is "<< b << " the XOR of these numbers is " << c << endl ;

// Bit-wise NOT operation
c = ~b ; // In C++, uses **2’s complement representation** (so result is `-(n+1)`).

cout << " no. second is "<< b << " the NOT of the number is " << c << endl ;

//SHIFT Operators 
// Left Shift operator 
int i = 1 ; 
int j ;
cin >> j ;
int k = i << j ;
cout << "the value of i is "<< i << " when left shifted by " << j << " the new value of i is " << k << endl ;

// Right Shift operator 
b = a>>1 ;
cout << "the value of a "<< a << "and the value of a<<1 " << b << endl  ;

cout << "End of the task " << endl ;

    return 0 ;
}