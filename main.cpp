#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>

using namespace std;

class Calculator {
public:
    // Function to check operator precedence
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    // Function to perform an arithmetic operation
    double applyOperation(double a, double b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return (b != 0) ? a / b : throw runtime_error("Division by zero");
        }
        return 0;
    }

    // Function to insert explicit multiplication (e.g., "15(5*7)" -> "15*(5*7)")
    string fixImplicitMultiplication(string expr) {
        string fixedExpr = "";
        for (int i = 0; i < expr.length(); i++) {
            char ch = expr[i];

            // Add '*' between number and '(' (e.g., "15(5*7)" -> "15*(5*7)")
            if (i > 0 && isdigit(expr[i - 1]) && ch == '(') {
                fixedExpr += '*';
            }

            fixedExpr += ch;
        }
        return fixedExpr;
    }

    // Function to convert infix expression to postfix
    string infixToPostfix(string infix) {
        stack<char> operators;
        string postfix = "";
        infix = fixImplicitMultiplication(infix);  // Fix implicit multiplication

        for (int i = 0; i < infix.length(); i++) {
            char ch = infix[i];

            // If the character is a number, extract the whole number
            if (isdigit(ch)) {
                while (i < infix.length() && (isdigit(infix[i]) || infix[i] == '.')) {
                    postfix += infix[i];
                    i++;
                }
                postfix += " "; // Space to separate numbers
                i--;
            }
            // If the character is '(', push it to stack
            else if (ch == '(') {
                operators.push(ch);
            }
            // If the character is ')', pop from stack until '(' is found
            else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    postfix += " ";
                    operators.pop();
                }
                operators.pop(); // Remove '(' from stack
            }
            // If the character is an operator
            else {
                while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                    postfix += operators.top();
                    postfix += " ";
                    operators.pop();
                }
                operators.push(ch);
            }
        }

        // Pop all remaining operators from the stack
        while (!operators.empty()) {
            postfix += operators.top();
            postfix += " ";
            operators.pop();
        }

        return postfix;
    }

    // Function to evaluate a postfix expression
    double evaluatePostfix(string postfix) {
        stack<double> values;
        stringstream ss(postfix);
        string token;

        while (ss >> token) {
            if (isdigit(token[0])) {  // If it's a number, push to stack
                values.push(stod(token));
            } else {  // If it's an operator, pop operands and calculate
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                values.push(applyOperation(a, b, token[0]));
            }
        }

        return values.top();
    }

    // Function to solve an infix mathematical expression
    double solveExpression(string expression) {
        string postfix = infixToPostfix(expression);
        return evaluatePostfix(postfix);
    }
};

int main() {
    Calculator calc;
    int choice;
    
    do {
        cout << "\n===================================== CLI Calculator Menu =====================================";
        cout << "\n1. Add";
        cout << "\n2. Subtract";
        cout << "\n3. Multiply";
        cout << "\n4. Divide";
        cout << "\n5. Solve an Expression";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            double num1, num2;
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            double result;
            switch (choice) {
                case 1: result = calc.applyOperation(num1, num2, '+'); break;
                case 2: result = calc.applyOperation(num1, num2, '-'); break;
                case 3: result = calc.applyOperation(num1, num2, '*'); break;
                case 4: 
                    if (num2 == 0) {
                        cout << "Error: Division by zero is not allowed!\n";
                        continue;
                    }
                    result = calc.applyOperation(num1, num2, '/'); 
                    break;
            }

            cout << "Result: " << result << endl;
        } else if (choice == 5) {
            string expression;
            cout << "Enter the mathematical expression (e.g., 20+15*(5*7)): ";
            cin >> expression;

            try {
                double result = calc.solveExpression(expression);
                cout << "Result: " << result << endl;
            } catch (const runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
        }
    } while (choice != 6);

    cout << "Exiting Calculator. Goodbye!\n";
    return 0;
}
