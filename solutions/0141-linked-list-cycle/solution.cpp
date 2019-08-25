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
        ListNode* cur = head;
        ListNode* follower = head;
        ListNode* runner = head;
        while ( follower != nullptr && runner != nullptr )
        {
            if ( runner->next != nullptr && runner->next->next != nullptr )
                runner = runner->next->next;
            else
                return false;
            follower = follower->next;
            if ( follower == runner )
            {
                return true;
            }
        }
        if ( !follower || !runner )
            return false;
        return false;
    }
};
