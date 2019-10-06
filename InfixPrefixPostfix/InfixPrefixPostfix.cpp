/* Author: Rodney Nedlose
 * Date: 10.6.19
 * File:   InfixPrefixPostfix.cpp
 * Purpose: Program that takes User data for simple mathmatetical
 * equations in Infix, Prefix, or Postfix format, displays equations,
 * performs arithmetic, and displays correct answer to equation.  Takes
 * User choice for secondary form of same equation and displays the
 * new format as well as the correct answer to the equation.  The stack
 * ADT is used in performing these operations.
 * Input: User input is taken as strings and converted where necessary.
 * Output: Formatted equations based on choice as well as correct answer to
 * entered equations.
 * Exceptions: None.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>

using namespace std;

// Global variables
char choice2;
string op1;
string op2;
string oper;

double optr1;
double optr2;
double ttl;

// Stack used in operations
stack <string> exp;

// Function declarations
void Infix();
void Prefix();
void Postfix();
double Arithmetic(double a, double b, string oprtr);

// Main function to run program
int main() {

    // Menu variable for User choice
    char choice;

    // Formatting
    const string UNDERLINE = "__________________________________________________";

    // First Menu
    cout << UNDERLINE << endl;
    cout << setw(50) << "Choose from Infix, Prefix, or Postfix" << endl;

    cout << setw(50) <<"A. Infix" << endl;
    cout << setw(50) <<"B. Prefix" << endl;
    cout << setw(50) <<"C. Postfix" << endl;
    cout << setw(50) << "Enter your choice (A, B, or C): ";
    cin >> choice;
    cout << "" << endl;

    // Decision structure based on User choice
    if (tolower(choice) == 'a') {
        // Call Infix() function
        Infix();
    }else if (tolower(choice) == 'b'){
        // Call Prefix() function
        Prefix();
    }else if (tolower(choice) == 'c'){
        // Call Postfix() function
        Postfix();
    }

    cout << UNDERLINE << endl;

    return 0;
}


// Infix function definition
void Infix() {
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

    // Convert input strings to doubles for arithmetic operations
    optr1 = stod(op1);
    optr2 = stod(op2);

    // Adding input to the stack
    exp.push(op2), exp.push(oper), exp.push(op1);

    /* Display the correctly formatted equation by using
     the top() function and then using the pop() function
     to remove items from the stack*/
    cout << setw(50) << "The Infix expression is: " << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " = "
    << Arithmetic(optr1, optr2, oper)<< endl;
    exp.pop();

    // Second menu for secondary choice
    cout << setw(50) << "Now choose from Prefix, or Postfix" << endl;
    cout << setw(50) <<"A. Prefix" << endl;
    cout << setw(50) <<"B. Postfix" << endl;
    cout << setw(50) << "Enter your choice (A or B): ";
    cin >> choice2;
    cout << "" << endl;

    // Decision structure for secondary choice
    if (choice2 == tolower('a')){
        cout << setw(50) << "Prefix expressions look like: " << endl;
        cout << setw(50) << "<operator> <operand> <operand>" << endl;
        exp.push(op2), exp.push(op1), exp.push(oper);
        cout << setw(50) << "The Prefix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " ";
        exp.pop();
        cout << exp.top() << " = "
        << Arithmetic(optr1, optr2, oper)<< endl;
        exp.pop();

    }else if (choice2 == tolower('b')) {
        cout << setw(50) << "Postfix expressions look like: " << endl;
        cout << setw(50) << "<operand> <operand> <operator>" << endl;
        exp.push(oper),exp.push(op2),exp.push(op1);
        cout << setw(50) << "The Postfix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " ";
        exp.pop();
        cout << exp.top() << " = "
        << Arithmetic(optr1, optr2, oper)<< endl;
        exp.pop();
    }
}

