#include "greatings_client.h"
int main(int argc, char const *argv[])
{
    /* code */

    struct sockaddr_un addr;
    int sfd;
    ssize_t numread;

    char buf[BUF_SIZE];

    /* create client socket */
    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == -1)
        exit(128);

    memset(&addr, 0, sizeof(struct sockaddr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCK_PATH_SERVER, sizeof(addr.sun_path) - 1);

    if (connect(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
        exit(128);

    while ((numread = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) /* read from socket to the buffer */
        if (write(sfd, buf, numread) != numread)             /* write to the socket */
            exit(128);
    if (numread == -1)
        exit(128);

    exit(EXIT_SUCCESS);
    return 0;
}
