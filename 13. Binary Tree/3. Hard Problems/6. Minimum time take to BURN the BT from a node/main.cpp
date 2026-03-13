// https://www.geeksforgeeks.org/problems/burning-tree/1


// https://www.geeksforgeeks.org/dsa/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void buildGraph(TreeNode* node, TreeNode* parent,
                    unordered_map<int, vector<int>>& graph){

        if(!node) return;

        if(parent){
            graph[node->val].push_back(parent->val);
            graph[parent->val].push_back(node->val);
        }

        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }

    int minTime(TreeNode* root, int target) {

        unordered_map<int, vector<int>> graph;

        buildGraph(root, nullptr, graph);

        queue<int> q;
        unordered_set<int> vis;

        q.push(target);
        vis.insert(target);

        int time = 0;

        while(!q.empty()){

            int size = q.size();
            bool burned = false;

            for(int i=0;i<size;i++){

                int node = q.front();
                q.pop();

                for(auto nbr: graph[node]){

                    if(!vis.count(nbr)){

                        vis.insert(nbr);
                        q.push(nbr);
                        burned = true;
                    }
                }
            }

            if(burned) time++;
        }

        return time;
    }
};

int main() {
    Solution sol;
    // make the graph and then call thw function
}

/*  time  => O(n) => do 2 full traversal s of the tree

in the first one, make the graph
in the second one, starting from the target we simulate the spreading of fire using BGS

    space  => O(n) 

we use an adjacency list to store the graoh => o(n)
a visited array is made => o(n)
bfs queue at any time will store atmax N elements so => O(n)    

*/