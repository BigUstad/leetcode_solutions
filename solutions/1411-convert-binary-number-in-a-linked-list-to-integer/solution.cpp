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
    int getDecimalValue(ListNode* head) {
        std::stack<int> s;
        int x = 1;
        unsigned long res = 0;
        auto cur = head;
        while (cur) {
            s.push(cur->val);
            cur = cur->next;
        }
        while (!s.empty()) {
            if (s.top() > 0)
                res += x;
            x = x * 2;
            s.pop();
        }
        return res;
    }
};
