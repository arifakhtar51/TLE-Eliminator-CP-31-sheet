#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>& a) {
    ll max_sum = accumulate(a.begin(), a.end(), 0LL); 
    while (a.size() > 1) {
    
        vector<ll> d1;
        for (int i = 1; i < a.size(); i++) {
            d1.push_back(a[i] - a[i - 1]);
        }

    
        vector<ll> d2;
        reverse(a.begin(), a.end());
        for (int i = 1; i < a.size(); i++) {
            d2.push_back(a[i] - a[i - 1]);
        }
        reverse(a.begin(), a.end());  

        ll sum_d1 = accumulate(d1.begin(), d1.end(), 0LL);
        ll sum_d2 = accumulate(d2.begin(), d2.end(), 0LL);
        if (sum_d1 >= sum_d2) {
            a = d1;
        } else {
            a = d2;
        }

        
        max_sum = max(max_sum, accumulate(a.begin(), a.end(), 0LL));
    }
    
    return max_sum;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n;  
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];  
        }

        cout << solve(a) << endl;
    }
    return 0;
}
