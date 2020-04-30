
/*
Implementation of B-TREE Operations
"Data Structures and Algorithms Using C++" , Chap13 Page 7~22
===
B-Tree
A data structure which is a height balanced version of m-way search tree is known as a B tree of order m. 
When the growth of an m-way search tree is left uncontrolled then in the worst case it yields a complexity of O(n).
This shows deterioration in performance. 
So, there is a need to have balanced m-way search trees which guarantees a complexity of O(log n) for search, insert and delete operations.
===
[Definition]: A B tree of order m is an m-way search tree and it may be empty. 
If not empty then the following properties are to be satisfied by the extended trees:
(1) The root node should have a minimum of two children and a maximum of m children.
(2) All the internal nodes except the root node should have a minimum of [m/2] non-empty children and a maximum of m non-empty children.
(3) All the external nodes are at the same level.
(4) A leaf node must have minimum [m/2–1] and maximum m–1 elements.
===

*/

#include <iostream> // <iostream> is different from <iostream.h>. <iostream.h> is compatible both in C and C++.
#include <stdlib.h> // for system("cls");
// #include <conio.h>  // for clrscr(); too old
// #include <cstdlib>  // for clrscr(); too old

using namespace std;

#define MAX 50

struct BTREE
{
    int n;
    int keys[MAX - 1];
    struct BTREE *p[MAX];
} *root = NULL;
typedef struct BTREE node1;
int eleCount = 0, ele;

enum KeyStatus
{
    Duplicate,
    SearchNodeFailure,
    Success,
    InsertIt,
    LessKeys
};

enum KeyStatus ins(node1 *r, int x, int *y, node1 **u);
enum KeyStatus del(node1 *r, int x);

void InsertNode()
{
    node1 *newnode;
    int upKey;
    enum KeyStatus value;
    cout << "Enter Element To Insert";
    cin >> ele;
    value = ins(root, ele, &upKey, &newnode);
    if (value == Duplicate)
    {
        cout << "Element Already Exists\n";
        return;
    }
    if (value == InsertIt)
    {
        node1 *uproot = root;
        root = (node1 *)malloc(sizeof(node1));
        root->n = 1;
        root->keys[0] = upKey;
        root->p[0] = uproot;
        root->p[1] = newnode;
    }
    eleCount++;
    cout << "Element Is Successfully Inserted";
}

int SearchNodePos(int key, int *key_arr, int n)
{
    int pos = 0;
    while (pos < n && key > key_arr[pos])
        pos++;
    return pos;
}

