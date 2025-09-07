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
    void reorderList(ListNode* head) {
        // Deal with any lists le than length 2
        if (!head || !head->next || !head->next->next) {
            return;
        }
        // Lets get the mid of the list as it will be the 'end'
        ListNode* mid = getMid(head);
        reorderListHelper(head, mid);
        /* ListNode* cur = head;
        while (cur) {
            std::cout << cur->val << " -> ";
            cur = cur->next;
        }
        std::cout << "EOL." << std::endl; */
    }
private:
    void reorderListHelper(ListNode* head, ListNode* mid) {
        std::stack<ListNode*> s;
        ListNode* cur = head;
        ListNode* top = nullptr;
        // Let's add the ones from Mid to last to stack.
        while (mid) {
            ListNode* temp = mid->next;
            mid->next = nullptr;
            s.push(mid);
            mid = temp;
        }
        // Pop from the stack & assign to the next of head
        while (!s.empty()) {
            top = s.top(); s.pop();
            ListNode* temp = cur->next;
            // If stack is empty. You've reached the original mid.
            cur->next = top;
            top->next = temp;
            // Original mid is the end of the list
            if (s.empty()) {
                top->next = nullptr;
            }
            cur = temp;
        }
    }
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // std::cout << "mid: " << slow->val << std::endl;
        return slow;
    }
};
