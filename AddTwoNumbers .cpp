#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int jinwei;
        jinwei = 0;
        ListNode *answerHead = NULL;
        ListNode *pos = NULL;
        ListNode *l1Head = l1;
        ListNode *l2Head = l2;
        while ((l1 != NULL) || (l2 != NULL))
        {
            int valTemp;
            if (l1 == NULL)
            {
                valTemp = l2 ->val + jinwei;
                jinwei = valTemp / 10;
                valTemp = valTemp % 10;
            }
            else if (l2 == NULL)
            {
                valTemp = l1 ->val + jinwei;
                jinwei = valTemp / 10;
                valTemp = valTemp % 10;
            }
            else
            {
                valTemp = l1->val + l2->val + jinwei;
                jinwei = valTemp / 10;
                valTemp = valTemp % 10;
            }
            ListNode *temp = new ListNode(valTemp);
            if (answerHead == NULL)
            {
                answerHead = temp;
                pos = answerHead;
            }
            else
            {
                pos->next = temp;
                pos = pos->next;
            }
            l1 = (l1 == NULL)?l1:l1->next;
            l2 = (l2 == NULL)?l2:l2->next;
        }

        if (jinwei != 0)
        {
            ListNode *temp = new ListNode(jinwei);
            pos -> next = temp;
            pos = pos->next;
        }
        l1 = l1Head;
        l2 = l2Head;
        return answerHead;
    }
};
int main()
{
    ListNode *l1;
    l1 = new ListNode(1);
    l1->next = new ListNode(8);
    ListNode *l2;
    l2 = new ListNode(0);
    Solution s;
    s.addTwoNumbers(l1,l2);
    cout << "Hello world!" << endl;
    return 0;
}
