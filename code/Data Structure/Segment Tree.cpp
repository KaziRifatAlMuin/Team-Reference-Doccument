struct node{
    ll sum, maxi, mini;
    node() { sum = 0; maxi = -1e17; mini = 1e17; }
};
node tree[N*4];
node merge(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    ans.mini = min(a.mini, b.mini);
    ans.maxi = max(a.maxi, b.maxi);
    return ans;
}
void build(int id, int l, int r){ // (1, 0, n-1)
    if(l == r){
        tree[id] = node();
        return;
    }
    ll mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id + 1, mid+1, r);
    tree[id] = merge(tree[2*id], tree[2*id + 1]);
}
void update(int id, int l, int r, int pos, ll val){
    if(pos < l || pos > r) return;
    if(l == r){
        tree[id].sum = val;
        tree[id].mini = val;
        tree[id].maxi = val;
        return;
    }
    ll mid = (l+r)/2;
    update(2*id, l, mid, pos, val);
    update(2*id + 1, mid+1, r, pos, val);
    tree[id] = merge(tree[2*id], tree[2*id + 1]);
}
node query(int id, int l, int r, int lq, int rq){
    if(lq > r || rq < l) return node();
    if(l >= lq && r <= rq) return tree[id];
    ll mid = (l+r)/2;
    return merge(query(2*id, l, mid, lq, rq), query(2*id + 1, mid+1, r, lq, rq));
}