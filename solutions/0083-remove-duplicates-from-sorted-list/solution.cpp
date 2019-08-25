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
     ListNode* holder = head;
     if ( !head || head->next == nullptr )
     {
         return head;
     }
     ListNode* runner = head->next;
     bool change = false;
     while ( holder!= nullptr && runner != nullptr )
     {
         // std::cout << " " << holder->val << " " << runner->val << std::endl;
         while ( runner != nullptr && holder->val == runner->val )
         {
             change = true;
             runner = runner->next;
         }
         if ( change )
         {
            holder->next = runner;
            holder = runner;
            if ( runner != nullptr )
                runner = runner->next;
            change = false;
         }
         else
         {
             holder = holder->next;
             runner = runner->next;
         }
     }
     return head;        
    }
};
