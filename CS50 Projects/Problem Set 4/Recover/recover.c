#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define blockSize 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error occured opening the file\n");
        return 1;
    }
    typedef uint8_t BYTE;
    BYTE buffer[blockSize];
    size_t bytes_read;
    bool is_first_jpeg = false;
    FILE *current_file;
    char current_filename[100];
    int current_filenumber = 0;
    bool found_jpeg = false;
    //Now we have valid file to read

    //Open memory card

    while (true)
    {
        //Read 512 bytes into buffer
        bytes_read = fread(buffer, sizeof(BYTE), blockSize, file);

        //Repeat until the end of card
        if (bytes_read == 0)
        {
            break; //end of the file
        }

        //If a start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpeg = true;
            //If first jpeg then mark the jpeg
            if (!is_first_jpeg)
            {
                is_first_jpeg = true;
            }

            //else close the current file being written to and open a new file
            else
            {
                fclose(current_file);

            }
            sprintf(current_filename, "%03i.jpg", current_filenumber);
            current_file = fopen(current_filename, "w");
            fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            current_filenumber++;

        }

        else
        {
            //if found the jpeg
            if (found_jpeg)
            {
                fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            }
        }
    }
    fclose(file); //close my raw file
    fclose(current_file); //close my current file
    return 0;

}
