#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertNode(Node* root , int value){
    if(root == nullptr){
        return new Node(value) ;
    }
    if(value < root->data){
        insertNode(root->left , value) ;
    }else{
        insertNode(root->right , value) ;
    }

    return root ;
}

Node* findMin(Node* node){
// returns the leftmost element of the right subtree which is the successor of the node to be deleted 
    while(!node->left){
        node = node->left ;
    }

    return node ;
}

Node* deleteNode(Node* root , int value){
    if(root == nullptr) return root ;
    if(root->data < value){
        // value greater than in right
        root->right = deleteNode( root->right , value) ;
    }else if(root->data > value){
        // value lesser than in left
        root->left = deleteNode(root->left , value) ;
    }else{
        // If the node is a leaf node 
        if(!root->left && !root->right){
            delete root ;
            root = nullptr ;
        }
        // if the node only have a single right or left child than delete the current node and position the single child to it's position 
        else if(!root->left){
            Node* temp = root ;
            root = root->right ;
            delete root ;
        }else if(!root->right){
            Node* temp = root ;
            root = root->left ;
            delete root ;
        }else{
            // find the inorder successor of the value 
            Node* temp = findMin(root->right) ;
            // transfer the value of the successor to the current node 
            root->data = temp->data ;
            // delete the successor node from the tree
            root->right = deleteNode(root->right , temp->data) ;
        }
    }

    return root ; 
}

Node* searchinBst(Node* root , int val){
    Node* ans = NULL ;
    if(root == NULL) return ans ;

    if(root->data > val){
        ans = searchinBst(root->left , val) ;
    }else if(root->data < val){
        ans = searchinBst(root->right , val) ;
    }else{
        ans = root ;
    }

    return ans ;
}

Node* searchbst(Node* root , int val){
    if(root == NULL || root->data == val) return root ;

    if(root->data > val) return searchbst(root->left , val) ;
    else return searchbst(root->right , val) ;
}

Node* bstFromVector(vector<int>& arr , int start , int end){
    if(start > end ){
        return NULL ;
    }

    int mid = (start + end)/2 ;
    Node* root = new Node(arr[mid]) ;
    root->left = bstFromVector(arr , start , mid-1) ;
    root->right = bstFromVector(arr , mid+1 , end) ;

    return root ;
}

Node* createBst( vector<int> & arr){
    return bstFromVector(arr , 0 , arr.size()-1) ;
}


int main(){

    return 0;
}