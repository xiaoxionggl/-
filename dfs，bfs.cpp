/*
我先讲讲大概的实现思路，首先，这8个城市太不方便了，用string里面的比较函数写起来不够直观，
所以，我把城市写成数组，后续就用编号代替。然后，我使用了离散数学里面的邻接矩阵，邻接矩阵
实际上记录了图里边节点与节点之间是否由一条边连接，标准的邻接矩阵用的是0,1来表示，但是这里
的实际情境中有权重，也就是距离，所以没连上的还是0，但是原来的1被我换成了距离，这样后续计算时
就比较方便，最后，关于bfs和dfs，算法是规定好的，没什么特别的内容，bfs加上邻接矩阵很好理解，
（也需要一些离散数学的基础），dfs难在对递归的理解（出口。。。）

基本就是这样了，这个确实有难度，算法能理解，但是用代码实现就难了。   写于2025.2.11晚上
*/

#include <iostream>
#include <string>

using namespace std;

// 城市数组
string cities[] = {
    "New York", "Chicago", "Denver", "Toronto",
    "Calgary", "Urbana", "Houston", "Los Angeles"
};

const int city_num = 8; // 城市总数

// 邻接矩阵（存储城市之间的距离）
int G[city_num][city_num] = { 0 };

// 初始化邻接矩阵
void init_flights() {
    // 纽约相关
    G[0][1] = 900;  G[1][0] = 900;  // New York <-> Chicago
    G[0][3] = 500;  G[3][0] = 500;  // New York <-> Toronto
    G[0][2] = 1800; G[2][0] = 1800; // New York <-> Denver

    // 芝加哥相关
    G[1][2] = 1000; G[2][1] = 1000; // Chicago <-> Denver
    G[1][3] = 500;  G[3][1] = 500;  // Chicago <-> Toronto

    // 丹佛相关
    G[2][5] = 1000; G[5][2] = 1000; // Denver <-> Urbana
    G[2][6] = 1000; G[6][2] = 1000; // Denver <-> Houston
    G[2][7] = 1000; G[7][2] = 1000; // Denver <-> Los Angeles

    // 多伦多相关
    G[3][4] = 1700; G[4][3] = 1700; // Toronto <-> Calgary
    G[3][7] = 2500; G[7][3] = 2500; // Toronto <-> Los Angeles

    // 休斯顿相关
    G[6][7] = 1500; G[7][6] = 1500; // Houston <-> Los Angeles
}

// 自定义队列结构（用于BFS）
struct Queue {
    int data[city_num]; // 存储队列元素
    int front;          // 队头指针
    int rear;           // 队尾指针
};

// init=初始化队列
void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空
bool is_queue_empty(Queue* q) {
    return q->front == q->rear;   //相当于最前的和最后的是同一个，那么里面就没东西了
}

// 入队操作
void enqueue(Queue* q, int value) {           //value是一个城市的编号
    if ((q->rear + 1) % city_num == q->front) {  //队取余 = 保证编号不越界，达到最大值后自动回到 0
        cout << "队列溢出！" << endl;
        return;
    }
    q->data[q->rear] = value;   
    q->rear = (q->rear + 1) % city_num;
}

// 出队操作
int dequeue(Queue* q) {
    if (is_queue_empty(q)) {           // 步骤1：检查队列是否为空
        cout << "队列为空！" << endl;
        return -1;
    }
    int value = q->data[q->front]; // 步骤2：取出队头元素（front指向的位置）
    q->front = (q->front + 1) % city_num;// 步骤3：队头指针后移（环形移动，模拟出队）
    return value;// 步骤4：返回取出的元素值
}

