## Sparse Table

Sparse Table is a data structure, that allows answering range queries. This data structure is only be used on immutable arrays.This means that we can't do update in this data structure without recomputed.

### Complexity
* Build - **O(nlogn)**
* Query - **O(logn)** / **O(1)** 
* Space - **O(nlogn)**

### Implementation
- [Source Code of Sparse Table](https://github.com/Saikat-S/algorithms/blob/master/Data_Structures/sparse_table/sparse_table.cpp)

### Practice Problems
* [SPOJ - RMQSQ](https://www.spoj.com/problems/RMQSQ/)
* [SPOJ - THRBL](https://www.spoj.com/problems/THRBL/)
* [Codechef - MSTICK](https://www.codechef.com/problems/MSTICK)
* [Codechef - SEAD](https://www.codechef.com/problems/SEAD)

### References
* [CP-Algorithms - Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)
* [Geeksforgeeks - Sparse Table](https://www.geeksforgeeks.org/sparse-table/)
* [Hackerearth - Sparse Table](https://www.hackerearth.com/practice/notes/sparse-table/)
* [Adilet - Sparse Table](http://adilet.org/blog/sparse-table/)
