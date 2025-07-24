#ifndef BITREEBASE_H //��һ�ΰ�����ͷ�ļ�ʱ���������Ϊ�棬��ִ������Ĵ��룻�ڶ��ΰ���ʱ�����ں��ѱ����壬����Ϊ�٣�ֱ������ #endif ֮��
#define BITREEBASE_H //�� #ifndef ��ϣ���� �����ͷ�ļ��Ѿ����������ˡ���

#include <iostream>
#include <queue>
using namespace std;


// һ���ṹ����
struct BiTNode{
	char data;
	BiTNode* left;
	BiTNode* right;
	BiTNode() : data('\0'), left(nullptr), right(nullptr) {}
	BiTNode(char x):data(x),left(nullptr),right(nullptr){}
};

typedef BiTNode* BiTree;

//����������������

// 1. ��ʼ��������
void InitBiTree(BiTree& T);                      // �������
void DestroyBiTree(BiTree& T);                   // ������
void ClearBiTree(BiTree& T);                     // ��������ÿգ�

// 2. �����ͻ�������
void CreateBiTree(BiTree& T);                    // �����������봴��
bool BiTreeEmpty(BiTree T);                      // �Ƿ�Ϊ��
int BiTreeDepth(BiTree T);                       // �����
BiTNode* Root(BiTree T);                         // ���ظ����

// 3. �����Ϣ����
char Value(BiTree T, BiTNode* e);                // ��ȡ���ֵ
void Assign(BiTree T, BiTNode* e, char value);   // ��ֵ

BiTNode* Parent(BiTree T, BiTNode* e);           // ˫��
BiTNode* LeftChild(BiTree T, BiTNode* e);        // ����
BiTNode* RightChild(BiTree T, BiTNode* e);       // �Һ���
BiTNode* LeftSibling(BiTree T, BiTNode* e);      // ���ֵ�
BiTNode* RightSibling(BiTree T, BiTNode* e);     // ���ֵ�

// 4. ��������/ɾ��
void InsertChild(BiTree& T, BiTNode* p, int LR, BiTree c); // ������/������
void DeleteChild(BiTree& T, BiTNode* p, int LR);           // ɾ����/������

// 5. ����
void PreOrderTraverse(BiTree T, void (*Visit)(BiTNode*));   // ����
void InOrderTraverse(BiTree T, void (*Visit)(BiTNode*));    // ����
void PostOrderTraverse(BiTree T, void (*Visit)(BiTNode*));  // ����
void LevelOrderTraverse(BiTree T, void (*Visit)(BiTNode*)); // ����

void Visit(BiTNode* node);
#endif

