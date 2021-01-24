#include "greatings_server.h"

int main(int argc, char const *argv[])
{
    struct sockaddr_un addr;
    int sfd, cfd; /* server and client file descriptor */
    ssize_t numread;
    char buf[BUF_SIZE];

    /* create a new socket */
    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == -1)
        exit(128);

    if (remove(SOCK_PATH_SERVER) == -1 && errno != ENOENT)
        exit(128);

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCK_PATH_SERVER, sizeof(addr.sun_path) - 1);

    if (bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1)
        exit(128);

    if (listen(sfd, BACKLOG) == -1)
        exit(128);

    for (;;)
    {
        cfd = accept(sfd, NULL, NULL);
        if (cfd == -1)
            exit(128);

        while ((numread = read(cfd, buf, BUF_SIZE)) > 0) /* read from the socket to the buffer */
        {
            if (write(STDOUT_FILENO, buf, numread) != numread) /* write to the std output */
                exit(128);
        }
        if (numread == -1)
            exit(128);

        if (close(cfd) == -1)
            exit(128);
    }

    return 0;
}
