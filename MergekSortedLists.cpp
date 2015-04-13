#include <iostream>
#include <vector>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        else
            return mergeSort(lists,0,lists.size() - 1);
    }

    ListNode *mergeSort(vector<ListNode *> &lists,int a,int b)
    {
        if (a == b)
        {
            return lists[a];
        }
        else if (a < b)
        {
            return mergeTwoLists(mergeSort(lists,a,(a + b) / 2),mergeSort(lists,(a + b) + 1,b));
        }
        else
        {
            return NULL;
        }
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *headL1 = l1;
        ListNode *headL2 = l2;
        ListNode *p;
        ListNode *q;
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
    cout << "Hello world!" << endl;
    return 0;
}
