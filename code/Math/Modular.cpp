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
// a^p mod m = a^(p mod (m-1)) mod m
ll p  = (powmod(2, n, mod-1) - 1 + (mod-1)) % (mod-1);
// Fermat's little theorem: a^(p-1) = 1 mod p, if p is prime and a is not divisible by p