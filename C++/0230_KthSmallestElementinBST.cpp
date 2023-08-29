/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    int res;
    int ctr;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(--ctr == 0)
            res = root->val;
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        ctr = k;
        inorder(root);
        return res;
    }
};
