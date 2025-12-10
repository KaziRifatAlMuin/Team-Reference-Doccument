// unbounded knapsack: ascending
for(auto x : v){ 
    for(int i = x; i <= N; i++){
        dp[i] = (dp[i] + dp[i-x]) % mod;
    }
}
// bounded knapsack: descending
for(auto x : v){ 
    for(int i = N; i >= x; i--){
        dp[i] = (dp[i] + dp[i-x]) % mod;
    }
}