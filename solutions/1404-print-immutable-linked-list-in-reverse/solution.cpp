/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    // Trying O(1)
    void print(ImmutableListNode* head, ImmutableListNode* last) {
        if (!head || (head == last)) {
            // No need to print print
            return;
        }
        if (head->getNext() == last) {
            // Reached end of the list
            // Print this one.
            head->printValue();
            return;
        }
        ImmutableListNode* follower = head;
        ImmutableListNode* runner = head;
        // Get follower to the mid of list
        // We only need the follower to be at the middle of the list.
        // Runner can be nullptr
        while (runner != last && runner->getNext() != last) {
            follower = follower->getNext();
            runner = runner->getNext()->getNext();
        }
        print(follower, last); // latter portion first
        print(head, follower);
    }
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head)
            return;
        if (!head->getNext()) {
            head->printValue();
            return;
        }
        // Get the last to halve the list.
        /* ImmutableListNode* last = head;
        while (last->getNext()) {
            last = last->getNext();
        } */
        print(head, /* last */nullptr);
    }
    /* void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head)
            return;
        if (!head->getNext()) {
            head->printValue();
            return;
        }
        ImmutableListNode* runner = head;
        ImmutableListNode* follower = head;
        uint16_t count = 1; // head already counted
        while (runner->getNext()) {
            ++count;
            runner = runner->getNext();
        }
        // runner is at last node.
        while(count) {
            runner->printValue();
            while (follower->getNext() && follower->getNext() != runner) {
                follower = follower->getNext();
            }
            runner = follower;
            follower = head;
            --count;
        }
    }*/
    /* void printLinkedListInReverse(ImmutableListNode* head) {
        std::stack<ImmutableListNode*, std::vector<ImmutableListNode*>> s;
        ImmutableListNode* cur = head;
        while ( cur != nullptr ) {
            s.push(cur);
            cur = cur->getNext();
        }
        while ( !s.empty() ) {
            auto e = s.top();
            e->printValue();
            s.pop();
        }
        //std::cout << "]";
    } */
};
