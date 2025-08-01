#include<bits/stdc++.h>
using namespace std ;

// In this file we would be covering the part i which we wuold form a binary tree from -
// provided preorder and postorder traversal of the tree 
// provided inorder and preorder traversal of the tree 

class node{

    public : 
    int data ;
    node* left ,* right ;

    node(int d){
        this->data = d; 
        this->left = NULL ; 
        this->right = NULL ;
    }
} ;

// Tree formation from in and preorder traversal 
 node* treeFromInPre(vector<int> inorder , vector<int> preorder){
    int indexPre = 0 ;
    int start = 0 ; 
    int end = inorder.size()-1 ;
    node* root = solve(inorder , preorder , indexPre , start , end) ;
 } 

 node* solve(vector<int>& inor , vector<int>& preor , int& indexPre , int start, int end){
    if(start > end) return nullptr ;

    node* root = new node(preor[indexPre++]) ;
    
    int index = findIndex(inor , root , start , end) ;

    root->left = solve(inor , preor , indexPre , start , index-1) ;
    root->right = solve(inor , preor , indexPre , index+1 , end) ;

    return root ;
 
 }

 int findIndex(vector<int>& inor , node* root , int start , int end){
    int val = root->data ;

    for(int i=start ; i<end ; i++){
        if(inor[i] == val) return i ;
    }

    return -1 ;
 }

 // Or instead of the find index we can use the uordered_map to store all the elements of the inordered traversal 
 // than we won't require the find index in the inordered traversal anymore