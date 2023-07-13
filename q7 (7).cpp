#include <iostream>
#include <stack>
#include <string>

std::string decodeString(const std::string& s) {
    std::stack<int> countStack;
    std::stack<std::string> stringStack;
    std::string currString;
    int currCount = 0;

    for (char c : s) {
        if (std::isdigit(c)) {
            currCount = currCount * 10 + (c - '0');
        } else if (c == '[') {
            countStack.push(currCount);
            stringStack.push(currString);
            currCount = 0;
            currString.clear();
        } else if (c == ']') {
            std::string decodedString = stringStack.top();
            stringStack.pop();
            int repeatCount = countStack.top();
            countStack.pop();

            for (int i = 0; i < repeatCount; ++i) {
                decodedString += currString;
            }

            currString = decodedString;
        } else {
            currString += c;
        }
    }

    return currString;
}

int main() {
    std::string encodedString;
    std::cout << "Enter the encoded string: ";
    std::cin >> encodedString;

    std::string decodedString = decodeString(encodedString);
    std::cout << "Decoded string: " << decodedString << std::endl;

    return 0;
}
