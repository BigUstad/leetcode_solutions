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
private:
    // Monotonic stack implementation from GeeksForGeeks
    void fillWithMonotonicStack(ListNode* head, std::vector<int>& l_res) {
        std::stack<std::pair<int, int>> s;
        int i = 0;
        // push the first element to the stack
        s.push(std::make_pair(head->val, 0));
        // iterate over the rest of the elements.
        while (head) {
            // If stack is empty push & find the NGE (next greater element)
            if (s.empty()) {
                s.push(std::make_pair(head->val, i));
                head = head->next;
                continue;
            }
            // If stack is not empty, pop the top.
            // If the popped element is smaller than cur
            // You got the pair. Now insert in the right place.
            // Pop till elements are smaller and stack is not empty
            while (!s.empty() && s.top().first < head->val) {
                l_res[s.top().second] = head->val;
                s.pop();
            }
            // The next element goes on stack to find the
            // next greater node
            s.push(std::make_pair(head->val, i));
            head = head->next;
            ++i;
            // Some guy on leetcode figured it out that
            // push_back(0), if it cannot be filled.
            // We just move on.
            // stack has been filled with elements already encountered
            l_res.push_back(0);
        }
        // The remaining elements on stack don't have next greater elements.
        // Print debug.
        /*
        while (!s.empty()) {
            l_res[s.top().second] = cur->val;
            std::cout << s.top().first << "-->" << " 0" << std::endl;
            s.pop();
            // All l_res assigned to 0 first, so no need for assignment
        }
        */
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> l_res;
        if (head == nullptr) {
            return l_res;
        }
        if (head->next == nullptr) {
            l_res.push_back(0);
            return l_res;
        }
        fillWithMonotonicStack(head, l_res);
        return l_res;
    }
};
