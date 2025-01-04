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
	vector<int> toArray(Node *node){
        if (!node) {
            vector<int> l_ret;
            return l_ret;
        }
        std::list<int> l;
        Node* cur = node;
        while (cur) {
            l.push_front(cur->val);
            cur = cur->prev;
        }
        cur = node->next;
        while (cur) {
            l.push_back(cur->val);
            cur = cur->next;
        }

        std::vector<int> v(l.begin(), l.end());
        return v;
    }
};
