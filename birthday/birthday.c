#include "mylib.h"
#include <time.h>

/*
    show the bithdate of a person by providing the age 
*/

int main(int argc, char const *argv[])
{
    time_t current_time = time(NULL);
    char *birthday = ctime(&current_time);
    printf("%s", birthday);

    // local time
    struct tm *dateToday = NULL;
    dateToday = localtime(&current_time);
    if (dateToday != NULL)
        printf("the date today is %d", dateToday->tm_hour);

    printf("\n\n");

    return 0;
}
