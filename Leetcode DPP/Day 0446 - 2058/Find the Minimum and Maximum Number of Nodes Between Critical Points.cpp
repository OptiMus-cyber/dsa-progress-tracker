/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        vector<int> v,ans(2,-1);
        int c =1;
        while(cur!=nullptr && cur->next!=nullptr){
            if(prev!=nullptr && cur->next!=nullptr){
                if(prev->val < cur->val && cur->val > cur->next->val){
                    v.push_back(c);
                }
                if(prev->val > cur->val && cur->val < cur->next->val){
                    v.push_back(c);
                }
            }
            prev=cur;
            cur=cur->next;
            c++;
        }
        if(v.size()>=2){
        ans[1]=v[v.size()-1]-v[0];
        for(int i=1;i<v.size();i++){
            if(ans[0]==-1||ans[0]>v[i]-v[i-1]){
                ans[0]=v[i]-v[i-1];
            }
        }
        }
        return ans;
    }
};