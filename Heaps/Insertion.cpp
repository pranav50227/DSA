#include <iostream>

using namespace std ;

class MaxHeap{

    
    int * arr ;
    int size ;
    int total_size ;

    public :

    MaxHeap(int n){
        arr = new int[n] ;
        size = 0 ;
        total_size = 10 ;
    }

    // insert into the heap 

    void insert(int value ){
        if(size == total_size){
            cout << "Heap Overflow " ;
            return ;
        }

        arr[size] = value ;
        int index = size ;
        size ++ ;

        // compare it with it's parents 
        while (index > 0 && arr[(index-1)/2] < arr[index])
        {
            swap(arr[index] , arr[(index-1)/2]) ;
            index = (index-1)/2 ;
        }

        cout << arr[index] << " is inserted at the " << index << "position in heap. " << endl ;
        
    }

    void print(){
        for(int i=0 ; i<size ; i++)
            cout << arr[i] << " " ;

        cout << endl ;
    }
};

int main(){

    MaxHeap H1(6) ;
    H1.insert(1) ;
    H1.insert(4) ;
    H1.insert(14) ;
    H1.insert(11) ;

    H1.print() ;

    return 0 ;
}