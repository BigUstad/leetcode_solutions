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
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == nullptr ||  head->next == nullptr )
        {
            return head;
        }
        ListNode* runner = head->next;
        ListNode* follower = head;
        
        while ( runner != nullptr)
        {
            if (follower != nullptr && 
                follower->val != runner->val )
            {
                if (follower->next != nullptr)
                    follower->next->val = runner->val;
                follower = follower->next;
            }
            runner = runner->next;
        }
        if ( follower != nullptr)
            follower->next = nullptr;
        return head;
    }
};
