#include<bits/stdc++.h>
using namespace std ;


// This document would be containing -
// Largest Sum bloodline of any tree 
// K-sum path - number of paths in a tree , whose sum is equal to K
// K-th ancestor - In this problem we are required to find the k th ancestor from the node value provided 
// The Max sum for non adjacent nodes - In this problem you are required to find out the maximum sum of the non-adjacent nodes 

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

// The first question states that we are required to find the sum of the longest path of the tree 
int SumLongpath(node* root){
    if(root == NULL) return 0 ;
    
    return sumLong(root).first ;
}

pair<int , int> sumLong(node* root){
    if(!root) return {0 , 0} ;

    pair<int , int> l= sumLong(root->left) ; ;
    pair<int , int> r = sumLong(root->right)  ;
    

    auto x = (l.second > r.second)? l:r ;
    x.first += root->data ;
    x.second += 1 ;
    return x ;
}

node* lca (node* root , int n1 , int n2){
    if(root == NULL) return NULL ;

    if(root->data == n1 || root->data == n2) return root ; 

    node* left = lca(root->left , n1 , n2) ; 
    node* right = lca(root->right , n1 , n2) ; 

    if(left != NULL && right == NULL) return left ;
    if(left == NULL && right != NULL) return right ;

    if((left->data == n1 && right->data == n2)|| (left->data == n2 && right->data == n1)) return root ;

}

 int numberOfPaths = 0 ;
int ksumpath(node* root , int K){
    if(root == NULL)return 0 ;
int left = ksumpath(root->left , K) ;
int right = ksumpath(root->right , K) ;
    if(root->data == K) numberOfPaths += 1 ;
    else if(left + root->data == K) numberOfPaths += 1 ;
    else if(right + root->data == K) numberOfPaths += 1 ;
    else return K-root->data ; 
}

int ksum(node* root , int k){
    int count = 0 ;
    unordered_map<int, int> path ;
    solve(root , k ,0 , count , path) ;
    return count ;
}

// we are required to use the referenced path map as if not used a new copy would be created at every new call 
void solve(node* root , int k , int currentSum , int& count , unordered_map<int, int>& path){
    if(root == NULL) return ;

    currentSum += root->data ;
    if(currentSum == k) count++ ;

    if(path.find(currentSum - k ) != path.end()){
        count += path[currentSum - k] ;
    }

    path[currentSum] ++ ;
   
    // left 
    solve(root->left , k , currentSum, count , path) ;
    // Right
    solve(root->right , k , currentSum , count , path) ;

    path[currentSum]-- ;
}

// Kth Ancestor 
node* kthAncestor(node* root , int& k , int n){
    if(root == NULL) return root ;

    if(root->data == n){
        return root ;
    }

    node* l = kthAncestor(root->left , k , n) ;
    node* r = kthAncestor(root->right , k , n) ;

    if(l || r){
        k-- ;
        if(k == 0){
            return root ;
        }else{
            return l ? l : r ;
        }
    }

    return nullptr ;
}

void solveMax(node* root , bool check , int& even , int& odd){
    if(root == NULL) return ;
    if(check){
        even += root->data ;
    }else{
        odd += root->data ;
    }

    solveMax(root->left , !check , even , odd) ;
    solveMax(root->right , !check , even , odd) ;
}

// Max sum of the non-adjacent nodes 
int MaxSum(node* root){
    if(!root) return 0 ;
    int even = 0 , odd = 0 ;
    bool check = true ;
    solveMax(root , check , even , odd) ;

    return max(even , odd) ;
}


// this solution won't work , because if you consider a case where the child of the grandchild and the node would make the maximum pair than we won'tbe able to find that outcome in our answer , so we need to find out the using the above method 
int maxSumNonAdj(node* root){
    if(!root) return 0 ;

    // including the current node and than would be adding the grandchildren or the childern of the grandchildren 
    int incl = root->data ;
    if(root->left){
        incl += maxSumNonAdj(root->left->left) + maxSumNonAdj(root->left->right) ;
    }
    if(root->right){
        incl += maxSumNonAdj(root->right->left) + maxSumNonAdj(root->right->right) ;
    }

    // excluding the current node and than checking for the current children of the node 
    int excl = 0 ;
    if(root->left) excl += maxSumNonAdj(root->left) ;
    if(root->right) excl += maxSumNonAdj(root->right) ;

    // Now considering the case as the node is to be added or not considering the outcomes from the incl and excl comparision and returning the result 
    return max(incl, excl) ;
}