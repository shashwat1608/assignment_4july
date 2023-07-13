#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (s.empty() || p.empty() || s.length() < p.length()) {
        return result;
    }
    
    unordered_map<char, int> charCount;
    for (char c : p) {
        charCount[c]++;
    }
    
    int left = 0, right = 0, count = p.length();
    while (right < s.length()) {
        if (charCount[s[right++]]-- >= 1) {
            count--;
        }
        
        if (count == 0) {
            result.push_back(left);
        }
        
        if (right - left == p.length() && charCount[s[left++]]++ >= 0) {
            count++;
        }
    }
    
    return result;
}

int main() {
    string s, p;
    cout << "Enter the string s: ";
    cin >> s;
    cout << "Enter the string p: ";
    cin >> p;
    
    vector<int> indices = findAnagrams(s, p);
    
    cout << "Start indices of p's anagrams in s: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}
