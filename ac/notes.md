### 基础算法

#### 排序

##### 快排  nlog(n)

给定序列q 分治

* 确定分界点：q[1]、q[mid]、q[end]、随机 
* 调整区间（重点） 
* 递归 处理左右两段

对于调整区间的处理方式如下：

* 暴力开辟空间
* 一头一尾双指针，终止条件指正相遇或者越过

cpp版本

```c++
// quick_sort
#include <iostream>

using namespace std;

const int N = 1e5;
int q[N];

void quick_sort(int q[], int l, int r) {
    if(l >= r) return;

    int i = l-1, j = r+1;
    int x = q[(i + j) / 2];
    while(i < j) {
        do i ++; while(q[i] < x);
        do j --; while(q[j] > x);
        if(i < j) {
            swap(q[i], q[j]);
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &q[i]);
    }
    quick_sort(q, 0, n - 1);
    for(int i = 0; i < n; i ++) {
        printf("%d ", q[i]);
    }
    cout << endl;
    return 0;
}
```

```python
def quick_sort(q, l, r):
    if l >= r:
        return

    i = l - 1
    j = r + 1
    x = q[l + r >> 1]

    while i < j:
        i += 1
        while q[i] < x:
            i += 1

        j -= 1
        while q[j] > x:
            j -= 1

        if i < j:
            q[i], q[j] = q[j], q[i]

    quick_sort(q, l, j)
    quick_sort(q, j + 1, r)


n = int(input())
q = list(map(int, input().split()))

quick_sort(q, 0, n - 1)

print(' '.join(list(map(str, q))))
```

##### 归并排序      nlog(n)

给定序列 分治：

* 确定分界点，这里使用mid

* 先递归左右两部分
* 归并（合二为一）

```c++
// merge sort
#include <iostream>

using namespace std;

const int N = 100000;
int q[N];
int tmp[N];

void merge_sort(int q[], int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int k = 0,i = l,j = mid + 1;
    while(i <= mid && j <= r){
        if(q[i] < q[j]) tmp[k ++] = q[i ++];
        else tmp[k ++] = q[j ++];
    }
    while(i <= mid) tmp[k ++] = q[i ++];
    while(j <= r) tmp[k ++] = q[j ++];
    for(i = l, j = 0;i <= r;i ++, j ++) q[i] = tmp[j];
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i ++) scanf("%d", &q[i]);
    merge_sort(q, 0, n-1);
    for(int i = 0;i < n;i ++) printf("%d ", q[i]);
    return 0;
}
```

####  二分

##### 整数二分

* 寻找mid，并对其进行判断，判断是否成立[mid, r] [l, mid - 1 ] 需要区分mid这个分界点·

是否需要mid+1是值得区分的问题如果(l, mid)则不需要    条件其实就是目标。

```c++
// 二分查找解决问题
#include <iostream>

using namespace std;

const int N = 100010;
int q[N];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i ++) scanf("%d", &q[i]);
    while(k --){
        int target;
        scanf("%d", &target);
        int l = 0, r = n - 1, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(q[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(q[l] != target){
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << " ";
        l = 0, r = n - 1;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(q[mid] > target) r = mid - 1;
            else l = mid;
        }
        cout << l << endl;
    }
    return 0;
}
```

##### 浮点数二分

#### 高精度

类型：

* 大整数相加
* 大整数乘法
* 除法

存储方式：

* 每一位存储至数组中
* 开始的位数存储低位效果比较好

运算：

* 加法实际上就是对应位置相加加上上一位的进位
* 减法，对应位置大于0直接减，如果不够的话是可以去借位的

#### 前缀和与差分

##### 前缀和 trick

S[r] = S[r-1] + a[r]

a[l, r] = S[r] - S[l-1]

需要 下标从1开始

* 如何求Si（前i个数字的和，下标从1开始算），Si是从Si-1算出来的
* **前缀和作用是什么，快速求出原数组一段数字的和**

二维前缀和（快速求解子矩阵）：

两重for循环

S[i, j] = S[i-1, j] + S[i, j-1] - S[i-1, j-1] + a[i, j]

S[x, y] = 大-小-小+小小

##### 差分 

假设元素是a1...an，需要构造B数组，使得ai=b1 + ..... + bn，也就是A是B的前缀和

差分矩阵

由aij获得bij





