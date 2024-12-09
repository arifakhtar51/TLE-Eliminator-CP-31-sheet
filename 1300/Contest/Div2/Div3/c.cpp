#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        // Convert string to a mutable vector of integers
        vector<int> digits(s.size());
        for(int i=0; i<s.size(); i++) digits[i] = s[i] - '0';
        
        // Iterate from left to right
        for(int i=1; i<digits.size(); i++){
            // While current digit can be swapped left to increase the left digit
            while(i >=1 && digits[i] > digits[i-1] +1 && digits[i] >0){
                // Perform the operation: swap digits[i] and digits[i-1], after decreasing digits[i] by 1
                int temp = digits[i];
                digits[i] = digits[i-1];
                digits[i-1] = temp -1;
                // Move one position to the left to check for further possible operations
                if(i >1) i--;
                else break;
            }
        }
        // Convert digits back to string
        string res = "";
        for(int d : digits) res += to_string(d);
        cout << res << "\n";
    }
}
