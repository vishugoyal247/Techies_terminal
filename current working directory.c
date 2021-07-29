// This function helps us to print the current directory ==>> Presented by Anubhav
void printDir()
{
    //initialized a variable for current working directory
	char cwd[1024];            
		if(getcwd(cwd,sizeof (cwd) ) == 0)              //The getcwd() function copies an absolute pathname of the cwd.
		
				perror("\033[92mgetcwd() error");            //cwd represents the current working directory.
		                                                     // perror used to print the error statement.
		else
            //Now, this will print the present working directory
			printf("\n\n\033[36mCurrent working directory is:\033[0m %s\n\n",cwd);
	
    
	
}