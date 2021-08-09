#include<iostream>
#include<stack>
using namespace std;

bool paranthesis(string s){
    int  n  = s.size();

    bool ans = true;
    stack<char>st;
    for(int i=0; i<n; i++){
        if(s[i] == '[' or s[i] == '{' or s[i] == '('){
            st.push(s[i]);
        }
        else if(!st.empty() && s[i] == ')'){
            if(st.top() == '('){
                st.pop();
            }else{
                ans = false; 
                break;
            }
        }
        else if(!st.empty() && s[i] == ']'){
            if(st.top() == '['){
                st.pop();
            }else{
                ans = false; 
                break;
            }
        }
        else if(!st.empty() && s[i] == '}'){
            if(st.top() == '{'){
                st.pop();
            }else{
                ans = false; 
                break;
            }
        }
    }
    if(!st.empty()){
        ans = false;
    }
    return ans;
}


int main(){
    string  s= "[{(}]";
    if(paranthesis(s)){
        cout << "Valid string "<< endl;
    }else{
        cout << " Not valid string " << endl;
    }
}