#include <iostream>
#include <cstring>
#include <cctype> // For tolower function
using namespace std;
char stack[30];
int top = -1, len;
void push(char ele) {
    if (top == len - 1) {
        cout << "Stack Overflow\n";
    } 
    else {
        top++;
        stack[top] = ele;
    }
}
char pop() {
    if (top == -1) {
        cout << "Stack Underflow\n";
        return '\0'; // Return null character if stack is empty
    } else {
        char ele = stack[top];
        top--;
        return ele;
}
}
int Palindrome(char str[]) {
    int actualLen = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            push(tolower(str[i]));
            actualLen++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            if (tolower(str[i]) != pop()) {
                return 0; // If any character doesn't match, it's not a palindrome
            }
        }
    }
    return 1;
}
int main() {
    char m[30];
    cout << "Enter string to check: ";
    cin.getline(m, 30);
    len = strlen(m);
    if (Palindrome(m)) {
        cout << "String is a palindrome\n";
    } 
    else {
        cout << "String is not a palindrome\n";
    }
    return 0;
}
