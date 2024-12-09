// #include <iostream>
// using namespace std;

// int main() {
//     int count = 0;
//     // cout<<(-10+6)%6<<" ";
//     // Iterate through all three-digit numbers
//     for (int n = 100; n <= 999; n++) {
//         int square = n * n;
        
//         // Check if the last two digits of n^2 are 54
//         if (square % 100 == 54) {
//             cout << "Number: " << n << ", Square: " << square << endl;
//             count++;
//         }
//     }

//     cout << "Total count of such numbers: " << count << endl;
//     return 0;
// }
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int oprn) {
        int n = nums.size();
        map<int, int> freq;
        vector<pair<int, int>> arr;

    
        for (auto &ele : nums) {
            freq[ele]++;
            arr.push_back({ele - k, +1});
            arr.push_back({ele + k + 1, -1});
        }

        // Collect unique points from arr and frequency map keys
        set<int> points;
        for (auto& event : arr) {
            points.insert(event.first);
        }
        for (auto& p : freq) {
            points.insert(p.first);
        }

        // Sort arr by the first element
        sort(arr.begin(), arr.end());

        int idx = 0;
        int temp = 0;
        int maxi = 0;

        for (int t : points) {
           
            while (idx < arr.size() && arr[idx].first <= t) {
                temp += arr[idx].second;
                idx++;
            }

          
            int cnt = freq.count(t) ? freq[t] : 0;
            int fr = cnt + min(oprn, temp - cnt);
            maxi = max(maxi, fr);
        }

        return maxi;
        
    }
};