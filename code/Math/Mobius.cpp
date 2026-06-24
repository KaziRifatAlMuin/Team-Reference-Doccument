// O(N log log N), # of non-empty subsequences of input with gcd = 1
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
// mu[1]=1, mu[n]=0 if square factor exists, else (-1)^(#distinct prime factors)
// sum(mu[d]) over divisors of n = (n==1)            // Mobius identity
// if f(n)=sum(g(d)) over divisors d, recover g using Mobius inversion
// gcd(a,b)==1 => sum(mu[d]) over divisors of gcd(a,b)
// coprime pairs => sum(mu[d] * C(cnt[d],2))
// coprime subsequences => sum(mu[d] * (2^cnt[d]-1))
// gcd exactly k => sum(mu[d] * C(cnt[k*d],2))
// exact gcd count => exact[g] = sum(mu[d] * multiple[g*d])
// phi(n) = sum(mu[d] * (n/d)) over divisors d of n
// keywords: gcd=1, coprime, exact gcd, lcm, divisor inversion => think Mobius