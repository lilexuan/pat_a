#include <cstdio>
#include <queue>
using namespace std;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

const int MAXN = 31;
int post[MAXN], in[MAXN];

node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR) {
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

void levelOrder(node* root) {
    if (root == NULL) {
        return;
    }
    queue<node*> q;
    q.push(root);
    bool flag = false;
    while (!q.empty()) {
        node* now = q.front();
        if (flag) {
            printf(" ");
        }
        flag = true;
        printf("%d", now->data);
        q.pop();
        if (now->lchild != NULL) {
            q.push(now->lchild);
        }
        if (now->rchild != NULL) {
            q.push(now->rchild);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }
    node* root = create(0, N - 1, 0, N - 1);
    // printf("hello world\n");
    levelOrder(root);
    return 0;
}