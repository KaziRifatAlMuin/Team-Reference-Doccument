#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// greater for descending, less_equal for muiltiset
typedef long long ll;
// Count inversions in array using PBDS - O(n log n)
// Returns number of pairs (i, j) where i < j and arr[i] > arr[j]
template <class T>
ll countInversions(vector<T> &arr) {
    ll inv = 0;
    pbds<T> pset;
    for(int i = arr.size() - 1; i >= 0; i--) { // traverse from right to left
        inv += pset.order_of_key(arr[i]); // count elements < arr[i] in right side
        pset.insert(arr[i]);
    }
    return inv;
}