// deque is double ended queue
// we can push and pop from both ends
#include<iostream>
#include<deque>
using namespace std;
int main (){
    deque<int> aa;
    aa.push_back(10);
    aa.push_back(20);
    aa.push_back(30);
    aa.push_front(40);
    while(!aa.empty()){
        cout<<aa.front()<<endl;
        aa.pop_front();
    }
    aa.pop_back();
    cout<<endl;
    return 0;
}