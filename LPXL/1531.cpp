//
// Created by smallflyfly on 2021/8/18.
//

#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

typedef struct TreeNode {
    char data;
    struct TreeNode *lchild, *rchild;
}TreeNode, *BinTree;

char preOrderTree[1001];
char inorderTree[1001];

int n;

void buildTree(BinTree &T, int s1, int n1, int s2, int n2) {
    int i;
    T = new TreeNode;
    T->data = preOrderTree[s1];
    for (i = s2; i < n2; ++i) {
        if (preOrderTree[s1] == inorderTree[i]){
            break;
        }
    }
    T->lchild = nullptr;
    T->rchild = nullptr;
    if (i > s2) {
        // 有左子树
        buildTree(T->lchild, s1+1, s1+i-s2+1, s2, i);
    }
    if (i < n2-1) {
        // 有右子树
        buildTree(T->rchild, s1+i-s2+1, n1, i+1, n2);
    }
}

int treeDepth(BinTree T, map<char, int> &depthMap) {
    int ldepth, rdepth;
    if (T == nullptr) {
        return 0;
    }
    if (T->lchild == nullptr && T->rchild == nullptr) {
        return 1;
    }
    ldepth = treeDepth(T->lchild, depthMap);
    rdepth = treeDepth(T->rchild, depthMap);
    depthMap.insert(pair<char, int>(T->data, ldepth+rdepth));
    return ldepth + rdepth;
}

void preTraverse(BinTree T, map<char, int> depthMap) {
    if (T != nullptr) {
        int c = depthMap[T->data];
        for (int i = 0; i < c-1; ++i) {
            printf("%c", T->data);
        }
        printf("%c\n", T->data);
        preTraverse(T->lchild, depthMap);
        preTraverse(T->rchild, depthMap);
    }
}

int main() {
    memset(preOrderTree, 0, sizeof(preOrderTree));
    memset(inorderTree, 0, sizeof(inorderTree));
    while (scanf("%s", &preOrderTree) != EOF) {
        scanf("%s", &inorderTree);
        n = strlen(preOrderTree);
        BinTree binTree;
        buildTree(binTree, 0, n, 0, n);
        map<char, int> depthMap;
        treeDepth(binTree, depthMap);
        preTraverse(binTree, depthMap);
    }

    return 0;
}