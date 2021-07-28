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




