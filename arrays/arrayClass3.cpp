#include<bits/stdc++.h>
using namespace std;
// Pass By Value

// void f(int a){
//     cout<<a<<" inside f"<<endl;
//     a=10;
// }
// Pass By Reference 
void fun(int  arr[]){
    arr[1]=29;
    
}
// void ff(int &a){
//     cout<<a<<" inside f"<<endl;
//     a=10;
// }

void ArifSwapFun(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
 } 
int main(){
    // int a=20;

    // f(a);
    // cout<<"after calling function"<<a<<endl;
    // int arr[]={1,2,4};
    // fun(arr);

    // cout<<"arr[0] = "<<arr[0];


    // swap two Numbers
    int x=10,y=20;
    ArifSwapFun(x,y);
    cout<<"x="<<x<<" y="<<y<<endl;
 
    return 0;

}