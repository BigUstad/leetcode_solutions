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
    ListNode* deleteDuplicates(ListNode* head) {
     if ( !head || head->next == nullptr ) {
         return head;
     }
     ListNode* holder = head;
     ListNode* runner = head->next;
     bool change = false;
     while ( holder!= nullptr && runner != nullptr )
     {
         while ( runner != nullptr && holder->val == runner->val ) {
             change = true;
             runner = runner->next;
         }
         if ( change ) {
            holder->next = runner;
            holder = runner;
            if ( runner != nullptr ){
                runner = runner->next;
            }
            change = false; // reset
         }
         else {
             holder = holder->next;
             runner = runner->next;
         }
     }
     return head;        
    }
};
