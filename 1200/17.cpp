#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        long long x; // Use long long for x to prevent overflow
        cin >> n >> x;

        vector<long long> a(n); // Use long long for elements of a
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Sort the array
        sort(a.begin(), a.end());

        // Calculate the initial sum
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }

        long long prevDay = -1;
        long long ans = 0;

        // Iterate from the end of the sorted array to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // Calculate the current day
            long long curDay = (x - sum >= 0) ? (x - sum) / (i + 1) : -1;

            // Update the answer
            ans += (i + 1) * (curDay - prevDay);

            // Update previous day and reduce the sum
            prevDay = curDay;
            sum -= a[i];
        }

        cout << ans << endl;
    }
    
    return 0;
}
