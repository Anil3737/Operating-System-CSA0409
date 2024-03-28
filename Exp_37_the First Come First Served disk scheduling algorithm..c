#include <stdio.h> #include <stdlib.h>

int main() {
int n, head, seek_time = 0,i;


printf("Enter the number of disk requests: "); scanf("%d", &n);

int request_queue[n];


printf("Enter the disk request queue:\n"); 
for ( i = 0; i < n; i++) {
scanf("%d", &request_queue[i]);
}


printf("Enter the initial position of the disk head: "); scanf("%d", &head);

// FCFS Scheduling
printf("\nFCFS Disk Scheduling:\n");
 
printf("Head Movement Sequence: %d", head); 
for (i = 0; i < n; i++) {
seek_time += abs(head - request_queue[i]); head = request_queue[i];
printf(" -> %d", head);
}


printf("\nTotal Seek Time: %d\n", seek_time); printf("Average Seek Time: %.2f\n", (float) seek_time / n);


return 0;
}

