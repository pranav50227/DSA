#include<bits/stdc++.h>
using namespace std ; 

// Topological sort only works on a DAG
// DAG - directed acyclic graph 

void formTS(int node , unordered_map<int , list<int>> &adj  , unordered_map<int , bool> visited ,  stack<int> st){
    visited[node] = true ;
    for(auto neighbor : adj[node]){
        if(!visited[neighbor]){
            formTS(neighbor , adj , visited , st);
        }
    }

    st.push(node) ;
}
vector<int> topologicalSort(vector<vector<int>> & edges , int n , int m){
    unordered_map<int , list<int>> adj ;
    for(int i=0 ; i<m ; i++){
        int u = edges[i][0] ;
        int v = edges[v][1] ;

        adj[u].push_back(v) ;
    }

    stack<int> st ;
    unordered_map<int , bool> visited ;

    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            formTS(i , adj , visited , st);
        }
    }
     vector<int> ans ;
    while(!st.empty()){
        ans.push_back(st.top()) ;
        st.pop() ;
    }
    return ans ;
}


int main(){
    return 0 ;
}