/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int num, int &res) {
        if(root==nullptr) return;
        num=(num<<1)+root->val;
        if(root->left==nullptr&&root->right==nullptr) {
            res+=num;
            return;
        }
        solve(root->left, num, res);
        solve(root->right, num, res);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        int res=0;
        solve(root, 0, res);
        return res;
    }
};