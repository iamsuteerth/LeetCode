/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/
 */
#include <iostream>
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
    int max(int a, int b){
        return a > b ? a : b;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int sizeOnLeft = 0, sizeOnRight = 0;
        if(root->left != NULL){
            sizeOnLeft = 1 + maxDepth(root->left);
        }
        else{
            sizeOnLeft += 1;
        }
        if(root->right != NULL){
            sizeOnRight = 1 + maxDepth(root->right);
        }
        else{
            sizeOnRight += 1;
        }
        return max(sizeOnRight, sizeOnLeft);
    }
};