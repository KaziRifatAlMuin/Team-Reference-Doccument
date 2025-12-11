const int N = 1e5 + 7, mod = 1e9 + 7;
ll cnt[N];  // cnt[x] = frequency of x in the input
ll d[N];    // d[i]   = # of input elements divisible by i
ll f[N];    // f[i]   = # of non-empty subseq’s all divisible by i
ll mob[N];  // Mobius function mu(i)
ll power(ll a, ll b) { }
void coprime_subsequence_mobius(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        cnt[x]++;
    }
    mob[1] = 1;
    for(int i = 1; i < N; i++){
        for(int j = i + i; j < N; j += i){
            mob[j] -= mob[i];
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            d[i] += cnt[j];
        }
    }
    ll ans = 0;
    for(int i = 1; i < N; i++){
        if(d[i] == 0 || mob[i] == 0) continue;  // nothing to add/subtract
        f[i] = (power(2, d[i]) - 1 + mod) % mod; // number of non-empty subsequences from d[i]
        ans = ((ans + mob[i] * f[i]) % mod + mod) % mod; // inclusion–exclusion using mobius
    }
    cout << ans << "\n";
}