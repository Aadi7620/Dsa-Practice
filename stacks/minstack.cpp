#include<iostream>
#include<stack>
using namespace std;
class MinStack{
public:
stack<int>aa;
stack<int> temp;
MinStack(){

}

void push(int val){
    aa.push(val);
    if(temp.empty()){
        temp.push(val);
    }else if(temp.top() >= val){
        temp.push(val);
    }
}
void pop(){
    if(aa.top() == temp.top()){
        temp.pop();
        aa.pop();
    }
}
int top(){
    return aa.top();
}
int getMin(){
    return temp.top();
}

};
int main(){
    MinStack aa;
    aa.push(1);
    aa.push(2);
    aa.push(3);
    aa.pop();
    cout << aa.top() << endl;
    cout << aa.getMin() << endl;
    return 0;
}