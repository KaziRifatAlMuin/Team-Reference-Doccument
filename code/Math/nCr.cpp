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

int f[N], invf[N];

void pre() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = 1LL * i * f[i - 1] % mod;
    }
    invf[N - 1] = power(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int r) {
    if (n < r or n < 0) return 0;
    return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}

// Catalan Number: 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, ...
// C(n) = (1 / (n + 1)) * (2n choose n) = (2n choose n) - (2n choose n + 1)
ll catalan = (nCr(2*n, n) % mod - nCr(2*n, n+1) % mod + mod) % mod;
// Hocky Stick Identity:
// sum_{k=r}^{n} (k choose r) = (n+1 choose r+1)
ll hockey_stick = nCr(n + 1, r + 1);
ll vandermonde = nCr(m + n, r);
ll C[N + 2][N + 2];
void pre(){
    C[0][0] = 1;
    for(int n = 1; n <= N; n++){
        C[n][0] = C[n][n] = 1;
        for(int k = 1; k < n; k++){
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }
}