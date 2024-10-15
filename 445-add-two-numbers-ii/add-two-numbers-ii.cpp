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
    ListNode* reverse(ListNode* node){
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = reverse(l1);
        ListNode* list2 = reverse(l2);
        int carry = 0, sum = 0;
        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while(list1 || list2 || carry){
            if(list1){
                carry+=list1->val;
                list1=list1->next;
            }
            if(list2){
                carry+=list2->val;
                list2=list2->next;
            }
            sum = carry%10;
            ListNode* temp = new ListNode(sum);
            ans->next = temp;
            carry = carry/10;
            ans = ans->next;
        }
        return reverse(curr->next);
    }
};