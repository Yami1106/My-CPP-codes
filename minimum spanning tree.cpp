#include <iostream>
#include<bits/stdc++.h> 
using namespace std; 

typedef  pair<int, int> intPair; 

//Structure to represent a graph 
class Graph 
{ 
    public :
    int V, E; 
    vector< pair<int, intPair> > edges; 
    Graph(int V, int E) 
    { 
        this->V = V; 
        this->E = E; 
    } 
    //method to add an edge 
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
    //Function to find MST using kruskal 
    int kruskalAlgo(); 

}; 
 
class DisjointSets 
{ 
    public :
    int *parent, *rnk; 
    int n; 
    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1];  
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0;  
            parent[i] = i; 
        } 
    } 
    
    //Find the parent of a node 'u' 
    int find(int u) 
    {
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
        //Make tree with smaller height a subtree of the other tree 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else 
            parent[x] = y; 
        if (rnk[x] == rnk[y]) 
        	rnk[y]++; 
    } 
};

 /*Functions returns weight of the MST*/ 
int Graph::kruskalAlgo() 
{ 
    int mst_wt = 0;
    sort(edges.begin(), edges.end()); 
    
    DisjointSets ds(V); 
    vector< pair<int, intPair> >::iterator it; 
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 
        if (set_u != set_v) 
        {
            cout << u << " - " << v << endl; 
            mst_wt += it->first; 
            ds.merge(set_u, set_v); 
        } 
    } 
    return mst_wt; 
} 

int main() 
{ 
    // Graph size number of vertices and edges
    int V = 9, E = 14; 
    Graph graph(V, E); 
    graph.addEdge(0, 1, 4); 
    graph.addEdge(0, 7, 8); 
    graph.addEdge(1, 2, 8); 
    graph.addEdge(1, 7, 11); 
    graph.addEdge(2, 3, 7); 
    graph.addEdge(2, 8, 2); 
    graph.addEdge(2, 5, 4); 
    graph.addEdge(3, 4, 9); 
    graph.addEdge(3, 5, 14); 
    graph.addEdge(4, 5, 10); 
    graph.addEdge(5, 6, 2); 
    graph.addEdge(6, 7, 1); 
    graph.addEdge(6, 8, 6); 
    graph.addEdge(7, 8, 7); 
    cout << "Edges of Minimal Spanning Tree are "<<endl; 
    int sum = graph.kruskalAlgo(); 
    cout << "\nWeight of Minimal Spanning Tree is " << sum;
    return 7;
}