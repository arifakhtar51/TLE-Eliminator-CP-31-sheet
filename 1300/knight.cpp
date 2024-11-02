#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    for(ll k=1;k<=n;k++){
        ll totNoWays=(ll)((k*k)*(k*k-1))/2;
        ll Attack=(ll)4*(k-1)*(k-2);
        ll ans=totNoWays-Attack;
        cout<<ans<<" \n";

    }
}