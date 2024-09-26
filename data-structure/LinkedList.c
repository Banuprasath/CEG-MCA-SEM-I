/*
You have to create a linked list of 12 nodes, each representing a class and handling staff. 
You need to store the data of the 12 nodes, traverse them, and split them into Primary, Secondary, and High School.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct school {
    int std;
    char name[30];
    struct school *next;
};

typedef struct school *Node;
Node head = NULL;

struct Primary {
    int std;
    char name[30];
    struct Primary *next;
};

typedef struct Primary *prim;
prim phead = NULL;

struct Secondary {
    int std;
    char name[30];
    struct Secondary *next;
};

typedef struct Secondary *sec;
sec shead = NULL;

struct HighSchool {
    int std;
    char name[30];
    struct HighSchool *next;
};

typedef struct HighSchool *high;
high hhead = NULL;

void createBaseNode(int std, char name[30]) {
    Node newNode = (Node)malloc(sizeof(struct school));
    newNode->std = std;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void createCategories() {
    Node temp = head;

    while (temp != NULL) {
        if (temp->std >= 1 && temp->std <= 4) {
            prim newNode = (prim)malloc(sizeof(struct Primary));
            newNode->std = temp->std;
            strcpy(newNode->name, temp->name);
            newNode->next = phead;
            phead = newNode;
        } else if (temp->std >= 5 && temp->std <= 8) {
            sec newNode = (sec)malloc(sizeof(struct Secondary));
            newNode->std = temp->std;
            strcpy(newNode->name, temp->name);
            newNode->next = shead;
            shead = newNode;
        } else if (temp->std >= 9 && temp->std <= 12) {
            high newNode = (high)malloc(sizeof(struct HighSchool));
            newNode->std = temp->std;
            strcpy(newNode->name, temp->name);
            newNode->next = hhead;
            hhead = newNode;
        }
        temp = temp->next;
    }
}

void traversePrimary(prim head) {
    printf("\nPrimary List (Classes 1 to 4):\n");
    while (head != NULL) {
        printf("Class: %d, Name: %s\n", head->std, head->name);
        head = head->next;
    }
}

void traverseSecondary(sec head) {
    printf("\nSecondary List (Classes 5 to 8):\n");
    while (head != NULL) {
        printf("Class: %d, Name: %s\n", head->std, head->name);
        head = head->next;
    }
}

void traverseHighSchool(high head) {
    printf("\nHigh School List (Classes 9 to 12):\n");
    while (head != NULL) {
        printf("Class: %d, Name: %s\n", head->std, head->name);
        head = head->next;
    }
}

int main() {
    int std[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    char name[30];

    for (int i = 0; i < 12; i++) {
        printf("\nEnter the staff name for class %d: ", std[i]);
        fgets(name, 30, stdin);
        name[strcspn(name, "\n")] = 0;
        createBaseNode(std[i], name);
    }

    createCategories();

    traversePrimary(phead);
    traverseSecondary(shead);
    traverseHighSchool(hhead);

    return 0;
}

/*
Expected Output:

Primary List (Classes 1 to 4):
Class: 4, Name: David
Class: 3, Name: Charlie
Class: 2, Name: Bob
Class: 1, Name: Alice

Secondary List (Classes 5 to 8):
Class: 8, Name: Harry
Class: 7, Name: Grace
Class: 6, Name: Frank
Class: 5, Name: Eve

High School List (Classes 9 to 12):
Class: 12, Name: Liam
Class: 11, Name: Kevin
Class: 10, Name: Jack
Class: 9, Name: Ian
*/
