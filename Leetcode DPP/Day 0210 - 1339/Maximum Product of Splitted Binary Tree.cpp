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
    int mod=1e9+7;
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if(root==nullptr) return 0;
        int left=solve(root->left, mp);
        int right=solve(root->right, mp);
        mp[root]=root->val+left+right;
        return mp[root];
    }
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        solve(root, mp);
        long long int res=0;
        for(auto m: mp) {
            if(m.first!=root) res=max(res, 1ll*(mp[root]-m.second)*m.second);
        }
        return res%mod;
    }
};