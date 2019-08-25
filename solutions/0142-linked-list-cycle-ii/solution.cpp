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
    ListNode *detectCycle(ListNode *head) {
        if ( !head || !head->next )
            return nullptr;
        ListNode* runner = head->next;
        ListNode* follower = head;
        ListNode* prev = follower;
        bool cycle = false;
        unsigned int followCount = 1;
        while ( !cycle && follower != nullptr && runner != nullptr )
        {
            if ( follower == runner )
            {
                std::cout << " Runner follower intersect at node: " << follower->val << std::endl;
                // Cycle found
                cycle = true;
            }
            prev = follower;
            if ( runner->next != nullptr)
                runner = runner->next->next;
            else return nullptr;
            follower = follower->next;
            ++followCount;
        }
        if ( cycle )
        {
            // follower == runner just confirms a cycle.
            std::map<ListNode*, int> ptrMap;
            ListNode* cur = head;
            unsigned int curCount=0;
            while (true )
            {
                if ( ptrMap.find(cur) == ptrMap.end() )
                {
                    // std::cout << " Not found in map: " << cur->val << std::endl;
                    ptrMap[cur] = cur->val;
                }
                else
                {
                    std::cout << " Found in map: " << cur->val << std::endl;
                    // Found the curve-causing node.
                    return cur;
                }
                prev=cur;
                cur=cur->next;
            }
        }
        return nullptr;
    }
};
