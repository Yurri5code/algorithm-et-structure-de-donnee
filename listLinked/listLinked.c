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

void insertValueAtTop(Liste* liste,const int nombre) {
    node* noeud = (node*)malloc(sizeof(node));
    noeud->value = nombre;
    noeud->next = liste->first;
    liste->first = noeud;
}

void insertValueAtEnd(Liste* liste,const int nombre) {
    node* noeud = (node*)malloc(sizeof(node*));
    if(noeud == NULL) {
        fprintf(stderr,"l'allocation du noeud a echouee\n");
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

void insertAtPosition(Liste* liste,const int position,const int data) {
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
    if(previous == NULL) {
        fprintf(stderr,"la variable previous est NULL\n");
        exit(EXIT_FAILURE);
    }
    previous->next = noeud;
    noeud->next = current;
}

bool isEmpty(const Liste* liste) {
    return liste->first == NULL;
}

int length(const Liste* liste) {
    int taille = 0;
    const node* current = liste->first;
    while(current->next != NULL) {
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
    if (*head_ref == NULL || (*head_ref)->value >= new_node->value) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        node *current = *head_ref;
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
        current = current->next;
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

void deleteNodeFromEnd(Liste* liste,int position) {
    if(liste == NULL) {
        printf("il n y a aucun element a supprimer la liste est vide\n");
        return;
    }
    int taille = length(liste), s = abs(taille - position);
    if(position > taille) {
        fprintf(stderr,"la position est plus grande que la taille du tableau");
        exit(0);
    }
    printf("la valeur de s : %d\n",s);
    if(s == 0) {
        node* current = liste->first;
        liste->first = liste->first->next;
        free(current);
        return;
    }
    if(position == taille) {
        node* current = liste->first;
        node* prev = current;
        while(current != NULL) {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(NULL);
        return;
    }
    node* current = liste->first;
    node* prev = current;
    for(int i = 0;i < s;i++) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);

}

//forme parfait de la fonction deleteNodeFromEnd supprimer une valeur de la liste en partant de la fin
//cette algorithm a 0ms aux testes de leetcode et 63% d'espace soit 9.34 mb
void deleteValueFromEnd(Liste* liste,const int position) {
    if(liste->first->next == NULL) {
        //et la position est forcement egal a 1 vue qu'il y a qu'un seul element dans la liste
        liste->first = NULL;
        return;
    }
    node *cur = liste->first,*prev = cur;
    int count = length(liste);
    int s = abs(count - position);
    if(s == 0) {
        node* delete = liste->first;
        liste->first = liste->first->next;
        free(delete);
        return;
    }
    cur = liste->first;
    for(int i = 0; i < s;i++) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = cur->next;
    free(cur);
}

/*
 * dans le cas de la fonction listToArray ici il est connu a l'avance la taille maximal que contiendra le
 * tableau, pour une utilisation optimal il faudra calculer la taille d'element de la liste pour une taille exacte de
 *du tableau
 */
/*
 * toutes ces fonctions resolus sur base de l'exercice leetcode add two numbers
 * presente une certaine limitation au niveau de la taille maximale
 * les nodes peuvent etre long de 100 , or un long ou un int ne peuvent pas contenir
 * une valeur de 100 chiffre cette algorithm a passer 1565/1569
 * c'etait une tres bonne aventure de l'ecrire /
 * avec des unsigned int 1566/1569
 */
int* listToArray(const Liste* l,int* returnSIze) {
    int* arr = (int*)malloc(100*sizeof(int));
    node* current = l->first;
    int i = 0;

    while(current != NULL) {
        arr[i] = current->value;
        i++;
        current = current->next;
    }
    free(current);
    *returnSIze = i;
    return arr;
}

int* listToArrayToGoodArray(const int* arr,int arrSize) {
    int* tab = (int*)malloc(arrSize*sizeof(int));
    int k = arrSize - 1;
    for(int i = 0;i <= arrSize; i++) {
        tab[i] = arr[k];
        k--;
    }
    return tab;
}

long arrayToLong(int arr[],const int size) {
    long result = 0;
    long multiplier = 1;

    for (int i = size - 1; i >= 0; i--) {
        result += arr[i] * multiplier;
        multiplier *= 10;
    }

    return result;
}

Liste* addTwoNumbers(Liste* L1,Liste* L2) {
    if(L1 == NULL && L2 == NULL) {
        return NULL;
    }
    if(L1 == NULL) {
        return L2;
    }
    if(L2 == NULL) {
        return L1;
    }

    int i = 0,j = 0;
    int* arr1 = listToArray(L1,&i);
    int* arr2 = listToArray(L2,&j);
    if(arr1 == NULL || arr2 == NULL) {
        fprintf(stderr,"l'allocation n'a pas marche\n");
        exit(EXIT_FAILURE);
    }
    int* t1 = listToArrayToGoodArray(arr1,i);
    int* t2 = listToArrayToGoodArray(arr2,j);
    if(t1 == NULL || t2 == NULL) {
        fprintf(stderr,"l'allocation n'a pas marche\n");
        exit(EXIT_FAILURE);
    }
    long isArr1 = arrayToLong(t1,i);
    long isArr2 = arrayToLong(t2,j);
    long sum = isArr1 + isArr2;
    for(int k = 0;k < i;k++)
        printf("%d",arr1[k]);
    printf("\n");
    for(int k = 0;k < i;k++)
        printf("%d",t1[k]);
    printf("\n");
    for(int k = 0;k<j;k++)
        printf("%d",arr2[k]);
    printf("\n");
    for(int k = 0;k<j;k++)
        printf("%d",t2[k]);
    printf("\n");
    printf("%ld %ld %ld\n",sum,isArr1,isArr2);

    Liste* newListe = initialisation();

    while(sum > 0) {
        int n = sum%10;
        insertValueAtEnd(newListe,n);
        sum /= 10;
    }
    free(arr1);
    free(arr2);
    return newListe;
}

//addTwoNUmbers2 est la solution a la premiere version de fonction plus courte et qui ne
//fait pas face a la contrainte de la taille max de long et int
Liste* addTwoNumbers2(const Liste* l1,const Liste* l2) {
    Liste* head = initialisation();
    Liste* tail = initialisation();
    node *liste_1 = l1->first,*liste_2 = l2->first,*cur_2 = tail->first;

    int carry = 0;

    while((liste_1 != NULL) || (liste_2 != NULL)) {
        int sum = carry;

        if((liste_1 != NULL)) {
            sum += liste_1->value;
            liste_1 = liste_1->next;
        }
        if(liste_2 != NULL) {
            sum += liste_2->value;
            liste_2 = liste_2->next;
        }
        if(sum >= 10) {
            carry = sum/10;
            sum %= 10;
        }else {
            carry = 0;
        }
        if(cur_2 == NULL) {
            insertValueAtEnd(tail,sum);
            head = tail;
        }else {
            insertValueAtEnd(tail,sum);
        }

    }
    if(carry > 0) {
        insertValueAtEnd(tail,carry);
    }

    return head;
}

void swap(node* slow,node* speed) {
    slow->next = speed->next;
    speed->next = slow;
}

Liste* swapNode(Liste* liste) {
    if(liste->first == NULL) {
        return NULL;
    }
    if(liste->first->next == NULL) {
        return liste;
    }

    node* slowNode = liste->first;
    node* speedNode = liste->first->next;
    liste->first = liste->first->next;
    while(true) {
        node* nextPair = speedNode->next;
        swap(slowNode,speedNode);
        if(nextPair == NULL || nextPair->next == NULL) {
            break;
        }

        slowNode->next = nextPair->next;
        slowNode = nextPair;
        speedNode = nextPair->next;
    }
    return liste;
}

void rotateRight(Liste* liste,int k) {
    if(liste->first == NULL || k == 0) {
        fprintf(stderr,"la liste est vide\n");
        return;
    }

    const int size = length(liste) + 1;
    const node* firstBefore = liste->first;
    boucleListe(liste);
    if(isBoucle(liste)) {
        printf("la liste a ete boucle avec succes\n");
    }else {
        printf("la liste n'a pas ete boucle\n");
    }
    k = k%size;
    const int steps = size - k;
    node* current = liste->first;
    if(firstBefore == liste->first) {
        printf("la liste n'a pas changee\n");
    }
    for(int i = 0;i < steps - 1;i++) {
        current = current->next;
    }
    liste->first = current->next;
    current->next = NULL;

    if(isBoucle(liste)) {
        printf("la liste a ete boucle avec succes\n");
    }else {
        printf("la liste n'a pas ete boucle\n");
    }
}

void testRotateRight() {
    Liste* chaine = initialisation();

    printf("entrez le nombre d'element de la liste \n");
    int nbr = 0,k = 0;
    scanf("%d",&nbr);
    for(int i = 0;i < nbr;i++) {
        int value = 0;
        scanf("%d",&value);
        insertValueAtEnd(chaine,value);
    }
    printf("affichage de la liste avant la rotation\n");
    printList(chaine);
    printf("entrez le nombre k : \n");
    scanf("%d",&k);
    rotateRight(chaine,k);
    printf("affichage de la liste apres la rotation de k = %d \n",k);
    printList(chaine);
    deleteListLinked(chaine);
}

void testSwapNode() {
    Liste* chaine = initialisation();

    printf("entrez le nombre d'element de la liste \n");
    int nbr = 0;
    scanf("%d",&nbr);
    for(int i = 0;i < nbr;i++) {
        int value = 0;
        scanf("%d",&value);
        insertValueAtEnd(chaine,value);
    }
    printf("affichage de la liste avant l'echange\n");
    printList(chaine);
    swapNode(chaine);
    printf("affichage de la liste apres\n");
    printList(chaine);
    deleteListLinked(chaine);
}

void testAddTwoNumbers() {
    Liste* l1 = initialisation();
    Liste* l2 = initialisation();
    printf("entrez le nombre d'element de la liste l1 et l2\n");
    int nbr1 = 0,nbr2 = 0;

    scanf("%d %d",&nbr1,&nbr2);

    printf("entrez les elements de la premiere liste 1\n");
    for(int i = 0;i < nbr1;i++) {
        int value = 0;
        scanf("%d",&value);
        insertValueAtTop(l1,value);
    }

    printf("entrez les elements de la premiere liste 2\n");
    for(int i = 0;i < nbr2;i++) {
        int value = 0;
        scanf("%d",&value);
        insertValueAtTop(l2,value);
    }
    printf("affichage de la liste 1\n");
    printList(l1);
    printf("affichage de la liste 2\n");
    printList(l2);
    Liste* sum = addTwoNumbers2(l1,l2);
    printf("affichage de la sum\n");
    printList(sum);
    deleteListLinked(l1);
    deleteListLinked(l2);
    deleteListLinked(sum);
}

int main(void) {
    testRotateRight();
    /*Liste* liste_chainee = initialisation();
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
   // deleteNode(liste_chainee,5);
    //printList(liste_chainee);
    //insertAtPosition(liste_chainee,4,11);
    //printList(liste_chainee);
    insertionSort(liste_chainee);
    printList(liste_chainee);
    printf("delete from\n");
    deleteNodeFromEnd(liste_chainee,2);
    printList(liste_chainee);
    deleteListLinked(liste_chainee);*/
    return 0;
}
