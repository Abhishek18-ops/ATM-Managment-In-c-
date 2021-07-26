#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 int t; cin>>t;
 while(t--){
    double a,b;
    cin>>a>>b;
    int sum =0;

//     double count=INT_MIN,sum=0;
//    int n1 = min(a,b);
//    int  n2 = max(a,b);
//    for(double i = n1; i<= n2; i++){
//        double a1 = (b-i)/(double)2;
//        double a2 = (i-a)/(double)2;
//        int l = round(a1);
//        int l1 = round(a2);
//        sum = sum+ l + l1;
//        if(count<sum){
//            count = sum;
           
//        }
//        sum =0;
//    }
   
//    cout<<ceil(count)<<endl;
int x=0,c=0;
if(a==b){
    cout<<"0"<<endl;
}
else if(b>a){
  cout<< (b-a) /2 + 1 <<"\n";
}else{
    c = a-b;
    if( c % 2 ==0){
        cout<< (b-a)/2 + 1 <<"\n";
    }else{
        cout<< (b-a)/2 <<"\n";

    }
  
}


// cout<<sum<<endl;

 }
//  
   return 0;
}