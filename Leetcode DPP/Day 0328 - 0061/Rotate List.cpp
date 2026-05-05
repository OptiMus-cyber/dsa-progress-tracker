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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* fast=head;
        int l=0;
        while(fast&&fast->next) {
            fast=fast->next->next;
            l++;
        }
        l*=2;
        if(fast) l++;
        k%=l;
        fast=head;
        ListNode* slow=head;
        while(k--) {
            fast=fast->next;
        }
        while(fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};