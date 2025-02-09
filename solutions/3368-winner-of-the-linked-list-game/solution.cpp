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
    string gameResult(ListNode* head) {
        const std::string odd("Odd"), tie("Tie"), even("Even");
        if (!head) {
            return tie;
        }
        if (head->next == nullptr) {
            if (head->val % 2) {
                return odd;
            }
            return even;
        }
        unsigned short odd_team_count = 0, even_team_count = 0;
        ListNode* evener = head;
        ListNode* odder = head->next;
        while (odder && evener) {
            if (odder->val > evener->val) {
                ++odd_team_count;
            } else {
                ++even_team_count;
            }
            evener = odder->next;
            if (evener != nullptr) {
                odder = evener->next;
            }
        }
        if (odd_team_count == even_team_count) {
            return tie;
        }
        if (odd_team_count > even_team_count) {
            return odd;
        }
        return even;
    }
};
