/* 
 * Name : Suteerth Subramaniam
 * Language Used : C++
 * Question Link : https://leetcode.com/problems/check-completeness-of-a-binary-tree/
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int i=0,f=0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(f && node != NULL) return false;
            if(node== NULL){
                f=1;
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;

    }
};
