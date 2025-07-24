#include "BiTreeBase.h"

int main() {
    BiTree T;
    InitBiTree(T);
    cout << "请输入二叉树先序序列（用#表示空节点）：";
    CreateBiTree(T); // 示例输入：ABC##DE#G##F###

    cout << "树是否为空：" << (BiTreeEmpty(T) ? "是" : "否") << endl;
    cout << "树深度：" << BiTreeDepth(T) << endl;

    cout << "先序遍历：";
    PreOrderTraverse(T, Visit); // 输出：A B C D E G F
    cout << endl;

    cout << "中序遍历：";
    InOrderTraverse(T, Visit); // 输出：C B E G D F A
    cout << endl;

    cout << "后序遍历：";
    PostOrderTraverse(T, Visit); // 输出：C G E F D B A
    cout << endl;

    cout << "层序遍历：";
    LevelOrderTraverse(T, Visit); // 输出：A B D C E F G
    cout << endl;

    BiTNode* root = Root(T);
    if (root) {
        cout << "根节点值：" << Value(T, root) << endl;
        Assign(T, root, 'X');
        cout << "修改后根节点值：" << Value(T, root) << endl;
    }

    // 测试插入和删除
    BiTree newTree;
    InitBiTree(newTree);
    newTree = new BiTNode('Y');
    InsertChild(T, root, 0, newTree); // 插入新子树
    cout << "插入新左子树后先序遍历：";
    PreOrderTraverse(T, Visit);
    cout << endl;

    DeleteChild(T, root, 0); // 删除左子树
    cout << "删除左子树后先序遍历：";
    PreOrderTraverse(T, Visit);
    cout << endl;

    DestroyBiTree(T); // 清理
    return 0;
}