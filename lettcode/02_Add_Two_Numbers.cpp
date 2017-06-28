/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c1 = l1, *c2 = l2;
        ListNode *head = NULL, *cur = NULL, *next_point = NULL;
        int sum = 0;
        while (c1 || c2 || su)
        {
            int val1 = c1? c1->val:0;
            int val2 = c2? c2->val:0;
            sum += val1 + val2;

            cur = new ListNode(sum%10);
            sum = sum/10;

            if(!head)
            {
                head = cur;
            }

            next_point = cur->next;
            c1 = c1? c1->next:NULL;
            c2 = c2? c2->next:NULL;
        }
        return head;
    }
};

int main()
{
    /* code */
    return 0;
}
