
#include <stdio.h> #include <stdlib.h> #include <sys/stat.h>

int main() {
char filename[] = "file.txt";
int new_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; // rw-rw-r--

if (chmod(filename, new_permissions) == 0) { printf("File permissions changed successfully.\n");
} else {
perror("chmod"); return 1;
 
}

return 0;
}


