#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MyStack{

    vector<int> v;
public:
void push(int val){
    v.push_back(val);
}
void pop(){
    v.pop_back();
}
int top(){
    return v[v.size()-1];
}
bool empty(){
    return v.size() == 0;
}
};
int main(){
    MyStack aa;
    aa.push(33);
    aa.push(44);
    aa.push(80);
    aa.pop();
    while(!aa.empty()){
        cout<<aa.top()<<" ";
        aa.pop();
    }
    return 0;
}