class SegmentTree{
    ll n,funcid;
    vector<ll>seg,lazy;
    vector<ll>marked;
    void build(vector<ll>&a, ll segid, ll segl, ll segr, ll funid){
        if(segl==segr){
            seg[segid]=a[segl];
            return;
        }
        ll mid=(segl+segr)/2;
        build(a,segid*2,segl,mid,funid);
        build(a,segid*2+1,mid+1,segr,funid);
        seg[segid]=MONOID[funid](seg[segid*2],seg[segid*2+1]);
    }
    void build(ll*a, ll*b, ll segid, ll segl, ll segr, ll funid){
        if(segl==segr){
            seg[segid]=a[segl];
            return;
        }
        ll mid=(segl+segr)/2;
        build(a,b,segid*2,segl,mid,funid);
        build(a,b,segid*2+1,mid+1,segr,funid);
        seg[segid]=MONOID[funid](seg[segid*2],seg[segid*2+1]);
    }
    ll RangeCalc(ll segid, ll segl, ll segr, ll l, ll r, ll funid){
        if(segl>r||segr<l)return Identity[funid];
        if(segl>=l&&segr<=r)return seg[segid];

        ll mid=(segl+segr)/2;
        return MONOID[funid](RangeCalc(2*segid,segl,mid,l,r,funid),RangeCalc(2*segid+1,mid+1,segr,l,r,funid));
    }
    void PointUpdate(ll segid, ll segl, ll segr, ll id, ll x, ll funid){
        if(id<segl||id>segr)return;
        if(segl==segr){
            seg[segid]=x;
            return;
        }
        ll mid=(segl+segr)/2;
        PointUpdate(2*segid,segl,mid,id,x,funid);
        PointUpdate(2*segid+1,mid+1,segr,id,x,funid);
        seg[segid]=MONOID[funid](seg[segid*2],seg[segid*2+1]);
    }
    void RangeUpdate(ll segid, ll segl, ll segr, ll l, ll r, ll addval, ll funid2){
        if(segl>r||segr<l)return;
        if(segl>=l&&segr<=r){
            seg[segid]=MONOID[funid2](seg[segid],addval);
            return;
        }
        ll mid=(segl+segr)/2;
        RangeUpdate(segid*2,segl,mid,l,r,addval,funid2);
        RangeUpdate(segid*2+1,mid+1,segr,l,r,addval,funid2);
    }
    ll PointQuery(ll segid, ll segl, ll segr, ll id, ll funid2){
        if(id<segl||id>segr)return Identity[funid2];
        if(segl==segr)return seg[segid];
        ll mid=(segl+segr)/2;
        return MONOID[funid2](seg[segid],MONOID[funid2](PointQuery(segid*2,segl,mid,id,funid2),PointQuery(segid*2+1,mid+1,segr,id,funid2)));
    }
    void RangeUpdateAssignment(ll segid, ll segl, ll segr, ll l, ll r, ll assignval){
        if(segl>r||segr<l)return;
        if(segl>=l&&segr<=r){
            seg[segid]=assignval;
            marked[segid]=1;
            return;
        }
        if(marked[segid]){
            seg[segid*2]=seg[segid];
            seg[segid*2+1]=seg[segid];
            marked[segid*2]=marked[segid*2+1]=1;
            marked[segid]=0;
        }
        ll mid=(segl+segr)/2;
        RangeUpdateAssignment(segid*2,segl,mid,l,r,assignval);
        RangeUpdateAssignment(segid*2+1,mid+1,segr,l,r,assignval);
    }
    ll PointQueryAssignment(ll segid, ll segl, ll segr, ll id){
        if(segl==segr){
            return seg[segid];
        }
        if(marked[segid]){
            marked[segid]=0;
            seg[segid*2]=seg[segid];
            seg[segid*2+1]=seg[segid];
            marked[segid*2]=marked[segid*2+1]=1;
        }
        ll mid=(segl+segr)/2;
        if(id>=segl&&id<=mid){
            return PointQueryAssignment(segid*2,segl,mid,id);
        }
        else if(id>=mid+1&&id<=segr){
            return PointQueryAssignment(segid*2+1,mid+1,segr,id);
        }
    }
    void RangeUpdateforRangeQuery(ll segid, ll segl, ll segr, ll l, ll r, ll addval){
        if(segl>r||segr<l)return;
        if(segl>=l&&segr<=r){
            lazy[segid]+=addval;
            seg[segid]+=addval; //seg[segid]+=(segr-segl+1)*addval; //For SUM instead of MIN/MAX
            return;
        }
        lazy[segid*2]+=lazy[segid];
        lazy[segid*2+1]+=lazy[segid];
        seg[segid*2]+=lazy[segid];
        seg[segid*2+1]+=lazy[segid];
        lazy[segid]=0;//polapan gulare handover kore ami relaxed
        ll mid=(segl+segr)/2;
        RangeUpdateforRangeQuery(segid*2,segl,mid,l,r,addval);
        RangeUpdateforRangeQuery(segid*2+1,mid+1,segr,l,r,addval);
        //polapaner update howa shesh; ekhon ami update hoi: Dedication for children(Not all->shobaire dite gele Bura hoye jabo TLE) :)
        seg[segid]=MONOID[funcid](seg[segid*2],seg[segid*2+1]);
    }
    ll RangeQuery(ll segid, ll segl, ll segr, ll l, ll r){
        if(segl>r||segr<l)return Identity[funcid];
        if(segl>=l&&segr<=r){
            return seg[segid];
        }
        lazy[segid*2]+=lazy[segid];
        lazy[segid*2+1]+=lazy[segid];
        seg[segid*2]+=lazy[segid];
        seg[segid*2+1]+=lazy[segid];
        lazy[segid]=0;
        ll mid=(segl+segr)/2;
        return MONOID[funcid](RangeQuery(segid*2,segl,mid,l,r),RangeQuery(segid*2+1,mid+1,segr,l,r));
    } 
public:
    SegmentTree(vector<ll>&a,ll funid){
        funcid=funid;
        n=a.size();
        seg.resize(4*n);
        lazy.resize(4*n);
        marked.resize(seg.size());
        seg[0]=Identity[funcid];
        build(a,1,0,n-1,funid);
    }
    SegmentTree(ll*a, ll*b, ll funid){
        funcid=funid;
        n=b-a;
        seg.resize(4*n);
        lazy.resize(4*n);
        marked.resize(seg.size());
        seg[0]=Identity[funcid];
        build(a,b,1,0,n-1,funid);
    }
    ll RangeCalc(ll l,ll r){return RangeCalc(1,0,n-1,l,r,funcid);}
    void PointUpdate(ll id, ll x){PointUpdate(1,0,n-1,id,x,funcid);}
    void RangeUpdate(ll l, ll r, ll addval, ll funid2){RangeUpdate(1,0,n-1,l,r,addval,funid2);}
    ll PointQuery(ll id, ll funid2){return PointQuery(1,0,n-1,id,funid2);}
    void RangeUpdateAssignment(ll l, ll r, ll assignval){RangeUpdateAssignment(1,0,n-1,l,r,assignval);}
    ll PointQueryAssignment(ll id){return PointQueryAssignment(1,0,n-1,id);}
    void RangeUpdateforRangeQuery(ll l, ll r, ll addval){RangeUpdateforRangeQuery(1,0,n-1,l,r,addval);}
    ll RangeQuery(ll l, ll r){return RangeQuery(1,0,n-1,l,r);}
};