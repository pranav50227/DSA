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
        total_size = 100 ;
    }

    // insert into the heap 

    void insert(int value ){
        if(size == total_size){
            cout << "Heap Overflow " << endl ;
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

    void Heapify(int index){
        int largest = index ;
        int left = index*2 +1 ;
        int right = index*2 + 2 ;

        // Largest will store the index of the number which is greater between parent and the childer 
        if(left < size && arr[left] > arr[largest]) largest = left ;
        else if(right < size && arr[right] > arr[largest]) largest = right ;
        else return ;

        if(largest != index ){
            swap(arr[index] , arr[largest]) ;
            Heapify(largest) ;
        }
    }

    void deletion(){
        if(size == 0){cout << " Heap Underflow \n" ; return ;}

        cout << arr[0] << "deleted from the heap \n" ;
        arr[0] = arr[size-1] ;
        size -- ;
        if(size == 0) return ;
        int index = 0 ;

        Heapify(0) ;
    }
};

int main(){

    MaxHeap H1(6) ;
    H1.insert(1) ;
    H1.insert(4) ;
    H1.insert(14) ;
    H1.insert(11) ;
    H1.insert(13) ;
    H1.insert(15) ;
    H1.insert(19) ;
    H1.insert(23) ;
    H1.insert(80) ;
    H1.insert(90) ;
    H1.insert(100) ;

    H1.print() ;
    H1.deletion() ;
    H1.print() ;
    H1.deletion() ;
    H1.print() ;

    return 0 ;
}