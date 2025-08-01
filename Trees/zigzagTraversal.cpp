#include<bits/stdc++.h>
using namespace std ;

class node{
    public : 
    int data ; 
    node* left ; 
    node* right ;

    node(int val){
        this->data = val ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

vector<int> zigzag(node* root){
    vector<int> result ;
     queue<node*> q ;
     q.push(root) ;
     bool leftToright = true ;

     while(!q.empty()){
        vector<int> ans ;

        for(int i=0 ; i<q.size() ; i++){
         node* temp = q.front() ;
         q.pop() ;

         int index = leftToright? i : q.size() - i - 1 ;
         ans[index] = temp->data ;
         if(temp->left) q.push(temp->left) ;
         if(temp->right) q.push(temp->right) ;

        } 
        leftToright = !leftToright ;

        for(auto i : ans){
            result.push_back(i) ;
        }
     }
     
return result ;
}

void leaves(node* root , vector<int> & result){
    if(root == NULL) return ;
    if(!root->left && !root->right){ result.push_back(root->data) ; return ;}
    leaves(root->left , result) ;
    leaves(root->right , result) ;
}
void traversalLeft(node* root , vector<int> & result){
    if((root == NULL)||(!root->left && !root->right)) return ;
    result.push_back(root->data) ;
    
    if(root->left) traversalLeft(root->left , result) ;
    else traversalLeft(root->right , result) ;
}

void traversalRight(node* root , vector<int> & result){
    if((root == NULL)||(!root->left && !root->right)) return ;
    
    if(root->right) traversalRight(root->right , result) ;
    else traversalRight(root->left , result) ;

    result.push_back(root->data) ; // add after recursion so that we can get a  reverse order and thus reduce the complexity of the overall function 
}

vector<int> boundary(node* root){
    vector<int> result ;
    if(root == NULL) return result ;
    if (root->left || root->right) result.push_back(root->data);
    
    traversalLeft(root->left , result) ;
    leaves(root , result) ;
    traversalRight(root->right , result) ; 
return result ;
}

int main(){

    return 0 ;
}