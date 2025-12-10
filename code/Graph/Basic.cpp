struct info{
    ll v, w;
    bool const operator < (const info node) const{
        return w > node.w;
    }
};
void dijkstra(int start){
    fill(dist, dist + N, 1e17);
    dist[start] = 0;
    priority_queue <info> q;
    q.push({start, 0});
    while(!q.empty()){
        info cur = q.top();
        q.pop();
        if(cur.w > dist[cur.v]) continue;
        for(auto x : G[cur.v]){
            ll v = x.first;
            ll w = x.second;
            if(dist[v] > cur.w + w){
                dist[v] = cur.w + w;
                q.push({v, dist[v]});
            }
        }
    }
}
// BFS
while(!q.empty()){
    auto[r,c,face,time] = q.front(); q.pop();
    if(r == n-1 && c == n-1 && face == 0){
        cout << time << "\n";
        break;
    }
    int nr = r + dr[face], nc = c + dc[face];
    if(!visited[r][c][(face+1)%4]){
        q.push({r, c, (face+1)%4, time+1});
        visited[r][c][(face+1)%4] = true;
    }
    if(nr < 0 || nr >= n || nc < 0 || nc >= n || s[nr][nc] == '#' || visited[nr][nc][face]) continue;
    q.push({nr, nc, face, time+1});
    visited[nr][nc][face] = true;
}
// DP on Trees
void dfs(int u, int par = -1){
    for(auto v : G[u]){
        if(v == par) continue;
        dfs(v, u);  // FIRST solve child's dp
        // THEN use child's dp to update parent u's dp
        // accumulate into dp[u][0] (when a_u = L[u]):
        dp[u][0] += max(
            dp[v][0] + abs(L[u] - L[v]),   // child picks L[v]
            dp[v][1] + abs(L[u] - R[v])    // child picks R[v]
        );
        // accumulate into dp[u][1] (when a_u = R[u]):
        dp[u][1] += max(
            dp[v][0] + abs(R[u] - L[v]),   // child picks L[v]
            dp[v][1] + abs(R[u] - R[v])    // child picks R[v]
        );
        // Update dp[u] using best from children  
        // assuming a_u is L[u] or R[u]
    }
}
// Floyd Warshall
for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}

// MST - Kruskal
int Find(int x) {
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}
void Union(int x, int y) {
    int root_x = Find(x);
    int root_y = Find(y);
    if(root_x != root_y){
        parent[root_x] = root_y;
    }
}
ll Kruskal(vector <tuple<ll,ll,ll>> edges) {
    vector <tuple<ll,ll,ll>> MST;
    sort(edges.begin(), edges.end());
    ll sum = 0;
    for(auto [w, u, v] : edges){
        if(Find(u) != Find(v)){
            MST.push_back({w, u, v});
            Union(u, v);
            sum += w;
        }
        if(MST.size() == n - 1) break;
    }
    if(MST.size() == n - 1) return sum;
    else return -1;
}
// Topological Sort - Kahn's Algorithm
void kahn_topological_sort(){   
    queue <int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for(auto v : G[u]){
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }
}
