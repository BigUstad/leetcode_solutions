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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if (head == NULL || (head->next == NULL && m > 0))
            return NULL;
        ListNode* cur = head;
        ListNode* prev_m = NULL;
        ListNode* prev_n = NULL;
        ListNode* ptr_m = head;
        ListNode* ptr_n = head;
        uint im = 1; uint in = 1;
        while (cur != NULL)
        {
            while(im <= m)
            {
                /*if (ptr_m->next == NULL)
                {
                    // Drop the rest of the list
                    cout << "1." << cur->val << endl;
                    cur->next = NULL;
                    return head;                    
                }*/
                if (ptr_m->next == NULL)
                {
                    return head;
                }
                prev_m = ptr_m;
                ptr_m = ptr_m->next;
                im++;
            }
            if (ptr_m->next == NULL)
            {
                // Drop the rest of the list
                cout << "2." <<  cur->val << endl;
                prev_m->next = NULL;
                return head;                
            }
            ptr_n = ptr_m;
            prev_n = prev_m;
            cur = prev_m;
            while (in <= n)
            {
                if (ptr_n->next == NULL && in <= n)
                {
                    cout << "3." <<  cur->val << " " << in << endl;
                    cout << "3." <<  ptr_n->val << " " << in << endl;
                    cur->next = NULL;
                    return head;                    
                }
                prev_n = ptr_n;
                ptr_n = ptr_n->next;
                in++;
            }
            prev_m->next = ptr_n; // Deletion part.
            cur = ptr_n;
            ptr_m = ptr_n;
            in = im = 1;
        }
        return head;
    }
};
