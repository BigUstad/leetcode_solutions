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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list1_b = list1;
        ListNode* list1_a = list1;
        ListNode* list2_last = list2;
        // Not solving for the standout cases

        if (!list2) {
            return list1;
        }
        if (a > b) {
            return list1;
        }
        if (a < 0 || b < 0) {
            return list1;
        }
        while (list2_last->next) {
            list2_last = list2_last->next;
        }
        // std::cout << list2_last->val << std::endl;
        int b_count = 0;
        while (b_count <= b) {
            if (list1_a && b_count < (a - 1)) {
                list1_a = list1_a->next;
            }
            if (list1_b && b_count != b) {
                list1_b = list1_b->next;
            }
            ++b_count;
        }
        // std::cout << "2. " << list1_a->val << ", " << list1_b->val << std::endl;
        // list1_a is now at prev of a
        // list1_b is now at b
        if (list1_a) {
            list1_a->next = list2;
        }
        if (list2_last && list1_b) {
            list2_last->next = list1_b->next;
        }
        return list1;
    }
};
