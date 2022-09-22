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
    ListNode* reverseList(ListNode* head) {
        if ( head == nullptr ) return head;
        if ( head->next == nullptr ) return head;
        if ( head->next->next == nullptr ) {
            ListNode* temp = head->next;
            head->next->next = head;
            head->next = nullptr;
            return temp;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = head->next;
        
        while ( cur != nullptr ) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            if ( next != nullptr) {
                next = next->next;
            }
        }
        return prev;
    }
};
