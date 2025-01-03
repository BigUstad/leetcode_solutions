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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return new_head;
        }
        int carry_over = 0;
        ListNode* l3_cur = nullptr;
        while (l1 && l2) {
            int l3_val = l1->val + l2->val + carry_over;
            if (l3_val >= 10) {
                carry_over = (l3_val / 10);
                l3_val = (l3_val % 10);
            } else {
                carry_over = 0;
            }
            // std::cout << "1." << l3_val << std::endl;
            if (!new_head) {
                new_head = l3_cur = new ListNode(l3_val);
            } else {
                l3_cur->next = new ListNode(l3_val);
                l3_cur = l3_cur->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1 && !l2 && !carry_over) {
            return new_head;
        }
        if (!l1 && !l2 && carry_over) {
            l3_cur->next = new ListNode(carry_over);
            return new_head;
        }
        // If the list is not completed.
        l3_cur->next = (l1) ? l1 : l2;
        if (carry_over) {
            ListNode* l3_prev = l3_cur;
            l3_cur = l3_cur->next;
            while (l3_cur != nullptr) {
                int l3_val = l3_cur->val + carry_over;
                if (l3_val >= 10) {
                    carry_over = (l3_val / 10);
                    l3_val = (l3_val % 10);
                } else {
                    carry_over = 0;
                }
                // std::cout << "2." << l3_val << std::endl;
                l3_cur->val = l3_val;
                l3_prev = l3_cur;
                l3_cur = l3_cur->next;
            }
            // std::cout << "3." << l3_cur << " " << carry_over << std::endl;
            if (carry_over) {
                l3_prev->next = new ListNode(carry_over);
            }
        }
        return new_head;
    }

private:
    ListNode* new_head = nullptr;
};
