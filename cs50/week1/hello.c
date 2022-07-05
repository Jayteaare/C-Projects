#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? "); // Get the user's name
    printf("Hello, %s!\n", answer); // Say hello to the user
}
