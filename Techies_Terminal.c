//Program to Design a Techies_Teminal 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
  
#define MAXCOM 1000 // max number of letters to be supported
#define MAXLIST 100 // max number of commands to be supported



// Function for Greeting_Shell...=>> Presented by Arnav....
void greet_shell()
{
system("clear"); // library function of stdlib.h $ it is used to clear the output screen
printf("****************************************************\n");
printf("****************************************************\n");
printf("**\t\t\t\t\t\t  **\n");
printf("**\t\t\t\t\t\t  **\n");
printf("**\t\t\t\t\t\t  **\n");
printf("**\033[1m\t\033[43m\033[30m  Welcome to Techies Terminal  \033[0m\t          **\n");
printf("**\t\t\t\t\t\t  **\n");
printf("**\033[1;31m\t\t   Team Members\033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t     Abhinav  \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t     Anubhav  \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t     Anushka  \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t      Arnav   \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t     Harshit  \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t     Tanishk  \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t      Tulsi   \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t     Samarth  \033[0m\t\t\t  **\n");
printf("**\033[0;32m\t\t      Vishu   \033[0m\t\t\t  **\n");
printf("**\t\t\t\t\t\t  **\n");
printf("**\t\t\t\t\t\t  **\n");
printf("****************************************************\n");
printf("****************************************************\n");
char* user = getenv("USER"); // stdlib.h function $ used for searching the environment
printf("\033[0;36m\n USER :\033[0m\033[0;31m Techies_Terminal\033[0m\033[0;36m@%s\033[0m\n",user);
sleep(4);/* function of unistd.h $ used in order to wait for a current thrad for a specified time */
system("clear");
}

//Presented by Arnav
// This function help us to know the various command used in Linux Terminal
void manual()
{
    printf("\n");
    printf("\n");
    printf("\t\t\t\033[4m\033[93m Welcome To Techies Terminal Module \033[0m\t\n");
    printf("\n");
    printf("\n");
    printf("\033[93mgedit \033[0m>>> a text editor for the Desktop\n");
    printf("\n");
    printf("\033[93mcd \033[0m>>> To change directory\n");
    printf("\n");
    printf("\033[93mls \033[0m>>> To see the content of the directory\n");
    printf("\n");
    printf("\033[93mrm \033[0m>>> To delete the directory\n");
    printf("\n");
    printf("\033[93mwget \033[0m>>> To download any fie from the internet\n");
    printf("\n");
    printf("\033[93mhistory \033[0m>>> To review the previous command used\n");
    printf("\n");
    printf("\033[93mmkdir \033[0m>>> To create a directory or folder\n");
    printf("\n");
    printf("\033[93menv \033[0m>>> To put your environment variables insides a file\n");
    printf("\n");
    printf("\033[93mifconfig enp0s3 \033[0m>>> To know the current I.P address\n");  
    printf("\n");
    printf("\033[93mgrep \033[0m>>> It will search a word in the long file easily\n");
    printf("\n");
    printf("\033[93mclear \033[0m>>> To clear the screen\n");
    printf("\n"); 
    printf("\033[93mdate \033[0m>>> To show date and time\n");
    printf("\n"); 
    printf("\033[93mmv \033[0m>>> To move one file from one place to another \n");
    printf("\n"); 
    printf("\033[93mpwd \033[0m>>> To see the directory(location) and files\n");
    printf("\n"); 
    printf("\033[93mcp \033[0m>>> To copy one file to new file or append to a existing file\n");
    printf("\n"); 
    printf("\033[93mecho \033[0m>>> To display the given text on the terminal window\n");
    printf("\n"); 
    printf("\033[93msleep \033[0m>>> To delay the execution\n");
    printf("\n");
    printf("\033[93mexit \033[0m>>> To exit\n");
    printf("\n");
}





// Function to take input  ==>> Presented by Abhinav...
int takeInput(char* str)
{
    // This variable is created for buffer input
    char* buf;
  
    buf = readline("\n>>> "); // readline function helps us to read the whole cmd from the terminal
    if (strlen(buf) != 0) {
        add_history(buf);  // It will add the cmd to the history
        strcpy(str, buf);  // It will help us to copy the input from buf to str string
        return 0;
    } else {
        return 1;
    }
}


// This function helps us to print the current directory ==>> Presented by Anubhav
void printDir()
{
    //initialized a variable for current working directory
	char cwd[1024];            
		if(getcwd(cwd,sizeof (cwd) ) == 0)              //The getcwd() function copies an absolute pathname of the cwd.
		
				perror("\033[92mgetcwd() error");            //cwd represents the current working directory.
		
		else
            //Now, this will print the present working directory
			printf("\n\n\033[36mCurrent working directory is:\033[0m %s\n\n",cwd);
	
    
	
}




// Presented by Samarth 
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

// Presented by Vishu Goyal
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



