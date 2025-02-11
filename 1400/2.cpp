#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> findStrictlyIncreasingLIS(const vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1), parent(n, -1);
    int maxLength = 0, endIndex = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            endIndex = i;
        }
    }

    vector<int> lis;
    for (int i = endIndex; i != -1; i = parent[i]) {
        lis.push_back(arr[i]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    int t;
    cin >> t;  // Take the number of test cases as input

    while (t--) {
        int n;
        cin >> n;  // Take the size of the array for the current test case
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];  // Take the array elements as input
        }

        if (n == 1 || n == 2) {
            cout << 0 << "\n";
            continue;
        }
        reverse(begin(arr),end(arr));

        vector<int> lis = findStrictlyIncreasingLIS(arr);
        reverse(begin(arr),end(arr));
        // Store frequency count of elements in the original array
        map<int, int> freqMap;
        for (int num : arr) {
            freqMap[num]++;
        }

        // Subtract frequencies of elements in LIS from freqMap
        for (int num : lis) {
            freqMap[num]--;
        }

        // // Output LIS
        // cout << "LIS: ";
        // for (int num : lis) {
        //     cout << num << " ";
        // }
        // cout << endl;

        // Output remaining elements in the same sequence as the original array
        // cout << "Remaining elements: ";
        vector<int>t;
        for (int i = 0; i < n; ++i) {
            if (freqMap[arr[i]] > 0) {
                t.push_back(arr[i]);
                freqMap[arr[i]]--;
            }
        }
        int ans=0;
        for(int i=0;i<t.size()-1;i++){
            if(t[i]<t[i+1])ans++;
        }
        cout<<ans;
        cout << endl;
    }

    return 0;
}
