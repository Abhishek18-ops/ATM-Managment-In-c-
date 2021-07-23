#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void deletionathead(Node* &head){
    Node* temp  = head;
    while(temp->next != head){
        temp = temp->next;
    }
    Node* todelete = head;
    temp->next = temp->next->next;
    head = head->next;
}
void deletionatend(Node* &head, int pos){
    if(pos == 1){
        deletionathead(head);
        return;
    }
    Node* temp = head;
    int count =1;
    while(count != pos-1){
        temp = temp->next;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int countofNode(Node* head){
    Node* temp = head;
    int count=0;
    do{
        temp = temp->next;
        count++;
    }
    while(temp!= head);
    return count;
}


void insertathead(Node* &head , int data){
    Node* n = new Node(data);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }
    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
  void intsrtatend(Node* &head , int data){
      Node* n = new Node(data);
      Node* temp = head;
      if(head == NULL){
          insertathead(head,data);
          return;
      }
      while(temp->next != head){
          temp = temp->next;
      }
      temp->next = n;
    //   n = temp;
      n->next = head;

  }
  void insertatanyposition(Node* &head,int pos,int data){
    if(pos == 1){
        insertathead(head,data);
        return;
    }
    Node* n = new Node(data);
    Node* temp = head;
    int count=1;
    while(count!=pos-1){
        
        temp = temp->next;
        if(temp == head){
            cout<<"invailid position \n";
            return;
        }
        count++;
    }
    n->next = temp->next;
    temp->next = n;
    
}

void display(Node* head){
    Node* temp = head;
    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head!=temp);

    cout<<endl;
}

int main(){
    Node* head = NULL;
   intsrtatend(head , 1);
   intsrtatend(head , 2);
   intsrtatend(head , 3);
   intsrtatend(head , 4);
   intsrtatend(head , 5);
//    insertathead(head, 74);
   insertatanyposition(head,1,0);

//    deletionathead(head);
   
    display(head);

    cout<<countofNode(head)<<endl;

}