// 19. Remove Nth Node From End of List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <list>

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
   ListNode *p1 = head, *p2 = head;
   int i = 0;
   while (p1)
   {
      if(i <= n)
      {
         p1 = p1->next;
         ++i;
         continue;
      }
      p1 = p1->next;
      p2 = p2->next;
      ++i;
   }
   std::cout << "c2->val:" << p2->val << '\n';
   ListNode *tmp = p2->next;
   p2->next = p2->next->next;
   delete tmp;
   return head;
}

ListNode* initList(int n)
{
   if (n <= 0)
      return nullptr;

   ListNode *head = new ListNode(0);
   ListNode *p = head;
   for (int i = 1; i < n; i++) {
      ListNode *tmp = new ListNode(i);
      p->next = tmp;
      p = p->next;
   }
   return head;
}

void destroyList(ListNode *head)
{
   ListNode *p = head;
   while(p)
   {
      ListNode *tmp = p;
      p = p->next;
      delete tmp;
   }
}

void printListNode(ListNode *head)
{
   ListNode *p = head;
   while (p)
   {
      std::cout << ":" << p->val;
      p = p->next;
   }
   std::cout << '\n';
}

int main()
{
   ListNode *L1 = initList(10);
   printListNode(L1);
   L1 =  removeNthFromEnd(L1, 6);
   printListNode(L1);
   destroyList(L1);
   return 0;
}
