#include <iostream>

using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *pre;
        ListNode *q;
        ListNode *p;
        ListNode *aft;

        ListNode * dummy = new ListNode(1);
        dummy -> next = head;

        pre = dummy;
        p = head;

        while (p != NULL)
        {
            if (p -> next != NULL)
            {
                q = p -> next;
                aft = q -> next;
                q -> next = p;
                p -> next = aft;
                pre -> next = q;
                pre = p;
            }
            p = p->next;
        }
        return dummy -> next;
    }
};
int main()
{
    ListNode *head;
    ListNode *p;
    p = new ListNode(1);
    head = p;
    for (int i = 2;i <= 5;i++)
    {
        p -> next = new ListNode(i);
        p = p -> next;
    }
    Solution s;
    p = s.swapPairs(head);
    head = p;
    while (p != NULL)
    {
        cout<<p -> val<<" ";
        p = p -> next;
    }
    delete head;
    return 0;
}
