int gpf[N];
ll SOD[N];

void seive(){ // O(N log log N)
    gpf[1] = 1;
    for(int i = 2; i < N; i++){
        if(gpf[i] == 0){
            for(int j = i; j <= N; j += i){
                gpf[j] = i; // greatest prime factor
            }
        }
    }
}

void FindSOD(){ // sum of divisors up to N in O(N log log N)
    seive();
    for(int i = 2; i < N; i++){
        ll x = i;
        ll sod = 1;
        while(x > 1){
            ll p = gpf[x];
            ll mul = p;
            while(x % p == 0){
                x /= p;
                mul *= p; // mul = pi^ni (at the end of loop)
            }
            mul -= 1;
            mul /= (p-1); // geometric series: (p^(n+1)-1)/(p-1)
            sod *= mul;
        }
        SOD[i] = sod;
    }
}

ll NOD(ll n) {
    vector<pair<ll, ll>> fact = factor(n);
    ll divisors = 1;
    for(auto x : fact){
        divisors *= (x.second + 1);
    }
    return divisors;
}
