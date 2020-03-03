#pragma once
#ifndef _TREE_
#define _TREE_
typedef struct TNode* BinTree;
typedef BinTree Position;
struct TNode
{
    ElementType Data;
    BinTree Right, Left;
};
typedef struct HNode* Heap;
struct HNode
{
    ElementType* Data;//���������ʽ����
    int Size;//��ǰ����
    int Capacity;//�ѵ��������
};
typedef struct AVLNode* AVLTree;
struct AVLNode
{
    ElementType Data;
    int Height;
    AVLTree Right, Left;
};
typedef Heap MaxHeap;
typedef Heap MinHeap;
//�����������Ĳ������ɾ��
BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);
//���ı���
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);
//�ѵĲ���ɾ������
MaxHeap CreatHeap(int MaxSize);//����һ���նѣ�
void InsertH(MaxHeap H,ElementType X);
ElementType DeleteMax(MaxHeap H);
//AVL����
int Max(int a,int b);
int GetHight(AVLTree T);
AVLTree SingleLeftRotation(AVLTree A);
AVLTree SingleRightRotation(AVLTree A);
AVLTree DoubleLeftRightRotation(AVLTree A);
AVLTree DoubleRightLeftRotation(AVLTree A);
AVLTree InsertT(AVLTree T, ElementType X);
void InorderTraversal(BinTree BT)
{
    if (BT) {
        InorderTraversal(BT->Left);
        printf("%c", BT->Data);
        InorderTraversal(BT->Right);
    }
}
void PreorderTraversal(BinTree BT)
{
    if (BT) {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void PostorderTraversal(BinTree BT)
{
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}
void LevelorderTraversal(BinTree BT)
{   Queue S;
    BinTree t;
    if (!BT) return;
    S = CreatQueue(1000);
    AddQ(S, BT);
    if (S->Rear != S->Front)
    {
        t = DeleteQ(S);
        printf(" %c", t->Data);
        if (t->Left) AddQ(S, t->Left);
        if (t->Right) AddQ(S, t->Right);
    }
}
BinTree Insert(BinTree BST, ElementType X)
{
    if (!BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else 
    {
        if (X < BST->Data) BST->Left = Insert(BST->Left,X);
        if (X > BST->Data) BST->Right = Insert(BST->Right,X);
    }
    return BST;
}
BinTree Delete(BinTree BST, ElementType X)
{
    BinTree tem;
    // ������� �ýڵ�û���ӽڵ�  ֻ��һ���ڵ�  �����ڵ�
    if (!BST)
    {
        printf("Not Found");
        return BST;
    }
    else
    {
        if (X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else
        {
            if (BST->Left && BST->Right)
            {
                tem = FindMin(BST->Right); //�������ӽڵ�ʱ ������������ұ���С������ýڵ�  ����ڵ�һ�����ֻ��һ���ӽڵ��  �ٵ���һ���ڵ������
                BST->Data = tem->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            }
            else {
                tem = BST;
                if (!BST->Left) //ֻ���ҽڵ��û�нڵ�
                    BST = BST->Right;
                else BST = BST->Left;
                free(tem);
            }

        }
    }
}
Position Find(BinTree BST, ElementType X)
{
    if (!BST)  return NULL;
    if (X < BST->Data)
        return Find(BST->Left, X);
    else if (X > BST->Data)
        return Find(BST->Right, X);
    else return BST;
}
Position FindMin(BinTree BST)
{
    if (!BST) return NULL;
    else if (!BST->Left) return BST;
    else return BST = FindMin(BST->Left);
}
Position FindMax(BinTree BST)
{
    if (!BST) return NULL;
    else if (!BST->Right) return BST;
    else return BST = FindMax(BST->Right);
}
#define MAXDATA 1000 //�ڱ�
MaxHeap CreatHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct TNode));
    H->Data = (ElementType*)malloc(sizeof(ElementType) * (MaxSize + 1));//��1��ʼ��  0��һ���ڱ���
    H->Data[0] = MAXDATA;
    H->Capacity = MaxSize;
    H->Size = 0;
    return H;
}
void InsertH(MaxHeap H, ElementType X)
{
    int i;
    if (H->Size == H->Capacity)
    {
        printf("The Heap Is Full");
        return;
    }
    else
    {
        i = H->Size++;
        while (H->Data[i/2]<X)
        {
            H->Data[i] = H->Data[i / 2];
            i /= 2;
        }
        H->Data[i] = X;
    }
}
ElementType DeleteMax(MaxHeap H)
{
    if (!H->Size) { printf("The Heap Is Empty"); return ERROR; }
    else
    {
        ElementType MaxItem, X;
        int Parent, Child;
        MaxItem = H->Data[1];
        X = H->Data[H->Size--];
        for (Parent = 1; Parent * 2 <= H->Size; Parent=Child)
        {
            Child = Parent * 2;
            if (Child + 1 <= H->Size && H->Data[Child] < H->Data[Child + 1])  Child++;//�ҳ������ӽڵ㣻
            if (H->Data[Child] > X) H->Data[Parent] = H->Data[Child];
            else break;
        }
        H->Data[Parent] = X;
        return MaxItem;
    }
}
int Max(int a, int b)
{
    return (a > b) ? a : b;
}
int  GetHight(AVLTree T)
{
    if (!T) return 0;
    else 
    {
        return  Max(GetHight(T->Left), GetHight(T->Right))+1;
    }
}
AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A = GetHight(A);
    B = GetHight(B);
    return B;
}
AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B;
    B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = GetHight(A);
    B->Height = GetHight(B);
    return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}
AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}
AVLTree InsertT(AVLTree T, ElementType X)
{
    if (!T)
    {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = T->Right = NULL;
        T->Height = 1;
    }
    else
    {
        if (X < T->Data)
        {
            T->Left = InsertT(T->Left,X);
            if (X < T->Left->Data)
                T = SingleLeftRotation(T);
            else T = DoubleLeftRightRotation(T);
        }
        else if (X > T->Data)
        {
            T->Right = InsertT(T->Right,X);
            if (X > T->Right->Data)
                T = SingleRightRotation(T);
            else T = DoubleRightLeftRotation(T);
        }
    }
    T = GetHight(T);
    return T;
}
#endif // !_TREE_
