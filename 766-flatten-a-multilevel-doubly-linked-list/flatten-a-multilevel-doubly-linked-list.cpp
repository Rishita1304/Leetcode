class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;

        Node* curr = head;
        stack<Node*> stk;

        while (curr) {
            if (curr->child) {
                // If there is a next node, push it to the stack
                if (curr->next) {
                    stk.push(curr->next);
                }

                // Connect the current node to the child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }

            // If there's no next node and the stack is not empty, pop from the stack
            if (!curr->next && !stk.empty()) {
                Node* nextNode = stk.top();
                stk.pop();
                curr->next = nextNode;
                nextNode->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};
