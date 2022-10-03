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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummyHead = new ListNode();
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* newCur = dummyHead;
        int sumBwZeroes = 0;
        
        bool firstOne = false;
        
        while ( cur != nullptr ) {
            if ( cur->val == 0 && !firstOne ) {
                firstOne = true;
                prev = cur;
                cur = cur->next;
            } else if ( cur->val == 0 && firstOne ) {
                firstOne = false;
                prev = cur;
                cur = cur->next;
                ListNode* temp = new ListNode(sumBwZeroes);
                newCur->next = temp;
                newCur = temp;
                sumBwZeroes = 0;
            } else if ( cur->val != 0 && firstOne ) {
                sumBwZeroes += cur->val;
                prev = cur;
                cur = cur->next;
            } else if ( cur->val != 0 && !firstOne ) {
                if ( prev->val == 0 ) {
                    firstOne = true;
                }
                sumBwZeroes += cur->val;
                prev = cur;
                cur = cur->next;
            }
        }
        cur = dummyHead->next;
        delete dummyHead;
        return cur;
    }
};
