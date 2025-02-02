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
    ListNode* middle(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeList(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode* temp;
        if(a->val <= b->val){
            temp = a;
            temp->next = mergeList(a->next, b);
        }
        else{
            temp = b;
            temp->next = mergeList(a, b->next);
        }
        return temp;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = middle(head);
        ListNode* a = head;
        ListNode* b = mid->next;
        mid->next = NULL;
        a = sortList(a);
        b = sortList(b);
        ListNode* result = mergeList(a,b);
        return result;
    }
};