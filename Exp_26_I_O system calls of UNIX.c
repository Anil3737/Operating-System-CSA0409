#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int flags = fcntl(fd, F_GETFL);
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("File 'example.txt' opened with non-blocking flag.\n");

    off_t offset = lseek(fd, 5, SEEK_SET);
    if (offset == -1) {
        perror("lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("File pointer moved to offset 5.\n");
    struct stat fileStat;
    if (fstat(fd, &fileStat) == -1) {
        perror("fstat");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("File Size: %lld bytes\n", (long long)fileStat.st_size);

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    printf("\nFiles in the current directory:\n");

    struct dirent *dp;
    while ((dp = readdir(dir)) != NULL) {
        printf("%s\n", dp->d_name);
    }

    closedir(dir);

    return 0;
}

