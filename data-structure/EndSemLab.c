/*
    Question 1: Graph-Based Application for Shortest Path Calculation

    You are required to develop a graph-based application where a user can enter 
    different cities and their connections. Each city is interconnected, and the 
    objective is to determine the shortest path between all cities using an efficient algorithm.

    Requirements:
    1. The program should allow users to input multiple cities and specify the distance between them.
    2. Implement an algorithm that efficiently finds the shortest path between all cities.
    3. Ensure that the program correctly handles cases where some cities are not directly connected.
    4. Display the shortest distance between every pair of cities.

    Marks Distribution:
    - Solution Implementation: 30 Marks
    - Finding the Correct Algorithm: 10 Marks
    - Selecting a Suitable Approach: 10 Marks

    Note:
    - The algorithm must be optimized for efficiency.
    - Justify why the chosen approach is the best for solving this problem.
*/
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
/*
    Question 2: Stack-Based Number Storage Application

    You are required to develop an application that uses the Stack Data Structure 
    to store and manage numbers based on the following conditions:

    1. Odd Number Stack (Primary Stack):
       - The program should accept 15 odd numbers and store them in a stack.
       - The stack follows LIFO (Last In, First Out) order.

    2. Overflow & Even Numbers Handling:
       - If the number is even, store it separately in another stack.
       - If the odd number stack exceeds 15, the extra odd numbers should be pushed into the overflow stack.
       - When an overflow occurs, display a message "Stack Overflow" but continue accepting inputs.

    3. Final Output:
       - Display the Primary Stack (first 15 odd numbers in LIFO order).
       - Display the Overflow Stack (extra odd numbers and even numbers in LIFO order).

    Marks Distribution:
    - Correct Stack Implementation: 30 Marks
    - Proper Overflow Handling: 10 Marks
    - Efficient Data Storage & Processing Using Stack: 10 Marks

    Note:
    - Implement the stack using an array-based or linked list-based approach.
    - The stack operations should include push, pop, and display methods.
*/

/* ---------------------------------------------------------------------------------------------------------------------------------------*/


//Question 2 Graph Data Structure
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_CITIES 100
#define INF 999999

int graph[MAX_CITIES][MAX_CITIES];
char cities[MAX_CITIES][50];
int city_count = 0;

int get_city_index(char *name) {
    for (int i = 0; i < city_count; i++) {
        if (strcmp(cities[i], name) == 0)
            return i;
    }
    strcpy(cities[city_count], name);
    return city_count++;
}

void floyd_warshall(int n) {
    int dist[MAX_CITIES][MAX_CITIES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] != 0)
                dist[i][j] = graph[i][j];
            else
                dist[i][j] = INF;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("\nShortest Distance Between All Cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%10s -> %-10s: INF\n", cities[i], cities[j]);
            else
                printf("%10s -> %-10s: %d\n", cities[i], cities[j], dist[i][j]);
        }
    }
}

int main() {
    int edges, weight;
    char city1[50], city2[50];

    printf("Enter number of roads (edges): ");
    scanf("%d", &edges);

    for (int i = 0; i < MAX_CITIES; i++)
        for (int j = 0; j < MAX_CITIES; j++)
            graph[i][j] = 0;

    for (int i = 0; i < edges; i++) {
        printf("Enter city1, city2, and distance: ");
        scanf("%s %s %d", city1, city2, &weight);
        int u = get_city_index(city1);
        int v = get_city_index(city2);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    floyd_warshall(city_count);
    return 0;
}



/* ---------------------------------------------------------------------------------------------------------------------------------------*/


//Question 1 stack data structure



#include <stdio.h>

#define MAX_SIZE 15
#define OVERFLOW_SIZE 50

int stack[MAX_SIZE], overflow_stack[OVERFLOW_SIZE];
int top = -1, overflow_top = -1;

void push(int num) {
    if (top < MAX_SIZE - 1)
        stack[++top] = num;
    else {
        overflow_stack[++overflow_top] = num;
        printf("Stack Overflow\n");
    }
}

void display() {
    printf("\nPrimary Stack (Odd Numbers): ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\nOverflow Stack (Extra Odd & Even Numbers): ");
    for (int i = overflow_top; i >= 0; i--)
        printf("%d ", overflow_stack[i]);
}

int main() {
    int num, count = 0;
    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (count < MAX_SIZE && num % 2 != 0) {
            push(num);
            count++;
        } else {
            push(num);
        }
        if (count >= MAX_SIZE + OVERFLOW_SIZE) break;
    }
    display();
    return 0;
}

