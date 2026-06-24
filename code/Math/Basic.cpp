// O(N log log N), spf[x] = smallest prime factor
void sieve() {
    for(int i = 1; i < N; i++) spf[i] = i;
    for(int i = 2; 1LL * i * i < N; i++) {
        if(spf[i] == i) { // prime
            for(int j = i * i; j < N; j += i)
                if(spf[j] == j) spf[j] = i;
        }
    }
    for(int i = 2; i < N; i++)
        if(spf[i] == i) primes.push_back(i);
}
// O(log n), returns {{prime,power},...}, n<N
vector<pair<int,int>> factor(int n){
    vector<pair<int,int>> f;
    while(n>1){
        int p=spf[n],cnt=0;
        while(n%p==0) n/=p,cnt++;
        f.push_back({p,cnt});
    }
    return f;
}
// O(pi(sqrt(n))), factorization up to 1e18
vector<pair<ll,int>> factorLL(ll n){
    vector<pair<ll,int>> f;
    for(int p:primes){
        if(1LL*p*p>n) break;
        if(n%p==0){
            int cnt=0;
            while(n%p==0) n/=p,cnt++;
            f.push_back({p,cnt});
        }
    }
    if(n>1) f.push_back({n,1});
    return f;
}
ll divisorCount(int n){
    ll ans=1;
    while(n>1){
        int p=spf[n],cnt=0;
        while(n%p==0) n/=p,cnt++;
        ans *= (cnt + 1);
    }
    return ans;
}
ll divisorSum(int n){
    ll ans=1;
    while(n>1){
        int p=spf[n],cnt=0;
        while(n%p==0) n/=p,cnt++;
        ll term=1,cur=1;
        for(int i=0;i<cnt;i++) cur*=p,term+=cur;
        ans*=term;
    }
    return ans; // SOD
}

// coprime = No common factors between two numbers except 1
// phi(n) = number of numbers less than n that are coprime with n
// phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
// phi(n) = n * ((p1 - 1)/p1) * ((p2 - 1)/p2) * ... * ((pk - 1)/pk)
// Here p1, p2, ... , pk - everyone devides n because they are prime divisors

// In this seive, phi[j] is always divisible by i (The Prime Factor)
// O(N log log N), phi[i] = number of integers less than i that are coprime with i
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

// O(log n), returns phi(n) using smallest prime factor
ll phi(int n){
    ll res=n;
    while(n>1){
        int p=spf[n];
        res-=res/p;
        while(n%p==0) n/=p;
    }
    return res;
}

// O(log n), mobius(n)=0 if square factor exists, else (-1)^(#distinct primes)
int mobius(int n){
    int cnt=0;
    while(n>1){
        int p=spf[n],pw=0;
        while(n%p==0) n/=p,pw++;
        if(pw>1) return 0;
        cnt++;
    }
    return cnt&1?-1:1;
}