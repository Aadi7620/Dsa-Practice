#include <iostream>
#include <vector>
using namespace std;

class MyStack {
    vector<char> v;

public:
    void push(char val) {
        v.push_back(val);
    }

    void pop() {
        if (!v.empty()) v.pop_back();
    }

    char top() {
        if (!v.empty()) return v.back();
        return '\0';  // Return null character if stack is empty
    }

    bool empty() {
        return v.empty();
    }

    bool validParenthesis(const string& s) {
        MyStack aa;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                aa.push(ch);
            } else {
                if (aa.empty()) return false;

                char topChar = aa.top();
                if ((topChar == '(' && ch == ')') ||
                    (topChar == '{' && ch == '}') ||
                    (topChar == '[' && ch == ']')) {
                    aa.pop();
                } else {
                    return false;
                }
            }
        }
        return aa.empty();
    }
};

int main() {
    MyStack stack;
    string expression;

    cout << "Enter the expression: ";
    cin >> expression;

    if (stack.validParenthesis(expression)) {
        cout << "Valid expression\n";
    } else {
        cout << "Invalid expression\n";
    }

    return 0;
}
