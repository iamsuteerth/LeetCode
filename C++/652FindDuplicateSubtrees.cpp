#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    string findSameStringSubtree(unordered_map<string, int> &umap, vector<TreeNode *> &res, TreeNode *root)
    {
        if (root == NULL)
        {
            return "N";
        }
        string subtr = to_string(root->val) + "," + findSameStringSubtree(umap, res, root->left) + "," + findSameStringSubtree(umap, res, root->right);
        if (umap[subtr] == 1)
        {
            res.push_back(root);
        }
        umap[subtr]++;
        return subtr;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> umap;
        vector<TreeNode *> res;
        findSameStringSubtree(umap, res, root);
        return res;
    }
};