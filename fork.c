#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (){
        char *env[] = {};
        char *args[] = {"/usr/games/cowsay","segundo!", NULL};

int pid, pid1, pid2;
pid = fork();

if (pid==0){

}
else {
 pid1 = fork();
 if (pid1 == 0){
        execve(args[0],args,env);
 }
 else {
        pid2 = fork();
        if(pid2 == 0){
                args[1] = "Primeiro";
                execve(args[0],args,env);
        } else {
                args[0] = "/usr/bin/date";
                args[1] = NULL;
                sleep(3);
                execve(args[0],args,env);
