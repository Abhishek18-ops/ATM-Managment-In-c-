#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool getbit(int n, int i){
    return ((n & (1 << i)) != 0);
}
void setbit(int n , int i ){
    int mask = 1<<i;
    cout<<(n|mask);
}

int main(){
    int n; cin>>n;
//     vector<int>arr;
//    while(n>0){
//        arr.push_back(n%2);
//        n = n/2;
//        i++;
//    }
// reverse(arr.begin(),arr.end());
// for(int i=0; i<arr.size(); i++){
//     cout<<arr[i]<<" ";
// }
    int pos;cin>>pos;
//    setbit(n,pos);


// question 1 of 26 july Raj Vikrsmafitya

   int arr[10] = {1,2,2,3,4,5,4,7,3};
   int Xor = 0;
   for(int i=0; i<10; i++){
       Xor = Xor^arr[i];
   }
   int count =0;
   while(Xor){
       if(Xor&1){
           break;
       }
       count++;
       Xor = Xor>>1;
   }
    int Xor1=0;
    int Xor2 =0;
    for(int i=0; i<10; i++){
        if((arr[i]&(1<<count))){
            Xor1 = Xor1^arr[i];
        }else{
            Xor2 = Xor^arr[i];
        }
    }
    cout<<Xor1<<" "<<Xor2;
   cout<<endl;
}