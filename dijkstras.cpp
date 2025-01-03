#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int V, vector<pair<int, int>> adj[], int src) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\tINF\n";
        } else {
            cout << i << "\t" << dist[i] << "\n";
        }
    }
}

int main() {
    int V = 4;
    int E = 5;

    vector<pair<int, int>> adj[V];
    adj[0].push_back({1, 10});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[1].push_back({0, 10});
    adj[1].push_back({3, 15});
    adj[2].push_back({0, 6});
    adj[2].push_back({3, 4});
    adj[3].push_back({0, 5});
    adj[3].push_back({1, 15});
    adj[3].push_back({2, 4});

    int src = 0;

    dijkstra(V, adj, src);

    return 0;
}
