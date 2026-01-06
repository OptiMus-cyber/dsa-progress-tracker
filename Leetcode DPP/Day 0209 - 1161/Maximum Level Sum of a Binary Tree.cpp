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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int curr=1;
        long long sum=0, res=LONG_LONG_MIN, ans=-1;
        while(!q.empty()) {
            pair<TreeNode*, int> top=q.front();
            q.pop();
            if(top.second==curr) {
                sum+=top.first->val;
            } else {
                if(sum>res) {
                   res=sum;
                // cout<<top.second<<endl;
                   ans=top.second-1;
                }
                sum=top.first->val;
                curr=top.second;
            }
            if(top.first->left) {
                q.push({top.first->left, top.second+1});
            }
            if(top.first->right) {
                q.push({top.first->right, top.second+1});
            }
            if(q.empty())
                if(sum>res) {
                     res=sum;
                     ans=top.second;
                }
            // cout<<res<<" "<<ans<<endl;
        }
        return ans;
    }
};