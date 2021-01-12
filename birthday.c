#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char *birthday = ctime(NULL);
    printf("%s", birthday);
    return 0;
}
