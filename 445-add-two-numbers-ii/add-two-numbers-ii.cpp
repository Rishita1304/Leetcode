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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
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
        int carry=0, sum=0;
        ListNode* curr = new ListNode(0);
        ListNode* temp = curr;
        while(list1 || list2 || carry){
            int sum=0;
            if(list1) {
                carry+=list1->val;
                list1=list1->next;
            }
            if(list2) {
                carry+=list2->val;
                list2=list2->next;
            }
            sum += carry%10;
            ListNode* ans = new ListNode(sum);
            temp->next = ans;
            carry/=10;
            temp = temp->next;
        }
        return reverse(curr->next);
    }
};