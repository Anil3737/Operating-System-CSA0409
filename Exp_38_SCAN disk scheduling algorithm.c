#include <stdio.h> #include <stdlib.h>

int main() {
int n, head, seek_time = 0,i;


printf("Enter the number of disk requests: "); scanf("%d", &n);

int request_queue[n];


printf("Enter the disk request queue:\n");
 
for ( i = 0; i < n; i++) 
{ 
   scanf("%d", &request_queue[i]);
}


printf("Enter the initial position of the disk head: "); scanf("%d", &head);

// Sort the request queue to simplify SCAN algorithm for (int i = 0; i < n - 1; i++) {
int j;
for ( j = i + 1; j < n; j++) {
if (request_queue[i] > request_queue[j]) { int temp = request_queue[i]; request_queue[i] = request_queue[j]; request_queue[j] = temp;
}
}
}


// SCAN (Elevator) Scheduling
printf("\nSCAN (Elevator) Disk Scheduling:\n");
int n;
 int start = 0;
int end = n - 1;
int current_direction = 1; // 1 for moving right, -1 for moving left


while (start <= end) {
if (current_direction == 1) {
for ( i = start; i <= end; i++) {
 
if (request_queue[i] >= head) {
seek_time += abs(head - request_queue[i]); head = request_queue[i];
start = i + 1; break;
}
}
current_direction = -1; // Change direction
} else {
for ( i = end; i >= start; i--) {
if (request_queue[i] <= head) {
seek_time += abs(head - request_queue[i]); head = request_queue[i];
end = i - 1; break;
}
}
current_direction = 1; // Change direction
}
}


printf("Total Seek Time: %d\n", seek_time); printf("Average Seek Time: %.2f\n", (float)seek_time / n);


return 0;
}

