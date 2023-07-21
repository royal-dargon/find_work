#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode *ta = pHead1;
        ListNode *tb = pHead2;
        while(ta != tb) {
            if(ta == nullptr) {
                ta = pHead2;
            } else {
                ta = ta->next;
            }
            if(tb == nullptr) {
                tb = pHead1;
            } else {
                tb = tb->next;
            }
        }
        return ta;
    }
};

int main() {

    return 0;
}