#include <stdio.h> #include <stdlib.h> #include <fcntl.h> #include <unistd.h>
#define BUFFER_SIZE 4096 void copy(){
const char *sourcefile= "C:/Users/itssk/OneDrive/Desktop/sasi.txt";
const char *destination_file="C:/Users/itssk/OneDrive/Desktop/sk.txt"; int source_fd = open(sourcefile, O_RDONLY);
int dest_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
char buffer[BUFFER_SIZE]; ssize_t bytesRead, bytesWritten;
while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0) { bytesWritten = write(dest_fd, buffer, bytesRead);
}
close(source_fd); close(dest_fd);
printf("File copied successfully.\n");
}
void create()
{
char path[100];
FILE *fp; fp=fopen("C:/Users/itssk/OneDrive/Desktop/sasi.txt","w"); printf("file created successfully");
}
 
int main(){
int n;
printf("1. Create \t2. Copy \t3. Delete\nEnter your choice: " ); scanf("%d",&n);
switch(n){
case 1: create(); break;
case 2:
copy(); break; case 3:
remove("C:/Users/itssk/OneDrive/Desktop/sasi.txt"); printf("Deleted successfully");
}}


