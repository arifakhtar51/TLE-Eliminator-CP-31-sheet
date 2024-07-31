#include<bits/stdc++.h>
using namespace std;

void arif(){
    cout<<"Hii i am arif";
}
void table(){
    int n;
    cin>>n;
    for(int i=1;i<=10;i++){
        cout<<i*n<<" ";
    }
}

int sum(int a,int b=0,int cd=10){
    return a+b+cd;    
}


double AreaOfCircle(int radius){
    double area=3.14*radius*radius;
    return area;
}
int check(int n){
    return n%2;
}
int main(){
    // arif();//calling
    // table();
    // int a,b;
    // cin>>a>>b;
    // int c=10;
    // int sm=sum(a,c);
    // cout<<sm<<" ";


    // AREA OF CIRRCLE

    int r=5;
    
    int ans=check(r);
    if(ans==0){
        cout<<"even";
    }
    else {
        cout<<"Odd";
    }


    // // Print a number is odd or even 

    // int n=29;

    // cout<<check(n);

    return 0;
}