enum KeyStatus ins(node1 *ptr, int key, int *upKey, node1 **newnode)
{
    node1 *newPtr, *lastPtr;
    int pos, i, n, splitPos;
    int newKey, lastKey;
    enum KeyStatus value;
    if (ptr == NULL)
    {
        *newnode = NULL;
        *upKey = key;
        return InsertIt;
    }
    n = ptr->n;
    pos = SearchNodePos(key, ptr->keys, n);
    if (pos < n && key == ptr->keys[pos])
        return Duplicate;
    value = ins(ptr->p[pos], key, &newKey, &newPtr);
    if (value != InsertIt)
        return value;
    if (n < MAX - 1)
    {
        pos = SearchNodePos(newKey, ptr->keys, n);
        for (i = n; i > pos; i--)
        {
            ptr->keys[i] = ptr->keys[i - 1];
            ptr->p[i + 1] = ptr->p[i];
        }
        ptr->keys[pos] = newKey;
        ptr->p[pos + 1] = newPtr;
        ++ptr->n;
        return Success;
    }
    if (pos == MAX - 1)
    {
        lastKey = newKey;
        lastPtr = newPtr;
    }
    else
    {
        lastKey = ptr->keys[MAX - 2];
        lastPtr = ptr->p[MAX - 1];
        for (i = MAX - 2; i > pos; i--)
        {
            ptr->keys[i] = ptr->keys[i - 1];
            ptr->p[i + 1] = ptr->p[i];
        }
        ptr->keys[pos] = newKey;
        ptr->p[pos + 1] = newPtr;
    }
    splitPos = (MAX - 1) / 2;
    (*upKey) = ptr->keys[splitPos];
    (*newnode) = (node1 *)malloc(sizeof(node1));
    ptr->n = splitPos;
    (*newnode)->n = MAX - 1 - splitPos;
    for (i = 0; i < (*newnode)->n; i++)
    {
        (*newnode)->p[i] = ptr->p[i + splitPos + 1];
        if (i < (*newnode)->n - 1)
            (*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
        else
            (*newnode)->keys[i] = lastKey;
    }
    (*newnode)->p[(*newnode)->n] = lastPtr;
    return InsertIt;
}

void Display(node1 *ptr, int blanks)
{
    if (eleCount == 0)
    {
        cout << "BTREE Is Empty";
        return;
    }
    if (ptr)
    {
        int i;
        for (i = 0; i < ptr->n; i++)
            cout << ptr->keys[i] << " ";
        cout << endl;
        for (i = 0; i <= ptr->n; i++)
            Display(ptr->p[i], blanks + 10);
    }
}

void search()
{
    int pos, i, n;
    node1 *ptr = root;
    if (eleCount == 0)
    {
        cout << "BTREE Is Empty";
        return;
    }
    cout << "Enter Element To Search Node";
    cin >> ele;
    while (ptr)
    {
        n = ptr->n;
        pos = SearchNodePos(ele, ptr->keys, n);
        if (pos < n && ele == ptr->keys[pos])
        {
            cout << "Element" << ele << "Is Found";
            return;
        }
        ptr = ptr->p[pos];
    }
    cout << "Element" << ele << "Is Not Found";
}

void DeleteNode()
{
    int flag = 1;
    node1 *uproot;
    enum KeyStatus value;
    if (eleCount == 0)
    {
        cout << "BTREE Is Empty";
        return;
    }
    cout << "Enter Element To Delete";
    cin >> ele;
    value = del(root, ele);
    switch (value)
    {
    case SearchNodeFailure:
        cout << "Element" << ele << "Is Not Available";
        flag = 0;
        break;
    case LessKeys:
        uproot = root;
        root = root->p[0];
        free(uproot);
        break;
    }
    if (flag == 1)
    {
        cout << "Element" << ele << "Is Deleted";
        eleCount--;
    }
}

enum KeyStatus del(node1 *ptr, int key)
{
    int pos, i, pivot, n, MAXin;
    int *key_arr;
    enum KeyStatus value;
    node1 **p, *lchild, *rchild;
    if (ptr == NULL)
        return SearchNodeFailure;
    n = ptr->n;
    key_arr = ptr->keys;
    p = ptr->p;
    MAXin = (MAX - 1) / 2;
    pos = SearchNodePos(key, key_arr, n);
    if (p[0] == NULL)
    {
        if (pos == n || key < key_arr[pos])
            return SearchNodeFailure;
        for (i = pos + 1; i < n; i++)
        {
            key_arr[i - 1] = key_arr[i];
            p[i] = p[i + 1];
        }
        return --ptr->n >= (ptr == root ? 1 : MAXin) ? Success : LessKeys;
    }
    if (pos < n && key == key_arr[pos])
    {
        node1 *qp = p[pos], *qp1;
        int nkey;
        while (1)
        {
            nkey = qp->n;
            qp1 = qp->p[nkey];
            if (qp1 == NULL)
                break;
            qp = qp1;
        }
        key_arr[pos] = qp->keys[nkey - 1];
        qp->keys[nkey - 1] = key;
    }
    value = del(p[pos], key);
    if (value != LessKeys)
        return value;
    if (pos > 0 && p[pos - 1]->n > MAXin)
    {
        pivot = pos - 1;
        lchild = p[pivot];
        rchild = p[pos];
        rchild->p[rchild->n + 1] = rchild->p[rchild->n];
        for (i = rchild->n; i > 0; i--)
        {
            rchild->keys[i] = rchild->keys[i - 1];
            rchild->p[i] = rchild->p[i - 1];
        }
        rchild->n++;
        rchild->keys[0] = key_arr[pivot];
        rchild->p[0] = lchild->p[lchild->n];
        key_arr[pivot] = lchild->keys[--lchild->n];
        return Success;
    }
    if (pos > MAXin)
    {
        pivot = pos;
        lchild = p[pivot];
        rchild = p[pivot + 1];
        lchild->keys[lchild->n] = key_arr[pivot];
        lchild->p[lchild->n + 1] = rchild->p[0];
        key_arr[pivot] = rchild->keys[0];
        lchild->n++;
        rchild->n--;
        for (i = 0; i < rchild->n; i++)
        {
            rchild->keys[i] = rchild->keys[i + 1];
            rchild->p[i] = rchild->p[i + 1];
        }
        rchild->p[rchild->n] = rchild->p[rchild->n + 1];
        return Success;
    }
    if (pos == n)
        pivot = pos - 1;
    else
        pivot = pos;
    lchild = p[pivot];
    rchild = p[pivot + 1];
    lchild->keys[lchild->n] = key_arr[pivot];
    lchild->p[lchild->n + 1] = rchild->p[0];
    for (i = 0; i < rchild->n; i++)
    {
        lchild->keys[lchild->n + 1 + i] = rchild->keys[i];
        lchild->p[lchild->n + 2 + i] = rchild->p[i + 1];
    }
    lchild->n = lchild->n + rchild->n + 1;
    free(rchild);
    for (i = pos + 1; i < n; i++)
    {
        key_arr[i - 1] = key_arr[i];
        p[i] = p[i + 1];
    }
    return --ptr->n >= (ptr == root ? 1 : MAXin) ? Success : LessKeys;
}

int main()
{
    int op;
    system("cls"); // [clrscr();] is too old and not standard
    while (1)
    {
        cout << "\nBTREE Opeartions\n1.Insertion\n2.Deletion\n3.Searching\n";
        cout << "4.Traversing\n5.Exit\n";
        cout << "Enter Your Option :";
        cin >> op;
        switch (op)
        {
        case 1:
            InsertNode();
            break;
        case 2:
            DeleteNode();
            break;
        case 3:
            search();
            break;
        case 4:
            cout << "BTREE Elements Are :\n";
            Display(root, 0);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid Choice\n";
        }
    }
}
