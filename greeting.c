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
