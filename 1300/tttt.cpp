#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Constants for MOD value and the pre-calculated array size
    static const int ARRAY_SIZE = 10001;
    static const int MOD = 1000000007;

    // Pre-calculated factorial and modular multiplicative inverse arrays
    static long long factorialArray[ARRAY_SIZE];
    static long long inverseArray[ARRAY_SIZE];

    // Static initializer block for pre-calculation of factorials and their inverses
    static void initialize() {
        factorialArray[0] = 1;
        inverseArray[0] = 1;
        for (int i = 1; i < ARRAY_SIZE; ++i) {
            factorialArray[i] = factorialArray[i - 1] * i % MOD;
            inverseArray[i] = quickModularInverse(factorialArray[i], MOD - 2);
        }
    }

    // Method to compute the quick modular inverse using exponentiation
    static long long quickModularInverse(long long base, long long exponent) {
        long long result = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }

    // Method to compute the combination (n choose k) under modulus
    static long long combination(int n, int k) {
        return ((factorialArray[n] * inverseArray[k]) % MOD) * inverseArray[n - k] % MOD;
    }

public:
    // Method to count the number of good subsequences in the string s
    int countGoodSubsequences(string s) {
        // Initialize our static arrays
        static bool initialized = false;
        if (!initialized) {
            initialize();
            initialized = true;
        }
      
        // Count array for each character with a maximum value tracker
        vector<int> characterCount(26, 0);
        int maxCount = 1;
      
        // Calculate character counts and find the max count
        for (char c : s) {
            maxCount = max(maxCount, ++characterCount[c - 'a']);
        }
      
        // Initialize the answer value which will be the final count
        long long answer = 0;
      
        // Iterate over all possible subsequence lengths
        for (int i = 1; i <= maxCount; ++i) {
            long long countForLength = 1;
            for (int j = 0; j < 26; ++j) {
                if (characterCount[j] >= i) {
                    countForLength = countForLength * (combination(characterCount[j], i) + 1) % MOD;
                }
            }
            // Subtract 1 because we are excluding the empty subsequence
            answer = (answer + countForLength - 1) % MOD;
        }
      
        // Return the result after casting to int
        return static_cast<int>(answer);
    }
};

long long Solution::factorialArray[Solution::ARRAY_SIZE];
long long Solution::inverseArray[Solution::ARRAY_SIZE];

// Main function for demonstrational purpose
int main() {
    int n=13;
    int m=(n+2)/2;
    int x=n+2;
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n*3+2;j++){
            if(i>m){
                if(j==0||j==3*n+1)cout<<"e";
                else cout<<" ";
                continue;
            }
            if(i==m){
                cout<<"e";
                for(int i=0;i<n;i++)cout<<"*";
                for(int l=0;l<n;l++)cout<<"e";
                for(int i=0;i<n;i++)cout<<"*";
                cout<<"e";
                break;
            }
            if(j==0||j==n*3+1){
                cout<<"e";continue;
            }
            if(i==0){
                cout<<" ";continue;
            }
            if(i>0){
                int temp=(3*n+1)/2;//ceil val
                temp=temp-i;
                if(j>temp){
                    for(int k=0;k<2*(i-1)+1;k++){
                        cout<<"e";
                    }
                    j+=2*(i-1);
                    for(int k=j+1;k<n*3+2;k++){
                        if(k==3*n+1){
                            cout<<"e";
                        }
                        else
                        cout<<" ";
                    }
                    j=n*3+2;
                }
                else cout<<" ";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
        
    return 0;
}
// for(int j=0;j<=x-i;j++){
//             if(j==0){
//                 cout<<"e";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         if(i!=0)
//         for(int k=0;k<2*(i-1)+1;k++){
//             cout<<"e";
//         }
//         for(int j=x+1+i;j<3*n;j++){
//             if(j==3*n-1)cout<<"e";
//             else cout<<" ";
//         }
//         cout<<endl;
//     }
//     for(int i=0;i<=n;i++){
//         if(i==0){
//             cout<<"e";
//         }else
//             cout<<"*";
//     }

//         for(int i=0;i<n;i++){
            
//             cout<<"e";
            
//         }
//         for(int i=0;i<=n;i++){
//             if(i==n)cout<<"e";
//             else
//             cout<<"*";
//         }
//         cout<<endl;
//     for(int i=0;i<m;i++){
//             for(int j=0;j<=3*n;j++){
//                 if(j==0||j==3*n){
//                     cout<<"e";
//                 }
//                 else{
//                     cout<<" ";
//                 }
//             }
//             cout<<endl;
//         }