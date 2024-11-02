#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = 0;
    for (int i = 0; i <= n; ++i) {
        vector<int> subarr(arr.begin(), arr.begin() + i);
        sort(subarr.rbegin(), subarr.rend());  // Sort in descending order

        int sum = 0;
        for (int j = 0; j < subarr.size(); j += 2) {  // Sum every second element
            sum += subarr[j];
        }
        // cout<<i<<" "<<sum<<" "<<k<<" "<<subarr.size()<<endl;

        if (sum <= k) {
            result = i;
        } else {
            break;
        }
    }

    cout << result << endl;
    return 0;
}