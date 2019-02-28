#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main (void) 
{
    pid_t pid;
    int count = 0;
    pid = fork ();
    if (pid < 0) printf("Error!\n");
    else if (pid == 0) {
        printf("I'm a child\n");
        while(1);
        exit (0);
    }
    else {
        printf("I'm the father, and my son's pid is %d \n",pid);
        while(1);
    }
    exit(0);
}
