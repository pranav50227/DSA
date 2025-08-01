#include<bits/stdc++.h>
using namespace std ;

// We are provided a problem that a node or a target node is provided 
// This target node is burned , and the fire spreads to the 
// surrounding nodes in one second , than the adjacent nodes are burned down in another second from the 
// previously burned nodes , so tell in what time all the nodes would have  burned down 
// if the target node is burned 

// Solution 
// First we would try to find the parent and child relationship in the tree 
// We would have a level order traversal and would store all the 
// parent - child nodes in the parent map 
// Now we find the position of the target node and would keep a check of the visited nodes from the burned nodes 
// a node would burn the adjacent nodes - which are - 
// left child 
// right child 
// parent node

// We can directly travel to the left and right child , and use the parent map for reaching the 
// parent node and would map true for the visited node so that we do not visit the same node more than once

class node{
    public :
    int data ;
    node* left ;
    node* right ;

    node(int d){
        this->data = d ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

int burnTreeTime(node* root , int val){
    map <node* , node* > parentChild ;
    if(root == NULL) return 0 ;

    int ans = 0 ;
    queue<node*> q ;
    q.push(root) ;
    node* target = NULL ;


    while(!q.empty()){
        node* temp = q.front() ;
        q.pop() ;
        if(temp->left){
             q.push(temp->left) ;
             parentChild[temp->left] = temp ;
        }
        if(temp->right){
             q.push(temp->right) ;
             parentChild[temp->right] = temp ;
        }    

        if(temp->data == val){
           target  = temp ;
        }
    }

    if(target == NULL) return 0 ;

    q.push(target) ;
    map<node* , bool> visited ;
    visited[target] = true ;
    

while(!q.empty()){

int size = q.size() ;
bool burned = false ;

for(int i=0 ; i< size ; i++){
     node* temp = q.front() ;
     q.pop() ;

     if(parentChild.find(temp) != parentChild.end() && !visited[parentChild[temp]]){
        node* parent = parentChild[temp] ;
       q.push(parent) ;    
       visited[parent] = true ;
       burned = true ;
     }

     if(temp->left && !visited[temp->left]){
        q.push(temp->left) ;
        visited[temp->left] = true ;
        burned = true ;
     }
     if(temp->right &&  !visited[temp->right]){
        q.push(temp->right) ;
        visited[temp->right] = true ;
        burned = true ;
     }
    }

if(burned)ans ++ ;
}

    return ans ;


}