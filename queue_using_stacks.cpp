#include<iostream>
#include<stack>
#define n 20
using namespace std;

class Queue{
    // int *arr;
    // int front; 
    // int back;
    public:
    // Queue(){
    //     front = -1;
    //     back = -1;
    // }
    stack<int>st1;
    stack<int>st2;
    void push(int x){
       
        // if(back == n-1){
        //     cout<<"Queue is overflow" << endl;
        //     return ;
        // }
        // back++;
        // arr[back] = x;
        // if(front == -1 ){
        //     front++;
        // }
        st1.push(x);
    }
    int pop(){

        if(st1.empty() && st2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        // if(front ==-1 || front >back){
        //     cout<<"Queue Underflow " << endl;
        //     return;
        // }
        // front++;
       
        int topval = st2.top();
        st2.pop();
       return topval;

    }

    // int peek(){
    //     // if(front ==-1 || front > back){
    //     //     cout<<"No element in the Queue" << endl;
    //     //     return -1;
    //     // }
    //     // return arr[front];
    //     int n1 = st2.size();
    //     return arr[n1-1];
    // }
    bool empty(){
         if(st1.empty()&&st2.empty()){
            return true;

        }return false;
    }

};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    cout<<q.pop()<<endl;
    q.push(3);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
}