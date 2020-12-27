#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
int main(void)
{
    string text = get_string("Text: ");
    int letters = 0;
    for(int i=0; i < strlen(text); i++){
        if((text[i]>64 && text[i]<91) || (text[i]>96 && text[i]<123)){
            letters++;
        }
    }
    //letters

    int words = 1;
    for(int i=0; i < strlen(text); i++){
        if(text[i] == 32){
            words++;
        }
    }
    //words

    int sentences = 0;
    for(int i=0; i < strlen(text); i++){
        if(text[i] == 33 || text[i] == 46 || text[i] == 63){
            sentences++;
        }
    }
    //sentences

    float avg_letters = (float)letters/words * 100;
    float avg_sentences = (float)sentences/words * 100;
    float index = 0.0588 * avg_letters - 0.296 * avg_sentences - 15.8;
    int grade = round(index);

    if(grade < 1){
        printf ("Before Grade 1\n");
    }
    else if(grade >= 16){
        printf ("Grade 16+\n");
    }
    else{
        printf ("Grade %i\n", grade);
    }

}