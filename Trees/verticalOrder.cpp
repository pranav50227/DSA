// This file contains -
// Vertical order traversal
// top view
// bottom view
// left view 
// right view


#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL, this->right = NULL;
    }
};

vector<int> verticalOrder(node *root)
{
    vector<int> result;

    map<int, map<int, vector<int>>> nodes;

    queue<pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto point = q.front();
        q.pop();
        int hor = point.second.first;
        int ver = point.second.second;
        node *temp = point.first;
        nodes[hor][ver].push_back(temp->data);

        if (temp->left)
            q.push({temp->left, {hor - 1, ver + 1}});
        if (temp->right)
            q.push({temp->right, {hor + 1, ver + 1}});
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            result.insert(result.end(), j.second.begin(), j.second.end());
        }
    }

    return result;
}

vector<int> topView(node *root)
{
    vector<int> result;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    result.push_back(root->data);
    int left = 0, right = 0;
    while (!q.empty())
    {
        node *temp = q.front().first;
        int val = q.front().second;
        q.pop();

        if (val < left)
        {
            result.insert(result.begin(), temp->data);
            left = val;
        }
        else if (val > right)
        {
            result.push_back(temp->data);
            right = val;
        }

        if (temp->left)
            q.push({temp->left, val - 1});
        if (temp->right)
            q.push({temp->right, val + 1});
    }

    return result;
}

vector<int> topview2(node *root)
{
    vector<int> result;

    if (root == NULL)
        return result;

    map<int, int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        node *temp = q.front().first;
        int hd = q.front().second;

        q.pop();

        if (mp.find(hd) == mp.end())
        {
            mp[hd] = temp->data;
        }

        if (temp->left)
            q.push({temp->left, hd - 1});
        if (temp->right)
            q.push({temp->right, hd + 1});
    }

    for (auto i : mp)
    {
        result.push_back(i.second);
    }

    return result;
}

vector<int> bottomView(node *root)
{
    vector<int> result;

    if (root == NULL)
        return result;

    map<int, int> mp;
    queue<pair<node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        node *temp = q.front().first;
        int hd = q.front().second;

        q.pop();

        mp[hd] = temp->data;

        if (temp->left)
            q.push({temp->left, hd - 1});
        if (temp->right)
            q.push({temp->right, hd + 1});
    }

    for (auto i : mp)
    {
        result.push_back(i.second);
    }

    return result;
}

vector<int> leftView(node* root){
    vector<int> result ;
    if(root == NULL) return result ;
    map<int , pair<int , int>> mp ;
    queue<pair<node* , pair<int , int>>> q ;
    q.push({root , {0 , 0}}) ;

    while(!q.empty()){
        node* temp = q.front().first ;
        int level = q.front().second.first ;
        int leftd = q.front().second.second ;

        q.pop() ;

        if(mp.find(level) == mp.end()){
            mp[level] = {leftd , temp->data} ;
        }else{
            if(mp[level].first > leftd){
                mp[level] = {leftd , temp->data};
            }
        }

        if(temp->left) q.push({temp->left , {level+1 , leftd-1}}) ;
        if(temp->right) q.push({temp->right , {level+1 , leftd+1}}) ;
    }

    for(auto i : mp){
        result.push_back(i.second.second) ;
    }
    return result ;
}

// Oh my , we have  a simpler version here 
vector<int> leftView2(node* root){
    vector<int> result ;
    if(root == NULL) return result ;
    queue<node*> q ;
    q.push(root) ;
    while(!q.empty()){
        int s = q.size() ;
       for(int i = 0 ; i < s ; i++){
        node* temp = q.front() ;
        q.pop() ;

        if(i == 0 )result.push_back(temp->data) ;

        if(temp->left)q.push(temp->left) ;
        if(temp->right)q.push(temp->right) ;
       }
    }
    return result ;
}

vector<int> rightView(node* root){
    vector<int> result ;
    if(root == NULL) return result ;
    queue<node*> q ;
    q.push(root) ;
    while(!q.empty()){
        int s = q.size() ;
       for(int i = 0 ; i < s ; i++){
        node* temp = q.front() ;
        q.pop() ;

        if(i == s-1 )result.push_back(temp->data) ;

        if(temp->left)q.push(temp->left) ;
        if(temp->right)q.push(temp->right) ;
       }
    }
    return result ;
}

int main()
{
    return 0;
}