#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *headL1 = l1;
        ListNode *headL2 = l2;
        ListNode *p;
        ListNode *q;
        if (headL1 == NULL)
            return l2;
        else if (headL2 == NULL)
            return l1;
        p = new ListNode(0);
        p -> next = l1;
        ListNode *dummy;
        dummy = p;
        while ((headL1 != NULL) && (headL2  != NULL))
        {
            if (headL1 -> val > headL2 -> val)
            {
                p -> next = headL2;
                q = headL2 -> next;

                headL2->next = headL1;
                headL2 = q;
                headL1 = p -> next;
            }
            else
            {
                p = headL1;
                headL1 = headL1 -> next;
            }
        }

        if (headL1  == NULL)
        {
            p -> next = headL2;
        }

        p = dummy;
        dummy = dummy -> next;
        delete p;
        return dummy;
    }
};
int main()
{
    Solution s;
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);
    l1 = s.mergeTwoLists(l1,l2);
    while (l1 != NULL)
    {
        cout<<l1 -> val;
        l1 = l1 -> next;
    }

    cout << "Hello world!" << endl;
    return 0;
}
