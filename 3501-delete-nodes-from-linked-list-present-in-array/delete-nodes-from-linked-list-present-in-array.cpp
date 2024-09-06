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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = new ListNode();
        temp->next = head;
        ListNode* res = temp;
        unordered_set<int> st(nums.begin(), nums.end());
        while(res->next){
            if(st.find(res->next->val) != st.end()){
                res->next = res->next->next;
            }
            else res = res->next;
        }
        return temp->next;
    }
};