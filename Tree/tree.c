//
// Created by claude delcroix on 31/10/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tree.h"


Tree* createNode(const int data) {
    Tree* noeud = (Tree*)malloc(sizeof(Tree));
    if(noeud == NULL) {
        fprintf(stderr,"l'allocation a echoue\n");
        exit(EXIT_FAILURE);
    }
    noeud->data = data;
    noeud->left = NULL;
    noeud->right = NULL;

    printf("Creationn de %d\n",noeud->data);
    return noeud;
}

Tree* insert(Tree* root,const int data) {
    if(root == NULL) {
        Tree* node = createNode(data);
        return node;
    }else {
        Tree* cur;

        if(data <= root->data) {
            cur = insert(root->left,data);
            root->left = cur;
        }else {
            cur = insert(root->right,data);
            root->right = cur;
        }
        return root;
    }
}

void deleteTree(Tree* tree) {
    if(tree == NULL) {
        printf("suppression reussie...\n");
        exit(0);
    }
    printf("suppression de %d\n",tree->data);

    deleteTree(tree->right);
    deleteTree(tree->left);
    free(tree);
}

bool isEmpty(const Tree* root) {
    return root == NULL;
}

Tree* join_tree(Tree* left,Tree* right,const int node) {
    Tree *tree = createNode(node);
    tree->left = left;
    tree->right = right;

    if(left != NULL) {
        left->root = tree;
    }
    if(right != NULL) {
        right->root = tree;
    }
    return tree;
}

void print_tree_prefix(const Tree* tree) {
    if(tree == NULL) {
        fprintf(stderr,"erreur l'arbre est vide\n");
        return;
    }
    if(tree->root != NULL) {
        printf("(%d) -> (%d)\n",tree->root->data,tree->data);
    }
    else {
        printf("(%d)\n",tree->data);
    }
    if(tree->left != NULL) {
        print_tree_prefix(tree->left);
    }
    if(tree->right != NULL) {
        print_tree_prefix(tree->right);
    }

}

int count_tree_node(const Tree* tree) {
    if(tree == NULL) {
      return 0;
    }
    return (count_tree_node(tree->left) + count_tree_node(tree->right) + 1);
}

// aa une faille a revoir cette fonction
/*la fonction a echoue au test de hackerrank lorsque le nombre total de node etait 15, forcement par ce que ce n'etait pas un binary search tree*/
/*solution en C++ en attendant de meilleure eclaircissement
 *
 */
int getHeight(const Tree* tree) {
    // Write your code here
    return (int)(ceil(log2(count_tree_node(tree))));
}

