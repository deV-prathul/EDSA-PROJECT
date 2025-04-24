//Prathul Dev CP
//ME24I1003
//Question 3:- Autonomous Crane Fabrication Unit


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6
#define LENGTH 20

//functions for partA
//Queue
char queue[SIZE][LENGTH];
int front=0, rear=0;
char *dequeue()
{
    if (front < rear) {
        return queue[front++];// Returns pointer to the dequeued string
    }
    return NULL;
}
void enqueue(char *component)
{
    if (rear < SIZE) {
        int i = 0;
        while (component[i] != '\0') {
            queue[rear][i] = component[i];
            i++;
        }
        queue[rear][i] = '\0';// Null terminator
        rear++;
    }
}
//Stack
char stack[SIZE][LENGTH];
int top = -1;

void push(char *component)
{
    if (top < SIZE - 1) {
        top++;
        int i = 0;
        while (component[i] != '\0') {
            stack[top][i] = component[i];
            i++;
        }
        stack[top][i] = '\0';
    }
}
char *pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return NULL;
}



//functions for partB
//Assembly Storage Unit (Fixed Array with Overflow)
char storage[SIZE][LENGTH];
int nextCrane = 0; // Index of the next oldest crane to be overwritten
int storageCount = 0;// Total number of cranes stored (initially)
void storeCrane(char *crane)
{
    if (storageCount < SIZE) {
        int i = 0;
        while (crane[i] != '\0') {
            storage[storageCount][i] = crane[i];
            i++;
        }
        storage[storageCount][i] = '\0';
        storageCount++;
    }
    else {
        printf("Lobby full!Deploying oldest crane: %s\n", storage[nextCrane]);
        int i = 0;
        while (crane[i] != '\0') {
            storage[nextCrane][i] = crane[i];
            i++;
        }
        storage[nextCrane][i] = '\0';
        nextCrane = (nextCrane + 1) % SIZE;
    }
}



//functions for partC
//Singly linked list
struct node {
    char name[LENGTH];
    struct node *next,*prev;
};
//Faulty Crane Tracker (Singly & Doubly Linked Lists)
struct node *faultyCrane = NULL;
void insertFaulty(char *crane)
{
    struct node newNode =(struct node)malloc(sizeof(struct node));
    strcpy(newNode->name, crane);
    newNode->next = faultyCrane;
    faultyCrane = newNode;
}
void deleteFaulty(char *crane)
{
    struct node *temp = faultyCrane, *prev = NULL;
    while (temp) {
        if (strcmp(temp->name, crane) == 0) {
            if (prev) prev->next = temp->next;
            else faultyCrane = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
//Doubly linked list
struct node *Head = NULL, *Tail = NULL;
void insertRepaired(char *crane)
{
    struct node newNode =(struct node)malloc(sizeof(struct node));
    strcpy(newNode->name, crane);
    newNode->prev = Tail;
    newNode->next = NULL;
    if (Tail) Tail->next = newNode;
    else Head = newNode;
    Tail = newNode;
}
void traverseFwd()
{
    struct node *temp = Head;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}
void traverseBack()
{
    struct node *temp = Tail;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->prev;
    }
}



//Functions for partD
//Priority Upgrades (Circular Linked List)
struct node *head = NULL;
void insertPriority(char *crane)
{
    struct node newNode =(struct node)malloc(sizeof(struct node));
    strcpy(newNode->name, crane);
    if (!head)
    {
        head = newNode;
        newNode->next = head;
    } else {
        struct node *temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}
void transversePriority(int rounds)
{
    if (!head) return;
    struct node *temp = head;
    int count = 0;
    printf("Priority Cranes (Traversed %d Rounds):\n", rounds);
    do {
        printf("%s\n", temp->name);
        temp = temp->next;
        count++;
    } while (count < rounds * 2); // 2 cranes * rounds
}



// MAIN part A
void partA()
{
    char *components[] = {"Boom", "Counterweight", "Cable", "Hook", "Base", "Pulley", "\0"};
    for (int i = 0; i < SIZE; i++)
    {
        enqueue(components[i]);
    }
    while (front < rear) push(dequeue());
    printf("Assembly Order (LIFO):\n[");
    char *component;
    while ((component = pop()) != NULL) {
        printf("%s, ", component);
    }
    printf("]\n\nwhy LIFO: \n We know that the components are transported via trucks. Loading a truck is same as putting CD's in a CD holder, that is, we put the first one at the bottom and the rest follows this one which basically is last in first out order.\n ");
}


//Main part B
void partB()
{
    char *cranes[] = {"Crane1", "Crane2", "Crane3", "Crane4", "Crane5", "Crane6", "Crane7", "Crane8", "\0"};
    for (int i = 0; i < 8; i++)
    {
        storeCrane(cranes[i]);
    }
    printf("\n\nCurrent Storage:\n[");
    int index = nextCrane;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%s, ", storage[index]);
        index = (index + 1) % SIZE;
    }
    printf("]\n\nReason for Deployment:\n Crane1 :- Crane has been sold to a private company.\n Crane2 :- Needs help in lifting a crashed vehicle.\n");
}


//Main part C
void partC()
{
    insertFaulty("Crane2");
    insertFaulty("Crane5");
    deleteFaulty("Crane2");
    insertRepaired("Crane2");
    printf("Repaired Cranes (Forward):\n");
    traverseFwd();
    printf("Repaired Cranes (Backward):\n");
    traverseBack();
    printf("Faulty And Fix: \n ->Crane2's hook got irreversible damage and is replaced by a new one.\n ->Crane5's hook broken,repairing is still going on.\n ");
}


//Main part D
void partD()
{
    insertPriority("Crane1");
    insertPriority("Crane4");
    transversePriority(2);
    printf("UPDATE:\n  ->The gripper of crane1 is replaced by a robotic octopus arm for better grip and maneuverability. \n  ->The pulley system in crane4 is replaced by a hydraulic one.\n");
}


//Main Function
int main()
{
    printf("\n  === PART A ===\n\n");
    partA();
    printf("\n  === PART B ===\n\n");
    partB();
    printf("\n  === PART C ===\n\n");
    partC();
    printf("\n  === PART D ===\n\n");
    partD();
    return 0;
}