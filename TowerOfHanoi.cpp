#include<iostream>

using namespace std;

void Hanoi(int n, char sorce, char temp , char dest){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<sorce<<" to "<<dest<<endl;
        return;
    }
    Hanoi(n-1, sorce , dest , temp);
    cout<<"Move disk "<<n<<" from "<<sorce<<" to "<<dest<<endl;
    Hanoi(n-1, temp , sorce , dest);

}

int main(){
    int n; 
    char sorce = 'A', temp = 'B', dest = 'C';
    cout<<"Enter the number of disks you want to transfer : ";
    cin>>n;
    cout<<endl;
    Hanoi(n,sorce,temp,dest);
}