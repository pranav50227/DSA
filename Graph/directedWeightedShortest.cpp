#include<bits/stdc++.h>
using namespace std ;

#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    void printAdj() {
        for(auto i : adj) {
            cout << i.first << "->";
            for(auto j : i.second) {
                cout << " " << j.first << "(" << j.second << "),";
            }
            cout << endl;
        }
    }

    void topologicalSortUtil(int node, unordered_map<int, bool>& visited, stack<int>& s) {
        visited[node] = true;
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor.first]) {
                topologicalSortUtil(neighbor.first, visited, s);
            }
        }
        s.push(node);
    }

    void shortestPath(int src, int n) {
        stack<int> s;
        unordered_map<int, bool> visited;
        
        // Perform topological sort
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                topologicalSortUtil(i, visited, s);
            }
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Process vertices in topological order
        while(!s.empty()) {
            int u = s.top();
            s.pop();

            // Update distances of all adjacent vertices
            if(dist[u] != INT_MAX) {
                for(auto neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if(dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Print the shortest distances
        for(int i = 0; i < n; i++) {
            if(dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdj();

    int n = 6; // Number of vertices
    int src = 1;
    // g.shortestPath(src, n);

    return 0;
}