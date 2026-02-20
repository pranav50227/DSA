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


// BFS TRaversal of a graph
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
            if(!visited[adj[x][i]]){
                q.push(adj[x][i]);
                visited[adj[x][i]] = 1 ;
            }
        }}
}

// DFS Traversal of a graph
void dfs(unordered_map<int , vector<int>> & adj , int start , unordered_map<int , bool> & visited){
    cout << start << "/t" ;
    visited[start] = 1 ;
    for(int i=0 ; i<adj[start].size() ; i++){
        if(!visited[adj[start][i]]){
            dfs(adj , adj[start][i] , visited) ;
        }
    }
}

int main(){
    return 0 ;
}