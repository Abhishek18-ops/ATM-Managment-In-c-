#include <iostream>
#include <stack>
#include<queue>
using namespace std;
  
int main()
{
    queue<int>q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.pop();
    cout<<q.front();
    cout<<endl<<q.size();

    cout<<endl;

    q.emplace(10);
    cout<<q.front()<<endl;
    cout<<q.back();

    
    return 0;
}