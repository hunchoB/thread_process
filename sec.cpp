#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
pid_t pid[2];


pid[0] = fork();

switch(pid[0])
{
case -1:
fprintf(stderr, "Fork Failed");
exit(1);
case 0:
sleep(1);
execl("first","1", NULL);
//sleep(2);
break;
default:
pid[1] = fork();
switch(pid[1])
{
case -1:
fprintf(stderr, "Fork Failed");
exit(1);
case 0:
sleep(0.2);
execl("first","2", NULL);
sleep(1);
break;
default:
wait(NULL);
}
}

kill(pid[0], SIGKILL);
kill(pid[1], SIGKILL);
exit(0);
}