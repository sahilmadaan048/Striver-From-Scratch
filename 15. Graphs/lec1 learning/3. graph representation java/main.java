class Solution {
    // Function to create and return adjacency list
    public List<List<Integer>> printGraph(int V, int edges[][]) {
        List<List<Integer>> adj = new ArrayList<>();
        
        // Initialize adjacency list for 'V' vertices
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Add edges to adjacency list
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u); // Since it's an undirected graph
        }

        return adj;
    }
}