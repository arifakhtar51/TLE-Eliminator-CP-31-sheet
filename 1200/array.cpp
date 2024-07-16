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

/* ===============BoilerPlate code end=========== */
/*====================You can Do it man!!====================*/
/*=================Think a bit more=============*/
// author -arifakhtar

bool isPalin(vll &arr){
int i=0,j=arr.size()-1;
while(i<j){
    if(arr[i]!=arr[j])return 0;
    i++,j--;
}
return 1;
}
bool CheckBits(vector<int>&temp1,vector<int>&temp2){
    for(int i=0;i<32;i++){
        if(temp1[i]>0){
            if(temp2[i]==0){
                return 0;
            }
        }
    }
    return 1;
}
void solve(){
    
    ll n;
    cin>>n;
    vector<ll>arr(n);for(ll i=0;i<n;i++){cin>>arr[i];}
    ll x;
    cin>>x;
    vpll psm(n);//prefix sum
    for(int i=0;i<n;i++){
        psm[i]={arr[i],i};
        if(i){
            psm[i]={(psm[i-1].first+arr[i]),i};
        }
    }
    unordered_map<ll,vector<ll>>mp;
    for(auto ele:psm){
        mp[ele.first].push_back(ele.second);
    }
    mp[0]={-1};
    bool flag=0;
    int s=0,e=0;
    for(ll i=0;i<n;i++){
        if(mp[psm[i].first-x].size()>=1){
            if(mp[psm[i].first-x][0]==psm[i].first){
                // cout<<"yaha for i= "<<i;cl;
                if(mp[psm[i].first-x].size()>=2){
                        s=mp[psm[i].first-x][0];
                        e=i;
                        flag=1;break;
                }
                else continue;
            }
            else{
                    s=mp[psm[i].first-x][0];
                    e=i;
                    flag=1;break;
            }
        }
    }
    if(flag==0){
        cout<<-1;cl;return ;
    }
    
    vector<int>ans(n,0);
    for(int i=s+1;i<=e;i++){
        ans[i]=arr[i];
    }
    printarr(ans);cl;
}
int main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // int t=1;
    // // cout<<string(3,'1');
    // cin>>t;
    // while(t--){

    //     solve();

    // }
    cout<<(4 ^ 9);cl;
    cout<<(2^5^7);

}