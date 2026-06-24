int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int n, m, ans = 0;
vector<pair<int,int>> fire;
vector<vector<int>> firetime;
vector<vector<bool>> visited;
vector<vector<char>> s;
bool isvalid(int x, int y, int timer){
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    if(firetime[x][y] <= timer) return false;
    return true;
}
bool isfree(int x, int y, int timer){
    if(!isvalid(x, y, timer)) return false;
    if(x == 0 || y == 0 || x == n - 1 || y == m - 1) return true;
    return false;
}
void firebfs(){
    queue <tuple<int,int,int>> q;
    for(auto [x,y] : fire){
        q.push({x, y, 0});
    }
    while(!q.empty()){
        auto[r, c, timer] = q.front();
        timer++; q.pop();
        for(int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(isvalid(rr, cc, timer)){
                firetime[rr][cc] = timer;
                q.push({rr, cc, timer});
            }
        }
    }
}
bool escapebfs(int sr, int sc){
    queue <tuple<int,int,int>> q;
    q.push({sr, sc, 0});
    visited[sr][sc] = true;
    while(!q.empty()){
        auto[r, c, timer] = q.front();
        timer++; q.pop();
        for(int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(isfree(rr, cc, timer)){
                ans = timer;
                return true;
            }
            if(isvalid(rr, cc, timer) && !visited[rr][cc]){
                visited[rr][cc] = true;
                q.push({rr, cc, timer});
            }
        }
    }
    return false;
}
// Minimum number of elements product is exactly equal to i
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
for(auto x : v){
    if(x <= n) dist[x] = 1, q.push(x);
}
while(!q.empty()){
    ll cur = q.front();
    q.pop();
    for(auto x : v){
        if(cur * x > n) break;
        ll xx = cur * x;
        if(dist[xx] == -1){
            dist[xx] = dist[cur] + 1;
            q.push(xx);
        }
    }
}