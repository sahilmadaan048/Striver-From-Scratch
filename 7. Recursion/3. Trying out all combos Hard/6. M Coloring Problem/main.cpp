/*
Given an integer M and an undirected graph with N vertices and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.



In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.


Examples:
Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]

Output : true

Explanation : Consider the three colors to be red, green, blue.

We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.

In this way we can color graph using 3 colors at most.



Input : N = 3 , M = 2 , E = 3 , Edges = [ (0, 1) , (1, 2) , (0, 2) ]

Output : false

Explanation : Consider the three colors to be red, green.

We can color the vertex 0 with red, vertex 1 with blue.

As the vertex 2 is adjacent to both vertex 1 and 0 , so we cannot color with red and green.

Hence as we could not color all vertex of graph we return false.




*/


// https://takeuforward.org/plus/dsa/problems/m-coloring-problem

// https://takeuforward.org/data-structure/m-coloring-problem/

#include<bits/stdc++.h>

using namespace std;
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  for (int k = 0; k < n; k++) {
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  if (node == N) {
    return true;
  }

  for (int i = 1; i <= m; i++) {
    if (isSafe(node, color, graph, N, i)) {
      color[node] = i;
      if (solve(node + 1, color, m, N, graph)) return true;
      color[node] = 0;
    }

  }
  return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {
    0
  };
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

int main() {
  int N = 4;
  int m = 3;

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}
// Output: 1

// Time Complexity: O( N^M) (n raised to m)
// Space Complexity: O(N)