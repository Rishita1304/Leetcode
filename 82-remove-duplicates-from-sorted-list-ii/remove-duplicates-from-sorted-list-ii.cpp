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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* curr = head;
        ListNode* prev = temp;
        while(curr){
            if(curr->next && curr->val == curr->next->val){
                while(curr->next && curr->val == curr->next->val) curr=curr->next;
                prev->next = curr->next;
            }
            else prev = curr;
            curr = curr->next;
        }
        return temp->next;
    }
};