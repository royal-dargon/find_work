#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        // write code here
        ListNode *res = new ListNode(0);
        ListNode *temp = res;
        while(pHead1 != nullptr && pHead2 != nullptr) {
            if(pHead1->val > pHead2->val) {
                temp->next = pHead2;
                temp = temp->next;
                pHead2 = pHead2->next;
            } else {
                temp->next = pHead1;
                temp = temp->next;
                pHead1 = pHead1->next;
            }
        }
        if(pHead1 != nullptr) {
            temp->next = pHead1;
        }
        if(pHead2 != nullptr) {
            temp->next = pHead2;
        }
        return res->next;
    }
};

int main() {
    Solution S;
    ListNode *head1= new ListNode(0);
    ListNode *head2= new ListNode(1);
    ListNode *temp = head1;
    for(int i=2; i<=10; i += 2) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode *temp2 = head2;
    for(int j=3; j<=11; j += 2) {
        temp2->next = new ListNode(j);
        temp2 = temp2->next;
    }
    ListNode *res = S.Merge(head1, head2);
    while (res != nullptr)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    delete head1;
    delete head2;
    return 0;
}