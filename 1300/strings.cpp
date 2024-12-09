#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // Step 1: Count the frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // Step 2: Find the most frequent character
    char most_frequent_char = s[0];
    int max_freq = 0;
    int mini=1e8;
    char c=s[0];
    
    for ( auto& entry : freq) {
        if (entry.second > max_freq) {
            most_frequent_char = entry.first;
            max_freq = entry.second;
        }
        if(entry.second<=mini){
            mini=min(entry.second,mini);
            c=entry.first;
        }
        
    }
    // cout<<c<<"ye \n";
    for(int i=0;i<n;i++){
        if(s[i]==c){
            s[i]=most_frequent_char;
            break;
        }
    }
    cout<<s<<"\n";
    
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
