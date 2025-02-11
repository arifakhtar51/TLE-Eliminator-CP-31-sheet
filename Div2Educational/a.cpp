#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        int operations = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                operations++;
            
            }
        }

        cout << operations << "\n";
    }

    return 0;
}
