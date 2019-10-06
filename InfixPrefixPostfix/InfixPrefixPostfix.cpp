#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <stack>

using namespace std;

bool isOperator(string str);
void Infix();
void Prefix();
void Postfix();

int main() {
    char choice;
    const string UNDERLINE = "__________________________________________________";

    cout << UNDERLINE << endl;
    cout << setw(50) << "Choose from Infix, Prefix, or Postfix" << endl;

    cout << setw(50) <<"A. Infix" << endl;
    cout << setw(50) <<"B. Prefix" << endl;
    cout << setw(50) <<"C. Postfix" << endl;
    cout << setw(50) << "Enter your choice (A, B, or C): ";
    cin >> choice;
    cout << "" << endl;

    if (tolower(choice) == 'a') {
        Infix();
    }else if (tolower(choice) == 'b'){
        Prefix();
    }else if (tolower(choice) == 'c'){
        Postfix();
    }

    cout << UNDERLINE << endl;

    return 0;
}

bool isOperator(string str) {
    if (str == "+" || str == "-" || str == "*" || str == "/"){
        return true;
    }
}

void Infix() {
    char choice2;
    string op1;
    string op2;
    string oper;
    stack <string> exp;

    cout << setw(50) << "Infix expressions look like: " << endl;
    cout << setw(50) << "<operand> <operator> <operand>" << endl;

    cout << setw(50) << "Enter the first operand(positive integers only): ";
    cin >> op1;
    cout << "" << endl;
    cout << setw(50) << "Enter the operator(+, -, *, /): ";
    cin >> oper;
    cout << "" << endl;
    cout << setw(50) << "Enter the second operand(positive integers only): ";
    cin >> op2;
    cout << "" << endl;

    exp.push(op2), exp.push(oper), exp.push(op1);
    cout << setw(50) << "The Infix expression is: " << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " ";
    exp.pop();
    cout << exp.top() << endl;
    exp.pop();
    cout << setw(50) << "Now choose from Prefix, or Postfix" << endl;

    cout << setw(50) <<"A. Prefix" << endl;
    cout << setw(50) <<"B. Postfix" << endl;
    cout << setw(50) << "Enter your choice (A or B): ";
    cin >> choice2;
    cout << "" << endl;

    if (choice2 == tolower('a')){
        cout << setw(50) << "Prefix expressions look like: " << endl;
        cout << setw(50) << "<operator> <operand> <operand>" << endl;
        exp.push(op2), exp.push(op1), exp.push(oper);
        cout << setw(50) << "The Prefix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << endl;
        exp.pop();

    }else if (choice2 == tolower('b')) {
        cout << setw(50) << "Postfix expressions look like: " << endl;
        cout << setw(50) << "<operand> <operand> <operator>" << endl;
        exp.push(op1);
        exp.push(op2);
        exp.push(oper);
        cout << "" << endl;
    }
}

void Prefix() {
    char choice2;
    string op1;
    string op2;
    string oper;
    stack <string> exp;
}

void Postfix() {
    char choice2;
    string op1;
    string op2;
    string oper;
    stack <string> exp;
}
