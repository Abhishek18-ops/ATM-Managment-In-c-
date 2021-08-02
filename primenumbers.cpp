#include<iostream>
using namespace std;

void prime(int st,int ls){
    if(st==ls+1)return ;
    int i=2;
    while(st%i != 0){
        i++;
    }
    if(st%i ==0){
        prime(st+1,ls);
    }else{
        cout<<st<<" ";
    }
    //  prime(st+1,ls);
    
    
}
int main(){
    int st,ls;
    cin>>st>>ls;
    prime(st,ls); 
}