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
    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead = nullptr;
        ListNode* bfr = new ListNode(0); // Dummy header of before.
        ListNode* aft = new ListNode(0); //Dummy
        ListNode* cur = head;
        ListNode* curBfr = nullptr;
        ListNode* curAft = nullptr;
        ListNode* eleNode = nullptr;
        ListNode* bfrPrev = nullptr;
        ListNode* aftPrev = nullptr;
        
        while ( cur != nullptr )
        {
            ListNode* temp1 = cur;
            ListNode* temp2 = cur->next;
            if ( cur->val < x )
            {
                if ( bfrPrev )
                    bfrPrev->next = cur;
                else
                    bfr->next = cur;
                cur->next = nullptr;
                bfrPrev = cur;
            }
            else if ( cur->val >= x )
            {
                if ( aftPrev )
                {
                    aftPrev->next = cur;
                }
                else
                    aft->next = cur;
                cur->next = nullptr;
                aftPrev = cur;
            }
            cur = temp2;
        }
        if ( bfrPrev )
        {
            bfrPrev->next = aft->next;
            newHead = bfr->next;
            delete bfr;
            delete aft;
        }
        else
        {
            newHead = aft->next;
            delete bfr;
            delete aft;
        }
        return newHead;
    }
};
