// https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/

// https://www.youtube.com/watch?v=j1QDfU21iZk

/*

POINTS TO NOTE 

it will be an articulation point if and inly if

1. lets say w are in the DFS looking through the edges starting from vertex v != root
    if the current edge (v, to) is such that none of the vrticds to or its descendants un the DFS 
    traversal tree has a back edge to any of the ancestors of v, then v is
    an articulation point, otherwise v is not an articluation point

2. lets consider the remaining case of v = root. This vertex will be the point of articulation if any only if this verex has more than one child in the DFS tree

*/

// low[v] = min(tin[v], tin[p], low[to])

#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> adj;

vector<bool> visited;
vector<int> tin, low;

int timer;


// node and the parent
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer;
    timer++;

    int children = 0; // for rott condition it must have more than one chioldren for it to be aan articulation point

    for(int to: adj[v]) {
        if(to == p) continue;   // skip the parent
        if(visited[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);

            if(low[to] == tin[v] and p != -1) {
                IS_CUTPOINT(v);
            }
            ++children;
        }
    }

    // of root and more than one chuildren it means it is an articulation point 
 
    if(p == -1 && children > 1) {
        IS_CUTPOINT(v);
    } 

}


void find() {
    visites.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    return;
}

int main() {
    // graph banana hai
}


/*
TIME COMPLEXITY IS O(n+m)


*/