#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int parent[10000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= V; ++i) {
        parent[i] = i;
    }

    int total_weight = 0;

    for (const Edge& edge : edges) {
        if (find(edge.from) != find(edge.to)) {
            union_set(edge.from, edge.to);
            total_weight += edge.weight;
        }
    }

    cout << total_weight << "\n";
    return 0;
}
