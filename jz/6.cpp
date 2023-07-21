#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x), next(NULL) { 
    } 
};

class Solution {
    public:
    // 鉴于链表无法从头开始访问，于是我们使用递归的方式进行访问
    void recursion(ListNode* head, vector<int>& res) {
        if(head != NULL) {
            recursion(head->next, res);
            res.push_back(head->val);
        }
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        recursion(head, res);
        return res;
    }
};

int main() {
    Solution S1;
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    for(int i=1;i < 10;i ++) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    vector<int> res = S1.printListFromTailToHead(head);
    for (int i = 0; i < res.size(); i ++) {
        cout << res[i] << " ";
    }
    cout << endl;
    delete head;
    return 0;
}
