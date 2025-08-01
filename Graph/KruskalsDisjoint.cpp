#include<iostream>
#include<map>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std ;


// The time complexity of kruskal's algorithm is O(nlogn) 
// The space complexity of kruskal's algorithm is O(n)
// Application of the disjoint set 
class DisjointSet{
    private :
     struct Node{
        int parent ;
        int rank ;
     };

     unordered_map<int , Node> nodes ;

     public : 

     void makeSet(int x){
        if(nodes.find(x) == nodes.end()){
            nodes[x].parent = x ;
            nodes[x].rank = 0 ;
        }
     }

     int find(int x){
        if(nodes[x].parent != x){
            nodes[x].parent = find(nodes[x].parent) ;
        }
        return nodes[x].parent ;
     }

     void unionSet(int x , int y){
        int rootx = find(x) ;
        int rooty = find(y) ;

        if(rootx == rooty) return ;

        if(nodes[rootx].rank >= nodes[rooty].rank){
            nodes[rooty].parent = rootx ;
            nodes[rootx].rank++ ;
        }else{
            nodes[rootx].parent = rooty ;
            nodes[rooty].rank++ ;
        }

     }

     bool isConnected(int x , int y){
        return find(x) == find(y) ;
     }

};

bool cmp(vector<int> &a , vector<int> &b){
   return a[2] < b[2] ;
}

void makeSet(vector<int> &parent , vector<int>& rank , int  n ){
   for(int i=0 ; i<n ; i++){
      parent[i] = i ;
      rank[i] = 0 ;
   }
}

int findParent(vector<int> & parent , int node ){
   if(parent[node] == node){
      return node ;
   }

   return parent[node] = findParent(parent , parent[node]) ;
}

void unionSet(int u , int v ,vector<int> & rank , vector<int> & parent ){
   u = findParent(parent , u ) ;
   v = findParent(parent , v ) ;

   if(rank[u] < rank[v]){
      parent[u] = v ;
   }else if(rank[u] > rank[v]){
      parent[v] = u ;
   }else{
      parent[v] = u ;
      rank[u]++ ;
   }
}

int minimumSpanningTree(vector<vector<int>>& edges , int n){

   sort(edges.begin() , edges.end() , cmp) ;
   vector<int> parent(n) ;
   vector<int> rank(n) ;
   makeSet(parent , rank , n) ;

   int minWeight = 0 ;

   for(auto i : edges){
      int u = findParent(parent , i[0] ) ;
      int v = findParent(parent , i[1] ) ;

      if(u != v){
         minWeight += i[2] ;
         unionSet(u , v ,rank , parent) ;
      }
   }

   return minWeight ;

}

int main(){

}