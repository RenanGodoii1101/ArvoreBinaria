#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int digito;
    struct Node *left, *right;
} Node;

Node* criarNo(int digito) {
    Node* addNo = (Node*)malloc(sizeof(Node));
    addNo->digito = digito;
    addNo->left = addNo->right = NULL;
    return addNo;
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

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* remover(Node* root, int digito) {
    if (root == NULL) {
        return root;
    }
    if (digito < root->digito) {
        root->left = remover(root->left, digito);
    } else if (digito > root->digito) {
        root->right = remover(root->right, digito);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->digito = temp->digito;
        root->right = remover(root->right, temp->digito);
    }
    return root;
}

void arvoreOrdem(Node* root) {
    if (root != NULL) {
        arvoreOrdem(root->left);
        printf("%d ", root->digito);
        arvoreOrdem(root->right);
    }
}

int main() {
    Node* root = NULL;
    int cpfDigitos[11];

    printf("Insira 11 dígitos do CPF:\n");
    for (int i = 0; i < 11; i++) {
        scanf("%d", &cpfDigitos[i]);
        root = inserir(root, cpfDigitos[i]);
    }

    printf("Árvore em ordem: ");
    arvoreOrdem(root);
    printf("\n");

    int digitoRemover = cpfDigitos[6];
    root = remover(root, digitoRemover);

    printf("Árvore em ordem (após remover o dígito): ");
    arvoreOrdem(root);
    printf("\n");

    return 0;
}
