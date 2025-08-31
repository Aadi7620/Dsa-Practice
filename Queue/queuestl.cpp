#include<iostream>
#include<queue>
using namespace std;
int main (){
    queue<int> aa;
    aa.push(10);
    aa.push(20);
    aa.push(30);
    while(!aa.empty()){
        cout<<aa.front()<<endl;
        aa.pop();
    }
    cout<<endl;
    return 0;
}