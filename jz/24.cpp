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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        ListNode *res=NULL, *temp;
        while (head != NULL)
        {
            temp = head->next;
            head->next = res;
            res = head;
            head = temp;
        }
        return res;
    }
};

int main() {
    Solution S1;
    ListNode *head = new ListNode(0);
    ListNode *temp = head; 
    for(int i=1; i<10; i++) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode *res = S1.ReverseList(head);
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    delete head;
    return 0;
}