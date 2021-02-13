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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* cur = head;
        ListNode* curcur = head->next;
        while (cur != nullptr && curcur != nullptr)
        {
            if (cur == curcur)//Same node encountered a second time. Circular
                return true;
            cur = cur->next;
            if (curcur->next != nullptr)
                curcur = curcur->next->next;
            else
                return false;
        }
        return false;        
    }
};
