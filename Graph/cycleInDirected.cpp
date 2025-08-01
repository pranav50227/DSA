#include<bits/stdc++.h>
using namespace std ;

bool checkCycleDfs(int node ,  unordered_map<int , bool > & visited , unordered_map<int , bool > & dfsVisited , unordered_map<int , list<int>> & adj ){
    visited[node] = true ;
    dfsVisited[node] = true ;

    for(auto neighbor : adj[node]){
        if(!visited[neighbor]){
            if(checkCycleDfs(neighbor , visited , dfsVisited , adj)) return true ;
        }else if(dfsVisited[neighbor]) return true ;
    }

    dfsVisited[node] = false ;
    return false ;
}

bool cycleDetection(vector<vector<int>> & edges , int n , int m){
    unordered_map<int , list<int>> adj ;
    for(int i=0 ; i<m ; i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
    }

    unordered_map<int , bool > visited ;
    unordered_map<int , bool > dfsVisited ;

    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            if(checkCycleDfs( i , visited , dfsVisited , adj)) return true ;
        }
    }

    return false ;
}


// Cycle detection in a directed graph using bfs algorithm
// If we take the kahn's algorithm for topological sort and check if the size of the returning vector is equal to 
// the number of nodes - if it is true than it does not have a cycle , while if the size is less than the number of 
// nodes than a cycle is present and thus some nodes weren't able to be reached 

bool topologicalSort(vector<vector<int>> & edges , int n , int m ){
    unordered_map<int , list<int>> adj ;
    vector< int > indegree(n+1) ;
    for(int i=0 ;i<m ; i++){
        int u = edges[i][0] ;
        int v = edges[i][0] ;
        indegree[v]++ ;
        adj[u].push_back(v) ;
    }

    queue<int> q ;
    for(int i=1 ; i<=n ; i++){
        if(indegree[i] == 0){
            q.push(i) ;
        }
    }

    // do bfs 
    vector<int> ans ;
    while(!q.empty()){
        int front = q.front() ;
        q.pop() ;
        ans.push_back(front) ;

        for(auto neighbor : adj[front]){
            indegree[neighbor]-- ;
            if(indegree[neighbor] == 0) q.push(neighbor) ;
        }
        
    }


    return ans.size() != n ;


}

int main(){
    return 0 ;
}