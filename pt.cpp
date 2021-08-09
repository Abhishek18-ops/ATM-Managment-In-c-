#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#include<set>
using namespace std;
void  bulb(ll n,ll p,ll k){
    ll count=0;
    for(ll i=0; i<n;i++){
        for(ll j =0; j<n; j++){
            if(j%k==i){
                count++;
                if(j==p)
               cout<<count<<endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin>>t;
    while(t--){
        ll n,p,k;
        ll ans =0;
        cin>>n>>p>>k;
        ll q = p%k;
        ll rem = p/k;
        ans = rem;
        ans +=(q)*(n/k);
        ll extra = n%k;
        if(extra > q){
            ans += q;
        }else{
            ans += extra;
        }
        cout<<ans+1<<endl;
      
    }

    
}