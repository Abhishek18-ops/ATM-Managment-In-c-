#include<iostream>
#include<stack>
using namespace std;


class tree{
    public:
    int data;
    tree* left;
    tree* right;

    tree(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

tree* takeInpute(tree* parent, bool ilc){
    if(parent ==  NULL){
        cout<<" Root Node Data ?"<<endl;
    }else{
        if(ilc){
            cout<<"Enter the left child data of "<<parent->data<<endl;
        }else{
            cout<<"Enter the right child data of "<<parent->data<<endl;
        }
    }
    int val; cin>>val;
    tree* nn = new tree(val);
    // size++;
    cout<<nn->data<<" has left chils ?"<<endl;
    bool hlc;
    cin>>hlc;
    if(hlc){
        nn->left = takeInpute(nn,true);
    }
    cout<<nn->data<<" has right chils ?"<<endl;
    bool hrc; cin>>hrc;
    if(hrc){
        nn->right = takeInpute(nn, false);
    }
    return nn;
}
void stackinorder(tree* root){
    stack<tree*>st;
    while(root!=NULL || !st.empty()){
        while(root!=NULL){
            st.push(root);
            //Got left subtree and keep on adding this
            root = root->left;
        }
        if(st.empty()){
            break;
        }
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        root = root->right;
    }
//    st.clear();
}
void inOrder(tree *root) {
   stack<tree*> s;
   tree*current = root;

   while (current != NULL || s.empty() == false) {
      while (current != NULL) {
         s.push(current);
         current = current->left;
      }

      current = s.top();
      s.pop();

      cout << current->data << " ";
      current = current->right;
   }
}

void inorder(tree* root ){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(tree* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void display(tree* root){
    if(root == NULL){
        return;
    }
    // string str ="";
    if(root->left == NULL){
        // str +=".";
        cout<<".";
    }else{
        // str += root->left->data;
        cout<< root->left->data;
    }
    cout<<" => " <<root->data <<" <=";
    // str += " => " + root->data ;
    // str += " <= ";
    if(root->right == NULL){
        // str += ".";
        cout<<".";
        
    }else{
        // str += root->right->data;/
        cout<<root->right->data;
    }
    cout<<endl;

    display(root->left);
    display(root->right);
}

int main(){
    // tree* root =NULL;
    // root->left = new tree(3);
    // root->right = new tree(6);
    // root->left->left = new tree(2);
    // root->left->right = new tree(0);
    // root->right->left = new tree(7);
    // root->right->left->right = new tree(9);
    // root->right->right = new tree(8);
    // tree* n = takeInpute(root,true);
    // display(n);
    // postorder(n);
    bool n ;
    cin>>n;// input true;
    if(n)
    cout<<"true";
    else
    cout<<"false";
    // postorder(n);
}