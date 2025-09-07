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
    ListNode* deleteMiddle(ListNode* head) {
        // Deal with any lists le than length 2
        if (!head || !head->next) {
            return nullptr;
        }
        if (!head->next->next) {
            ListNode* cur = head->next;
            delete cur;
            head->next = nullptr;
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* slow = head; ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            next = slow->next; // slow has been changed
            fast = fast->next->next;
        }

        ListNode* mid = slow;
        prev->next = next;
        delete mid;
        return head;
    }
};
