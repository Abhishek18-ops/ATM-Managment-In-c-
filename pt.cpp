#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
     cin>>t;
    while(t--){
       int n; 
       cin>>n;
       int arr[10];
       int sum =0;
       for(int i=1; i<=n; i++){

           //Conversion of decimal to  binary
          for(int j=0; i>0; i++)    
            {    
                arr[j]=i%2;    
                i= i/2;  
            } 
            // summing over bits of odd positions

            for(int i =1; i<=sizeof(arr)/sizeof(arr[0]); i=i+2)   {
                sum = sum + arr[i];
            } 

            // again initializing the array to zero;

            arr[10]= {0};
       }
       // printing the answer;
       cout<<sum<<endl;
        
    }
    // cout<<sum;
}