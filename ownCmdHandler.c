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
		printf("\n\033[0;31m Hello %s. \033[0m\t \n  The Only way to learn a new programming language is by writing programs in it!"
				"\033[0;33m  Have a good tour to our Techies Terminal"  
			"\n  Use help to know more.. \033[0m\t \n",
			username);
		return 1;
	case 2:
		printf("\n\033[0;34m Welcome to the Techies Terminal. This project is developed by team of nine students \033[0m\t ");
		printf("\n\033[0;33m \t Abhinav Pandey \n \t Anubhav Varshney \n \t Anushka Birla \n \t Arnav Srivastava \n \t Harshit Garg \n \t Samarth Srivastava \n \t Tanishk Gupta \n \t Tulsi Rajput \n \t Vishu Goyal \033[0m\t \n");
		printf("\n\033[0;34m Under the guidance of project supervisor\033[0m ");
		printf("\033[0;31m Ms. Harvindar Kaur. \033[0m  \n");
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
