# 10.7 Morning

标签（空格分隔）： Note

---
### $STL$的几个比较实用的东西：
$set$ ： $lower$_ $bound(A + 1, A + N + 1, K)$寻找在整个序列中不小于K的数。$upper$_$bunder(A + 1, A + N + 1, K)$寻找整个序列中大于$K$的数。

$nth_element$找第$K$小
$nth$_$element(A +1, A + K, A + N + 1)$，其中$A[K]$即为第$K$小。

$reverse(A + 1, A + N + 1)$ ： 区间全部翻转。
$next$_$permutation$ ： 寻找下一个排列

$min$_$element(A + 1, A + N + 1)$ ： 寻找最小值所在的位置。

$binary$_$search(A + 1, A + N + 1, K)$ ： 从$1$ - $N$中二分查找$K$。
$swap$可以交换长度相同的数组。