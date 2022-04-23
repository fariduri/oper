#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#define MAX_COUNT 200
#define BUF_SIZE 100
void main(void)
{
 pid_t pid;
 pid_t ppid; 
 int i;
 char buf[BUF_SIZE];
 fork();
 pid = getpid();
 ppid = getppid();
 for (i = 1; i <= MAX_COUNT; i++) {
 sprintf(buf, "This line is from pid %d with ppid %d, value = %d\n", pid, 
ppid, i);
 write(1, buf, strlen(buf));
 } 
 exit(1);
}
