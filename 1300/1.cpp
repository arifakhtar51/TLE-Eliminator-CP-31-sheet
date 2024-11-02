#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define int long long 
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    map<pair<int, int>, int> cnt;
    int ans = 0;
    
    for (int e : a) {
        int xx = e % x;
        int yy = e % y;
        
        // Add to the answer the count of the pair ((x - xx) % x, yy)
        ans += cnt[make_pair((x - xx) % x, yy)];
        
        // Increment the count of the pair (xx, yy)
        cnt[make_pair(xx, yy)]++;
    }
    
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
