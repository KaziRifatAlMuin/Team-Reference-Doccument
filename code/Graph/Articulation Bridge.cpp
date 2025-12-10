int timer = 0;
vector <int> G[N];
bool visited[N];
int disc[N], low[N];
vector <pair <int, int>> bridges;

void DFS(int v, int par = -1){
    visited[v] = true;
    disc[v] = low[v] = timer;
    timer++;
    for(auto child : G[v]){
        if(!visited[child]){
            DFS(child, v);
            low[v] = min(low[child], low[v]);
            if(disc[v] < low[child]){
                bridges.push_back({min(v,child), max(v, child)});
            }
        }
        else{
            if(child == par) continue;
            low[v] = min(low[child], low[v]);
        }
    }
}