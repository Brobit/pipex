# pipex

## Things to do before begin to code :

- [x] find out what really does a pipe in the shell and how it works
- [x] find out about < and > operator in shell, what do they do and how it works
- [ ] find out about some external function that are authorize :
    - [x] perror :
    stdio.h , void perror(const char *prefix), display an error message in stderr
    - [x] strerror :
    string.h, char *strerror(int errcode), convert an errcode into a string
    - [x] access :
    unistd.h : int access(const char * pathname, int mode), allow us to check the user permission on a file
    - [x] dup :
    unistd.h, int dup(int oldfd), create a copy of the fd of oldfd and give us the smallest fd available, return the new fd or -1 if an error occur
    - [x] dup2 :
    unistd.h, int dup2(int oldfd, int newfd), transform newfd in a copy of oldfd, return the new fd or -1 if an error occur
    - [x] execve :
    unistd.h, int execve(const char *file, char *const argv[], char *const envp[]), watch a video about execve to understand it better
    - [x] exit :
    stdlib.h, void exit(int status), finish properly a processus
    - [x] fork :
    unistd.h, pid_t fork(void) create a son processus, watch a video about fork to undestand it better
    - [x] pipe :
    unistd.h, int pipe(int pipefd[2]), create a tube, watch a video about pipe to understand it better
    - [x] unlink :
    unistd.h, int unlink(const char *pathname), destroy a name and eventually the associate file
    - [x] wait
    - [x] waitpid

- [x] do the makefile that going to compile the libft and the code 
