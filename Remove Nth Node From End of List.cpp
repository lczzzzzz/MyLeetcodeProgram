#include <iostream>
#include <vector>

using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //vector<ListNode *> result;
        ListNode *p,*q;
        p = head;
        q = head;
        while (n)
        {
            p = p -> next;
            n--;
        }

        if (p == NULL)
        {
            p = head;
            head = p -> next;
            delete p;
            return head;
        }
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }

        p = q -> next;
        q -> next = p -> next;
        delete p;
        return head;
    }
};

int main()
{
    ListNode *head;
    head = new ListNode(1);
    head -> next = new ListNode(2);
    Solution s;
    s.removeNthFromEnd(head,1);
    cout << "Hello world!" << endl;
    return 0;
}
