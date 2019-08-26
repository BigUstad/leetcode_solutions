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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Cur = l1;
        ListNode* l2Cur = l2;
        int carryOver = 0;
        ListNode* newHead = nullptr;
        ListNode* lCur = nullptr;
        ListNode* lPrev = nullptr;
        while ( l1Cur != nullptr && l2Cur != nullptr )
        {
            int lSum = carryOver + l1Cur->val + l2Cur->val;
            int lRem = lSum % 10;
            int lQuot = lSum / 10;
            ListNode* newNode = new ListNode(lRem);
            if ( !newHead )
            {
                newHead = newNode;
            }
            carryOver = lQuot;
            if ( lPrev )
            {
                lPrev->next = newNode;
            }
            lPrev = newNode;
            l1Cur = l1Cur->next;
            l2Cur = l2Cur->next;
        }
        lCur = (l1Cur != nullptr)?l1Cur:l2Cur;
        while ( (lCur != nullptr) || carryOver > 0 )
        {
            int lSum;
            int lRem;
            if ( lCur )
            {
                lSum = carryOver + lCur->val;
                lRem = lSum % 10;
                carryOver = lSum / 10;
            }
            else
            {
                lRem = carryOver;
                if ( carryOver >= 10 )
                {
                    lRem = carryOver % 10;
                    carryOver = lRem / 10;
                    lSum = lRem;
                }
                else
                {
                    lRem = carryOver;
                    carryOver = 0;
                }
            }
            ListNode* newNode = new ListNode(lRem);
            if ( lPrev )
            {
                lPrev->next = newNode;     
                lPrev = newNode;

            }
         
            if (lCur)
                lCur = lCur->next;
        }
        return newHead;
    }
};
