#include<bits/stdc++.h>
using namespace std ;
// Topological Sort using the Kahn's Algorithm 
// It's also known as TS using bfs 
vector<int> topologicalSort(vector<vector<int>> & edges , int n , int m ){
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


    return ans ;


}

int main(){

    return 0 ;
}