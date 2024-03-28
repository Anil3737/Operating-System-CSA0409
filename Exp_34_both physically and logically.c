#include <stdio.h> #include <stdlib.h>

// Structure to represent a record struct Record {
int recordNumber;
char data[256]; // Adjust the size as needed for your records
};


int main() { FILE *file;
struct Record record; int recordNumber;

// Open or create a file in write mode (for writing records) file = fopen("sequential_file.txt", "w");
if (file == NULL) {
printf("Error opening the file.\n");
 
return 1;
}


// Write records sequentially to the file
printf("Enter records (Enter '0' as record number to exit):\n"); while (1) {
printf("Record Number: "); scanf("%d", &record.recordNumber); if (record.recordNumber == 0) {
break;
}


// Input data for the record printf("Data: ");
scanf(" %[^\n]", record.data);


// Write the record to the file
fwrite(&record, sizeof(struct Record), 1, file);
}


fclose(file);


// Reopen the file in read mode (for reading records) file = fopen("sequential_file.txt", "r");
if (file == NULL) {
printf("Error opening the file.\n"); return 1;
 
}


// Read a specific record from the file while (1) {
printf("Enter the record number to read (0 to exit): "); scanf("%d", &recordNumber);
if (recordNumber == 0) { break;
}


// Read and display records up to the requested record while (fread(&record, sizeof(struct Record), 1, file)) {
printf("Record Number: %d\n", record.recordNumber); printf("Data: %s\n", record.data);
if (record.recordNumber == recordNumber) { break;
}
}


rewind(file); // Reset the file pointer to the beginning of the file
}


fclose(file); return 0;
}

