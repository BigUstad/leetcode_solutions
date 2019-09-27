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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if ( !l1 )
        return l2;
      if ( !l2 )
        return l1;
      ListNode* newHead = new ListNode(INT_MIN);
      ListNode* dummyhead = newHead;
      ListNode* prev = dummyhead;
      ListNode* cur = nullptr;
      ListNode* cur1 = l1;
      ListNode* cur2 = l2;
        

        while ( cur1 != nullptr && cur2 != nullptr) //cur1 && cur2
        {
            if ( cur1->val <= cur2->val)
            {
              cur = cur1;
              cur1 = cur1->next;
            } 
            else if (cur1->val > cur2->val) 
            {
              cur = cur2;
              cur2 = cur2->next;
            }

            if ( prev )
              prev->next = cur;
            prev = cur;
        }
        if ( cur1 != nullptr && prev )
        {
            prev->next = cur1;
        }
        else if ( cur2 != nullptr && prev )
        {
            prev->next = cur2;
        }
        ListNode* temp = dummyhead->next;
        delete dummyhead;
        return temp;
        
    }
};
