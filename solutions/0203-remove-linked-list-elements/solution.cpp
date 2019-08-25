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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        while ( head && head->val == val )
        {
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
        if ( !head )
            return nullptr;
        ListNode* cur = head;
        while ( head!= nullptr && cur != nullptr )
        {
            ListNode* temp = cur;
            ListNode* temp2 = cur->next;
            bool delCur = false;
            if ( cur->val == val )
            {
                if ( prev )
                {
                    prev->next = cur->next;
                }
                else
                {
                    head = cur->next;
                }
                delCur = true;
                delete cur;
            }
            if ( !delCur )
                prev = temp;
            cur = temp2;
        }
        return head;
    }
};
