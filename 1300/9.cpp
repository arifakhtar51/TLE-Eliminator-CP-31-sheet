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
vll prefixSum(vll&arr){
    vll psum(arr.size(),0);
    psum[0]=arr[0];int n=arr.size();
    for(int i=1;i<n;i++)psum[i]=psum[i-1]+arr[i];
    return psum;
}
vll factors(ll n){
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
    return fact;
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
void printvpll(vpll&vp){
    for(auto i:vp){
        cout<<i.first<<" "<<i.second<<" ";cl;
    }
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
vector<int> Z_Function(string s) {
    int N = s.length();
    vector<int> Z(N, 0);
    int left = 0, right = 0;
    
    for (int i = 1; i < N; ++i) {
        if (i < right) 
            Z[i] = min(right - i, Z[i - left]);
        
        while (i + Z[i] < N && s[Z[i]] == s[i + Z[i]])
            Z[i]++;
        
        if (i + Z[i] > right) {
            left = i;
            right = i + Z[i];
        }
    }
    return Z;
}
//         //z[i] represent length of longest substr starting at i that is prefix of s
//         // str=pattern+'@' +s
//         // and apply z function over str 
//         // q) How many more char need to append in s to make s palindrome
//         //  str=rev(s)+'@' +s;

int log_a_to_base_b(int a, int b)
{
    return log2(a) / log2(b);
}

/* ===============BoilerPlate code end=========== */
/*====================You can Do it man!!====================*/
/*=================Think a bit more=============*/
// author -arifakhtar

void solve(){

    ll n;
    cin>>n;
    bool flag=0;
    // map<vector<ll>,ll>mp;
    vector<ll>prev,prev2;
    int mx=n+1;
    vector<ll>arr(mx,0);
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            ll x;cin>>x;
            arr[x]=1;
        }
        
            prev2=prev;
            prev=arr;

        
    }
    if(prev2==prev){
        cy;
    }
    else{
        cn;
    }
}
int main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // int t=1;
    // cout<<string(3,'1');
        ll t, f, i, j, n, p;
    string ans;
    
    cin>>t;
    
    for(;t--;)
    {
        cin>>n;
        
        unordered_map<ll, ll> mp;
        
        ll k[n];
        vector<ll> bits[n];
        
        for(i=0; i<n; i++)
        {
            cin>>k[i];
            
            for(j=0; j<k[i]; j++)
            {
                cin>>p;
                if(mp.find(p)==mp.end()){
                    mp[p]=1;
                }else{
                    mp[p]++;
                }
                bits[i].push_back(p);
            }
        }
        
        ans="NO";
        
        for(i=0; i<n; i++)
        {
            f=0;
            for(j=0; j<k[i]; j++)
            {
                if(mp[bits[i][j]]==1){
                    f++;
                    break;
                }
            }
            if(f==0){
                ans="YES";
                break;
            }
        }
        
        cout<<ans<<"\n";
    }

}