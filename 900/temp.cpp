// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// #define cl cout<<endl;
// #define cy cout<<"Yes"<<endl;
// #define cn cout<<"No"<<endl;
// #define vll vector<ll>
// int lcm(int a,int b){
//     return a*b/__gcd(a,b);
// }
// void solve(){
//     //  x given arr , query_values
//     int n=arr.size();
//     unordered_map<int,int>mp;
//     for(auto i:arr)mp[i]++;
//     vector<int>ans;
//     for(auto i:query_values){
//         if(mp[X]>=i){
//             int cnt=0;
//             for(int j=0;j<n;j++){
//                 if(arr[j]==X){
//                     cnt++;
//                 }
//                 if(cnt==i){
//                     ans.push_back(j);
//                     break;
//                 }
//             }
//         }
//         else{
//             ans.push_back(-1);
//         }
//     }
//     return ans;
// }
// int main(){

//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }