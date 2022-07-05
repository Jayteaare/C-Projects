#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // Prompt user for height of pyramid
    int height = get_int("Height: ");

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
        return (0);
    }
    else
    {
        return main();
    }
}
