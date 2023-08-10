/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/unique-binary-search-trees-ii/
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<TreeNode*> solve(int start, int end){
        if(start > end){
            return {NULL};
        }
        if(start == end){
            TreeNode* root = new TreeNode(start);
            return {root};
        }
        vector<TreeNode*> res;
        for(int i = start ; i <= end ; i++){
            
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);   
            
            for(TreeNode* leftRoot : left) {
                for(TreeNode* rightRoot : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left  = leftRoot;
                    root->right = rightRoot;
                    res.push_back(root);
                }
            }
        }
         return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};
