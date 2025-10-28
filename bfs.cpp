#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS traversal from source node
void bfs(vector<vector<int>>& adj, int src, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    cout << "BFS from node " << src << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    // building undirected graph
    adj[0].push_back(1); adj[1].push_back(0);
    adj[0].push_back(2); adj[2].push_back(0);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[3].push_back(5); adj[5].push_back(3);
    adj[4].push_back(5); adj[5].push_back(4);

    bfs(adj, 0, n);

    return 0;
}
