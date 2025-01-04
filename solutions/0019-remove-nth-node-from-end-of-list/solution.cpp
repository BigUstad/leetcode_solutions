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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;
        if (head->next == nullptr && n > 0)
            return nullptr;
        if (head->next == nullptr && n == 0)
            return head;
        ListNode* runner = head;
        ListNode* follower = head;
        ListNode* prev = nullptr;
        while (n) {
            runner = runner->next;
            --n;
        }
        while (runner) {
            prev = follower;
            follower = follower->next;
            runner = runner->next;
        }
        if (prev == nullptr) {
            // Only case I think
            return head->next;
        }
        prev->next = follower->next;
        return head;
    }
};
