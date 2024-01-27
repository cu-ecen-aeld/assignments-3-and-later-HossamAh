#include <syslog.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int errno;

void WriteFn(const char* writeFile, const char* writeStr)
{
    int fd;
    fd = creat (writeFile, 0644);
    if (fd == -1)
    {
        syslog(LOG_ERR,"can't create the file");
        exit(EXIT_FAILURE);
    }
    ssize_t nr;
    /* write the string in 'buf' to 'fd' */
    nr = write (fd, writeStr, strlen (writeStr));
    if (nr == -1)
    {
        /* error */
        syslog(LOG_ERR,"can't write to the file");
        exit(EXIT_FAILURE);
    }
    if (close (fd) == -1)
    {
        syslog(LOG_ERR,"can't close the file");
        perror ("close");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[])
{
    openlog("logs",0,LOG_USER);
    if(argc<3)
    {
        syslog(LOG_ERR,"invalid number of arguments :%d",argc);
        exit(EXIT_FAILURE);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    if (writefile[0] == '\0') {
        syslog(LOG_ERR, "Write file path is empty.");
        exit(EXIT_FAILURE);
    }

    if (writestr[0] == '\0') {
        syslog(LOG_ERR, "Write string is empty.");
        exit(EXIT_FAILURE);
    }

    WriteFn(writefile, writestr);

    syslog(LOG_DEBUG,"Writing %s to %s",writestr,writefile);

return 0;
}