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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        dummy->next = head;
        ListNode* temp = dummy;
        while(temp->next!=NULL){
            if(temp->next->val==val){
                ListNode* nodetodelete = temp->next;
                temp->next = temp->next->next;
                delete nodetodelete;
            } 
            else temp = temp->next;
        }
        return dummy->next;
    }
};