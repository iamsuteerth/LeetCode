/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/symmetric-tree/
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
    bool areEqual(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2)
            return true;
        if((!n1 || !n2) && (n1 || n2))
            return false;
        if(n1->val == n2->val)
            return (areEqual(n1->right, n2->left) && areEqual(n1->left, n2->right));
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return false;
        return areEqual(root->right, root->left);
    }
};