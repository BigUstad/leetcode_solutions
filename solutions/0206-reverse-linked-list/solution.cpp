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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* newHead = nullptr;
        if ( !head || head->next == nullptr)
        {
            return head;
        }
        while ( cur != nullptr)
        {
            listStack.push(cur);
            cur = cur->next;
        }
        while(!listStack.empty())
        {
            cur = listStack.top();
            if ( newHead == nullptr)
            {
                newHead = cur;
            }
            cur->next = nullptr;
            listStack.pop();
            if ( prev != nullptr )
            {
                prev->next = cur;
            }
            prev = cur;
        }
        return newHead;
    }
private:
    stack<ListNode*> listStack;
};
