#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 4096
#define STDOUT 1
char buff[BUFF_SIZE];
int fd;

int main(int argc, char *argv[]) {
    // For cat, we have to iterate over all command-line arguments of
    // our process. Thereby, argv[0] is our program binary itself ("./cat").
    for (int idx = 1; idx < argc; idx++) {
        char* path =  argv[idx];
        printf("argv[%d] = %s\n", idx, path);
        fd = open(path, O_RDONLY);
        while( read(fd, buff, BUFF_SIZE)){
            write(STDOUT, buff, BUFF_SIZE);
            memset(buff, 0, BUFF_SIZE);
        } 
        close(fd);  
    }

    return 0;
}
