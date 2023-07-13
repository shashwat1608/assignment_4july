#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool canSwapStrings(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    int firstMismatch = -1;
    int secondMismatch = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != goal[i]) {
            if (firstMismatch == -1) {
                firstMismatch = i;
            } else if (secondMismatch == -1) {
                secondMismatch = i;
            } else {
                return false; // More than two mismatches
            }
        }
    }

    if (firstMismatch == -1 && secondMismatch == -1) {
        // No mismatches
        return true;
    }

    if (secondMismatch == -1 || firstMismatch == -1) {
        // Only one mismatch
        return false;
    }

    // Check if swapping the characters at firstMismatch and secondMismatch results in goal
    swap(s[firstMismatch], s[secondMismatch]);
    return s == goal;
}

int main() {
    string s, goal;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string goal: ";
    cin >> goal;

    bool result = canSwapStrings(s, goal);
    cout << "Can swap strings? " << (result ? "Yes" : "No") << endl;

    return 0;
}
