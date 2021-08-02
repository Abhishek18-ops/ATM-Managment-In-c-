#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std;

int postfixexpretion(string s){
    int n = s.size();
    stack<int>st;
    for(int i =0; i<n; i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    cout << postfixexpretion(s) << " " << endl;

}
