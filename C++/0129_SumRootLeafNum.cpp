/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/
 */
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
    void fun(TreeNode* root, int &s, int temp){
        if(!root)
            return;
        if(!root->left && !root->right){
            temp = temp*10 + root->val;
            s += temp;
            return;
        }
        temp = temp*10 + root->val;
        fun(root->right, s, temp);
        fun(root->left, s, temp);
    }
    int sumNumbers(TreeNode* root) {
        int s = 0;
        fun(root, s, 0);
        return s;
    }
};