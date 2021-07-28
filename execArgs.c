// Function where the system command is executed
// for Using this function we need a linux based library that is <unistd.h>
void execArgs(char** parsed)
{
    // Forking a child
    /* fork() function is used to create new processess which is known as child process,
     which runs concurrently with the process that makes the fork() call (parent process).
     It takes no parameters and returns an integer value.
     Negative Value: creation of a child process was unsuccessful.
     Zero: Returned to the newly created child process.
     Positive value: Returned to parent or caller. The value contains process ID of newly created child process.*/


    pid_t pid = fork(); 

    //  pid_t defined in sys/types.h
  
    if (pid == -1) 
    {
        printf("\nCreation of child process was unsuccessful");
        return;
    } 
    else if (pid == 0)
     {
         /* execvp, Using this command, the created child process does not have to run the same program as the parent process does.
        The exec type system calls allow a process to run any program files,
        which include a binary executable or a shell script*/

        if (execvp(parsed[0], parsed) < 0) 
        {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else
     {
        // waiting for child process or function to terminate
        wait(NULL); 
        return;
    }
}