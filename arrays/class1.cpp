#include<bits/stdc++.h>
using namespace std;

int printarr(int arr[]){
    int n=10;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    
    int arr[10];
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<"n="<<n<<" ";
    // arr[0]=10;
    // arr[1]=20;
    // for(int i=0;i<=11;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<sizeof(arr);
    // cout<<arr[0]<<arr[1];
    int cnt=203;
    for(int i=0;i<10;i++){
        arr[i]=i+1;
        
    }
    // int maxi=arr[0];
    // for(int i=1;i<10;i++)
    // {
    //     if(arr[i]<maxi){
    //         maxi=arr[i];
    //     }
    // }
    // cout<<maxi<<" ";

    // printarr(arr);
    // cout<<"\nafter reverse "<<endl;
    // int i=0,j=n-1;
    // while(i<j){
    //     swap(arr[i],arr[j]);
    //     i++,j--;
    // }
    // printarr(arr);
    int i=5;
    i=i++;
    cout<<i;
    return 0;
}