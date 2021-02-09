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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr
            || (head->next == nullptr && k == 1) )
            return head;
        uint n = 1;
        ListNode* kNode = head;
        ListNode* nMinusKNode = head;
        uint ik = 1;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            if (n == k)
            {
                kNode = cur;
                cout << "First " << kNode->val << endl;
            }
            cur = cur->next;
            n++;
        }
        uint iNmK = 1;
        cur = head;
        //uint nmk = ()
        while (cur != nullptr &&
               iNmK < (n-k))
        {
            cur = cur->next;
            iNmK++;
        }
        if (cur != nullptr)
        {
            nMinusKNode = cur;
            cout << "Second " << nMinusKNode->val << endl;
        }
        int temp = nMinusKNode->val;
        nMinusKNode->val = kNode->val;
        kNode->val = temp;
        return head;
    }
};
