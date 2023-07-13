#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    int index = 0;  // index to track the position in the modified array

    for (int i = 0; i < chars.size(); i++) {
        char currentChar = chars[i];
        int count = 1;

        // Count the number of consecutive repeating characters
        while (i + 1 < chars.size() && chars[i + 1] == currentChar) {
            count++;
            i++;
        }

        chars[index++] = currentChar;

        // Append the count to the array if it's greater than 1
        if (count > 1) {
            std::string countString = std::to_string(count);

            for (char c : countString) {
                chars[index++] = c;
            }
        }
    }

    return index;
}

int main() {
    std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);

    std::cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        std::cout << chars[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "New length: " << newLength << std::endl;

    return 0;
}
