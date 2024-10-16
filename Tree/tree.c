#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Tree Tree;
struct Tree {
    int data;
    Tree* right;
    Tree* left;
    Tree* root;
};

Tree* createNode(const int data) {
    Tree* noeud = (Tree*)malloc(sizeof(Tree));
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
    return count_left_tree(root->left);
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

int main(void) {
    /*Tree* binaryTree = NULL;
    for(int i = 0;i<10;i++) {
        int value = 0;
        scanf("%d",&value);
        binaryTree = insert(binaryTree,value);
    }
    printf("Hello, World!\n");
    inOrder(binaryTree);
    printf("le nombre de noeud : %d\n",count_tree_node(binaryTree));
    int height = getHeight(binaryTree);
    printf("le height : %d\n",height);
    int left = count_left_tree(binaryTree);
    printf("le nombre de noeud left : %d \n",left);

    printf("denut de la fonction inOrderInArray\n");
    int size = 0;
    int* t = inOrderInArray(binaryTree, &size);
    printf("ize = %d\n",size);
    for(int i = 0;i < 10;i++) {
        printf("%d ",t[i]);
    }
    free(t);
    deleteTree(binaryTree);
    */
    testLevelOrder();
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
