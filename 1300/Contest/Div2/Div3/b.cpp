#include <iostream>
#include <vector>
using namespace std;

bool canBalance(const vector<int>& a, int n) {
    long long total = 0;
    for (int x : a) {
        total += x;
    }

    if (total % n != 0) {
        return false;
    }

    long long target = total / n;
    long long sum_even = 0, sum_odd = 0;
    int count_even = 0, count_odd = 0;


    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sum_even += a[i];
            count_even++;
        } else {
            sum_odd += a[i];
            count_odd++;
        }
    }


    return sum_even >= count_even * target && sum_odd >= count_odd * target;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << (canBalance(a, n) ? "YES" : "NO") << endl;
    }

    return 0;
}
