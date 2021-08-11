#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node* nextsibling;

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
void levelInverseOrder(Node* root){
    if(!root){
        return;
    }
    queue<Node*>q;
    stack<Node*>s;
    Node* temp;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }    
        if(temp->right){
            q.push(temp->right);
        }
        s.push(temp);
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
    }
    cout<<endl;
}
int sizeofthetree(Node* root){
    Node* temp;
    queue<Node*> q;
    int size=0;
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
int leveloftree(Node* root){
    if(!root){
        return 0;
    }
    int level =0;
    queue<Node*>q;
    q.push(NULL);
    q.push(root);
    while(!q.empty()){
        root = q.front();
        q.pop();
        if(root == NULL){
            if(!q.empty())
            q.push(NULL);
            level++;
        }
        else{
            if(root->left){
                q.push(root->left);
            }
            if(root->right){
                q.push(root->right);
            }
        }
    }
    return level;
}
void deleteatree(Node* root){
    if(!root){
        return;
    }
    //first delete both subtrees
    deleteatree(root->left);
    deleteatree(root->right);
    //Now delete the current node
    free(root);
}
int heightofthetree(Node* root){
    int leftheight ,rightheight;
    if(!root){
        return 0;
    }else{
        //compute the left subtree
        leftheight = heightofthetree(root->left);
        //compute the right subtree
        rightheight = heightofthetree(root->right);

        if(leftheight>rightheight){
            return leftheight+1;
        }else{
            return rightheight+1;
        }
    }

}
Node* dippestNode(Node* root){
    if(!root){
        return NULL;
    }
    Node* temp;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return temp;
}
void swapNode(Node* a,Node* b){
    Node* temp = a;
    a = b;
    b =  temp;
}
// Deleting a articular node from a binary tree;
void deletingAnode(Node* root,int data){
    if(!root){
        return ;
    }
    Node* temp;
    Node* node;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(data == temp->data){
            node = temp;
            break;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    Node* deep = dippestNode(root);
    Node* temp1 = deep;
    deep = node;
    node = temp1;

    free(node);
    // cout<<node-data;
}
int NoOfLeaves(Node* root){
    if(!root){
        return 0;

    }
    queue<Node*>q;
    Node* temp;
    int count=0;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(!temp->left && !temp->right){
            count++;
        }
        if(temp->left){
            q.push(temp->left);

        }
        if(temp->right){
            q.push(temp->right);
        }

    }
    return count;
}
int NoOfFullNodes(Node* root){
    if(!root){
        return 0;

    }
    queue<Node*>q;
    Node* temp;
    int count=0;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left && temp->right){
            count++;
        }
        if(temp->left){
            q.push(temp->left);

        }
        if(temp->right){
            q.push(temp->right);
        }

    }
    return count;
}
int NoOfHalfNodes(Node* root){
    if(!root){
        return 0;
    }
    queue<Node*>q;
    Node* temp;
    int count=0;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if((temp->left && !temp->right) || (!temp->left && temp->right)){
            count++;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return count;
}

bool identicaltree(Node* root1, Node* root2){
    bool po = false;
    if(!root1 && !root2){
       return true;
    }if(!root1 || !root2){
        return false;
    }
    return ((root1->data == root2->data) && (identicaltree(root1->left ,root2->left)) 
    && (identicaltree(root1->right,root2->right)));
}

int diameter(Node* root){
    if(!root){
        return 0;
    }
    int hight1 = heightofthetree(root->left);
    int hight2 = heightofthetree(root->right);
    int diameter1 = diameter(root->left);
    int diameter2 = diameter(root->right);

    return max(hight1+hight2,max(diameter1,diameter2));

}

int maxsumatanylevel(Node* root){
    if(!root){
        return 0;
    }
    Node* temp;
    queue<Node*> q;
    int level =0,maxlevel=0,currentsum=0,maxsum=INT_MIN;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        temp =  q.front();
        q.pop();
        if(temp == NULL){
            if(currentsum > maxsum){
                maxsum = currentsum;
                maxlevel = level;
            }
            currentsum =0;
            if(!q.empty()){
                q.push(NULL);
            }
                level++;
        }else{
            currentsum += temp->data;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return maxsum;
}
// Function that prints out all the array on a line
void printArray(int ints[],int len){
    for(int i=0;i<len; i++){
        cout<< ints[i]<<" ";
    }cout<<endl;
}

// Printing all the root to leave path 
void printpath(Node* root,int path[],int pathlen){
    if(!root){
        return ;
    }
    path[pathlen] = root->data;
    pathlen++;
    // It's a leave so print the path and led it here
    if(root->left == NULL && root->right == NULL){
        printArray(path,pathlen);
    }else{
        //Otherwise print both the subtree
        printpath(root->left, path,pathlen);
        printpath(root->right,path,pathlen);

    }

}
// Give an algorithm to print the path wich is equal to the given sum
int hasPathSum(Node* root,int sum){
    if(root == NULL){
        return (sum =0);
    }
    else{
        //otherwise check both subtree;
        int remainingSum = sum -root->data;
        if((root->left && root->right) || (!root->left && !root->right)){
            return (hasPathSum(root->left,remainingSum) || hasPathSum(root->right,remainingSum));

        }else if(root->left){
            return hasPathSum(root->left,remainingSum);
        }else{
            return hasPathSum(root->right,remainingSum);
        }
    }
}
//Printing the sum of all the elements;
int sumofthetree(Node* root){
    if(root== NULL){
        return 0;
    }
    else{
        return (root->data + sumofthetree(root->left)+sumofthetree(root->right));
    }
}
int sumofthetreewithoutrecursion(Node* root){
    if(root== NULL){
        return 0;
    }
    Node* temp ;
    queue<Node*> q;
    int sum =0;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        sum += temp->data;
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return sum;
}

// Problem 24
Node* mirror(Node* root){
    Node* temp;
    if(root){
        mirror(root->left);
        mirror(root->right);
        temp= root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

//Problem 25
bool  Ismirror(Node* root1,Node*root2){
    if(root1 == NULL && root2 == NULL)return 1;
    if(root1 == NULL || root2 == NULL)return 0;
    if(root1->data != root2->data){
        return 0;
    }
    else{
        return (Ismirror(root1->left,root2->left)) && (Ismirror(root1->right,root2->right));
    }
}

//Problem 29
int printallAncestors(Node* root,Node* root1){
    if(root == NULL || root1 == NULL)return 0;
    if(root->left == root1 || root->right == root1
    || printallAncestors(root->left,root1) || printallAncestors(root->right,root1)){
        cout<< root->data ;
    return 1;
    }
    return 0;
}

// Problem 34
//nextsibling
int fillsibling(Node* root){
    if(!root){
        return 0;

    }
    Node* temp;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        // cout<<temp->data<<" ";
        if(temp== NULL){
            // PUt another mark for the next level;
            if(!q.empty()){
                q.push(NULL);
            }else{
                temp->nextsibling = q.front();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    return 0;
}

int main(){
    int pos[] = {4,2,9,3,1};
    int ino[] = {4,2,1,9,3};
    Node* root1 = new Node(5);
    root1->left = new Node(1);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->right  = new Node(6);
    root1->right->right->right  = new Node(10);
    root1->right->left = new Node(7);
    root1->right->left->left = new Node(9);

    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right  = new Node(6);
    root->right->right->right  = new Node(10);
    // root->right->right->right->left  = new Node(11);
    root->right->left = new Node(7);
    root->right->left->left = new Node(9);
    
    // int m = sizeof(pos)/sizeof(pos[0]);

    // Node* n = BuildtreewithPostAndIn(pos,ino,0,m-1,m);
    // // displayInorder(n);
    // // cout<<searchelement(n,5);
    // lavelorder(n);
    // cout<<endl;
    // cout << maxelementwithoutrecursion(n);
    // cout << endl;
    // cout << "size => " << sizeofthetree(n,0) << endl;
    // deleteatree(root);
    lavelorder(root);
    cout << endl;
    // cout<<heightofthetree(root)<<endl;
    cout << "No of levels " << leveloftree(root) << endl;
    // cout  << dippestNode(root) << endl;
    // deletingAnode(root,2);
    lavelorder(root);


    cout<< endl  << NoOfHalfNodes(root) << endl;
     cout  << endl << identicaltree(root1,root) << endl;
    // int path[sizeofthetree(root)];
    // printpath(root,path,sizeofthetree(root));
     cout<<sumofthetreewithoutrecursion(root)<<endl;
     Node* mirror0 = mirror(root);
    //  lavelorder(mirror0);

     cout<<endl;
     cout<<printallAncestors(root1,mirror0);
     cout<<(root);
}