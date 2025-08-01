#include<bits/stdc++.h>
using namespace std ;

// In this file we have the following questions - 
// check if bst or not 
// kth smallest element in the bst 
// kth largest element in the bst 
// finding the lowest common ancestor of two numbers 



class Node{
    public :

    int data ;
    Node* left ;
    Node* right ;

    Node(int d){
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

bool checkbst(Node* root){
    if(root == NULL) return true ;

    if(root->data > root->left->data && root->right->data >= root->data){
        bool l = checkbst(root->left) ;
        bool r = checkbst(root->right) ;

        return l && r ;
    }else{
        return false ;
    }
}

bool chkbst(Node* root , int min = INT_MIN , int max = INT_MAX){
    if(root == NULL) return true ;
    if(root->data < min && root->data > max ){
        return false ;
    }
    
    return chkbst(root->left , min , (root->data)-1 ) && chkbst(root->right , root->data , max) ;
}


// We can simply find the kth smallest number by performing an inorder traversal 
// and stopping at the kth element , storing the element's value in a result 
// would pretty much do it

void smallestkth(Node* root , int& k , int& result){
    if(root == NULL || k<=0) return ;
    k-- ;
    smallestkth(root->left , k , result ) ;

    if( k == 0 ){
        result = root->data ;
        return ;
    }

    smallestkth(root->right , k , result) ; 
}


void largestkth(Node* root , int& k , int& result){
    if(root == NULL || k<=0 ) return ;
    k-- ; 
    largestkth(root->right , k , result) ;

    if(k == 0){
        result = root->data ;
        return ;
    }

    largestkth(root->left , k , result) ;
}

pair<int , int> largestSmallestkth(Node* root , int k){
    int largest = -1  , t = k;
    largestkth(root , t , largest) ;
    int smallest = -1 ;
    t = k ;
    smallestkth(root , t , smallest ) ;
    return {smallest , largest} ;
}

// if we think properly , the leftsubtree elements are all smaller than the node 
// And the rightSubtree elements are all larger than node value 
// if the node has a value lying between the two values 

Node* LCA(Node* root , int v1 , int v2){
    if(root == NULL) return nullptr ;

    if(root->data > v1 && root->data >v2){
        return LCA(root->right , v1 , v2) ;
    }

    if(root->data < v1 && root->data < v2){
        return LCA(root->right , v1 , v2) ;
    }

    return root ;
} 