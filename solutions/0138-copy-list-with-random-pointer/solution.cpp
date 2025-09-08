/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<int, int> indices_map;
        std::unordered_map<int, Node*> new_nodes_map;
        if (!head) return nullptr;
        Node* new_head = nullptr;
        getKeyMap(head, indices_map);
        createNewList(head, new_head, new_nodes_map);
        assignRandoms(head, new_head, indices_map, new_nodes_map);

        return new_head;
    }
private:
    inline void getKeyMap(Node* head, std::unordered_map<int, int>& indices_map) {
        Node* cur = head;
        std::unordered_map<Node*, int> addr_to_index_map;
        int index = 0;
        while (cur) {
            addr_to_index_map[cur] = index++;
            cur = cur->next;
        }
        cur = head;
        index = 0;
        while (cur) {
            if (cur->random) {
                indices_map[index++] = addr_to_index_map[cur->random];
            } else {
                indices_map[index++] = -1;
            }
            cur = cur->next;
        }
    }
    inline void createNewList(Node* head, Node*& new_head, std::unordered_map<int, Node*>& new_nodes_map) {
        Node* prev = nullptr;
        int index = 0;
        while (head) {
            Node* cur = new Node(head->val);
            if (!new_head) {
                new_head = cur;
            }
            if (prev) {
                prev->next = cur;
            }
            new_nodes_map[index++] = cur;
            head = head->next;
            prev = cur;
        }
    }
    inline void assignRandoms(Node* head, Node* new_head,
        std::unordered_map<int, int>& indices_map,
        std::unordered_map<int, Node*>& new_nodes_map) {
        int index = 0;
        while (head && new_head) {
            int orig_index = indices_map[index++];
            if (orig_index != -1) {
                new_head->random = new_nodes_map[orig_index];
            } else {
                new_head->random = nullptr;
            }
            head = head->next;
            new_head = new_head->next;
        }
    }
};
