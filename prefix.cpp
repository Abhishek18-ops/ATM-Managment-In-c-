#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std;

int prefixexpretion(string s){
    int n = s.size();
    stack<int>st;
    for(int i = n-1; i >= 0; i--){
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i]-'0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
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
            cout << "Chala Ja Bhosdike !! " << endl;
                break;
            }
        }
    }
    return st.top();
}

int main(){
    string s;
    cin>>s;
    cout << prefixexpretion(s) << " " << endl;

}
