#include<bits/stdc++.h>
using namespace std ;

class Graph{
    public :
    unordered_map<int , list<pair<int , int>>> adj ; 
    
    void addEdge(int u , int v , int weight){
        adj[u].push_back(make_pair(v , weight)) ;
    }
  
};

vector<int> dijkstra(vector<vector<int>> &vec , int vertices , int edges , int  src ){
    unordered_map<int , list<pair<int , int>>> adj ;
    for(int i=0 ; i<edges ; i++){
        int u = vec[i][0] ;
        int v = vec[i][1] ;
        int w = vec[i][2] ;
        adj[u].push_back(make_pair(v , w)) ;
        adj[v].push_back(make_pair(u , w)) ;
    }

    vector<int> dist(vertices , INT_MAX) ;

    set<pair<int, int>> st ;
    dist[src]= 0 ;
    st.insert({0 , src}) ;

    while(!st.empty()){
        auto top = *st.begin() ;
        
        int nodeDist = top.first ;
        int topNode = top.second ;

        st.erase(st.begin()) ;

        for(auto neighbor : adj[topNode]){
            if(nodeDist + neighbor.second < dist[neighbor.first]){
                auto record = st.find(make_pair(dist[neighbor.first] , neighbor.first)) ;
                if(record != st.end()){
                    st.erase(record) ;
                }

                dist[neighbor.first] = nodeDist + neighbor.second ;
                st.insert(make_pair(dist[neighbor.first] , neighbor.first)) ;

        }
    }
}
}

vector<int> ShortestPathToAll( unordered_map<int , list<pair<int , int>>> &adj , int src ){
    vector<int> dist(adj.size() , INT_MAX) ;
    dist[src] = 0 ;
    set<pair<int , int>> s ;
    s.insert(make_pair(dist[src] ,src)) ;

    while(!s.empty()){
        pair<int,int> p = *s.begin();
        s.erase(s.begin()) ;
        int distance = p.first ;
        int node = p.second ;
        for(auto i : adj[node]){
            int neighbor = i.first ;
            int weight = i.second ;
            if(distance != INT_MAX){
                if(dist[neighbor] > distance + weight ){
                    dist[neighbor] = distance + weight ;
                    s.insert(make_pair(dist[neighbor] , neighbor)) ;
                }
            }
        }
    }

    return dist ;
}


int main(){



    return 0 ;
}