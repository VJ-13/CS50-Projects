#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    //Get the key
    //Validate the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i = 0; i < strlen(argv[1]); i++)
    {
       if((argv[1][i] < 65 || argv[1][i] > 90) && (argv[1][i] < 97 || argv[1][i] > 122))
       {
           printf("Key must only contain alphabetic letter \n");
           return 1;
       }
    }

    for(int i = 0; i < strlen(argv[1]) - 1; i++)
    {
       for(int j = i + 1; j < strlen(argv[1]); j++)
       {
           if(argv[1][i] == tolower(argv[1][j]) || argv[1][i] == toupper(argv[1][j]))
           {
           printf("Key must not contain repated characters \n");
           return 1;
           }
       }
       
    }
    
//Get plaintext
string text = get_string("Plaintext: ");

printf("ciphertext: ");

//Encipher
    for(int i = 0; i < strlen(text); i++)
    {
        int a = 0;
        if(text[i] >= 97 && text[i] <= 122)
        {
           a = text[i] - 97; 
           printf("%c", tolower(argv[1][a]));
        }
        else if(text[i] >= 65 && text[i] <= 90)
        {
           a = text[i] - 65; 
           printf("%c", toupper(argv[1][a]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    //Print ciphertext
}
