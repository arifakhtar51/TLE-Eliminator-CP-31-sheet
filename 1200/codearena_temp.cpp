#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countValidPairs(vector<int>& arr, int x) {
    int n = arr.size();
    int count = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int left = i + 1, right = n - 1, j = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (2 * arr[mid] >= x) {
                j = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (j < n) {
            count += (n - j);
        }
    }

    return count;
}

int main() {
    vector<int> arr = {0, 0, 3};
    int x = 3;
    cout << "Number of valid pairs: " << countValidPairs(arr, x) << endl;
    return 0;
}
