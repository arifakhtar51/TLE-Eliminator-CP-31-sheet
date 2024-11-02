#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll fun(ll mid, ll n, ll k) {
    ll a = k;
    ll an = k + n - 1;

    ll tot = (an - a + 1);
    ll smMid = (mid - a + 1);
    
    ll totSum = (tot * (a + an)) / 2;
    ll midSum = (smMid * (a + mid)) / 2;
    ll Rsm = totSum - midSum;

    return abs(Rsm - midSum);
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll ans = LLONG_MAX;

    ll s = k, e = k + n - 1;

    ll len=e-s+1;
    if(len%2==0){
        cout<<min(fun(len/2,n,k),fun(len/2-1,n,k))<<endl;
    }
    else{
        ll x=s+(len/2-1);
        cout<<fun(x,n,k)<<endl;
    }


    // cout << ans << endl;
}

int main() {
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
