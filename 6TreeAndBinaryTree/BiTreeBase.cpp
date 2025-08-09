#include "BiTreeBase.h"  //这一步是告诉编译器：我们要实现头文件 BiTreeBase.h 中声明的那些函数。

void InitBiTree(BiTree& T) {
	T = nullptr;
};


void DestroyBiTree(BiTree& T) {
	if (T == nullptr) return;
	DestroyBiTree(T->left);
	DestroyBiTree(T->right);
	delete T;
	T = nullptr;
}

void ClearBiTree(BiTree& T) {
	DestroyBiTree(T);
}

void CreateBiTree(BiTree& T) {
	char ch;
	cin >> ch;
	if (ch == '#') T = nullptr;

	else {
		T = new BiTNode;
		T->data = ch;	
		CreateBiTree(T->left);
		CreateBiTree(T->right);
	}
}

bool BiTreeEmpty(BiTree T) {
	if (T == nullptr) {
		return true;
	}
	else {
		return false;
	}
};

int BiTreeDepth(BiTree T) {
	if (BiTreeEmpty(T)) {
		return 0;
	}

	else {
		int leftDepth = BiTreeDepth(T->left);
		int rightDepth = BiTreeDepth(T->right);
		return 1 + max(leftDepth, rightDepth);
	}
}

BiTNode* Root(BiTree T) {
	return T;
}

char Value(BiTree T, BiTNode* e) {
	if (T == nullptr || e == nullptr) {
		return '\0'; // 空树或空节点返回空字符
	}
	return e->data; // 返回指定节点的值
}

void Assign(BiTree T, BiTNode* e, char value) {
    if (T == nullptr || e == nullptr) {
        return;
    }
    e->data = value;
}

BiTNode* Parent(BiTree T, BiTNode* e) {
    if (T == nullptr || e == nullptr || T == e) {
        return nullptr;
    }
    queue<BiTNode*> q;
    q.push(T);
    while (!q.empty()) {
        BiTNode* current = q.front();
        q.pop();
        if (current->left == e || current->right == e) {
            return current;
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return nullptr;
}

BiTNode* LeftChild(BiTree T, BiTNode* e) {
    if (T == nullptr || e == nullptr) {
        return nullptr;
    }
    return e->left;
}

BiTNode* RightChild(BiTree T, BiTNode* e) {
    if (T == nullptr || e == nullptr) {
        return nullptr;
    }
    return e->right;
}

BiTNode* LeftSibling(BiTree T, BiTNode* e) {
    if (T == nullptr || e == nullptr) {
        return nullptr;
    }
    BiTNode* parent = Parent(T, e);
    if (parent == nullptr || parent->left == nullptr || parent->right == e) {
        return nullptr;
    }
    return parent->left;
}

BiTNode* RightSibling(BiTree T, BiTNode* e) {
    if (T == nullptr || e == nullptr) {
        return nullptr;
    }
    BiTNode* parent = Parent(T, e);
    if (parent == nullptr || parent->right == nullptr || parent->left == e) {
        return nullptr;
    }
    return parent->right;
}

void InsertChild(BiTree& T, BiTNode* p, int LR, BiTree c) {
    if (T == nullptr || p == nullptr) {
        return;
    }
    if (LR == 0) {
        BiTree temp = p->left;
        p->left = c;
        DestroyBiTree(temp);
    }
    else if (LR == 1) {
        BiTree temp = p->right;
        p->right = c;
        DestroyBiTree(temp);
    }
}

void DeleteChild(BiTree& T, BiTNode* p, int LR) {
    if (T == nullptr || p == nullptr) {
        return;
    }
    if (LR == 0) {
        DestroyBiTree(p->left);
        p->left = nullptr;
    }
    else if (LR == 1) {
        DestroyBiTree(p->right);
        p->right = nullptr;
    }
}

void PreOrderTraverse(BiTree T, void (*Visit)(BiTNode*)) {
    if (T == nullptr) {
        return;
    }
    Visit(T);
    PreOrderTraverse(T->left, Visit);
    PreOrderTraverse(T->right, Visit);
}

void InOrderTraverse(BiTree T, void (*Visit)(BiTNode*)) {
    if (T == nullptr) {
        return;
    }
    InOrderTraverse(T->left, Visit);
    Visit(T);
    InOrderTraverse(T->right, Visit);
}

void PostOrderTraverse(BiTree T, void (*Visit)(BiTNode*)) {
    if (T == nullptr) {
        return;
    }
    PostOrderTraverse(T->left, Visit);
    PostOrderTraverse(T->right, Visit);
    Visit(T);
}

void LevelOrderTraverse(BiTree T, void (*Visit)(BiTNode*)) {
    if (T == nullptr) {
        return;
    }
    queue<BiTNode*> q;
    q.push(T);
    while (!q.empty()) {
        BiTNode* current = q.front();
        q.pop();
        Visit(current);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// 示例 Visit 函数
void Visit(BiTNode* node) {
    if (node) {
        cout << node->data << " ";
    }
}

