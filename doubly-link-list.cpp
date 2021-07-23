#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};
  void insertatfront(Node* &head , int data){
      Node* n = new Node(data);
      if(head == NULL){
          head = n;
          return ;
      }
      n->next= head;
      if(head!=NULL){
          head->prev = n;
      }
      head= n;
      
  }

  void insertatend(Node* &head,int data){
      Node* n = new Node(data);
      Node* temp = head;
      while(temp->next!=NULL){
          temp = temp->next;
      }
      
      temp->next = n;
      n->prev = temp;
      temp = n;
      n->next = NULL;
  }
  void insertafterNode(Node* &head,int key,int data){
      Node* n = new Node(data);
      Node* temp = head;
      while(temp!=NULL){
          if(temp->data==key){
              
              n->next = temp->next;
              temp->next = n;
              n->prev= temp;
              n->next->prev = n;

          }
          temp = temp->next;
      }
  }

  void insertbeforeNode(Node* &head,int key,int data){
      Node* n = new Node(data);
      Node* temp = head;
      while(temp!=NULL){
          if(temp->data == key){
            n->prev = temp->prev;
            temp->prev->next = n;
            n->next = temp;
            temp->prev = n;
            
          }
          temp = temp->next;
      }
  }

 Node* reverseNode(Node* &head){
    //   Node* temp = head;
      Node* p1 = head;
      Node* p2 = p1->next;
      p1->next = NULL;
      p1->prev = p2;
      while(p1!=NULL){
          p2->prev = p2->next;
          p2->next = p1;
          p1 = p2;
          p2 = p2->prev;
      }
      head = p1;
      return head;
  }

  void display(Node* head){
      while(head!=NULL){
          cout<<head->data<<" ";
          head = head->next;
      }cout<<endl;
  }
int main(){
    Node* head = NULL;
    insertatfront(head,10);
    insertatfront(head,9);
    insertatfront(head,8);
    insertafterNode(head,8,7);
    insertafterNode(head,8,13);
    insertbeforeNode(head,7,6);
    insertatend(head,11);
    insertatend(head,12);
    display(head);

    Node* reverse = reverseNode(head);
    display(reverse);
}