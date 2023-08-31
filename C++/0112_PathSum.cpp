/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/pascals-triangle-ii/
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
    bool visit(TreeNode* root, int sum, int &targetSum){
        if(!root){
            return false;
        }
        if (!root->left && !root->right)
            return sum + root->val == targetSum; // Check if this is a leaf node and the sum matches the target
        return visit(root->left, sum + root->val, targetSum) || visit(root->right, sum + root->val, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return visit(root, 0, targetSum);
    }
};
