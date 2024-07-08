#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ATMCHANNEL "/tmp/atmchannel"

typedef struct {
    int sender;
    int receiver;
    char *message;
} Message;

int main() {
    int fd;
    char message[100];
    

    // Create the channel if it doesn't exist
    mkfifo(ATMCHANNEL, 0666);

    // fd = open(FIFO_FILE, O_WRONLY);
    fd = open(ATMCHANNEL, O_RDWR);

    while (1) {
        printf(">_");
        fgets(message, 100, stdin);

        const char * to_be_deleted = "\n";
        message[strcspn(message, to_be_deleted)] = 0;

        char *toWrite = strstr(message, "write");
        char *toRead = strstr(message, "read");
        if (strcmp(message, "exit") == 0) {
            break;
        } else if(toWrite != NULL) {
            write(fd, message, sizeof(message));
            toWrite = NULL;
        } else if(toRead != NULL) {
            read(fd, message, sizeof(message));
            printf("Got: %s\n", message);
            toRead = NULL;
        }
    }

    close(fd);
    unlink(ATMCHANNEL);

    printf("closed\n");

    return 0;
}
