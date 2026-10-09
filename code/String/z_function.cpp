vector<ll> z_function(string& s){
    ll n=s.size(); vector<ll>z(n);
    z[0]=n; ll l=0,r=0;
    for(ll i=1;i<n;i++){  
        if(i<r)z[i]=min(z[i-l],r-i);
        if(z[i]<r-i)continue;
        for(ll j=max(r,i);j<n;j++){
            if(s[j]==s[j-i])z[i]++;
            else break;
        }
        l=i; r=i+z[i];
    }
    return z;
}