//affichage en commencant par le left node
void preOrder(const Tree *root) {
    if(root != NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

//affichage en commencant par le right node
void postOrder(const Tree *root) {
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

//affichage en ordre
void inOrder(const Tree*root) {
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void inOrderTraversal(const Tree* root,int* array,int* index) {
    if(root != NULL) {
        inOrderTraversal(root->left,array,index);
        array[*index] = root->data;
        (*index)++;
        inOrderTraversal(root->right,array,index);
    }
}

int* inOrderInArray(const Tree* root,int* returnize) {
    int* array = (int*)malloc(100*sizeof(int));
    if(array == NULL) {
        fprintf(stderr,"l'alocation dynamique a echouee\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    inOrderTraversal(root,array,&i);

    *returnize = i;
    return array;
}

//une version qui se fait en une seule fonction sans faire appel a une ordre fonction pour recopier les element de l'arbre en ordre croissant
int* inOrderInArray2(const Tree* root, int* returnsize) {
    int* array = (int*)malloc(100 * sizeof(int)); // Taille fixe pour l'exemple
    int i = 0; // Initialisation de l'index

    if (root != NULL) {
        // Traverser l'arbre en ordre croissant
        if (root->left != NULL) {
            int* leftArray = inOrderInArray(root->left, &i);
            for (int j = 0; j < i; j++) {
                array[j] = leftArray[j];
            }
            free(leftArray);
        }
        array[i++] = root->data;
        if (root->right != NULL) {
            int* rightArray = inOrderInArray(root->right, &i);
            for (int j = 0; j < i; j++) {
                array[i + j] = rightArray[j];
            }
            free(rightArray);
        }
    }

    *returnsize = i;
    return array;
}


int count_left_tree(const Tree* root) {
    if(root == NULL) {
        return 0;
    }
    return count_left_tree(root->left) + 1;
}

bool sameTree(const Tree* tree_1,const Tree* tree_2) {
    if(tree_1 == NULL && tree_2 == NULL) {
        return true;
    }
    if(tree_1 == NULL || tree_2 == NULL) {
        return false;
    }
    if(tree_1 ->data != tree_2->data) {
        return false;
    }
    return sameTree(tree_1->left,tree_2->left) && sameTree(tree_1->right,tree_2->right);
}

//cette fonction elle semblable a maxDepth qui calcule la longue profondeur d'un arbre
int height(const Tree* root) {
    if(root == NULL) {
        return 0;
    }
    else {
        const int leftHeight = height(root->left);
        const int rightHeight = height(root->right);
        if(leftHeight > rightHeight) {
            return (leftHeight + 1);
        }else {
            return (rightHeight + 1);
        }
    }
}

void printCurrentLevelOrder(const Tree* root,const int level) {
    if(root == NULL) {
        return;
    }
    if(level == 1) {
        printf("%d ",root->data);
    }else if(level >1) {
        printCurrentLevelOrder(root->left,level - 1);
        printCurrentLevelOrder(root->right,level - 1);
    }
}

void levelOrder(const Tree* root) {
    const int h = height(root);
    for(int i = 1;i <= h;i++) {
        printCurrentLevelOrder(root,i);
    }
}

bool isSameTree(const Tree* tree_1,const Tree* tree_2) {
    if(tree_1 == NULL && tree_2 == NULL) {
        return true;
    }
    if(tree_1 == NULL || tree_2 == NULL) {
        return false;
    }
    if(tree_1 ->data != tree_2->data) {
        return false;
    }
    return sameTree(tree_1->left,tree_2->right) && sameTree(tree_1->right,tree_2->left);
}


bool isSymmetricTree(const Tree* root) {
    // il se peut que le test de root ne soit pas necessaire puisque
    //la fonction isSameTree verifie cela, tout reste encore a verifier avec un test
    /*if(root == NULL) {
        return true;
    }*/
    return isSameTree(root->left,root->right);
}

Tree* sortedArrayToBST(int* arr,const int size) {
    if(size <= 0) {
        return NULL;
    }
    int left = 0;
    int right = (size - 1);
    int mid = (left + right)/2;

    Tree* leftNode = sortedArrayToBST(arr,mid);
    Tree* rightNode = sortedArrayToBST(arr + mid + 1,right - mid);

    Tree* proot = (Tree*)malloc(sizeof(Tree*));
    proot->data = arr[mid];
    proot->left = leftNode;
    proot->right = rightNode;

    return proot;
}

void preOrderInArray(const Tree *root,int* array,int* size) {
    if(root != NULL){
        array[++(*size)] = root->data;
        preOrder(root->left);
        preOrder(root->right);
    }
}

int* preorderTraversal(const Tree* root,int* returnSize) {
    int* array = (int*)malloc(100*sizeof(int));
    int i = 0;

    preOrderInArray(root,array,&i);
    *returnSize = i;
    return array;
}

void postOrderTraversalInArray(const Tree* root,int* array,int* size) {
    if(root != NULL) {
        postOrderTraversalInArray(root->left,array,size);
        postOrderTraversalInArray(root->right,array,size);
        array[(*size)] = root->data;
        (*size)++;
    }
}

int* postOrderTraversal(const Tree* root,int* returnSize) {
    int* array = (int*)malloc(100*sizeof(int));
    if(array == NULL) {
        fprintf(stderr,"erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;

    postOrderTraversalInArray(root,array,&i);
    *returnSize = i;

    return array;
}

bool isBalanced(const Tree* root) {
    if(root == NULL) {
        return true;
    }

    const int leftHeight = height(root->left);
    const int rightHeight = height(root->right);

    if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}

//pour l'instant ne sert pas a grand chose
Tree* lookV(Tree* root,const int v) {
    while(root != NULL && v != root->data) {
        if(v < root->data) {
            root = root->left;
        }else {
            root = root->right;
        }
    }
    return root;
}

Tree* lca(Tree* root,const int v1,const int v2) {
    while(root != NULL) {
        if(v1 < root->data && v2 < root->data) {
            root = root->left;
        }else if(v1 > root->data && v2 > root->data) {
            root = root->right;
        }else {
            break;
        }
    }
    return root;
}

void level_order_to_array(const Tree* root,const int level,int* arr,int* size) {
    if(root == NULL) {
        return;
    }
    if(level == 1) {
        arr[*size] = root->data;
        (*size)++;
    }else if(level > 1) {
        level_order_to_array(root->left,level - 1,arr,size);
        level_order_to_array(root->right,level - 1,arr,size);
    }
}

void levelOrderToArray(const Tree* root,int* arr,int* size) {
    const short h = height(root);
    for(short i = 1;i <= h;i++) {
        level_order_to_array(root,i,arr,size);
    }
}

Tree* invertBinaryTreeFromArray(Tree* root,const int value) {
    if(root == NULL) {
        Tree* node = createNode(value);
        return node;
    }else {
        Tree* cur = NULL;
        if(value >= root->data) {
            cur = invertBinaryTreeFromArray(root->left,value);
            root->left = cur;
        }else {
            cur = invertBinaryTreeFromArray(root->right,value);
            root->right = cur;
        }
        return root;
    }

}

Tree* invertTree(Tree* root) {
    if(root == NULL) {
        return NULL;
    }
    int *arr = (int*)calloc(100,sizeof(int*));
    if(arr == NULL) {
        fprintf(stderr,"allocation arr failled\n");
        exit(EXIT_FAILURE);
    }
    int size = 0;
    levelOrderToArray(root,arr,&size);

    printf("size = %d\n",size);
    for(int i = 0;i < size;i++) {
        printf("%d ",arr[i]);
    }
    Tree* newRoot = NULL;
    newRoot = insert(newRoot,arr[0]);

    for(int i = 1;i < size;i++ ) {
        newRoot = invertBinaryTreeFromArray(newRoot,arr[i]);
    }
    printf("\n affichage du level order apres newRoot \n");
    levelOrder(newRoot);

    free(arr);
    return newRoot;
}

//la solution precedente de invert est bien placer pour resoudre des arbres parfaits qui n'ont pas de valeurs null
//a la place d'un fils mais aussi la fonction pour convertir le level order en tableau est benefique
// Fonction pour inverser un arbre binaire
Tree* invertTreeBest(Tree* root) {
    if(root == NULL) {
        return NULL;
    }

    Tree* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTreeBest(root->left);
    invertTreeBest(root->right);

    return root;
}

Tree* searchMinValue(Tree* root) {
    if(root == NULL || root->data == 0) {
        return NULL;
    }
    if(root->left == NULL) {
        return root;
    }
    return searchMinValue(root->left);
}

Tree* searchMaxValue(Tree* root) {
    if(root == NULL || root->data == 0) {
        return NULL;
    }
    if(root->right == NULL) {
        return root;
    }
    return searchMaxValue(root->right);
}