// 深度优先搜索（DFS）
// current: 当前访问的城市索引
// target: 目标城市索引(就是内个去向哪里)
// *path: 指向存储当前路径字符串数组的指针 (路径上的城市名)
// path_len: 当前路径的长度 (包含多少个城市)
// *visited: 指向布尔数组的指针，标记城市在当前DFS路径中是否已被访问
// *result_path: 指向用于存储最终找到的路径字符串的指针
// *result_dist: 指向用于存储最终找到的路径总距离的指针
void dfs(int current, int target, string* path, int path_len, bool* visited, string* result_path, int* result_dist) {

    
    if (current == target) {// 递归出口：如果当前城市==目标城市
        
        *result_path = path[0]; // 从路径的第一个城市开始
        for (int i = 1; i < path_len; i++) {
            *result_path += " to " + path[i]; // 拼接后续城市
        }

        // 计算该路径的总距离
        *result_dist = 0; // 初始化总距离为0
        // 遍历路径中的每一段（相邻两个城市）
        for (int i = 0; i < path_len - 1; i++) {
            // 查找 path[i] (段起点城市名) 在全局 cities 数组中的索引 j
            for (int j = 0; j < city_num; j++) {
                if (path[i] == cities[j]) {
                    // 查找 path[i+1] (段终点城市名) 在全局 cities 数组中的索引 k
                    for (int k = 0; k < city_num; k++) {
                        if (path[i + 1] == cities[k]) {
                            *result_dist += G[j][k]; // 累加这两个城市间的距离
                            
                        }
                    }
                }
            }
        }
        return; // 找到路径，结束当前递归分支
    }

    // 标记当前城市为已访问（在当前DFS路径中）
    visited[current] = true;

    // 遍历所有可能的下一个城市
    for (int i = 0; i < city_num; i++) {
        // 如果城市 i 与当前城市 current 之间有路径，并且城市 i 在当前DFS路径中未被访问过
        if (G[current][i] != 0 && !visited[i]) {
            path[path_len] = cities[i]; // 将城市 i 加入当前路径
            // 递归调用DFS，从城市 i 继续搜索，路径长度加1
            dfs(i, target, path, path_len + 1, visited, result_path, result_dist);
        }
    }

    
    
    visited[current] = false;// 回溯：取消对当前城市的访问标记
}

// 广度优先搜索（BFS）
void bfs(int start, int target) {        //city_num =8
    bool visited[city_num] = { false };  // 记录已访问节点
    int prev[city_num];                  // 记录前驱节点（前驱就是前面的那个）
    int dist[city_num] = { 0 };          // 记录到起点的距离（默认为0）

    
    for (int i = 0; i < city_num; i++) {
        prev[i] = -1;
    }

    Queue queue;  
    init_queue(&queue);  //&取地址
    enqueue(&queue, start);  // 入队
    visited[start] = true;

    while (!is_queue_empty(&queue)) {
        int current = dequeue(&queue);  // 取出队头节点

        // 遍历所有相邻节点
        for (int i = 0; i < city_num; i++) {
            if (G[current][i] != 0 && !visited[i]) {  //邻接矩阵不为0，即可以一步到达 && 没访问过
                visited[i] = true;   //第i个访问了
                prev[i] = current;  // 记录前驱节点
                dist[i] = dist[current] + G[current][i];  // 更新距离
                enqueue(&queue, i);  // 将节点入队

                // 如果找到目标节点
                if (i == target) {
                    // 回溯路径（从终点到起点）
                    string path[city_num];
                    int path_len = 0;
                    int node = target;    //node 当前指向要回溯的城市编号
                    while (node != -1) {  // 直到回到起点（prev[start]=-1）
                        path[path_len++] = cities[node];
                        node = prev[node];
                    }

                    // 反转,输出结果
                    string final_path = path[path_len - 1];  // 起点
                    for (int j = path_len - 2; j >= 0; j--) {
                        final_path += " to " + path[j];  // 添加中间节点和终点
                    }

                    cout << "BFS 找到路径: " << final_path << endl;
                    cout << "总距离: " << dist[target] << endl;
                    return;  
                }
            }
        }
    }
    cout << "BFS 未找到路径。" << endl;
}
int main() {
    init_flights(); // 初始化航班数据

    // 获取用户输入
    string from, to;
    cout << "从哪个城市出发？ ";
    cin >> from;
    cout << "目标城市是？ ";
    cin >> to;

    // 查找起始城市和目标城市的索引
    int start = -1, target = -1;
    for (int i = 0; i < city_num; i++) {
        if (cities[i] == from)  start = i;
        if (cities[i] == to)   target = i;
    }

    if (start == -1 || target == -1) {
        cout << "城市未找到，请检查拼写（区分大小写）。" << endl;
        return 0;
    }

    // 深度优先搜索（DFS）
    string dfs_path;
    int dfs_dist = 0;
    string path_dfs[city_num]; // 存储DFS路径
    path_dfs[0] = cities[start]; // 起点城市
    bool visited_dfs[city_num] = { false }; // 记录已访问城市
    dfs(start, target, path_dfs, 1, visited_dfs, &dfs_path, &dfs_dist);

    if (dfs_path != "") {
        cout << "DFS 找到路径: " << dfs_path << endl;
        cout << "总距离: " << dfs_dist << endl;
    }
    else {
        cout << "DFS 未找到路径。" << endl;
    }

    // 广度优先搜索（BFS）
    bfs(start, target);

    return 0;
}

