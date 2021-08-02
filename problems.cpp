#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long int 
using namespace std;

int countDivisors(int n)
{
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			// If divisors are equal,
			// count only one
			if (n / i == i)
				cnt++;

			else // Otherwise count both
				cnt = cnt + 2;
		}
	}
	return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; 
    cin>>t;
    while(t>0){
       cout<<countDivisors(12);
        t--;
    }
    return 0;
}