#include<bits/stdc++.h>
using namespace std ;

bool isCyclicBfs(int src , unordered_map<int , bool> &visited ,unordered_map<int , list<int>> &adj ){
    unordered_map<int , int> parent ;
    parent[src] = -1 ;
    visited[src] = 1 ;
    queue<int> q ;
    q.push(src) ;

    while(!q.empty()){
        int front = q.front() ;
        q.pop() ;

        for(auto neighbor : adj[front]){
            if(visited[neighbor] == true && neighbor != parent[front]) return true ;
            else if(!visited[neighbor]){
                q.push(neighbor) ;
                visited[neighbor] = 1 ;
                parent[neighbor] = front ;
            }
        }
    }

    return false ;
}

bool isCyclicDfs(int src , int parent , unordered_map<int , bool> &visited ,unordered_map<int , list<int>> &adj ){
    visited[src] = 1 ;

        for(auto neighbor : adj[src]){
             if(!visited[neighbor]){ 
                if(isCyclicDfs(neighbor , src , visited , adj )) return true ;
            }else if( neighbor != parent) return true ;
    }

    return false ;
}

bool cycleDetection(vector<vector<int>> & edges , int n , int m){
    unordered_map<int , list<int>> adj ;
    for(int i=0 ; i<m ; i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;  
    }

    unordered_map<int , bool> visited ;
    for(int i=0 ; i<n ; i++){
        if(!visited[i]){
           if(isCyclicBfs(i , visited , adj)) return true ;
           // if(isCyclicDfs(i , -1 , visited , adj)) return true ;
        }
    }

    return false ;
}

int main(){

    return 0 ;
}