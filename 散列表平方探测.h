#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXTABLESIZE 100000
typedef int Index;
typedef Index Position;
typedef int ElementType;
typedef struct HashEntry Cell;
typedef enum { Legitmate, Empty, Deleted } EntryType; //����״̬
typedef enum { true, false }bool;
struct HashEntry
{
	ElementType data;
	EntryType Info;
};
typedef struct TbNode* HashTable;
struct TbNode
{
	int TableSize;
	Cell* Cells;
};
HashTable CreateTable(int TableSize) //����һ����ϣ��
{
	HashTable H;
	H = (HashTable)malloc(sizeof(struct TbNode));
	H->TableSize = NextPrime(H->TableSize);//ȡһ��������Ϊ����
	H->Cells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	for (int i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = Empty;
	return H;
}
int NextPrime(int N)
{
	int i, p = (N % 2) ? N + 2 : N + 1;
	while (p < MAXTABLESIZE)
	{
		for (i = sqrt(p); i > 2; i--)
			if (p % i == 0) break;
		if (i == 2) p += 2;
	}
	return p;
}
Position Find(HashTable H, ElementType Key)  //����key  
{
	Position CurrentPos, NewPos;
	int CNum = 0;//��ͻ����
	NewPos = CurrentPos = Hash(Key, H->TableSize);
	while (H->Cells[NewPos].Info != Empty && H->Cells[NewPos].data != Key) //�ַ���strcmp
	{
		if (++CNum % 2)
		{
			NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4;
			if (NewPos >= H->TableSize)
				NewPos = NewPos % H->TableSize;
		}
		else
		{
			NewPos = CurrentPos - CNum * CNum / 4;
			if (NewPos < 0)
				NewPos += H->TableSize;
		}
	}
	return NewPos;
}
bool Insert(HashTable H, ElementType Key)
{
	Position Pos = Find(H, Key);
	if (H->Cells[Pos].Info != Legitmate)
	{
		H->Cells[Pos].data = Key;
		H->Cells[Pos].Info = Legitmate;
		return true;
	}
	else {

		printf("��ֵ�Ѵ���")��
			return false;
	}
}
