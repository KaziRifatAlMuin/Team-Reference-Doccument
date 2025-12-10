vector <ll> par, sum, diff, sz;
ll find(ll a) {
    if(par[a] == a) return a;
    ll root = find(par[a]); // recursion should be called first to update diff & par
    diff[a] += diff[par[a]]; // adds all parent offset
    return par[a] = root;
}
void merge(ll a, ll b){
    ll ra = find(a);
    ll rb = find(b);
    if(ra != rb){
        if(sz[ra] <= sz[rb]){
            par[ra] = rb;
            sz[rb] += sz[ra];
            diff[ra] = sum[ra] - sum[rb];
        }
        else{
            par[rb] = ra;
            sz[ra] += sz[rb];
            diff[rb] = sum[rb] - sum[ra];
        }
    }
}