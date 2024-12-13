#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tree.h"



//creation de la queue pour le topview
typedef struct queue queue;
struct queue {
    Tree* node;
    int dist;
    queue* next;
};

queue* createQueueNode(Tree* root,const int data) {
    queue* newQueue = (queue*)malloc(sizeof(queue));
    newQueue->dist = data;
    newQueue->node = root;
    newQueue->next = NULL;
    return newQueue;
}



/*void testIsSymmetricTree() {
    Tree* root = NULL;
    printf("remplissage de l'arbre \n");
    for(int i = 0;i < 7;i++) {
        int value = 0;
        scanf("%d",&value);
        root = insert(root,value);
    }
    if(isSymmetricTree(root)) {
        printf("l'arbre est symmetric\n");
    }else {
        printf("l'arbre n'est pas symmetric\n");
    }
    deleteTree(root);
}*/

/*toute la fonction est encore en phase de test
 *void enqueue(queue** front,queue** rear,Tree* root,const int dist) {
    queue* newQueue = createQueueNode(root,dist);
    if(*rear) {
        (*rear)->next = newQueue;
    }else {
        *front = newQueue;
    }
    *rear = newQueue;
}

Tree* dequeue(queue** front,queue** rear,int* dist) {
    if(*front == NULL) {
        return NULL;
    }
    queue* temp = *front;
    Tree* node = temp->node;
    *dist = temp->dist;
    *front = temp->next;
    if(*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return node;
}

void topView(Tree* root) {
    if(root == NULL) {
        return;
    }
    queue *front = NULL,*rear = NULL;
    int min_dist = INT_MAX, max_dist = INT_MIN;
    int horizontal_dist[200] = {0};

    enqueue(&front,&rear,root,0);

    while(front) {
        int dist;
        Tree* node = dequeue(&front,&rear,&dist);

        if(dist < min_dist)min_dist = dist;
        if(dist > max_dist)max_dist = dist;

        if(horizontal_dist[dist + 100] == 0) {
            printf("%d",node->data);
            horizontal_dist[dist + 100] = 1;
        }
        if(node->left) {
            enqueue(&front,&rear,node->left,dist-1);
        }
        if(node->right) {
            enqueue(&front,&rear,node->right,dist + 1);
        }
    }
}

void testTopView() {
    Tree* root = NULL;
    int nbr = 0;

    printf("entrez le nombre d'element de l'arbre... : \n");
    scanf("%d",&nbr);

    for(int i = 0;i < nbr;i++) {
        int value = 0;
        printf("\nentrez l'element numero %d : ",i+1);
        scanf("%d",&value);
        root = insert(root,value);
    }
    printf("affichage du topView\n");
    topView(root);
    deleteTree(root);

    if(isEmpty(root)) {
        printf("l'arbre a ete vide avec succes\n");
    }
    else {
        printf("echec de la suppression de l'arbre \n");
    }
}*/




void testIsBalanced() {
    Tree* root = NULL;

    root = insert(root,11);
    root = insert(root,9);
    root = insert(root,20);
    root = insert(root,15);
    root = insert(root,7);
    printf("envoi sur isBalanced\n");

    if(isBalanced(root)) {
        printf("le tree est equilibre\n");
    }else {
        printf("le tree n'est pas equilibre\n");
    }

    deleteTree(root);
}

void testSortedArrayToBST() {
    int t[]= {-10,-3,0,5,9};
    Tree* root = sortedArrayToBST(t,5);
    levelOrder(root);
    deleteTree(root);
}

void testLevelOrder() {
    Tree* root = NULL;
    printf("remplissage de l'arbre \n");
    for(int i = 0;i < 7;i++) {
        int value = 0;
        scanf("%d",&value);
        root = insert(root,value);
    }
    levelOrder(root);
    deleteTree(root);
}

void testSameTree() {
    Tree* tree_1 = NULL;
    Tree* tree_2 = NULL;
    printf("remplissage du premier arbre\n");
    for(int i = 0;i < 3;i++) {
        int value = 0;
        scanf("%d",&value);
        tree_1 = insert(tree_1,value);
    }
    printf("remplissage du second arbre\n");
    for(int i = 0;i < 3;i++) {
        int value = 0;
        scanf("%d",&value);
        tree_2 = insert(tree_2,value);
    }
    if(sameTree(tree_1,tree_2)) {
        printf("les deux arbres sont identiques\n");
    }
    else {
        printf("les deux arbres ne sont pas identiques\n");
    }
    deleteTree(tree_1);
    free(tree_2);
}

void testLCA() {
    Tree* arbre = NULL;
    printf("entrez le nombre d'element de l'arbre \n");
    int nbr = 0;
    scanf("%d",&nbr);

    for(int i = 0;i < nbr;i++) {
        printf("\nentrez la valeur numero %d :  ",i+1);
        int value = 0;
        scanf("%d",&value);
        arbre = insert(arbre,value);
    }

    printf("c'est partie pour la recherche du parent.... \n");
    Tree* parent = lca(arbre,4,6);

    printf("la valeur du parent %d \n",parent->data);

    deleteTree(arbre);
}

void testPrintModel() {
    Tree* tree = NULL;
    printf("entrez le nombre d'element de l'arbre : \n");
    short nbr = 0;
    scanf("%hd",&nbr);

    for(int i = 0;i < nbr;i++) {
        printf("\ninserez l'element numero %d : ",i+1);
        int value = 0;
        scanf("%d",&value);
        tree = insert(tree,value);
    }

    printf("affichage en inOrder\n");
    inOrder(tree);
    printf("\n affichage en preOrder\n");
    preOrder(tree);
    printf("\n affichage en postOrder\n");
    postOrder(tree);
    printf("affichage en levelOrder\n");
    levelOrder(tree);

    deleteTree(tree);
}

void testInvertTree() {
    Tree* root = NULL;
    printf("entrez le nombre d'element de l'arbre :  \n");
    short nbr = 0;
    scanf("%hd",&nbr);

    for(short i = 0;i < nbr;i++) {
        printf("entrez la valeur numero %hd  :  ",i+1);
        int value = 0;
        scanf("%hd",&value);
        root = insert(root,value);
    }

    printf("affichage de la premiere entree\n");
    levelOrder(root);
    printf("\n premiere essaie de la fonction levelOrderToArray\n");
    Tree* newRoot = invertTree(root);

    levelOrder(newRoot);
    deleteTree(root);
    deleteTree(newRoot);
}


int main(void) {
    testInvertTree();
    return 0;
}
/*fonction main pour travailler avec la fonction insert qui le fait sur la logique l'arbre de recherche binaire
 * la fonction ne fait que ajouter l'un apres l'autre tout en respectant les regles de la recherche d'arbre binaire
* int main() {

    struct node* root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    preOrder(root);
    return 0;
}
 */

