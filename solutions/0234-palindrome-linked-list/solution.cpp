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
    bool isPalindrome(ListNode* head) {
        ListNode* prev;
        ListNode* cur;
        // Determine length
        cur = head; prev=nullptr;
        if ( head == nullptr || head->next == nullptr)
            return true;
        if ( head->next != nullptr && head->next->next == nullptr)
        {
            return (head->val == head->next->val);
        }
        int lth = 0;
        while ( cur != nullptr)
        {
            cur = cur->next;
            lth++;
        }
        bool lOdd = true;
        int lMid;
        if ( (lth % 2) == 0 )
            lOdd = false;
        if ( lOdd )
        {
            lMid = ceil((float)(lth /2));
        }
        else
        {
            lMid = lth/2;
        }
        int prevTravLth = lMid;
        int curIdx = 1;
        cur = head; prev = nullptr;
        while ( curIdx <= lMid && cur != nullptr)
        {
            palStack.push(cur->val);
            cur = cur->next;
            curIdx++;
        }
        if ( lOdd )
        {
            cur = cur->next;
        }
        while ( cur != nullptr && !palStack.empty())
        {
            int checkVal = palStack.top();
            palStack.pop();
            if ( cur->val != checkVal)
                return false;
            cur = cur->next;
        }
        return true;
    }
private:
    stack<int> palStack;
};
