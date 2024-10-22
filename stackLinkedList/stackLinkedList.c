#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack stack;
struct stack {
   int data;
   stack* next;
};

typedef struct element element;
struct element {
    stack* first;
 };

 element* initialisation(){
   element* new = (element*)malloc(sizeof(element));
   if(new == NULL){
       fprintf(stderr,"l'allocation a echoue\n");
       exit(1);
   }
   new->first = NULL;
   return new;
 }

 void push(element* pile,const int data){
     stack* chaine = (stack*)malloc(sizeof(stack));
     if(chaine == NULL) {
         fprintf(stderr,"l'allocation a echoue\n");
         exit(EXIT_FAILURE);
     }
     chaine->data = data;
     chaine->next = pile->first;
     pile->first = chaine;
 }

bool isEmpty(const element* pile) {
     return pile->first == NULL;
 }

void printStack(const element* pile) {
     if(pile->first == NULL) {
         fprintf(stderr,"la liste est vide\n");
         exit(EXIT_FAILURE);
     }
     stack* cur = pile->first;
     while(cur != NULL) {
         printf("%d->",cur->data);
         cur = cur->next;
     }
     printf("NULL\n");
}

void pop(element* pile) {
     if(pile->first == NULL) {
         fprintf(stderr,"la liste est vide\n");
         exit(EXIT_FAILURE);
     }
     stack* cur = pile->first;
     pile->first = pile->first->next;
     free(cur);
 }

int top(const element* pile) {
     if(pile->first == NULL) {
         printf("la pile est vide\n");
         return -1;
     }
     return pile->first->data;
 }

void deleteStack(element* pile) {
     if(pile->first == NULL) {
         printf("la pile est deja videe...\n");
         return;
     }
     stack* cur = pile->first;

     while(cur != NULL) {
         stack* prev = cur->next;
         free(cur);
         cur = prev;
     }
     free(pile);
     pile = NULL;
 }

void test1() {
     element* listeStack = initialisation();
     printf("entrez le nombre d'element de la pile\n");
     int nbr = 0;
     scanf("%d",&nbr);

     for(int i = 0;i < nbr;i++) {
         int value = 0;
         printf("\nentrez l'element numero %d : ",i+1);
         scanf("%d",&value);
         push(listeStack,value);
     }
     printf("affichage de la liste...\n");
     printStack(listeStack);
     int t = top(listeStack);
     printf("top = %d\n",t);
     printf("affichage la liste apres le pop\n");
     pop(listeStack);
     printStack(listeStack);
     t = top(listeStack);
     printf("top = %d\n",t);

     deleteStack(listeStack);

     if(isEmpty(listeStack)) {
         printf("la pile a ete totalement supprimee\n");
     }else {
         printf("echec de la suppression...\n");
     }
 }

int main(){
     test1();
     return 0;
 }
