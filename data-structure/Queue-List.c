/*

Write a C program to simulate waiting list allotment in a ticket booking system. Imagine the total number of tickets available is 5.
Maintain an extra list for additional requests, and allot tickets from this list whenever there is a cancellation. Identify a suitable data structure.
*/


#include<stdio.h>
#include<stdlib.h>

int ticket[5];
int waitlist[4];
int top = 0;

void cancel(int id){
    int found = 0;
    for(int i = 0; i < 5; i++){
        if(ticket[i] == id){
            found = 1;
            if(top < 4){
                printf("Ticket ID %d has been canceled.\n", id);
                ticket[i] = waitlist[top];
                printf("New slot has been allocated for Waiting List ID: %d\n", ticket[i]);
                top++;
            } else {
                printf("Ticket ID %d has been canceled. No one on the waiting list.\n", id);
                ticket[i] = 0;
            }
            break;
        }
    }
    if(!found){
        printf("Ticket ID %d not found in confirmed tickets.\n", id);
    }
}

void view(){
    printf("\n----------------- The Booking List ------------------\n");
    for(int i = 0; i < 5; i++){
        if(ticket[i] != 0){
            printf("Ticket confirmed for ID: %d\n", ticket[i]);
        } else {
            printf("Slot %d is available.\n", i + 1);
        }
    }
    for(int i = top; i < 4; i++){
        printf("Ticket Not-confirmed for Waiting List ID: %d\n", waitlist[i]);
    }
    printf("-----------------------------------------------------\n");
}

int main(){
    int ticketCount = 0;
    int waitlistCount = 0;
    
    int choice = 0;
    while(1){
        printf("\nEnter your choice:\n 1. Book Ticket \n 2. Cancel Ticket \n 3. View Tickets \n 4. Exit \n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(ticketCount < 5){
                    int val;
                    printf("Enter the Ticket ID to confirm:\n");
                    scanf("%d", &val);
                    ticket[ticketCount++] = val;
                    printf("Ticket confirmed for ID: %d\n", val);
                } else if(waitlistCount < 4){
                    int val;
                    printf("All tickets are booked! Adding to waiting list.\n");
                    printf("Enter the Ticket ID for waiting list:\n");
                    scanf("%d", &val);
                    waitlist[waitlistCount++] = val;
                    printf("Ticket added to waiting list for ID: %d\n", val);
                } else {
                    printf("Sorry, waiting list is full. Cannot book more tickets.\n");
                }
                break;
                
            case 2:
                printf("Enter the Ticket ID to cancel:\n");
                int cancelId;
                scanf("%d", &cancelId);
                cancel(cancelId);
                break;
                
            case 3:
                view();
                break;
                
            case 4:
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
/*
Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
Enter the Ticket ID to confirm:
101
Ticket confirmed for ID: 101

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
Enter the Ticket ID to confirm:
102
Ticket confirmed for ID: 102

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
Enter the Ticket ID to confirm:
103
Ticket confirmed for ID: 103

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
Enter the Ticket ID to confirm:
104
Ticket confirmed for ID: 104

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
Enter the Ticket ID to confirm:
105
Ticket confirmed for ID: 105

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
All tickets are booked! Adding to waiting list.
Enter the Ticket ID for waiting list:
201
Ticket added to waiting list for ID: 201

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
1
All tickets are booked! Adding to waiting list.
Enter the Ticket ID for waiting list:
202
Ticket added to waiting list for ID: 202

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
3

----------------- The Booking List ------------------
Ticket confirmed for ID: 101
Ticket confirmed for ID: 102
Ticket confirmed for ID: 103
Ticket confirmed for ID: 104
Ticket confirmed for ID: 105
Ticket Not-confirmed for Waiting List ID: 201
Ticket Not-confirmed for Waiting List ID: 202
-----------------------------------------------------

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
2
Enter the Ticket ID to cancel:
103
Ticket ID 103 has been canceled.
New slot has been allocated for Waiting List ID: 201

Enter your choice:
 1. Book Ticket 
 2. Cancel Ticket 
 3. View Tickets 
 4. Exit 
3

----------------- The Booking List ------------------
Ticket confirmed for ID: 101
Ticket confirmed for ID: 102
Ticket confirmed for ID: 201
Ticket confirmed for ID: 104
Ticket confirmed for ID: 105
Ticket Not-confirmed for Waiting List ID: 202
-----------------------------------------------------
*/

