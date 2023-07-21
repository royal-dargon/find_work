#include <iostream>

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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        for(int i=0; i<k; i++) {
            if(fast == nullptr) {
                return fast;
            } else {
                fast = fast->next;
            }
        }
        while(fast != nullptr) {
            slow = slow->next;
            fast= fast->next;
        }
        return slow;
    }
};

int main() {
    Solution S;
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    for(int i = 1; i < 10; i ++) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode *res = S.FindKthToTail(head, 2);
    while(res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    delete head;
    return 0;
}