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
        if (!head || !head->next) {
            return head;
        }
        ListNode* prev_holder = nullptr;
        ListNode* holder = head;
        ListNode* runner = head->next;
        bool change = false;
        while (holder!= nullptr && runner != nullptr) {
            while (runner != nullptr && holder->val == runner->val) {
                change = true;
                runner = runner->next;
            }
            if (change) {
                if (prev_holder) {
                    prev_holder->next = runner;
                    // prev_holder stays same because everything from holder to prev of runner is being dropped from the list
                } else {
                    head = runner;
                    prev_holder = nullptr;
                }
                holder = runner;
                runner = (runner)?runner->next:nullptr;
                change = false; // Reset for next iteration
            } else {
                prev_holder = holder;
                holder = runner;
                runner = runner->next;
            }
        }
        return head;
    }
};
