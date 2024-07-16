#include<bits/stdc++.h>
using namespace std;
int main(){

    // int a,b;
    // cin>>a>>b;
    // int gcdOab=__gcd(a,b);
    // int lcm=(a*b)/gcdOab;
    // cout<<"Lcm=> of "<<a<<" "<<b<<"= "<<lcm;
    int n=53;
    // for(int i=1;i<=n/2;i++){
    //     if(n%i==0){
    //         cout<<i<<" ";
    //     }
    // }
    // cout<<n<<" ";
    int i=2;
    while(n>1){
        if(n%i==0){
            cout<<i<<" ";
            while(n%i==0){
                n=n/i;
            }
        }
        else {
            i++;
        }
        cout<<i<<" ";
    }
    
    // Tc=0(n)
    return 0;

}