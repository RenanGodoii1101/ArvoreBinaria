#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digito;
    struct Node *left;
    struct Node *right;
} Node;

Node* criarNo(int digito) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->digito = digito;
    novoNo->left = NULL;
    novoNo->right = NULL;
    return novoNo;
}

Node* inserir(Node* root, int digito) {
    if (root == NULL) {
        return criarNo(digito);
    }
    if (digito < root->digito) {
        root->left = inserir(root->left, digito);
    } else {
        root->right = inserir(root->right, digito);
    }
    return root;
}

void visualizar(Node* root) {
    if (root != NULL) {
        visualizar(root->left);
        printf("%d ", root->digito);
        visualizar(root->right);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int cpf[11];

    printf("Dê os 11 dígitos do CPF: ");
    for (int i = 0; i < 11; i++) {
        scanf("%d", &cpf[i]);
        root = inserir(root, cpf[i]);
    }

    printf("Os dígitos do CPF armazenados na árvore em ordem: ");
    visualizar(root);
    printf("\n");

    freeTree(root);
    return 0;
}
