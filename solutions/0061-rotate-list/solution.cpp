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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 0) {
            return head;
        }
        int n = 0;
        ListNode *cur = head;
        ListNode *last = nullptr;
        ListNode* new_head = head;
        ListNode* new_last = nullptr;
        int i = 0;
        // Find n
        while (cur) {
            ++n;
            last = cur;
            cur = cur->next;
        }
        if (k >= n) {
            k = k % n;
        }
        if (k == 0) {
            return head;
        }
        cur = head;
        // Find new_last, which is the n-k th node
        while ((i != (n - k)) && cur) {
            ++i;
            new_last = cur;
            cur = cur->next;
        }
        last->next = head;
        new_head = new_last->next;
        new_last->next = nullptr;
        return new_head;
    }
};
