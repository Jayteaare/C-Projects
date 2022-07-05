#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;

    // Prompt user for input
    printf("Height: ");
    scanf("%c", &ch);

    // Save input to a variable
    int height = ch - '0';

    // Check if input is valid (not letters)
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("Please provide a height in the 1-8 range utilizing digits.\n");
        // End program
        return(0);
    }
    // If the height is between 1-8
    if (height >= 1 && height <= 8)
        {
            // Make both sides of the pyramid
            for (int h = 0; h < height; h++)
                {
                    // Print spaces
                    for (int s = 0; s < height - h - 1; s++)
                        {
                            printf(" ");
                        }
                    // Print hashes
                    for (int p = 0; p < h + 1; p++)
                        {
                            printf("#");
                        }
                    printf("  ");
                    // New line
                    for (int l = 0; l < h + 1; l++)
                        {
                            printf("#");
                        }
                    printf("\n");
                }
            return(0);
        }
    // If user input is lower than 1 or greater than 8
    else
        {
            printf("Please provide a height in the 1-8 range.\n");
            // Return to start
            return(0);
        }
}
