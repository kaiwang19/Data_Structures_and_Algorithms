/*
Implementation of B+ TREE Operations
"Data Structures and Algorithms Using C++" , Chap13 Page 23
===
In large file systems, both random and sequential processing of data are required. 
For such systems most of the popular file organization methods prefer and use the B tree to process the data randomly. 
But, when the data are to be processed sequentially, the B tree takes much processing time in moving up and down the tree structure. 
This ineffciency leads to the second variant of the B tree, B+ tree.
===
B+ tree differs from B tree in two points. They are:
1. Though elements are found in the internal nodes their corresponding data entry must be represented at the leaf level. 
   As the internal nodes are used only for searching, they do not hold data.
2. Every leaf node is with an additional pointer and is used to proceed to the next leaf node in sequence
===

*/