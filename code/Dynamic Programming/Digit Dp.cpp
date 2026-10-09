// 1. Generic Digit DP
const int MAXD=10,STATES=16;
ll freeTbl[MAXD+1][STATES]; bool freeVis[MAXD+1][STATES];
int combine(int st,int d){return st^d;}
ll base(int st){return st;}
int initState(){return 0;}
ll freeSum(int d,int st){
    if(!d)return base(st);
    if(freeVis[d][st])return freeTbl[d][st];
    freeVis[d][st]=1; ll res=0;
    for(int x=0;x<=9;x++)res=(res+freeSum(d-1,combine(st,x)))%MOD;
    return freeTbl[d][st]=res;
}
ll tightWalk(const string&s,int pos,int st){
    if(pos==s.size())return base(st);
    int hi=s[pos]-'0'; ll res=0;
    for(int d=0;d<hi;d++)res=(res+freeSum(s.size()-pos-1,combine(st,d)))%MOD;
    return (res+tightWalk(s,pos+1,combine(st,hi)))%MOD;
}
ll G(ll n){
    if(n<0)return 0;
    string s=to_string(n);
    return tightWalk(s,0,initState());
}
ll rangeQuery(ll l,ll r){return (G(r)-G(l-1)+MOD)%MOD;}
ll pointQuery(ll n){return G(n);}

// 2. Count zeros
ll dp[20][20][2][2];
ll digitDP(const string&num,ll pos=0,ll cnt=0,bool tight=1,bool isStart=1){
    if(pos==num.size())return isStart ? 1 : cnt;
    if(dp[pos][cnt][tight][isStart]!=-1)return dp[pos][cnt][tight][isStart];
    ll ans=0,lim=tight ? num[pos]-'0' : 9;
    for(int digit=0;digit<=lim;digit++)
        ans += digitDP(num,pos+1,cnt+(!isStart && digit==0),tight && digit==lim,isStart && digit==0);
    return dp[pos][cnt][tight][isStart]=ans;
}
void solve(){
    ll l,r; cin>>l>>r;
    memset(dp,-1,sizeof(dp)); ll ans1=digitDP(to_string(r));
    memset(dp,-1,sizeof(dp)); ll ans2=digitDP(to_string(l-1));
    cout<<ans1-ans2<<"\n";
}