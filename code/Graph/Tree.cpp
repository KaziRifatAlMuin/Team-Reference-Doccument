// Tree DFS Basic Structure
void dfs(int u, int par = -1){
    // process u's information
    for(auto v : G[u]){
        if(v == par) continue;
        // process edge u-v's information
        // process v's information
        dfs(v, u);
        // process child v's information to update u's information
    }
    // process u's information after processing all children
}
// Common Tricks for tree dfs/dp on trees
// 1. To find the parent of each node, pass the parent as a parameter in the dfs function.
// 2. To find the depth of each node, pass the depth as a parameter in the dfs function.
// 3. To find the size of each subtree, maintain a size array and update it during the dfs.
// 4. To find the maximum depth of each subtree, maintain a max_depth array and update it during the dfs.
// 5. To find the sum of values in each subtree, maintain a sum array and update it during the dfs.
// 6. To find the answer for each node based on its children, maintain a dp array and update it during the dfs.
// 7. To find the answer for each node based on its parent, maintain a dp array and update it during the dfs.
vector <ll> depth, a, sub, dp1, dp2, max_depth;
void dfs1(int u, int par = -1){
    sub[u] += a[u];
    max_depth[u] = depth[u];
    for(auto v : G[u]){
        if(v == par) continue;
        depth[v] = depth[u] + 1;
        dfs1(v, u);
        sub[u] += sub[v];
        max_depth[u] = max(max_depth[u],  max_depth[v]);
        dp1[u] += (dp1[v] + sub[v]);
    }
}
void dfs2(int u, int par = -1){
    ll f = 0, s = 0;
    for(auto v : G[u]){
        if(v == par) continue;
        if(f < max_depth[v]) s = f, f = max_depth[v];
        else if(s < max_depth[v]) s = max_depth[v];
    }
    for(auto v : G[u]){
        if(v == par) continue;
        dfs2(v, u);
        // take best among: previous answer, best inside child, or cutting this child
        if(max_depth[v] != f) dp2[u] = max({dp2[u], dp2[v], sub[v] * (f+1-depth[v])});
        else dp2[u] = max({dp2[u], dp2[v], sub[v] * (s+1-depth[v])});
    }
}