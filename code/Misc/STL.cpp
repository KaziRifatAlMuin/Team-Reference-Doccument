// ---------- PBDS ----------
*st.find_by_order(k);                 // k-th smallest (0-indexed)
st.order_of_key(x);                   // count < x
// ---------- SET / MAP ----------
s.lower_bound(x);                     // first >= x
s.upper_bound(x);                     // first > x
prev(s.upper_bound(x));               // largest <= x
*s.rbegin();                          // largest element
mp.lower_bound(x); mp.upper_bound(x); // first >= x, first > x
// ---------- VECTOR ----------
sort(all(v));
v.erase(unique(all(v)),v.end());      // unique
rotate(all(v),v.begin()+k);           // left rotate k
partial_sort(v.begin(),v.begin()+k,v.end());
// ---------- PERMUTATION ----------
next_permutation(all(v));
prev_permutation(all(v));
// ---------- TUPLE ----------
auto [a,b,c] = t;
get<0>(t); get<1>(t);
// ---------- HEAP ----------
priority_queue<int> mx;
priority_queue<int,vector<int>,greater<int>> mn;
// ---------- REMOVE ----------
v.erase(remove(all(v),x),v.end()); // O(n)
v.erase(remove_if(all(v),pred),v.end());
// ---------- STRING ----------
stoi(s); stoll(s);
to_string(x);
stringstream ss(s);
// ---------- MIN/MAX ----------
*max_element(all(v));
*min_element(all(v));
auto [mn,mx] = minmax_element(all(v));
// ---------- COORD COMP ----------
sort(all(v));
v.erase(unique(all(v)),v.end());
id = lower_bound(all(v),x)-v.begin();