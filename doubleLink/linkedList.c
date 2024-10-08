#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct doubleNode doubleNode;
struct doubleNode {
    int value;
    doubleNode* next;
    doubleNode* prev;
};

typedef struct doubleListe doubleListe;
struct doubleListe {
    doubleNode* head;
    doubleNode* tail;
};

doubleNode* createDoubleNode(const int data) {
    doubleNode* noeud = (doubleNode*)malloc(sizeof(doubleNode));
    noeud->value = data;
    noeud->next = NULL;
    noeud->prev = NULL;

    return noeud;
}

doubleListe* initialistion() {
    doubleListe* d_liste = (doubleListe*)malloc(sizeof(doubleListe));
    if(d_liste == NULL) {
        exit(EXIT_FAILURE);
    }
    d_liste->head = NULL;
    d_liste->tail = NULL;
    return d_liste;
}

void insertValue(doubleListe* liste,const int value) {
    doubleNode* node = createDoubleNode(value);
    if(node == NULL || liste == NULL) {
        exit(EXIT_FAILURE);
    }
    if(liste->head == NULL) {
        node->next = liste->head;
        liste->head = node;
        liste->tail = node;
        return;
    }
    doubleNode *current = liste->head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    node->prev = current;
    node->next = NULL;
    liste->tail = node;
}

void insertFirst(doubleListe* liste,const int value) {
    doubleNode* node = createDoubleNode(value);
    if(node == NULL) {
        exit(EXIT_FAILURE);
    }
    if(liste->head == NULL) {
        liste->head = node;
        liste->tail = node;
    }
    else {
        node->next = liste->head;
        liste->head->prev = node;
        liste->head = node;
    }
}

void printList(const doubleListe* liste) {
    if(liste->head == NULL) {
        printf("NULL\n");
        return;
    }
    doubleNode* current = liste->head;
    while(current != NULL) {
        printf("%d->",current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void printListBackward(const doubleListe* liste) {
    doubleNode* current = liste->tail;
    printf("NULL");
    while(current != NULL) {
        printf("->%d",current->value);
        current = current->prev;
    }
    printf("\n");
}

void deleteFirstNode(doubleListe* liste) {
    doubleNode *current = liste->head;
    if(liste->head == NULL){
        printf("la liste est deja vide\n");
        return;
    }
    if(liste->head->next == NULL) {
        free(liste->head);
        liste->head = NULL;
        return;
    }
    liste->head = liste->head->next;
    free(current);
    current = liste->head;
    current->prev = NULL;
}

void deleteNodes(doubleListe* liste) {
    doubleNode *current = liste->head;
    while(current != NULL) {
        doubleNode *prev = current->next;
        free(current);
        current = prev;
    }
    free(current);
    liste->head = NULL;
}

bool isEmpty(const doubleListe* liste) {
    return liste->head == NULL;
}

int length(const doubleListe* liste) {
    doubleNode* current = liste->head;
    int count = 0;

    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

void insertAtPosition(doubleListe* liste,int data,int position) {
    doubleNode *noeud = createDoubleNode(data);
    doubleNode *current = liste->head,*prev = NULL;
    if(noeud == NULL) {
        exit(EXIT_FAILURE);
    }

    int taille = length(liste);
    if((position<0) || (position > (taille))) {
        printf("la position n'est pas dans l'ordre\n");
        return;
    }

    if(position == 0) {
        noeud->next = liste->head;
        noeud->prev = NULL;
        liste->head = noeud;
        return;
    }

    for(int i = 0;i < position;i++) {
        prev = current;
        current  = current->next;
    }

    if(position == taille) {
        noeud->prev = current;
        prev->next = noeud;
        return;
    }

    noeud->next = current;
    noeud->prev = prev;
    prev->next = noeud;
    current->prev = noeud;
}

bool valueInList(const doubleListe* liste,int value) {
    doubleNode* current = liste->head;
    while(current != NULL) {
        if(current->value == value) {
            return value;
        }
        current = current->next;
    }
    return false;
}

void reverseListe(doubleListe* liste) {
    doubleNode *prev = NULL,*current = liste->head;
    liste->tail = liste->head;

    while(current != NULL) {
        doubleNode* next = current->next;
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
    }
    liste->head = prev;
}

int main(void) {
    doubleListe* liste = initialistion();
    printf("entrez le nombre de node :  ");
    int nbr = 0;
    scanf("%d",&nbr);
    for(int i = 0;i < nbr;i++) {
        int value = 0;
        printf("entrez la valeur numero %d : ",i+1);
        scanf("%d",&value);
        insertFirst(liste,value);
    }
    printList(liste);
    insertAtPosition(liste,300,3);
    printList(liste);
    printListBackward(liste);
    reverseListe(liste);
    printList(liste);
    printListBackward(liste);
    deleteNodes(liste);

    if(isEmpty(liste)) {
        printf("la liste est vide,la memoire liberee\n");
    }else {
        printf("echec de la liberation de la memoire...\n");
    }
    return 0;
}
