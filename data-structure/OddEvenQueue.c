/*

Question:
Create a Stack and Separate Odd and Even Numbers into Queues

Write a C program that does the following:

Stack:

Create a stack to store integer numbers.
Allow the user to input a set number of integers to add to the stack.
Queues:

Create two separate queues: one for odd numbers and one for even numbers.
Processing:

After the numbers are added to the stack, separate them into the odd and even queues based on whether they are odd or even.
Display:

Show the numbers in the stack.
Show the numbers in the odd queue.
Show the numbers in the even queue.



*/



#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int data;
    struct Stack *next;
};

typedef struct Stack *StackPtr;

// Queue structure
struct Queue {
    int data;
    struct Queue *next;
};

typedef struct Queue *QueuePtr;

// Global variables
StackPtr head = NULL;
QueuePtr oHead = NULL; // Odd queue head
QueuePtr eHead = NULL; // Even queue head

// Function to create a stack node
void createStackNode(int data) {
    StackPtr newNode = malloc(sizeof(struct Stack));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to create a queue node
void createQueueNode(QueuePtr *queueHead, int data) {
    QueuePtr newNode = malloc(sizeof(struct Queue));
    newNode->data = data;
    newNode->next = NULL;

    if (*queueHead == NULL) {
        *queueHead = newNode;
    } else {
        QueuePtr temp = *queueHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the odd queue
void showOddQueue() {
    printf("The values in the Odd Queue:\n");
    QueuePtr temp = oHead;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the even queue
void showEvenQueue() {
    printf("The values in the Even Queue:\n");
    QueuePtr temp = eHead;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to traverse the stack and populate the odd/even queues
void traverse() {
    printf("The values in the Stack:\n");
    StackPtr temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        if (temp->data % 2 == 0) {
            createQueueNode(&eHead, temp->data); // Add to even queue
        } else {
            createQueueNode(&oHead, temp->data); // Add to odd queue
        }
        temp = temp->next;
    }

    showOddQueue();
    showEvenQueue();
}

// Main function
int main() {
    int d, n;
    printf("Enter the number of elements in the stack:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the element %d:\n", i);
        scanf("%d", &d);
        createStackNode(d);
    }

    traverse();
    return 0;
}


/* 

Enter the number of elements in the stack:
5
Enter element 1:
10
Enter element 2:
15
Enter element 3:
20
Enter element 4:
25
Enter element 5:
30

The values in the Stack:
30
25
20
15
10

The values in the Odd Queue:
15	25	
The values in the Even Queue:
10	20	30	

*/
