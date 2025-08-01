#include<bits/stdc++.h>
using namespace std ;

vector<int> shortestPath(int src , int dest , vector<vector<int>> & edges){
    int m = edges.size() ;
    unordered_map<int , list<int>> adj ;
    for(int i=0 ; i < m ; i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    unordered_map<int , bool > visited ;
    unordered_map<int , int > parent ;
    queue<int> q ;
    q.push(src) ;
    visited[src] = true ;

    bool present = false ;
    while(!q.empty()){
        int front = q.front() ;
        q.pop() ;
        if(front == dest) present = true ;

        for(auto neighbor : adj[front]){
            if(!visited[neighbor]){
                q.push(neighbor) ;
                visited[neighbor] = true ;
                parent[neighbor] = front ;
            }
        }
        
    }

    vector<int> ans ;
    if(!present) return ans ;
    int current = dest ;
    ans.push_back(current) ;
    while(current != src){
        current = parent[current] ;
        ans.push_back(current) ;
    }

    return ans ;
}

int main(){
    return 0 ;
}