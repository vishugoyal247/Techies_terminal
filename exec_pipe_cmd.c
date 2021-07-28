// This function helps us to executed piped commands
void execArgsPiped(char** parsed, char** parsedpipe)
{
    
    int pipefd[2]; // (pipe file descriptor)  
    /*The array pipefd is used to return two file descriptors referring
     to the ends of the pipe. pipefd[0] refers to the read end of the pipe.
    pipefd[1] refers to the write end of the pipe.*/ 

    pid_t p1, p2;  //pid_t data type stands for process identification
                   // it is used to represent process ids
  


    // learn about pipe() function:
    /* On success pipe function is returned zero.  
    On error it will returned -1. */
    if (pipe(pipefd) < 0) 
    {
        printf("\nPipe could not be initialized");
        return;
    }



    // learn about fork() function: ##  fork() vs exec()  ##
    // Fork system call is used for creating a new process, which is called child process
    /*Negative Value: creation of a child process was unsuccessful.
    Zero: Returned to the newly created child process.
    Positive value: Returned to parent or caller. 
    The value contains process ID of newly created child process.*/
    p1 = fork();
    if (p1 < 0) {
        printf("\nCould not fork");
        return;
    }
  
    if (p1 == 0) {
        // Child 1 executing..
        // It only needs to write at the write end
        close(pipefd[0]); // read file descripter is closed
        dup2(pipefd[1], STDOUT_FILENO); //unistd.h    It helps us to copy the output of cmd
                                                     // and in write form 
        close(pipefd[1]); // write file descripter is closed
        

        //learn about execvp()
        /*The exec type system calls allow a process to run any program files,
        which include a binary executable or a shell script */

        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command 1..");
            exit(0);  // exit() the program
        }
    } else {
        // Parent executing
        p2 = fork();
  
        if (p2 < 0) {
            printf("\nCould not fork");
            return;
        }
  
        // Child 2 executing..
        // It only needs to read at the read end
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
                printf("\nCould not execute command 2..");
                exit(0);
            }
        } else {
            // parent executing, waiting for two children
            wait(NULL);
            wait(NULL);
            /*wait(NULL) will block parent process until any of its children has finished.
             If child terminates before parent process reaches wait(NULL) then the child 
             process turns to a zombie process until its parent waits on it and its released 
             from memory.*/
        }
    }
}