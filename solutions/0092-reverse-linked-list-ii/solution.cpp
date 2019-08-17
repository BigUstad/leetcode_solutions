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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if ( head == nullptr || head->next == nullptr)
        {
            return head;
        }
        if ( m < 0 || n < 0 )
        {
            return head;
        }
        if ( m == 0 && n == 0)
        {
            return head;
        }
        if ( n <= m )
        {
            return head;
        }
        int lth = n - m + 1;

        bool lOdd = (lth % 2 == 0)? false:true;
        // std::cout << " List lth to be swapped: " << lth << " m, n " << m << ", " << n <<  " And odd " << lOdd << std::endl;
        int curIndex = 1;
        float lHalf = (float)lth / 2;

        int addToM = lOdd?(int)floor(lHalf):(int)lHalf;
        int mid = m + addToM;
        // std::cout << "Half " << lHalf << " Mid: " << mid << std::endl;
        ListNode* cur = head;
        while ( curIndex < m && cur != nullptr )
        {
			curIndex++;
            cur = cur->next;
        }
        while ( curIndex < mid && cur != nullptr )
        {
			// std::cout << "Pushing " << cur->val << std::endl;
            listStack.push(cur);
            curIndex++;
            cur = cur->next;
        }
        if ( lOdd )
        {//Skip the mid if odd length.
			curIndex++;
			cur = cur->next;
		}
        ListNode* swapCur = cur;
        while (curIndex <= n && cur != nullptr )
        {
            swapCur = listStack.top();
            if ( swapCur != nullptr )
            {
                // std::cout << "Swapping: " << swapCur->val << " & " << cur->val << std::endl;
                std::swap ( swapCur->val , cur->val);
			}
            else
                break;
            listStack.pop();
            curIndex++; cur = cur->next;
        }
        return head;
    }
private:
    std::stack<ListNode*> listStack;
};
