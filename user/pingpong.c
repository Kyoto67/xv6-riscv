//
// Created by kyoto on 17.09.23.
//

#include "user.h"

#define EXIT_FAILURE 1
typedef int pid_t;

int main() {
    int pipe_fd[2]; // Дескрипторы конца пайпа

    if (pipe(pipe_fd) == -1) {
        fprintf(2, "pipe_err");
        exit(EXIT_FAILURE);
    }

    char buf[512];
    pid_t pid = fork();

    if(pid > 0){
        //parent
        write(pipe_fd[1],"ping",4);
        read(pipe_fd[0],buf,sizeof buf);
        printf("%d: got %s\n",getpid(),buf);
        exit(0);
    } else if(pid == 0){
        //child
        read(pipe_fd[0], buf,sizeof buf);
        printf("%d: got %s\n",getpid(),buf);
        write(pipe_fd[1],"pong",4);
        exit(0);
    } else {
        fprintf(2, "fork_err");
        exit(EXIT_FAILURE);
    }

    return 0;

}
