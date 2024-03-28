#include <stdio.h> #include <stdlib.h>

#define MAX_FRAMES 3

void printFrames(int frames[], int n) { for (int i = 0; i < n; i++) {
if (frames[i] == -1) {
printf(" - ");
} else {
printf(" %d ", frames[i]);
}
}
printf("\n");
}

int main() {
int frames[MAX_FRAMES];
for (int i = 0; i < MAX_FRAMES; i++) { frames[i] = -1; // Initialize frames to -1 (empty)
}

int pageFaults = 0;
int referenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; int n = sizeof(referenceString) / sizeof(referenceString[0]);

printf("Reference String: "); for (int i = 0; i < n; i++) {
 
printf("%d ", referenceString[i]);
}
printf("\n\n");
printf("Page Replacement Order:\n"); for (int i = 0; i < n; i++) {
int page = referenceString[i];
int pageFound = 0;

// Check if the page is already in memory (a page hit) for (int j = 0; j < MAX_FRAMES; j++) {
if (frames[j] == page) { pageFound = 1; break;
}
}

if (!pageFound) {
printf("Page %d -> ", page);

int optimalPage = -1; int farthestDistance = 0;

for (int j = 0; j < MAX_FRAMES; j++) { int futureDistance = 0;
for (int k = i + 1; k < n; k++) {
if (referenceString[k] == frames[j]) { break;
}
futureDistance++;
}

if (futureDistance > farthestDistance) { farthestDistance = futureDistance; optimalPage = j;
 
}
}

frames[optimalPage] = page;

printFrames(frames, MAX_FRAMES); pageFaults++;
}
}

printf("\nTotal Page Faults: %d\n", pageFaults);

return 0;
}

