#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = i + j; // Number of deletions required to make one string empty
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no deletion required
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]); // Choose minimum from deletion in word1 or word2
            }
        }
    }

    return dp[m][n]; // Minimum number of deletions required
}

int main() {
    string word1 = "abcdef";
    string word2 = "azced";

    int minSteps = minDistance(word1, word2);

    cout << "Minimum number of steps required: " << minSteps << endl;

    return 0;
}
