#include "BiTreeBase.h"

int main() {
    BiTree T;
    InitBiTree(T);
    cout << "������������������У���#��ʾ�սڵ㣩��";
    CreateBiTree(T); // ʾ�����룺ABC##DE#G##F###

    cout << "���Ƿ�Ϊ�գ�" << (BiTreeEmpty(T) ? "��" : "��") << endl;
    cout << "����ȣ�" << BiTreeDepth(T) << endl;

    cout << "���������";
    PreOrderTraverse(T, Visit); // �����A B C D E G F
    cout << endl;

    cout << "���������";
    InOrderTraverse(T, Visit); // �����C B E G D F A
    cout << endl;

    cout << "���������";
    PostOrderTraverse(T, Visit); // �����C G E F D B A
    cout << endl;

    cout << "���������";
    LevelOrderTraverse(T, Visit); // �����A B D C E F G
    cout << endl;

    BiTNode* root = Root(T);
    if (root) {
        cout << "���ڵ�ֵ��" << Value(T, root) << endl;
        Assign(T, root, 'X');
        cout << "�޸ĺ���ڵ�ֵ��" << Value(T, root) << endl;
    }

    // ���Բ����ɾ��
    BiTree newTree;
    InitBiTree(newTree);
    newTree = new BiTNode('Y');
    InsertChild(T, root, 0, newTree); // ����������
    cout << "�����������������������";
    PreOrderTraverse(T, Visit);
    cout << endl;

    DeleteChild(T, root, 0); // ɾ��������
    cout << "ɾ�������������������";
    PreOrderTraverse(T, Visit);
    cout << endl;

    DestroyBiTree(T); // ����
    return 0;
}