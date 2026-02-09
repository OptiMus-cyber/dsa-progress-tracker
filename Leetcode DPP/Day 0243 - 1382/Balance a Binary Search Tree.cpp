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
    void solve(TreeNode* root, vector<int> &arr) {
        if(root==nullptr) return;
        solve(root->left, arr);
        arr.push_back(root->val);
        cout<<arr.back();
        solve(root->right, arr);
    }

    TreeNode* cTree(int l, int r, vector<int> &arr) {
        if(l>r) return nullptr;
        if(l==r) return new TreeNode(arr[l]);
        int mid=(r-l)/2+l;
        TreeNode* left=cTree(l, mid-1, arr);
        TreeNode* right=cTree(mid+1, r, arr);
        return new TreeNode(arr[mid], left, right);
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        solve(root, arr);
        TreeNode* res;
        res=cTree(0, arr.size()-1, arr);
        return res;
    }
};