// Prefix function definition
void Prefix() {
    cout << setw(50) << "Prefix expressions look like: " << endl;
    cout << setw(50) << " <operator> <operand> <operand>" << endl;

    cout << setw(50) << "Enter the operator(+, -, *, /): ";
    cin >> oper;
    cout << "" << endl;
    cout << setw(50) << "Enter the first operand(positive integers only): ";
    cin >> op1;
    cout << "" << endl;
    cout << setw(50) << "Enter the second operand(positive integers only): ";
    cin >> op2;
    cout << "" << endl;

    // Convert input strings to doubles for arithmetic operations
    optr1 = stod(op1);
    optr2 = stod(op2);

    // Adding input to the stack
    exp.push(op2),exp.push(op1),exp.push(oper);

    /* Display the correctly formatted equation by using
    the top() function and then using the pop() function
    to remove items from the stack*/
    cout << setw(50) << "The Prefix expression is: " << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " = "
    << Arithmetic(optr1, optr2, oper)<< endl;
    exp.pop();

    // Second menu for secondary choice
    cout << setw(50) << "Now choose from Infix, or Postfix" << endl;
    cout << setw(50) <<"A. Infix" << endl;
    cout << setw(50) <<"B. Postfix" << endl;
    cout << setw(50) << "Enter your choice (A or B): ";
    cin >> choice2;
    cout << "" << endl;

    // Decision structure for secondary choice
    if (choice2 == tolower('a')){
        cout << setw(50) << "Infix expressions look like: " << endl;
        cout << setw(50) << "<operand> <operator> <operand>" << endl;
        exp.push(op2),exp.push(oper),exp.push(op1);
        cout << setw(50) << "The Infix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " = "
        << Arithmetic(optr1, optr2, oper)<< endl;
        exp.pop();

    }else if (choice2 == tolower('b')) {
        cout << setw(50) << "Postfix expressions look like: " << endl;
        cout << setw(50) << "<operand> <operand> <operator>" << endl;
        exp.push(oper),exp.push(op2),exp.push(op1);
        cout << setw(50) << "The Postfix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " ";
        exp.pop();
        cout << exp.top() << " = "
        << Arithmetic(optr1, optr2, oper)<< endl;
        exp.pop();
    }
}

// Postfix function definition
void Postfix() {
    cout << setw(50) << "Postfix expressions look like: " << endl;
    cout << setw(50) << "<operand> <operand> <operator>" << endl;

    cout << setw(50) << "Enter the first operand(positive integers only): ";
    cin >> op1;
    cout << "" << endl;
    cout << setw(50) << "Enter the second operand(positive integers only): ";
    cin >> op2;
    cout << "" << endl;
    cout << setw(50) << "Enter the operator(+, -, *, /): ";
    cin >> oper;
    cout << "" << endl;

    // Convert input strings to doubles for arithmetic operations
    optr1 = stod(op1);
    optr2 = stod(op2);

    // Adding input to the stack
    exp.push(oper), exp.push(op2), exp.push(op1);

    /* Display the correctly formatted equation by using
    the top() function and then using the pop() function
    to remove items from the stack*/
    cout << setw(50) << "The Postfix expression is: " << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " ";
    exp.pop();
    cout << exp.top() << " = "
    << Arithmetic(optr1, optr2, oper)<< endl;
    exp.pop();

    // Second menu for secondary choice
    cout << setw(50) << "Now choose from Prefix, or Infix" << endl;
    cout << setw(50) <<"A. Infix" << endl;
    cout << setw(50) <<"B. Prefix" << endl;
    cout << setw(50) << "Enter your choice (A or B): ";
    cin >> choice2;
    cout << "" << endl;

    // Decision structure for secondary choice
    if (choice2 == tolower('a')){
        cout << setw(50) << "Infix expressions look like: " << endl;
        cout << setw(50) << "<operand> <operator> <operand>" << endl;
        exp.push(op2),exp.push(oper),exp.push(op1);
        cout << setw(50) << "The Infix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " ";
        exp.pop();
        cout << exp.top() << " = "
        << Arithmetic(optr1, optr2, oper)<< endl;
        exp.pop();

    }else if (choice2 == tolower('b')) {
        cout << setw(50) << "Prefix expressions look like: " << endl;
        cout << setw(50) << "<operator> <operand> <operand>" << endl;
        exp.push(op2), exp.push(op1), exp.push(oper);
        cout << setw(50) << "The Prefix expression is: " << exp.top() << " " ;
        exp.pop();
        cout << exp.top() << " ";
        exp.pop();
        cout << exp.top() << " = "
        << Arithmetic(optr1, optr2, oper)<< endl;
        exp.pop();
    }
}

// Artithmetic function definition
// @return result of mathmatical equation based
// on operator type
double Arithmetic(double a, double b, string oprtr) {
    double total;

    if (oprtr == "+") {
        total = a + b;
    }else if (oprtr == "-"){
        total = a - b;
    }else if (oprtr == "*") {
        total = a * b;
    }else if (oprtr == "/"){
        total = a / b;
    }
    return total;
}
