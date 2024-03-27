#include <stdio.h>

#define MAX_BLOCKS 100

int memory[MAX_BLOCKS];
int processSize[MAX_BLOCKS];
void initializeMemory(int size);
int bestFit(int size);
void deallocateMemory(int blockIndex, int size);
void displayMemoryStatus(int size);
int main() {
    int memorySize, choice, processSize, blockIndex;

    printf("Enter the size of memory: ");
    scanf("%d", &memorySize);

    initializeMemory(memorySize);

    while (1) {
        printf("\n1. Allocate Memory\n2. Deallocate Memory\n3. Display Memory Status\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the process: ");
                scanf("%d", &processSize);
                blockIndex = bestFit(processSize);
                if (blockIndex != -1) {
                    printf("Memory allocated successfully at block %d\n", blockIndex);
                    displayMemoryStatus(memorySize);
                } else {
                    printf("Memory allocation failed. No suitable block found.\n");
                }
                break;

            case 2:
                printf("Enter the block index to deallocate: ");
                scanf("%d", &blockIndex);
                deallocateMemory(blockIndex, memory[blockIndex]);
                printf("Memory deallocated successfully from block %d\n", blockIndex);
                displayMemoryStatus(memorySize);
                break;

            case 3:
                displayMemoryStatus(memorySize);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void initializeMemory(int size) {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        memory[i] = size;
    }
}

int bestFit(int size) {
    int minBlockSize = memory[MAX_BLOCKS - 1] + 1;
    int blockIndex = -1;

    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (memory[i] >= size && memory[i] < minBlockSize) {
            minBlockSize = memory[i];
            blockIndex = i;
        }
    }

    if (blockIndex != -1) {
        memory[blockIndex] -= size;
    }

    return blockIndex;
}

void deallocateMemory(int blockIndex, int size) {
    memory[blockIndex] += size;
}

void displayMemoryStatus(int size) {
    printf("Memory Status:\n");

    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: %d\n", i, memory[i]);
    }
}

