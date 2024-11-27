#include <bits/stdc++.h>
using namespace std;

#define N 100

class Stack {
public:
    string s1[N];
    int top;
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == N - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string s) {
        if (isFull()) {
            cout << "Insertion not possible. Overflow" << endl;
        } else {
            top = top + 1;
            s1[top] = s;
        }
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack is Empty. Pop not possible." << endl;
            return "";
        } else {
            string temp = s1[top];
            top = top - 1;
            return temp;
        }
    }
};

class Expression {
public:
    string in, pre, post;
    Stack s;

    bool isOperator(char x) {
        return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
    }

    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    void infix_to_postfix() {
        cout << "Enter infix expression: ";
        cin >> in;

        for (int i = 0; i < in.length(); i++) {
            if (isalnum(in[i])) {  // Operand (variable or number)
                post += in[i];
            } else if (in[i] == '(') {
                s.push(string(1, in[i]));  // Push '(' to stack
            } else if (in[i] == ')') {
                while (!s.isEmpty() && s.s1[s.top] != "(") {
                    string t = s.pop();
                    post += t;
                }
                s.pop();  // Pop '(' from stack
            } else {  // Operator
                while (!s.isEmpty() && prec(in[i]) <= prec(s.s1[s.top][0])) {
                    string t = s.pop();
                    post += t;
                }
                s.push(string(1, in[i]));
            }
        }
        while (!s.isEmpty()) {
            post += s.pop();
        }

        cout << "Given infix expression: " << in << endl;
        cout << "Converted postfix expression: " << post << endl;
    }

    void prefix_to_infix() {
        cout << "Enter Prefix Expression: ";
        cin >> pre;

        int n = pre.length();
        for (int i = n - 1; i >= 0; i--) {
            if (isOperator(pre[i])) {
                string op1 = s.pop();
                string op2 = s.pop();
                string s0 = "(" + op1 + pre[i] + op2 + ")";
                s.push(s0);
            } else {
                s.push(string(1, pre[i]));
            }
        }
        in = s.pop();
        cout << "Converted Infix expression is: " << in << endl;
    }

    void postfix_evaluation() {
        cout << "Enter Postfix Expression: ";
        cin >> post;

        int n = post.length();
        for (int i = 0; i < n; i++) {
            if (isOperator(post[i])) {
                string s1 = s.pop();
                string s2 = s.pop();

                stringstream stm1(s1), stm2(s2);
                int op1, op2, ans;

                stm1 >> op1;
                stm2 >> op2;

                if (post[i] == '+') ans = op2 + op1;
                else if (post[i] == '-') ans = op2 - op1;
                else if (post[i] == '*') ans = op2 * op1;
                else if (post[i] == '/') ans = op2 / op1;
                else if (post[i] == '^') ans = pow(op2, op1);

                stringstream stm3;
                stm3 << ans;
                s.push(stm3.str());
            } else if (isdigit(post[i])) {
                s.push(string(1, post[i]));
            }
        }

        string final = s.pop();
        cout << "Result of Postfix Evaluation: " << final << endl;
    }
};

int main() {
    Expression e1;
    int choice;

    do {
        cout << "Enter your choice: " << endl;
        cout << "1. Prefix to Infix Conversion" << endl;
        cout << "2. Infix to Postfix Conversion" << endl;
        cout << "3. Postfix Evaluation" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                e1.prefix_to_infix();
                break;
            case 2:
                e1.infix_to_postfix();
                break;
            case 3:
                e1.postfix_evaluation();
                break;
            case 4:
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}


