#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define edge pair<int, int>
#define graph vector<pair<int, edge>>

graph input;
graph mst;
vector<int> parent;

void addWeightedEdge(int u, int v, int w) {
    input.push_back(make_pair(w, edge(u, v)));
}

int findSet(int i) {
    if (i == parent[i])
        return i;
    else
        return findSet(parent[i]);
}

void unionSet(int u, int v) {
    parent[u] = parent[v];
}

void kruskal() {
    sort(input.begin(), input.end());

    for(int i = 0; i < input.size(); i++) {
        int u = findSet(input[i].second.first);
        int v = findSet(input[i].second.second);
        if (u != v) {
            mst.push_back(input[i]);
            unionSet(u, v);
        }
    }
}

int main(){
    int V = 5;
   
    for (int i = 0; i < V; i++) {
        parent.push_back(i);
    }

    addWeightedEdge(0, 3, 13);
    addWeightedEdge(0, 1, 24);
    addWeightedEdge(0, 4, 22);
    addWeightedEdge(0, 2, 13);
    addWeightedEdge(2, 0, 13);
    addWeightedEdge(2, 3, 19);
    addWeightedEdge(2, 1, 22);
    addWeightedEdge(2, 4, 14);
    addWeightedEdge(2, 4, 14);
    addWeightedEdge(4, 2, 14);
    addWeightedEdge(4, 0, 22);
    addWeightedEdge(4, 3, 19);
    addWeightedEdge(4, 1, 13);
    addWeightedEdge(1, 4, 13);
    addWeightedEdge(1, 2, 22);
    addWeightedEdge(1, 0, 24);
    addWeightedEdge(1, 3, 11);
    addWeightedEdge(3, 1, 13);
    addWeightedEdge(3, 4, 19);
    addWeightedEdge(3, 2, 19);
    addWeightedEdge(3, 0, 13);


    kruskal();
    cout << "Edge :" << " Weight" << endl;
    for (int i = 0; i < mst.size(); i++)
    {
        cout << mst[i].second.first << " - " << mst[i].second.second << " : "
             << mst[i].first;
        cout << endl;
    }

    return 0;
}