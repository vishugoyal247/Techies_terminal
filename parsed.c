
// function for parsing command words

void parseSpace(char* str, char** parsed)// parsed is the address of string 
{
    int i;
    /*  strsep() is a predefined function in the library string.h. It seperates the string 
	into pieces marked by the given delimiter. It returns NULL when string is empty      */
   
    for (i = 0; i < MAXLIST; i++)      
	{
        parsed[i] = strsep(&str, " "); // strsep is used here to seperate the string based on space and stores string in respective command address
  
        if (parsed[i] == NULL)         // if the command is empty, we'll come out of the loop
            break;
            
        if (strlen(parsed[i]) == 0)    // if length of command is zero, then value of i will decrease and iteration will stop 
            i--;
    }
}

