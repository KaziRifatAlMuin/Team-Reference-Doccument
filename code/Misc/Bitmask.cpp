// ----- Basic Bit Operations -----
#define SetBit(x, k)      ( x |=  (1LL << (k)) )
#define ClearBit(x, k)    ( x &= ~(1LL << (k)) )
#define ToggleBit(x, k)   ( x ^=  (1LL << (k)) )
#define CheckBit(x, k)    ( ((x) >> (k)) & 1LL )

#define to_Binary(n)      ( bitset<8>(n).to_string() )
#define LowBit(x)         ( (x) & -(x) )                         // lowest 1-bit value
#define LowBitIndex(x)    ( __builtin_ctzll(x) )                 // index of lowest 1-bit
#define HighBitIndex(x)   ( 63 - __builtin_clzll(x) )            // index of highest 1-bit
#define CountBits(x)      ( __builtin_popcountll(x) )

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
