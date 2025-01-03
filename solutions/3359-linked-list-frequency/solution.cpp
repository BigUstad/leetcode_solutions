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
    ListNode* frequenciesOfElements(ListNode* head) {
        std::unordered_map<unsigned int, unsigned int> freq_map;
        while (head != nullptr) {
            auto itr = freq_map.find(head->val);
            if (itr == freq_map.end()) {
                freq_map[head->val] = 1;
            } else {
                itr->second++;
            }
            head = head->next;
        }
        head = nullptr;
        ListNode *cur = nullptr;
        for (auto& [v, c]: freq_map) {
            if (head == nullptr) {
                head = new ListNode(c);
                cur = head;
            } else {
                cur->next = new ListNode(c);
                cur = cur->next;
            }
        }
        return head;
    }
};
