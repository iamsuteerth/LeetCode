/*
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * HARD QUESTION
 */
class Solution {
public:
    int lcs(string X, string Y, int m, int n){
        vector<vector<int>> L (m+1, vector<int>(n+1));
        // L[i][j] contains LCS of X[0..i-1] and Y[ 0...j-1]
        for (int i = 0 ; i <= m ; i++){
            for(int j = 0 ; j <= n ; j++){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                }
                else if (X[i - 1] == Y[j - 1]){
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else{
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]); // Diagonal element max
                }
            }
        }
        return L[m][n];
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        return n - lcs(s,t,n,n);
    }
};
