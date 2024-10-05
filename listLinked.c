#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;
struct node {
    int value;
    node* next;
};

typedef struct Liste Liste;
struct Liste {
    node* first;
};

Liste* initialisation() {
    Liste* premier = (Liste*)malloc(sizeof(Liste));
    if(premier == NULL) {
        exit(EXIT_FAILURE);
    }
    premier->first = NULL;
    return premier;
}

void insertValueAtTop(Liste* liste,int nombre) {
    node* noeud = (node*)malloc(sizeof(node));
    noeud->value = nombre;
    noeud->next = liste->first;
    liste->first = noeud;
}

void insertValueAtEnd(Liste* liste,int nombre) {
    node* noeud = (node*)malloc(sizeof(node*));
    if(liste == NULL || noeud == NULL) {
        exit(EXIT_FAILURE);
    }
    noeud->value = nombre;
    if(liste->first == NULL) {
        noeud->next = liste->first;
        liste->first = noeud;
        return;
    }
    noeud->next = NULL;
    node* current = liste->first;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = noeud;
}

void insertAtPosition(Liste* liste,int position,int data) {
    node* noeud = (node*)malloc(sizeof(node));
    noeud->value = data;
    if(position == 0) {
        noeud->next = liste->first;
        liste->first = noeud;
        return;
    }
    node* current = liste->first;
    node* previous = NULL;

    for(int i = 0;i<position;i++) {
        previous = current;
        current = current->next;
    }
    if(current->next == NULL) {
        noeud->next = NULL;
        current->next = noeud;
        return;
    }
    previous->next = noeud;
    noeud->next = current;
}

bool isEmpty(const Liste* liste) {
    return liste->first == NULL;
}

int length(const Liste* liste) {
    int taille = 0;
    node* current = liste->first;
    while(current != NULL) {
        current = current->next;
        taille++;
    }
    return taille;
}

void printList(const Liste* liste) {
    node* current = liste->first;
    while(current != NULL) {
        printf("%d->",current->value);
        current = current ->next;
    }
    printf("NULL\n");
}

void deleteNode(Liste* liste,const int data) {
    node *current = liste->first,*q1 = liste->first;

    while(current != NULL) {
        if(current->value == data) {
            if(current == liste->first) {
                liste->first = current->next;
                free(current);
                current = liste->first;
            }
            else {
                q1->next = current->next;
                free(current);
                current = q1->next;
            }
        }
        else {
            q1 = current;
            current = current->next;
        }
    }

}

void reverseList(Liste* liste) {
    node *previous = NULL,*current = liste->first;
    while(current != NULL) {
        node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    liste->first = previous;
}


void sortedInsert(node** head_ref, node* new_node) {
    node* current;
    if (*head_ref == NULL || (*head_ref)->value >= new_node->value) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while (current->next != NULL && current->next->value < new_node->value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}


void insertionSort(Liste* liste) {
    node* sorted = NULL;
    node* current = liste->first;
    while (current != NULL) {
        node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    liste->first = sorted;
}

void boucleListe(const Liste* liste) {
    node* current = liste->first;
    node* firstNode = liste->first;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = firstNode;
}

bool isBoucle(const Liste* liste) {
    node* current = liste->first->next;
    node* firstNode = liste->first;
    while(current != NULL) {
        if(current == firstNode) {
            return true;
        }
    }
    return false;
}

void fundMaxNodeAndReturnIt(Liste* liste) {
    node* current = liste->first->next;
    node *firstNode = liste->first,*maxNode = firstNode;
    while(current != firstNode) {
        if(current->value >= maxNode->value) {
            maxNode = current;
        }
        current = current->next;
    }
    liste->first = maxNode;
    while(current->next != maxNode) {
        current = current->next;
    }
    current->next = NULL;
}

void deleteListLinked(Liste* liste) {
    node *current = liste->first,*suivant = NULL;
    while(current != NULL) {
        suivant = current->next;
        free(current);
        current = suivant;
    }
    free(liste);
    liste = NULL;
}

int main(void) {
    Liste* liste_chainee = initialisation();
    int nbrElement = 0;
    printf("entrez le nombre d'element \n");
    scanf("%d",&nbrElement);
    for(int i = 0;i < nbrElement;i++) {
        int value = 0;
        printf("\n entrez la valeur numero %d : ",i+1);
        scanf("%d",&value);
        insertValueAtEnd(liste_chainee,value);
    }
    printList(liste_chainee);
    deleteNode(liste_chainee,5);
    printList(liste_chainee);
    insertAtPosition(liste_chainee,5,11);
    printList(liste_chainee);
    insertionSort(liste_chainee);
    printList(liste_chainee);
    deleteListLinked(liste_chainee);
    return 0;
}
