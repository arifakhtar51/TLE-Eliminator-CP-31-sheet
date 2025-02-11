#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define cl cout<<endl;
#define cy cout<<"Yes"<<endl;
#define cn cout<<"No"<<endl;
#define vll vector<ll>
int lcm(int a,int b){
    return a*b/__gcd(a,b);
}
void solve(){
     int t;
    cin >> t;
    for(int tc=0;tc<t;++tc){
        int n,x=0,y=1000000000,z=0;
        cin >> n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i){
            cin >> a[i];
        }
        for(int i=0;i<n;++i){
            cin >> b[i];
            if (a[i]<b[i]){
                ++x;
                z=b[i]-a[i];
            }
            else y=min(a[i]-b[i],y);
        }
        if (x==0||(x==1&&z<=y))cout <<"YES\n";
        else cout <<"NO\n";
    }
    // 4 5 4 10 10
    // 5 7 4 9 9

    // 5 3 3 9 9

    // 5 7 3 9 9

}
int main(){

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}