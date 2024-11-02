#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define cl cout<<endl;
#define cy cout<<"YES"<<endl;
#define cn cout<<"NO"<<endl;
#define cyr cout<<"YES"<<endl; return ;
#define cnr cout<<"NO"<<endl; return ;
#define vll vector<ll>
#define srt(x) sort(begin(x),end(x))
#define vi vector<int>
#define rev(x) reverse(begin(x),end(x))
#define printarr(arr) for(int i=0;i<arr.size();i++)cout<<arr[i]<<" ";
#define sortr(x) sort(rbegin(x),rend(x))
#define vpll vector<pair<ll,ll>>
#define um unordered_map<ll,ll>
#define IOS                \
ios::sync_with_stdio(0); \
cin.tie(0);              \
cout.tie(0);
const ll MOD = 1e9 + 7;

// Prefix sum

vll prefixSum(vll&arr){
    vll psum(arr.size(),0);
    psum[0]=arr[0];int n=arr.size();

    for(int i=1;i<n;i++)psum[i]=psum[i-1]+arr[i];
    return psum;
}
void factors(ll n){
    vll fact;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(n/i==i)fact.push_back(i);
            else {
                fact.push_back(i);
                fact.push_back(n/i);
            }
        }
    }
}
bool static  mycomp(pair<ll,ll>p1,pair<ll,ll>p2){
    if(p1.first==p2.first){
        return p1.second>p2.second;
    }
    else {
        return p1.first<p2.first;
    }
}

void FindPrime(){
    vector<bool>Prime(3001,1);
    Prime[0]=0;
    Prime[1]=0;
    for(int i=2;i*i<=3000;i++){
        int j=i*i;
        while(j<=3000){
            Prime[j]=0;
            j+=i;
        }
    }
}

int sumOfDigit(int n){
    int sm=0;
    while(n){
        sm+=n%10;
        n/=10;
    }
    return sm;
}
ll power(ll a,ll b){
    if(!b)return 1;
    ll temp=power(a,b/2);
    temp*=temp;
    if(b&1)temp*=a;
    return temp;
}
ll power(ll x, ll y, ll p) {
    ll res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p
    while (y > 0) {
        // If y is odd, multiply x with the result
        if (y & 1)
            res = (res * x) % p;
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p; // Change x to x^2
    }
    return res;
}
ll binpow(ll a, ll b, ll mod) {
    if (b == 0)
        return 1;
    if (b % 2) {
        return a * binpow(a, b - 1, mod) % mod;
    } else {
        ll temp = binpow(a, b / 2, mod);
        return temp * temp % mod;
    }
}
int lcm(int a,int b){return a*b/__gcd(a,b);}

vector <int> Z_Function (string s) {
    // "aaabaab" -  
    // [0, 2, 1, 0, 2, 1, 0] 
    // Suppose we are given a string  
    // $s$  of length  
    // $n$ . The Z-function for this string is an array of length  
    // $n$  where the  
    // $i$ -th element is equal to the greatest number of characters starting from the position  
    // $i$  that coincide with the first characters of  
    // $s$ .
        int N = s.length();
        
        vector <int> Z(N, 0);
        
        int left = 0, right = 0;
        
        for (int i=1; i < N; ++i) {
            
            if (i < right) 
                Z[i] = min(right - i, Z[i-left]);
            
            while ((i + Z[i] < N) and (s[Z[i]] == s[i + Z[i]]))
                Z[i]++;
            
            if (i + Z[i] > right) {
                
                left = i;
                right = i + Z[i];
            }
        }
        
        
        return Z;
    }
int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}
bool isPalin(vll &arr){
    int i=0,j=arr.size()-1;
    while(i<j){
        if(arr[i]!=arr[j])return 0;
        i++,j--;
    }
    return 1;
}

/* ===============BoilerPlate code end=========== */
/*====================You can Do it man!!====================*/
/*=================Think a bit more=============*/
// author -arifakhtar

void solve(){
    
    ll n;
    cin >> n;
    vll arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> res(n);
    int i=0;
    while(i<n) {
        if (arr[i] != n){
            // can ecnt equal
            res[i] = arr[i] + 1;}
        else{
            res[i] = 1;}
            i++;
    }

    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
cl;
    
//      vll brr;
    
//         for(int i=n/2;i<n;i++){
//             // cout<<arr[i]<<" ";
//             brr.push_back(arr[i]);
//         }
//             srt(brr);
//             rev(brr);
//             vll temp;
//         for(int i=0;i<n/2;i++){
//             // cout<<arr[i]<<"";
//             temp.push_back(arr[i]);
//         }
//         srt(temp);
//         // if(n%2!=0){
//         //     swap(brr[0],brr[1]);
//         // }
//         // printarr(brr);
//         // printarr(temp);cl;
//         vll ans;
//         for(auto i:brr){
//             ans.push_back(i);
//         }
//         for(auto i:temp){
//             ans.push_back(i);
//         }

//         for(int i=0;i<n-1;i++){
//             if(ans[i]==arr[i]){
//                 swap(ans[i],ans[i+1]);
//             }
//         }
// printarr(ans);cl;

    
     
//     //  vll brr;
//     //  next_permutation(begin(arr),end(arr));
//     // rev(brr);
//     // int i=0,j=n-1;
//     // while(i<=j){
//     //     if(i==j){
//     //         brr.push_back(arr[i]);
//     //     }
//     //     else{
//     //         brr.push_back(arr[j]);
//     //         brr.push_back(arr[i]);


//     //     }
//     //     i++,j--;

//     // }
//     // for(int i=0;i<n;i++){
//     //     if(arr[i]==brr[i]){
//     //         swap(brr[i],brr[i-1]);
//     //     }
//     // }
//     // printarr(brr);cl;

//     // for(ll i=0;i<n;i++){
//     //     if(arr[i]==brr[i]){
//     //         if(i==0){
//     //             swap(brr[i],brr[i+1]);
//     //         }
//     //         else{
//     //             swap(brr[i],brr[i-1]);
//     //         }
//     //     }
//     // }
//     // printarr(brr);
//     //  printarr(arr);cl;
//     // for(auto i:arr){
//     //     cout<<i<<" ";
//     // }
//     // cl;
    
}
int main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t=1;
    // cout<<string(3,'1');
    cin>>t;
    while(t--){

        solve();

    }
    // cout<<(4 ^ 9);cl;
    // cout<<(2^5^7);

}