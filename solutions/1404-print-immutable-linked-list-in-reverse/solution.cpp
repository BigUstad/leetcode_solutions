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
    void printLinkedListInReverse(ImmutableListNode* head) {
        std::stack<ImmutableListNode*> s;
        ImmutableListNode* cur = head;
        while ( cur != nullptr ) {
            s.push(cur);
            cur = cur->getNext();
        }
        //std::cout << "[";
        while ( !s.empty() ) {
            auto e = s.top();
            e->printValue();
            /*if ( s.size() > 1 )
                std::cout << ",";*/
            s.pop();
        }
        //std::cout << "]";
    }
};
