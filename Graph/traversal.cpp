#include<bits/stdc++.h>
using namespace std ;

class Graph{

    public : 
    unordered_map<int , vector<int>> adj ;

    void addEdge(int u , int v , bool direction){
        // direction -> 0 - undirected
        // direction -> 1 - directed

        // create an edge from u to v
        adj[u].push_back(v) ;

        if(direction == 0){
            adj[v].push_back(u) ;
        }
      }

      void printAdjList(){
        for(auto i : adj){
            cout << i.first << "->" ; 
            for(auto j : i.second ){
                cout << j << " ,";
            }
            cout<< endl ;
        }
      }

};

void travesal(unordered_map<int , vector<int>> & adj , int start){
    unordered_map<int , bool> visited ;
    queue<int> q ;
    q.push(start) ;
    visited[start] = 1 ;

    while(!q.empty()){
        int x = q.front() ;
        q.pop() ;
        cout << x << "/t" ;
        for(int i=0 ; i<adj[x].size() ; i++){


        }}
}

int main(){
    return 0 ;
}