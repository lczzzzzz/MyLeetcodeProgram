#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(1);
        dummy -> next = head;
        ListNode *pre = dummy;
        ListNode *p = head;
        ListNode *q;
        ListNode *aft;

        if (p == NULL) return NULL;

        int i = 1;
        while (p != NULL)
        {
            i = 1;
            q = p -> next;
            while ((i < k) && (q != NULL))
            {
                aft = q -> next;
                q -> next = p;
                p = q;
                q = aft;
                i++;
            }
            ListNode *temp;
            temp = pre -> next;
            temp -> next = q;
            pre -> next = p;
            if (i != k)
            {
                i = 1;
                q = p -> next;
                while ((i < k) && (q != NULL))
                {
                    aft = q -> next;
                    q -> next = p;
                    p = q;
                    q = aft;
                    i++;
                }
                ListNode *temp;
                temp = pre -> next;
                temp -> next = q;
                pre -> next = p;
                p = NULL;
            }
            else
            {
                pre = temp;
                p = q;
            }

        }
        return dummy -> next;
    }
};

int main()
{
    Solution s;
    ListNode *head  = new ListNode(0);
    ListNode *p = head;
    int size = 2;
    for (int i = 1;i < size;i++)
    {
        p -> next = new ListNode(i);
        p = p -> next;
    }
    p = s.reverseKGroup(head,3);
    for (int i = 0;i < size ;i++)
    {
        cout<<p -> val<<" ";
        head = p -> next;
        delete p;
        p = head;

    }
    cout << "Hello world!" << endl;
    return 0;
}
