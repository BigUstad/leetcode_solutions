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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        if (!head->next->next) {
            if (head->val == head->next->val) {
                return nullptr;
            }
            return head;
        }
        ListNode* prev = nullptr;
        unsigned short count = 0;
        ListNode* cur = head;
        ListNode* next = head->next;
        while (cur) {
            auto itr = l_counts.find(cur->val);
            if (itr == l_counts.end()) {
                l_counts[cur->val] = 1;
            } else {
                itr->second++;
            }
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            auto itr = l_counts.find(cur->val);
            if (itr->second <= 1) {
                prev = cur;
                if (next) {
                    next = next->next;
                }
                cur = cur->next;
                continue;
            }
            // Just remove the one node & continue
            // Not updating count in l_counts map
            // If it is more than 1, the node is removed from the linked list.
            if (prev) {
                prev->next = next;
                // For this case prev should remain the same
            } else {
                head = next;
            }
            if (next) {
                next = next->next;
            }
            cur = cur->next;

        }
        return head;
    }
private:
    std::unordered_map<int, unsigned short> l_counts;
};
