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
    int pairSum(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        int l=0;
        while(f) {
            s=s->next;
            f=f->next->next;
            l++;
        }
        f=head;
        vector<int>arr(l, 0);
        for(int i=0; i<l; i++) {
            arr[i]+=(s->val);
            arr[l-i-1]+=(f->val);
            s=s->next;
            f=f->next;
        }
        return *max_element(arr.begin(), arr.end());
    }
};