# PD_hw2_datastructure
test performance of linked list, binary search tree, array, array with binary search, and hash.

-d N (required) 插入的資料筆數，每筆資料是唯一的 (1e4, 1e5, 1e6)
-q M (required) 查詢資料筆數 (1e3, 1e4, 1e5)
-bst: 測量BST建立和查詢所需時間
-bs:  測量 Binary Search建立資料結構(含 sorting) 和查詢所需時間
-arr: 測量 array 建立資料結構和查詢(linear search)所需時間
-ll: 測量 linked list 建立資料結構和查詢所需時間
-hash 測量 hash 建立資料結構和查詢所需時間

ex:
./a.out -q 100 -d 1000 -ll -bs -arr
可做 插入1000筆資料並查詢100資料的 linked list 、 array with binary search、 array 的時間測量
