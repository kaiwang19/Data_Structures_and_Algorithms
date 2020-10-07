/*
Implementation of a generic binary search tree.
"Data Structures and Algorithms in C++, 4th edition" (Adam Drozdek, 2012) Chap 6, P280~285
===
In the binary search tree, one key is used to navigate inthe tree to perform any operation. 
However, a binary search tree can be used in its pure form and yet be able to use multiple keys. 
One such tree is a multidimensional (k-dimensional) binary search tree or k-d tree (Bentley 1975). 
Multidimensionality refers to items stored in the tree, not to the tree itself.
===

*/


// void insert(el)
// {
//     int i = 0;
//     p = root;
//     prev = 0;
//     while
//         p ≠ 0 prev = p;
//     if
//         el.keys[i] < p->el.keys[i] p = p->left;
//     else
//         p = p->right;
//     i = (i + 1) % k;
//     if
//         root == 0 root = new BSTNode(el);
//     else if
//         el.keys[(i - 1) mod k] < p->el.keys[(i - 1) mod k] prev->left = new BSTNode(el);
//     else
//         prev->right = new BSTNode(el);
// }

// void search(ranges[][])
// {
//     if (root != 0)
//         search(root, 0, ranges);
// }

// void search(p, i, ranges[][])
// {
//     found = true;
//     for (j = 0; j < k; j++)
//     {
//         if (!(ranges[j][0] <= p->el.keys[j] <= ranges[j][1]))
//             found = false;
//         break;
//     }
//     if (found)
//         output p->el;
//     if (p->left != 0 and ranges[i][0] <= p->el.keys[i])
//         search(p->left, (i + 1) mod k, ranges);
//     if (p->right != 0 and p->el.keys[i] <= ranges[i][1])
//         search(p->right, (i + 1) mod k, ranges);
// }

// delete (el)
// {
//     p = the node with el;
//     delete(p, discriminator’s index i for p);
// }

// delete (p)
// {
//     if
//         p is a leaf delete p;
//     else if
//         p->right ≠ 0 q = smallest(p->right, i, (i + 1) mod k);
//     else
//         q = smallest(p->left, i, (i + 1) mod k);
//     p->right = p->left;
//     p->left = 0;
//     p->el = q->el;
//     delete (q, i);
// }

// smallest(node q, int i, int j)
// {
//     qq = q;
//     if (i == j)
//     {
//         if (q->left != 0)
//             qq = q = q->left;
//         else
//             return q;
//     }
//     if (q->left != 0)
//     {
//         lt = smallest(q->left, i, (j + 1) % k);
//         if (qq->el.keys[i] >= lt->el.keys[i])
//             qq = lt;
//     }
//     if (q->right != 0)
//     {
//         rt = smallest(q->right, i, (j + 1) % k);
//         if (qq->el.keys[i] >= rt->el.keys[i])
//             qq = rt;
//     }
//     return qq;
// }