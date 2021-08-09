#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search(int ino[], int start , int end,int curr){
    for(int i=start; i<=end;i++){
        if(ino[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* BuildTree(int pre[],int ino[], int start,int end){
    static int idx =0;
    if(start > end){
        return NULL;
    }
    int curr = pre[idx];
    idx++;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = search(ino,start,end,curr);
    node->left = BuildTree(pre,ino,start,pos-1);
    node->right = BuildTree(pre,ino,pos+1,end);
    return node;
}
Node* BuildtreewithPostAndIn(int pos[],int ino[],int start,int end,int size){
    // int size = sizeof(pos)/sizeof(pos[0]);
    static int idx = size-1;
    if(start>end){
        return NULL;
    }
    int curr = pos[idx];
    idx--;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    int position = search(ino,start,end,curr);
    node->right = BuildtreewithPostAndIn(pos,ino,position+1,end,size);
    node->left = BuildtreewithPostAndIn(pos,ino,start,position-1,size);
    return node;
}
void displayInorder(Node* node){
    if(node == NULL){
        return ;
    }
    displayInorder(node->left);
    displayInorder(node->right);

    cout<<node->data<<" ";
}
void lavelorder(Node* root){
    Node* temp;
    queue<Node*> q;
    if(!root){
        return ;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int sizeofthetree(Node* root,int size){
    Node* temp;
    queue<Node*> q;
    if(!root){
        return 0;
    }
    q.push(root);
    while(!q.empty()){
        size++;
        temp = q.front();
        q.pop();
        // cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return size;
}
int searchinlevelorder(Node* root,int data){
    Node* temp;
    queue<Node*>q;
    if(root == NULL){
        return 0;
    }
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        //Check if the element is found or not
        if(data == temp->data){
            q.pop();
            return 1;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }

    }
    return 0;
}
int findelement(Node* root,int data){
    int temp;
    //Base case  == empty tree in that case the data is not found so return false
    if(root == NULL){
        return 0;
    }
    else{
        //see if found here
        if(data == root->data){
            return 1;
        }
        else {
            //otherwise recur down the correct subtree
            temp = findelement(root->left,data);
            if(temp!=0){
                return temp;
            }
            else{
                return findelement(root->right,data);
            }
        }
    }
    return 0;
}
int findmaxelement(Node* root){
    int root_val,left,right,max=INT_MIN;
    if(root!=NULL){
        root_val = root->data;
        left = findmaxelement(root->left);
        right = findmaxelement(root->right);
        //Find the largest value in the three value;
        if(left > right){
            max = left;
        }
        else{
            max = right;
        }
        if(root_val > max){
            max = root_val;
        }
    }
    return max;
}
int maxelementwithoutrecursion(Node* root){
    Node* temp;
    int max = INT_MIN;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        //Check for the largest data;
        if(max < temp->data){
            max = temp->data;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return max;
}
int main(){
    int pos[] = {4,2,9,3,1};
    int ino[] = {4,2,1,9,3};
    int m = sizeof(pos)/sizeof(pos[0]);

    Node* n = BuildtreewithPostAndIn(pos,ino,0,m-1,m);
    // displayInorder(n);
    // cout<<searchelement(n,5);
    lavelorder(n);
    cout<<endl;
    cout << maxelementwithoutrecursion(n);
    cout << endl;
    cout << "size => " << sizeofthetree(n,0);
}