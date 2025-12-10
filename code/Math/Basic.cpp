// a + ar + ar^2 + ar^3 + ... + ar^n-1 = a(r^(n) - 1) / (r - 1)
// 1 + a + a^2 + a^3 + a^4 + .... + a^(n-1) = (a^n - 1) / (a - 1)

// 1 + a + a^2 + a^3 + a^4 + a^5 = 1 + a^2 + (a^2)^2 + a(1 + a^2 + (a^2)^2) 
// bigsum(a, 6) = bigsum(a^2, 3) + a * bigsum(a^2, 3)
// 1 + a + a^2 + a^3 + a^4 = 1 + a(1 + a + a^2 + a^3)
// bigsum(a, 5) = 1 + a * bigsum(a, 4)

ll bigsum(ll a, ll n) {
    if(n == 0 || n == 1) return n % mod;
    if(n & 1) return ((a % mod) * bigsum(a % mod, n - 1) + 1) % mod;
    ll x = bigsum((a * a) % mod, n / 2);
    return (x + (a * x) % mod) % mod;
}

ll power(ll a, ll b) {
    ll result = 1;
    a = a % mod;
    while (b > 0){
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1ll;
    }
    return result;
}

inline ll modInverse(ll a) { return power(a, mod - 2); }

ll formula(ll a, ll n){
    if(a == 1) return n;
    return ((power(a, n) - 1) * (modInverse(a - 1))) % mod; // if mod is prime
}

int NotPrime[N], phi[N];
// coprime = No common factors between two numbers except 1
// phi(n) = number of numbers less than n that are coprime with n
// phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
// phi(n) = n * ((p1 - 1)/p1) * ((p2 - 1)/p2) * ... * ((pk - 1)/pk)
// Here p1, p2, ... , pk - everyone devides n because they are prime divisors
// In this seive, phi[j] is always divisible by i (The Prime Factor)
void seivePhi(){
    for(int i = 1; i < N; i ++) phi[i] = i;
    NotPrime[1] = 1;
    for(int i = 2; i < N; i++){
        if(!NotPrime[i]){
            for(int j = i; j < N; j += i){
                NotPrime[j] = 1;
                phi[j] = (phi[j] / i) * (i - 1); 
            }
        }
    }
}
// Properties of Phi :
//     1. if p is a prime number, phi[p] = p - 1;
//     2. if p is a prime number and n is a positive integer, phi[p^n] = p^n - p^(n-1);
//     3. if a and m are coprime, a^phi[m] = 1 mod m (Euler's Theorem)
//     4. if a and m are coprime and m is prime, a^(m-1) = 1 mod m (Fermat's little theorem)

int phi(int n){
    int ans = n;
    for(int i = 2; 1ll * i * i <= n; i++){
        if(n % i == 0){ // i is prime
            while(n % i == 0){
                n /= i;
            }
        }
        ans -= (ans / i); // n * (1 - 1/p1) -> (n - n/p1)
    }
    if(n > 1){
        ans -= (ans / n); // there can be only one prime factor > sqrt(n)
    }
    return ans;
}

int spf[N];
vector <int> primes;

void sieve() {
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; 1ll * i * i < N; i++) {
        if(spf[i] == i) { // i is prime
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    for(int i = 2; i < N; i++){
        if(spf[i] == i) primes.push_back(i);
    }
}
vector <pair<ll,ll>> factor(ll n) {
    vector <pair<ll,ll>> fact;
    for(auto p : primes){
        if(1ll * p * p > n) break;
        if(n % p == 0){
            ll power = 0;
            while(n % p == 0){
                n /= p;
                power++;
            }
            fact.push_back({p, power});
        }
    }
    if(n > 1) fact.push_back({n, 1});
    return fact;
}

// Modular Arithmetic Functions
static inline ll mulmod(ll a, ll b, ll m) {
    a %= m; b %= m;
    return (ll)((__int128)a * b % m);
}
ll powmod(ll a, long long b, ll m) {
    a %= m;
    if (a < 0) a += m;
    ll res = 1 % m;
    while (b > 0) {
        if (b & 1) res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }
    return res;
}

ll modMul(ll a, ll b) { return mulmod(a, b, mod); }
ll modAdd(ll a, ll b) { return ( (a%mod) + (b%mod) ) % mod; }
ll modSub(ll a, ll b) { return ( (a%mod) - (b%mod) + mod ) % mod; }
ll modInverse(ll a)   { return powmod((a%mod+mod)%mod, mod-2, mod); }
ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

// Exponents reduced modulo (mod-1)
ll p  = (powmod(2, n, mod-1) - 1 + (mod-1)) % (mod-1);
