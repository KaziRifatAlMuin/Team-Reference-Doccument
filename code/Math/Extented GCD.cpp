// Extended GCD: finds gcd(a,b) and x,y such that a*x + b*y = gcd(a,b)
int gcdExt(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0; // base: a*1 + 0*0 = a
        return a;
    }
    int x1, y1;
    int g = gcdExt(b, a % b, x1, y1); // recurse
    x = y1; // transform back
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse: returns x where (a*x) % m = 1, exists only if gcd(a,m) = 1
int modInv(int a, int m) {
    int x, y;
    int g = gcdExt(a, m, x, y); // a*x + m*y = gcd(a,m), if g==1 then x is inverse
    return (x % m + m) % m; // normalize to positive
}
