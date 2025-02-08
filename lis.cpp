#include "bits/stdc++.h"
using namespace std;
#define int long long

// Function to compute the length of the Longest Increasing Subsequence (LIS)
int lengthOfLIS(vector<int>& v) {
    const int INF = INT32_MAX;  // Use INT32_MAX as a large value
    int n = v.size();
    vector<int> d(n + 1, INF);
    d[0] = -INF;  // Dummy value to ease comparisons

    // For each element in v, update d using upper_bound
    for (auto a : v) {
        int i = upper_bound(d.begin(), d.end(), a) - d.begin();
        if (i <= n && d[i - 1] < a)
            d[i] = a;
    }
    
    int i = 0;
    while (i <= n && d[i] != INF)
        i++;
    return i - 1;  // Subtract 1 because d[0] is a dummy
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;  // Number of elements in the array
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << lengthOfLIS(v) << "\n";
    return 0;
}
