#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    int lchild;
    int rchild;
} Node[11];

int seq[11][2];
bool flag1 = false, flag2 = false;

void buildTree(int root) {
    Node[root].lchild = seq[root][1];
    Node[root].rchild = seq[root][0];
    if (Node[root].lchild != -1) {
        buildTree(Node[root].lchild);
    }
    if (Node[root].rchild != -1) {
        buildTree(Node[root].rchild);
    }
}

void inOrder(int root) {
    if (root == -1) {
        return;
    }
    inOrder(Node[root].lchild);
    if (flag2) {
        printf(" ");
    } else {
        flag2 = true;
    }
    printf("%d", root);
    inOrder(Node[root].rchild);
    return;
}

void levelOrder(int root) {
    queue<int> q;
    if (root != -1) {
        q.push(root);
    }
    while (!q.empty()) {
        if (flag1) {
            printf(" ");
        } else {
            flag1 = true;
        }
        int now = q.front();
        printf("%d", now);
        q.pop();
        if (Node[now].lchild != -1) {
            q.push(Node[now].lchild);
        }
        if (Node[now].rchild != -1) {
            q.push(Node[now].rchild);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    bool hashTable[n] = {false};
    for (int i = 0; i < n; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        if ('0' <= c1 && c1 <= '9') {
            int number = c1 - '0';
            hashTable[number] = true;
            seq[i][0] = number;
        } else if (c1 == '-') {
            seq[i][0] = -1;
        }
        if ('0' <= c2 && c2 <= '9') {
            int number = c2 - '0';
            hashTable[number] = true;
            seq[i][1] = number;
        } else if (c2 == '-') {
            seq[i][1] = -1;
        }
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (hashTable[i] == false) {
            root = i;
            break;
        }
    }

    // // test
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", seq[i][0], seq[i][1]);
    // }
    // printf("root is %d", root);

    buildTree(root);
    levelOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    return 0;
}