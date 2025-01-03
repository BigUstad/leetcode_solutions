/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */
class Solution {
public:
	vector<int> toArray(Node *head) {
        Node* cur = head;
        uint8_t count = 1; // 1 for head
        while (cur->next != nullptr) {
            count++;
            cur = cur->next;
        }
        std::vector<int> v(count, 0);
        while (cur != nullptr) {
            v[count - 1] = cur->val;
            cur = cur->prev;
            --count;
        }
        return v;
    }
};
