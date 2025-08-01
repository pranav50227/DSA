#include<bits/stdc++.h>
using namespace std ;

bool isCyclic(unordered_map<int , list<int>> & adj , int node , int parent , unordered_map<int , bool> & visited ){
    visited[node] = true ;
    for(auto neighbor : adj[node]){
        if(!visited[neighbor]){
            if(isCyclic(adj , neighbor , node , visited)) return true ;
        }else if(neighbor != parent) return true ;
    }

    return false ;
}

void Kruskal(vector<vector < pair<int , int >>> & edges , int m , int n){
    map<int , pair<int , int>> adj ;
    for(int i = 0 ; i<m ; i++){
        int v = edges[i][0].first ;
        int weight = edges[i][0].second ;
    }
}

int main(){

    return 0 ;
}