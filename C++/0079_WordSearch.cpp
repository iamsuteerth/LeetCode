/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/word-search/
 */
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    bool solve(vector<vector<char>> &board, string &word, int x, int y, int index){
        if(index == word.length()){
            return true;
        }
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]){
            return false;
        }
        char curr = board[x][y];
        board[x][y] = '#';
        bool res = solve(board, word, x + 1, y, index + 1) || 
                   solve(board, word, x, y + 1, index + 1) || 
                   solve(board, word, x - 1, y, index + 1) || 
                   solve(board, word, x, y - 1, index + 1);
        board[x][y] = curr;
        return res;
    }
     bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0] && solve(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
