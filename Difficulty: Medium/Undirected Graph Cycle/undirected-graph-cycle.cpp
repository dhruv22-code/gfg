class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                if (dfs(nei, node, adj, visited)) return true;
            } else if (nei != parent) {
                return true; // found a back edge
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};
