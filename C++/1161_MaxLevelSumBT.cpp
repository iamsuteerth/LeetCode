#include <iostream>
#include <map>
#include <queue>
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
    map<int,int> mp;
    // int BFSmaxLevelSum(TreeNode* root) {
    //     int maxSum = INT_MIN;
    //     int resLevel = 0;
        
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     int currLevel = 1;
    //     while(!q.empty()){
    //         int n = q.size();
    //         int sum = 0;
    //         // Traversing n elements of current level
    //         while(n--){
    //             TreeNode* front = q.front();
    //             q.pop();
    //             sum += front->val;
    //             if(front->left)
    //                 q.push(front->left);
    //             if(front->right)
    //                 q.push(front->right);
    //         }
    //    if(sum > maxSum){
    //             maxSum = sum;
    //             resLevel = currLevel;
    //         }
    //         currLevel++;
    //     }
    //     return resLevel;
    // }
void dfs(TreeNode* root, int level){
    if(!root)
        return;
    mp[level] += root->val;
    dfs(root->left, level+1);
    dfs(root->right, level+1);
}
int maxLevelSum(TreeNode* root){
        mp.clear();
        dfs(root, 1);
        map<int, int>::iterator it = mp.begin();
        int maxSum = INT_MIN;
        int minLevel = 0;
        for( ; it != mp.end() ; it++){
            if(it->second > maxSum){
                maxSum = it->second;
                minLevel = it->first;
            }
        }
        return minLevel;
    }
};
