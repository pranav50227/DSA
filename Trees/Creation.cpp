#include<bits/stdc++.h>
using namespace std ;

class node{
    public : 
    int data ; 
    node* left ;
    node* right ;
// STEPS FOR THE CREATION OF A NEW NODE USING THE CONTRUCTOR FUNCTION 
  //   the int from the constructor is provided to the node data
  //   the newly created nodes left and right pointers are provided null value 
    node(int d){ // this is the constructor function 
        this -> data = d ;  
        this->left = NULL ; 
        this->right = NULL ; 
    }
};

node* buildTree(node* root){

    cout << "Enter the data:" << endl ;
int data ;
cin >> data ;
root = new node(data) ;

if(data == -1) return NULL ;

cout << "Enter data for inserting in left" << endl ;
root->left = buildTree(root->left) ;
cout << "Enter data for inserting in right" << endl ;
root->right = buildTree(root->right) ;
return root ;

}

void levelOrder(node* root){
    queue<node*> q ;
    q.push(root) ;

    while(!q.empty()){
        node* temp = q.front() ;
        cout << temp->data << " " ;
         q.pop() ;
        if(temp->left)q.push(temp->left) ;
        if(temp->right)q.push(temp->right) ;
    }
}

void DFS(node* root){
    stack<node*> q ;
    q.push(root) ;

    while(!q.empty()){
        node* temp = q.top() ;
        cout << temp->data << " " ;
         q.pop() ;
        if(temp->left)q.push(temp->left) ;
        if(temp->right)q.push(temp->right) ;
    }
}

void Inorder(node* root){
    node* temp = root ;
    if(temp == NULL) return ;
    Inorder(temp->left) ;
    cout << temp->data << " " ;
    Inorder(temp->right) ;
}

void Preorder(node* root){
    node* temp = root ;
    if(temp == NULL) return ;
    cout << temp->data << " " ;
    Preorder(temp->left) ;
    Preorder(temp->right) ;
}

void Postorder(node* root){
    node* temp = root ;
    if(temp == NULL) return ;
    Postorder(temp->left) ;
    Postorder(temp->right) ;
    cout << temp->data << " " ;
    
}

node* buildTreeFromLevelOrder(node* root){
   queue<node*> q ;
   int data ;
   cin >> data ;
   root = new node(data) ;
   q.push(root) ;
   while(!q.empty()){
    int x ;
    node* temp = q.front() ;
    q.pop() ;
    cout << "Enter next left data" << endl ;
    cin >> x ;
    if(x != -1){
    temp->left = new node(x) ;
    q.push(temp->left) ;
    }
    cout << "Enter next right data" << endl ;
    cin >> x ;
    if(x != -1){
    temp->right = new node(x) ;
    q.push(temp->right) ;
    }
   }

    return root ;
}



int height(int &m , node* root , int x){
    if(x > m) m = x ;

    if(root->left) height(m , root->left , x+1) ;
    if(root->right) height(m , root->right , x+1) ;

    return m ;
}

int height2(node* root){
    if(root == NULL) return 0 ;
    int left = height2(root->left) ;
    int right = height2(root->right) ;

    return max(left , right) + 1 ;
}

int diameter(node* root ,  int& m ){
    if(root == nullptr) return 0 ;
    int left = diameter(root->left ,  m) ;
    int right = diameter(root->right , m) ;

    m = max(m , left + right + 1) ;
    return max(left , right) +1 ;
}

int dia(node* root){
    if(root == NULL) return 0 ;
    int op1 = dia(root->left) ;
    int op2 = dia(root->right) ;
    int op3 = height2(root->right) + height2(root->left) +1  ;
    return max(op1 , max(op2 , op3)) ;
}

// better approach than the above one would be using a pair funciton 
// we would use pair as a parameter and save the height and diameter at a
// particular node at the same time 

pair<int , int> diameterht(node* root){

    if(root == NULL){
        pair<int , int > p = make_pair(0,0) ;
        return p ;
    }

pair<int , int> left = diameterht(root->left) ;
pair<int , int> right = diameterht(root->right) ;

int op1 = left.first ;
int op2 = right.first ;
int op3 = left.second + 1 + right.second ;

pair<int , int> ans ;
ans.first = max(op1 , max(op2 , op3)) ;
ans.second = max(left.second , right.second) +1 ;
return ans ;

}

// Check for a height balanced tree 
bool Balanced(node* root){
    if(root == NULL) return true ;
    int h1 = height2(root->left) ;
    int h2 = height2(root->right);
    return abs(h1 - h2) <= 1 ;
}
// checking for HBT using the pair function 
pair<bool , int> balance(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true , 0) ;
        return p ;
    }
    pair<bool , int> left = balance(root->left) ;
    pair<bool , int> right = balance(root->right) ;
    
    bool check = (abs(left.second-right.second)<= 1)&&left.first&&right.first ;
    pair<bool,int> ans = make_pair(check , 1 + max(left.second , right.second)) ;

    return ans ;
}

// Check if the two trees provided are identical or not 
// check in the same direction at the same time 
// Or traverse in both the trees at the same time 
// If the trees have the same value at all the points than they are identical 
bool checkIdentical(node* root1 , node* root2){
  if(root1 == NULL && root2 == NULL ) return true ;
  if(root1 == NULL || root2 == NULL) return false ;
  if(root1->data != root2->data) return false ;
  return checkIdentical(root1->left , root2->left) && checkIdentical(root1->right , root2->right) ; 
}

pair<bool , int> sumcheck(node* root){
    if(root == NULL) return {true , 0} ;
    pair<bool , int> left = sumcheck(root->left) ;
    pair<bool , int> right = sumcheck(root->right) ;

    bool check = ((root->data)==(left.second + right.second)) ;
    pair<bool , int> ans ; 
    ans.first = (check && left.first && right.first) ;
    ans.second = left.second + right.second + root->data ;
    return ans ;

}

int main(){

    node* root = NULL ;

    // creating a tree
    root = buildTree(root) ;
    cout << "The level wise traversal of the tree would be:- " << endl ;
    levelOrder(root) ;
    cout << endl ;
     // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

     cout << "The inorder traversal of the tree would be :" << endl ;
     Inorder(root) ;
     cout << endl ;

     cout << "The preorder traversal of the tree would be :" << endl ;
     Preorder(root) ;
     cout << endl ;

     cout << "The postorder traversal of the tree would be :" << endl ;
     Postorder(root) ;
     cout << endl ;

     cout << "The depth first search traversal of the tree would be :" << endl ;
     DFS(root) ;
     cout << endl ;

    //  if(root){
    //     int m = 1 ; 
    //     int x = 1 ;
    //     m = height(m , root , x) ;
    //     cout << " height of the binary tree is : "  << m << endl ;
    //  }else{
    //     cout << "height of the binary tree is : 0 " << endl ;
    //  }

    cout << "height of the tree is: " << height2(root) << endl ;
    
    // diameter of a tree is the longest path between any of the two nodes , thus we need 
    // to find the max distance between two leaf nodes 

    int m = 0 ; 
    diameter(root , m ) ;

    cout << " the diameter of the tree is : " << m  << endl ;



    return 0 ;
}