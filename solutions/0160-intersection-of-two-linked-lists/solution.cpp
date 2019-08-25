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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// // std::cout << " Checking for nulls. Etc. " << !headA << " " << !headB << " " << !headA->next << " " << !headB->next << std::endl;
        if ( !headA || !headB )
        {
			// std::cout << " SOmething is null." << std::endl;
            return nullptr;
		}
        if ( headA == headB )
        {
            return headA;
        }
        // std::cout << "Continuing" << std::endl;
        unsigned int countA=0;
        unsigned int countB=0;
        ListNode* curA=headA;
        ListNode* curB=headB;
        while ( curA != nullptr )
        {
            countA++;
            curA = curA->next;
        }
        // std::cout << " Count of List A: " << countA << std::endl;
        while ( curB != nullptr )
        {
            countB++;
            curB = curB->next;
        }
        // std::cout<< " Length of List A: "<< countA << " & B: " << countB << std::endl;
        unsigned int curCount = 0;
        curA = headA; curB = headB;
        if ( countA > countB )
        {
            while ( curA != nullptr && curCount < (countA - countB))
            {
				// std::cout << "A. Advancing to " << curA->val << std::endl;
                curA = curA->next;
                curCount++;
            }
        }
        else if ( countB > countA )
        {
            while ( curB != nullptr && curCount < (countB - countA))
            {
				// std::cout << "B. Advancing to " << curB->val << std::endl;
				curB = curB->next;
                curCount++;
            }
        }
        // Now we can say they are equi-distant from the
        // intersecting node
        while ( curA != nullptr && curB != nullptr &&
                curA != curB )
        {
			// std::cout << " A&B. Checking " << curA->val << " " << curB->val << " " << curB << " " << curA << std::endl;
            curA = curA->next;
            curB = curB->next;
        }
        /*if ( !curA || !curB )
            return nullptr;
        else*/
            return curA;        
    }
};
