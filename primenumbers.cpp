#include<iostream>
using namespace std;

void prime(int st,int ls){
    bool flag = false;
    if(st<2 || st==ls+1)return ;
    int i=2;
    while(st%i != 0){
        i++;
    }
    
    
    
}
int main(){
    int st,ls;
    cin>>st>>ls;
    prime(st,ls); 
}