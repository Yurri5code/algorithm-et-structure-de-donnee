//
// Created by claude delcroix on 31/10/2024.
//

#ifndef TREE_H
#define TREE_H
#include <stdbool.h>
#include "tree.h"

typedef struct Tree Tree;
struct Tree {
    int data;
    Tree* right;
    Tree* left;
    Tree* root;
};

Tree* createNode(const int data) ;
Tree* insert(Tree* root,const int data);
void deleteTree(Tree* tree);
bool isEmpty(const Tree* root);
Tree* join_tree(Tree* left,Tree* right,const int node);
void print_tree_prefix(const Tree* tree);
int count_tree_node(const Tree* tree);
int getHeight(const Tree* tree);
void preOrder(const Tree *root);
void postOrder(const Tree *root);
void inOrder(const Tree*root);
void inOrderTraversal(const Tree* root,int* array,int* index);
int* inOrderInArray(const Tree* root,int* returnize);
int* inOrderInArray2(const Tree* root, int* returnsize);
int count_left_tree(const Tree* root);
bool sameTree(const Tree* tree_1,const Tree* tree_2);
int height(const Tree* root);
void printCurrentLevelOrder(const Tree* root,const int level) ;
void levelOrder(const Tree* root);
bool isSameTree(const Tree* tree_1,const Tree* tree_2);
bool isSymmetricTree(const Tree* root) ;
Tree* sortedArrayToBST(int* arr,const int size);
void preOrderInArray(const Tree *root,int* array,int* size);
int* preorderTraversal(const Tree* root,int* returnSize);
void postOrderTraversalInArray(const Tree* root,int* array,int* size);
int* postOrderTraversal(const Tree* root,int* returnSize);
bool isBalanced(const Tree* root);
Tree* lca(Tree* root,const int v1,const int v2);
Tree* lookV(Tree* root,const int v);
void levelOrderToArray(Tree* root,int* arr,int* size);
void level_order_to_array(const Tree* root,const int level,int* arr,int* size);
Tree* invertTree(Tree* root);
Tree* invertBinaryTreeFromArray(Tree* root,const int value);
Tree* searchMinValue(Tree* root);
Tree* searchMaxValue(Tree* root);
#endif //TREE_H
