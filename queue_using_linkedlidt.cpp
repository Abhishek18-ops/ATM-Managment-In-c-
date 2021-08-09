#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class Queue{
    node* front ;
    node* back;
    public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    void push(int c){
        node* n = new node(c);
        if(front == NULL){
            back=n;
            front=n; 
            return;
            
        }
        
        back->next = n;
        back = n;
    }

    void pop(){
        if(front ==NULL){
            cout<<"Queue has no element "<<endl;
            return ;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }
    int peek(){
        if(front ==NULL){
            cout<<"Queue has no element "<<endl;
            return -1;
        }
        return front->data;

    }
    bool empty(){
        if(front ==NULL){
            // cout<<"Queue has no element "<<endl;
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;

    for(int i=0; i<20; i++){
        q.push(i);
    }
    for(int i=0; i<20; i++){
        cout<<q.peek()<<" ";
    q.pop();
    }

    q.push(20);
    cout<<q.peek()<<" ";
    // q.pop();
    // cout<<q.peek()<<" ";
    // q.pop();
    // cout<<q.peek()<<" ";
    // q.pop();
    // cout<<q.peek()<<" ";
    // q.pop();
    cout<<endl<<q.empty()<<endl;
}