#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class MyStack {
public:
    string arr[50];
    int top;
    MyStack() { top = -1; }

    bool isempty() {
        return top == -1;
    }

    bool isfull() {
        return top == 49;
    }

    void push(string str) {
        if (isfull()) {
            cout << "Stack is full." << endl;
        } else {
            arr[++top] = str;
        }
    }
    
    string pop() {
        if (isempty()) {
            cout << "Stack is empty." << endl;
            return "";
        } else {
            return arr[top--];
        }
    }
};

class Expression {
public:
    bool isoperator(char x) {
        return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
    }

    bool isoperand(char x) {
        return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9');
    }
    int prec(char x) {
        if (x == '^')
            return 3;
        else if (x == '/' || x == '*')
            return 2;
        else if (x == '+' || x == '-')
            return 1;
        else
            return 0;
    }


void prefix_to_infix() {
        MyStack s;
        string prefix, infix;
        cout << "Enter the prefix expression: ";
        cin >> prefix;
        int length = prefix.length();

        for (int i = length - 1; i >= 0; i--) {
            if (isoperand(prefix[i])) {
                s.push(string(1, prefix[i]));
            } else if (isoperator(prefix[i])) {
                string op1 = s.pop();
                string op2 = s.pop();
                string temp = "(" + op1 + prefix[i] + op2 + ")";
                s.push(temp);
            }
        }
        infix = s.pop();
        cout << "\nInfix expression is: " << infix << endl;
    }
void infix_to_postfix() {
    MyStack s;
    string infix, postfix = "";
    cout << "Enter the infix expression: ";
    cin >> infix;
    int length = infix.length();

    for (int i = 0; i < length; i++) {
        
        if (isoperand(infix[i])) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(string(1, infix[i]));
        }
        else if (infix[i] == ')') {
            while (!s.isempty() && s.arr[s.top] != "(") {  
                postfix += s.pop();
            }
            s.pop();
        }
        else if (isoperator(infix[i])) {
            while (!s.isempty() && prec(infix[i]) <= prec(s.arr[s.top][0])) {
                postfix += s.pop();
            }
            s.push(string(1, infix[i]));
        }
    }
    while (!s.isempty()) {
        postfix += s.pop();
    }

    cout << "\nPostfix expression is: " << postfix << endl;
}


    void prefix_postfix(){
        MyStack s;
        string prefix,postfix;
        cout<<"Enter prfix"<<endl;
        cin>>prefix;
        int n=prefix.length();

        for(int i=n-1; i>=0; i--){
            if(isoperand(prefix[i])){
                s.push(string(1,prefix[i]));

            }
            else{
                s.push(s.pop()+s.pop()+prefix[i]);
            }
        }

        cout << s.pop() << endl;
    }
};

class EvalStack {
public:
    int data[50];
    int top;

    EvalStack() {
        top = -1; 
    }
        bool isoperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }
    void push(int x) {
        if (top == 49) {
            cout << "Stack is full." << endl;
        } else {
            data[++top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1; 
        } else {
            return data[top--];
        }
    }

void postfix_eval() {
        string postfix;
        cout << "Enter Postfix Expression: ";
        cin >> postfix;

        int len = postfix.length();
        for (int i = 0; i < len; i++) {
             if (isdigit(postfix[i])) {  
                int num = 0;
                while (i < len && isdigit(postfix[i])) {
                    num = num * 10 + (postfix[i] - '0');
                    i++;
                }
                push(num);
                i--;  
            } else if (isoperator(postfix[i])) {  
                int y = pop();
                int x = pop();
                int result = operate(x, y, postfix[i]);
                push(result);
            }
        }

        cout << "Postfix Evaluation Result: " << pop() << endl;
    }

    int operate(int x, int y, char op) {
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/': 
                if (y == 0) {
                    cout << "Error: Division by zero." << endl;
                    return 0;
                }
                return x / y;
            case '^': 
            {
                int result = 1;
                for (int i = 0; i < y; i++) {
                    result *= x;
                }
                return result;
            }
            default: 
                cout << "Invalid operator" << endl;
                return 0;
        }
    }
};

int main() {
    Expression exp;
    EvalStack eval;

    int choice;
    cout << "1. Prefix to Infix\n";
    cout << "2. Infix to Postfix\n";
    cout << "3. Postfix Evaluation\n";
    cout<<  "4. Prefix to Postfix\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            exp.prefix_to_infix();
            break;
        case 2:
            exp.infix_to_postfix();
            break;
        case 3:
            eval.postfix_eval();
            break;

        case 4:
            exp.prefix_postfix();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}