// Presented by Vishu Goyal
// This function helps us to know about the predefined commands
void openHelp()
{
    puts("\n\033[107m\033[30m*****************************************************************\033[0m"
        "\n\033[107m\033[30m*****************************************************************\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m       \033[2m\033[43m\033[30m***  WELCOME TO MY TECHIES_TERMINAL HELP    ***\033[0m\033[106m       \033[107m\033[30m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m" 
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                   \033[1m\033[21m\033[31m\033[4mCopyright @ Techies\033[0m\033[106m                       \033[30m\033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m          !!! Use the shell at your own risk !!!             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m        \033[5mList of self build and supported Commands:\033[0m\033[106m           \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m        ==========================================           \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                >hello                                       \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                >intro                                       \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                >help                                        \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                >manual                                      \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                >exit                                        \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                Hope it helped you a lot                     \033[107m**\033[0m"
        "\n\033[107m\033[30m**\033[106m\033[30m                                                             \033[107m**\033[0m"
        "\n\033[107m\033[30m\033[30m*****************************************************************\033[0m"
        "\n\033[107m\033[30m*****************************************************************\033[0m");
    // return;
}


// Presented by Harshit
// Function to execute builtin commands
int ownCmdHandler(char** parsed)
{	
	// total no of commands is 5 
	int NoOfCmds = 5, i, switchOwnArg = 0;
	char* ListOfCmds[NoOfCmds];
	char* username;
	// List of commands
	ListOfCmds[0] = "hello";
	ListOfCmds[1] = "intro";
	ListOfCmds[2] = "help";
	ListOfCmds[3] = "exit";
	ListOfCmds[4] = "manual";

	
	for (i = 0; i < NoOfCmds; i++) {
		if (strcmp(parsed[0], ListOfCmds[i]) == 0) {
			switchOwnArg = i + 1;
			break;
		}
	}
	
	// switch case is used to run the particular commands 
	switch (switchOwnArg) {
	case 1:
		username = getenv("USER");
		printf("\n\033[0;36m Hello %s. \033[0m\t \n  The Only way to learn a new programming language is by writing programs in it!"
				"\033[0;33m  \n  Have a good tour to our Techies Terminal"  
			"\n  Use help to know more.. \033[0m\t \n",
			username);
		return 1;
	case 2:
		printf("\n\033[0;34m Welcome to the Techies Terminal. This project is developed by team of nine students \033[0m\t\n\n ");
		printf("\n\033[0;33m \t -> Abhinav Pandey \n \t -> Anubhav Varshney \n \t -> Anushka Birla \n \t -> Arnav Srivastava \n \t -> Harshit Garg \n \t -> Samarth Srivastava \n \t -> Tanishk Gupta \n \t -> Tulsi Rajput \n \t -> Vishu Goyal \033[0m\t \n");
		printf("\n\033[0;34m Under the guidance of project supervisor\033[0m ");
		printf("\033[0;36m\033[5m Ms. Harvindar Kaur. \033[0m  \n");
		printf("\n\033[0;32m We would like to thank all who helped us for completing our project sucessfully. This project contributes in enhancing our skill and knowledge in C language.\033[0m\t \n");
		return 1;
	case 3:
		openHelp();
		return 1;
	case 4:
		printf("\n\033[0;33m \nThank you for sharing your time with our Techies Terminal\033[0m\t \n");
		printf("\n\033[0;35m  \t\t .................. \033[0m\t \n");
		exit(0);
	case 5:
		manual();
		return 1;
	default:
		break;
	}

	return 0;
}


// Presented by Anuska 
// function for finding pipe
int parsePipe(char* str, char** strpiped)
{
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|"); // strsep() works to separate a string into pieces marked by given delimeters.
        if (strpiped[i] == NULL) // null means if there is no pipe found then the loop will stop.
            break;
    }
  
    if (strpiped[1] == NULL)
        return 0; // returns zero if no pipe is found.
    else {
        return 1; // returns if pipe is found
    }
}



// Presented by Tulsi
// function for parsing command words

void parseSpace(char* str, char** parsed)// parsed is the address of string 
{
    int i;
    /*strsep() is a predefined function in the library string.h. It seperates the string 
	into pieces marked by the given delimiter. It returns NULL when string is empty*/
   
    for (i = 0; i < MAXLIST; i++)      
	{
        parsed[i] = strsep(&str, " "); // strsep is used here to seperate the string based on space and stores string in respective command address
  
        if (parsed[i] == NULL)         // if the command is empty, we'll come out of the loop
            break;
            
        if (strlen(parsed[i]) == 0)    // if length of command is zero, then value of i will decrease and iteration will stop 
            i--;
    }
}



// Presented by Tanishk Gupta
int processString(char* str, char** parsed, char** parsedpipe)
{
  
    char* strpiped[2];
    int piped = 0;
  
    piped = parsePipe(str, strpiped);
  
    if (piped) {
        parseSpace(strpiped[0], parsed);
        parseSpace(strpiped[1], parsedpipe);
  
    } else {
  
        parseSpace(str, parsed);
    }
  
    if (ownCmdHandler(parsed))
        return 0;
    else
        return 1 + piped;
}

int main()
{
    char inputString[MAXCOM], *parsedArgs[MAXLIST];
    char* parsedArgsPiped[MAXLIST];
    int execFlag = 0;

    greet_shell();

    while (1) {
        // print shell line
        printDir();
        // take input
        if (takeInput(inputString))
            continue;
        // process
        execFlag = processString(inputString,
        parsedArgs, parsedArgsPiped);
        // execflag returns zero if there is no command
        // or it is a builtin command,
        // 1 if it is a simple command
        // 2 if it is including a pipe.
  
        // execute
        if (execFlag == 1)
            execArgs(parsedArgs);
  
        if (execFlag == 2)
            execArgsPiped(parsedArgs, parsedArgsPiped);
    }
    return 0;
}
