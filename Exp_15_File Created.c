#include <stdio.h> #include <stdlib.h>
 
#include <string.h> int main() {
char mainDirectory[] = "C:/Users/itssk/OneDrive/Desktop"; char subDirectory[] = "os";
char fileName[] = "example.txt"; char filePath[200];
char mainDirPath[200];
snprintf(mainDirPath, sizeof(mainDirPath), "%s/%s/", mainDirectory, subDirectory);
snprintf(filePath, sizeof(filePath), "%s%s", mainDirPath, fileName); FILE *file = fopen(filePath, "w");
if (file == NULL) { printf("Error creating file.\n"); return 1;
}
fprintf(file, "This is an example file content."); printf("File created successfully: %s\n");
}


