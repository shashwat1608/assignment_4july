#include <iostream>
#include <stack>

bool isValidString(std::string s) {
    std::stack<int> leftParentheses, asterisks;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            leftParentheses.push(i);
        } else if (s[i] == '*') {
            asterisks.push(i);
        } else {
            if (!leftParentheses.empty()) {
                leftParentheses.pop();
            } else if (!asterisks.empty()) {
                asterisks.pop();
            } else {
                return false;
            }
        }
    }

    while (!leftParentheses.empty() && !asterisks.empty()) {
        if (leftParentheses.top() > asterisks.top()) {
            return false;
        }
        leftParentheses.pop();
        asterisks.pop();
    }

    return leftParentheses.empty();
}

int main() {
    std::string s;
    std::cout << "Enter the string: ";
    std::cin >> s;

    if (isValidString(s)) {
        std::cout << "The string is valid." << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }

    return 0;
}
