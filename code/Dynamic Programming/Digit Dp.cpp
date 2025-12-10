ll dp[20][20][2]; // How many zeros
ll digitDP(const string &num, ll pos = 0, ll cnt = 0, bool tight = 1, bool isStart = 1){
    if(pos == num.size()) return isStart ? 1 : cnt;
    else if(dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
    ll ans = 0, lim = tight ? num[pos] - '0' : 9;
    for(int digit = 0; digit <= lim; digit++){
        ans += digitDP(num, pos + 1, cnt + (!isStart && digit == 0), tight && digit == lim, isStart && digit == 0);
    }
    return isStart ? ans : dp[pos][cnt][tight] = ans;
}
void solve() {
    ll l, r;
    cin >> l >> r;
    memset(dp, -1, sizeof(dp)); 
    ll ans1 = digitDP(to_string(r));
    memset(dp, -1, sizeof(dp));
    ll ans2 = digitDP(to_string(l - 1));
    cout << ans1 - ans2 << "\n";
}