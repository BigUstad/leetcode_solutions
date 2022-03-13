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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
            return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        auto cur1 = list1; auto cur2 = list2; auto newHead = new ListNode();
        ListNode* prev = newHead;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                 prev->next = cur1;
                cur1 = cur1->next;
            } else {
                 prev->next = cur2;
                cur2 = cur2->next;
            }
            prev = prev->next;
        }
        if (cur1)
            prev->next = cur1;
        if (cur2)
            prev->next = cur2;
            
        return newHead->next;
    }
};
