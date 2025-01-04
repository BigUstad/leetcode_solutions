/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool detectCycleFirst(ListNode* head, ListNode*& runner, int &n) {
        ListNode* follower = head;
        while (follower && runner) {
            follower = follower->next;
            if (runner->next != nullptr) {
                runner = runner->next->next;
            } else {
                return false;
            }
            if (follower == runner) {
                return true;
            }
            ++n;
        }
        // If either of them reached nullptr.
        // No cycle
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        int n = 0;
        ListNode* runner = head;
        if (!detectCycleFirst(head, runner, n)) {
            return nullptr;
        }
        // At this point runner is pointing to a node in the cycle.
        // Follower needs to catch up with it.
        ListNode* follower = head;
        while (follower != runner) {
            // follower will touch each node once.
            // Runner will remain in the cycle.
            // So they will meet at one point
            follower = follower->next;
            runner = runner->next;
        }

        return runner;
    }
};
