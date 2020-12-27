#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long number;
    number = get_long("Number: ");
    int n1 = (number % 10); 
    int n2 = ((number/10) % 10); 
        int x2 = n2 * 2;
    int n3 = ((number/100) % 10); 
    int n4 = ((number/1000) % 10);
        int x4 = n4 * 2;
    int n5 = ((number/10000) % 10); 
    int n6 = ((number/100000) % 10); 
        int x6 = n6 * 2;
    int n7 = ((number/1000000) % 10); 
    int n8 = ((number/10000000) % 10);
        int x8 = n8 * 2;
    int n9 = ((number/100000000) % 10); 
    int n10 = ((number/1000000000) % 10);
        int x10 = n10 * 2;
    int n11 = ((number/10000000000) % 10); 
    int n12 = ((number/100000000000) % 10); 
        int x12 = n12 * 2;
    int n13 = ((number/1000000000000) % 10); 
    int n14 = ((number/10000000000000) % 10); 
        int x14 = n14 * 2;
    int n15 = ((number/100000000000000) % 10); 
    int n16 = ((number/1000000000000000) % 10); 
        int x16 = n16 * 2;
        
    int first = x2 + x4 + x6 + x8 + x10 + x12 + x14 + x16;
    int total = first + n1 + n3 + n5 + n7 + n9 + n11 + n13 + n15;
    if (total % 10 == 0)
    {
       printf("The card is valid\n");
    }
    else
    {
        printf("The card is not valid\n");
    }
    
    if(n15 == 3 && (n14 == 4 || n14 == 7))
    {
        printf("AMEX\n");
    }
    else if (n16 == 5 && (n15 == 1 || n15 == 2 || n15 == 3 || n15 == 4 || n15 == 5))
    {
        printf("MASTERCARD\n");
    }
    else if (n16 == 4 || n13 == 4)
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
  
    
}