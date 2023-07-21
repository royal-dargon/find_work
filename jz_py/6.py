import sys

# 设定该代码
sys.setrecursionlimit(100000)


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def recursion(self, head: ListNode, res):
        if head:
            self.recursion(head.next, res)
            res.append(head.val)

    def printList(self, listNode: ListNode):
        res = []
        self.recursion(listNode, res)
        return res

test_data = ListNode(0)
temp = test_data
for i in range(1, 10):
    temp.next = ListNode(i)
    temp = temp.next

s = Solution()
r = s.printList(test_data)
print(r)

