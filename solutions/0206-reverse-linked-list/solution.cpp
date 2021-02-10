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
        stack<ListNode*> aux;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            aux.push(cur);
            cur = cur->next;
        }
        ListNode* new_head = nullptr;
        while (!aux.empty())
        {
            cur = aux.top();
            cur->next = nullptr;
            cout<< cur->val << endl;
            aux.pop();
            if (new_head == nullptr)
            {
                new_head = cur;
            }
            if (prev != nullptr)
            {
                prev->next = cur;
            }
            prev = cur;
        }
        return new_head;
    }
};
