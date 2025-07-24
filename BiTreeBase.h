#ifndef BITREEBASE_H //第一次包含该头文件时，这个条件为真，会执行下面的代码；第二次包含时，由于宏已被定义，条件为假，直接跳到 #endif 之后。
#define BITREEBASE_H //与 #ifndef 配合，标记 “这个头文件已经被包含过了”。

#include <iostream>
#include <queue>
using namespace std;


// 一、结构定义
struct BiTNode{
	char data;
	BiTNode* left;
	BiTNode* right;
	BiTNode() : data('\0'), left(nullptr), right(nullptr) {}
	BiTNode(char x):data(x),left(nullptr),right(nullptr){}
};

typedef BiTNode* BiTree;

//二、操作函数声明

// 1. 初始化和销毁
void InitBiTree(BiTree& T);                      // 构造空树
void DestroyBiTree(BiTree& T);                   // 销毁树
void ClearBiTree(BiTree& T);                     // 清空树（置空）

// 2. 创建和基本性质
void CreateBiTree(BiTree& T);                    // 按先序定义输入创建
bool BiTreeEmpty(BiTree T);                      // 是否为空
int BiTreeDepth(BiTree T);                       // 树深度
BiTNode* Root(BiTree T);                         // 返回根结点

// 3. 结点信息操作
char Value(BiTree T, BiTNode* e);                // 获取结点值
void Assign(BiTree T, BiTNode* e, char value);   // 赋值

BiTNode* Parent(BiTree T, BiTNode* e);           // 双亲
BiTNode* LeftChild(BiTree T, BiTNode* e);        // 左孩子
BiTNode* RightChild(BiTree T, BiTNode* e);       // 右孩子
BiTNode* LeftSibling(BiTree T, BiTNode* e);      // 左兄弟
BiTNode* RightSibling(BiTree T, BiTNode* e);     // 右兄弟

// 4. 子树插入/删除
void InsertChild(BiTree& T, BiTNode* p, int LR, BiTree c); // 插入左/右子树
void DeleteChild(BiTree& T, BiTNode* p, int LR);           // 删除左/右子树

// 5. 遍历
void PreOrderTraverse(BiTree T, void (*Visit)(BiTNode*));   // 先序
void InOrderTraverse(BiTree T, void (*Visit)(BiTNode*));    // 中序
void PostOrderTraverse(BiTree T, void (*Visit)(BiTNode*));  // 后序
void LevelOrderTraverse(BiTree T, void (*Visit)(BiTNode*)); // 层序

void Visit(BiTNode* node);
#endif

