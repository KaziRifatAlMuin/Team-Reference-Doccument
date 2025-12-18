#define ckbit(n, k) ((n) & (1LL << (k)))
#define toggle(n, k) ((n) ^= (1LL << (k)))    
#define setbit(n, k) ((n) |= (1LL << (k)))     
#define unsetbit(n, k) ((n) &= ~(1LL << (k))) 
#define lowbit(n) ((n) & -(n))  
#define highbit(n) (63 - __builtin_clzll(n))
// ----- Iterate Submasks (non-zero) -----
#define ForSubmask(s, m)  for (ll s = (m); s; s = (s - 1) & (m))
// ----- Iterate Supersets of m inside [0, 1<<n) -----
#define ForSuperset(s, m, n)  for (ll s = (m); s < (1LL << (n)); s = (s + 1) | (m))
// ----- Gosper's Hack — next mask with same popcount -----
inline ll NextCombination(ll x){
    ll u = x & -x;
    ll v = x + u;
    return v + (((v ^ x) / u) >> 2);
}
// XOR Properties
a | b = a ^ b + a & b
a ^ (a & b) = (a | b) ^ b
b ^ (a & b) = (a | b) ^ a
(a & b) ^ (a | b) = a ^ b
// Addition
a + b = a | b + a & b
a + b = a ^ b + 2(a & b)
// Subtraction
a - b = (a ^ (a & b)) - ((a | b) ^ a)
a - b = ((a | b) ^ b) - ((a | b) ^ a)
a - b = (a ^ (a & b)) - (b ^ (a & b))
a - b = ((a | b) ^ b) - (b ^ (a & b))
// Precompute XOR from 1 to n
ll prexor(ll n){
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0;
}
// Bit Hacks
# x & -x is the least bit in x.
# iterate over all the subsets of the mask
for (int s=m; ; s=(s-1)&m) {
 ... you can use s ...
 if (s==0)  break;
}
# c = x&-x, r = x+c; (((rˆx) >> 2)/c) | r is the
next number after x with the same number of bits set.
# __builtin_popcount(x) //number of ones in binary
  __builtin_popcountll(x) // for long long
# __builtin_clz(x) // number of leading zeros
  __builtin_ctz(x) // number of trailing zeros, they also have long long version

// __int128 for 128 bit integer operations