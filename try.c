#include <stdio.h>

// C program to Append a Character to a String
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
    // declare and initialize string
    char    *str;
    str = (char *)malloc(sizeof (char) * 9);
    // append to str
    strncat(str ,"1", 2);
    strncat(str ,"0", 2);
    strncat(str ,"0", 2);
    strncat(str ,"1", 2);
    strncat(str ,"1", 2);
    strncat(str ,"0", 2);
    strncat(str ,"0", 2);
    // print string
    printf("Appended String: %s\n", str);
    return 0;
}