#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int pre[40], in[40];
bool flag = false;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* buildTree(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }

    node* root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++) {
        if (in[k] == pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->lchild = buildTree(preL + 1, preL + numLeft, inL, k - 1);
    root->rchild = buildTree(preL + numLeft + 1, preR, k + 1, inR);
    return root;
}

void postOrder(node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    if (flag) {
        printf(" ");
    } else {
        flag = true;
    }
    printf("%d", root->data);
}

int main() {
    int n, preIndex = 0, inIndex = 0, tmp;
    stack<int> st;
    scanf("%d", &n);

    // 从输入的数据里面构造先序序列pre[]和中序序列in[]
    for (int i = 0;i < 2 * n; i++) {
        char cmd[5];
        scanf("%s", cmd);
        if (strcmp(cmd, "Push") == 0) {
            scanf("%d", &tmp);
            pre[preIndex++] = tmp;
            st.push(tmp);
        } else {
            in[inIndex++] = st.top();
            st.pop();
        }
    }

    node* root = buildTree(0, n - 1, 0, n - 1);
    postOrder(root); 
    return 0;
}