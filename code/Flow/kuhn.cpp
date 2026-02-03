// Problem: find a maximum matching in a bipartite graph (no two chosen edges share a vertex).
// Where to use: assignment problems, scheduling, pairing tasks/agents, Kőnig's theorem for
// minimum vertex cover in bipartite graphs, minimum path cover in DAGs (via reduction).
// Brief usage: set `n` = left size, `k` = right size; fill `g[0..n-1]` with right indices (0..k-1).
// Call: `mt.assign(k, -1); for (int v=0; v<n; ++v) { used.assign(n,false); try_kuhn(v); }`
// Result: `mt[r] = l` if right r matched with left l, else -1. Complexity: O(n*m).
int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;
bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}
int main() {
    //... reading the graph ...

    mt.assign(k, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }
    for (int i = 0; i < k; ++i)
        if (mt[i] != -1)
            printf("%d %d\n", mt[i] + 1, i + 1);
}