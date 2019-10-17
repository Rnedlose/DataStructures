#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int front, int end, string str);

int main() {

    string str;
    int front = 0;
    int end;

    cout << "Check if a string is a Palindrome." << endl;
    cout << "I.E. the word reads the same left to right as it does right to left" << endl;
    cout << "Example: madam." << endl;
    cout << "Enter a string: ";
    getline(cin,str);

    end = str.length()-1;

    if (isPalindrome(front, end, str))
        cout << "That string is a palindrome." << endl;
    else
        cout << "That string is NOT a palindrome." << endl;

    return 0;
}


bool isPalindrome(int front, int end, string str)
{
    if (front >= end) return true;
    if (tolower(str[front]) != tolower(str[end])) return false;

    return isPalindrome(++front, --end, str);
}
