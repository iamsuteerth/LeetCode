/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/minimum-depth-of-binary-tree/
 */
#include <iostream>
#include <climits>
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
    int ans = INT_MAX;
    int dfs(TreeNode* root, int currentDepth){
        if (root == NULL) {
            return INT_MAX;
        }
        if(root->right == NULL && root->left == NULL){
            return currentDepth;
        }
        ans = min(ans,min(dfs(root->left, currentDepth + 1), dfs(root->right, currentDepth + 1)));
        return ans;
    }
    int minDepth(TreeNode* root) {
        ans = dfs(root, 1);
        return (ans == INT_MAX) ? 0 : ans;
    }
};
