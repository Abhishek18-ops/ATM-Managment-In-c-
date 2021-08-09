#include<iostream>
#include<bits/stdc++.h>
#define n 20
using namespace std;

class Queue{
        int  *arr;
        int back;
        int front;
     public:
     Queue(){
         arr = new int[n];
         front =-1;
         back =-1;
     }
        void push(int x){
            if(back == n-1){
                cout<<"queue overflow "<<endl;
                return ;
            }
            
            back++;
            arr[back] = x;
            
            if(front== -1){
                front++;
            }
        }
        void pop(){
            if(front ==-1 || front > back ){
                cout<<"queue underflow "<<endl;
                return ;
            }
            
            front++;
            
        }
        int peek(){
            if(front ==-1 || front > back ){
                cout<<" No element in the queue "<<endl;
                return -1;
            }else{
                return arr[front];
            }
        }
        bool empty(){
            if(front ==-1 || front > back ){
                return true;
            }
            return false;
        }
};



int main(){
    Queue q;
    // for(int i=0; i<2; i++){
    //     q.push(i);
    // }
   
    // for(int i=0; i<2; i++){
    //    cout<<q.peek()<<" ";
    //    q.pop();
    // }
     q.push(20);
     q.push(30);
     q.push(40);
     q.push(50);
     q.push(60);
     q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.peek()<<endl;
    // q.pop();
    // cout<<q.empty();
}