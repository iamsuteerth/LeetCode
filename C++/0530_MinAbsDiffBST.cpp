/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 */
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int prev = -1;
    int min(int a, int b){
        return a < b ? a : b;
    }
    int abs(int a, int b){
        return (a-b < 0) ? b-a : a-b;
    }
    void inOrder(TreeNode* root, int &res){
        if(root == NULL){
            return;
        }
        inOrder(root->left, res);
            if(prev >= 0){
                res = min(res, root->val - prev);
            }
        prev = root->val;
        inOrder(root->right, res);
    }
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        inOrder(root, res);
        return res;
    }
};
