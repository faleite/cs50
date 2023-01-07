#include <stdio.h>
#include <stdlib.h>

// #include <stdint.h>  // Include uint8_t

// represents an 8-bit unsigned integer
// typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if exist one command-line argument
    if (argc != 2)
    {
        // print message help
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");

    // check file is valid
    if (file == NULL)
    {
        // print message error
        printf("Error: This is not a file!\n");
        return 1;
    }

    // variables declaration

    // store blocks of 512 bytes in an array
    unsigned char arr[512];

    // count images generated
    int counter = 0;

    // file pointers for recovered images
    FILE *output_image = NULL;

    // reserve space in memory
    char *filename = malloc(8 * sizeof(char));

    // read the blocks of 512 bytes in a array
    while (fread(arr, sizeof(char), 512, file) == 512)
    {
        // check if buffer is a JPEG
        if (arr[0] == 0xff && arr[1] == 0xd8 &&
            arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {
            // close image file if one has been created
            if (counter > 0)
            {
                fclose(output_image);
            }

            // write the JPEGs filenames
            sprintf(filename, "%03i.jpg", counter);

            // open image and write
            output_image = fopen(filename, "w");

            // count number of images
            counter++;
        }
        if (output_image != NULL)
        {
            fwrite(arr, sizeof(char), 512, output_image);
        }
    }

    free(filename);
    fclose(file);
    fclose(output_image);

    return 0;
}
