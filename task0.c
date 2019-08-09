#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int add(int *numbers, int length)
{
    int result = 0;
    for (int i = 0; i < length; i++)
    {
        result = result + numbers[i];
    }
    return result;
}

int mul(int *numbers, int length)
{
    int result = 1;
    for (int i = 0; i < length; i++)
    {
        result = result * numbers[i];
    }
    return result;
}

char *lowered(char *str)
{
    int l = strlen(str);
    char *low_str;
    low_str = malloc((l + 1) * sizeof(char));
    if (low_str == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    for (int i = 0; i < l; i++)
    {
        low_str[i] = tolower(str[i]);
    }

    return low_str;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Hello, please enter a command and try again.\n");
        return 1;
    }

    char *command;
    command = (char*) malloc((strlen(argv[1]) + 1) * sizeof(char));
    if (command == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    command = lowered(argv[1]);

    if (strcmp(command, "add") != 0 && strcmp(command, "mul") != 0)
    {
        printf("Unavailable command, available commands are : \"[Add, Mul]\"\n");
        return 1;
    }

    int *numbers;
    numbers = (int*) malloc((argc - 2) * sizeof(int));
    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    int no_of_numbers = 0;

    if (argc < 4)
    {
        printf("command {%s} should have at least two numbers, but you enterd: %i number\n", argv[1], argc - 2);
        numbers = realloc(numbers, 2 * sizeof(int));
        if (argc == 3)
        {
            numbers[0] = atoi(argv[2]);
            printf("Please enter a second number: ");
            scanf("%i", numbers + 1);
        }
        else
        {
            printf("Please enter a first number: ");
            scanf("%i", numbers);
            printf("Please enter a second number: ");
            scanf("%i", numbers + 1);
        }
        no_of_numbers = 2;
    }
    else
    {
        no_of_numbers = argc - 2;
        for (int i = 0; i < no_of_numbers; i++)
        {
            numbers[i] = atoi(argv[i + 2]);
        }
    }

    if (strcmp(command, "add") == 0)
    {
        printf("The result is: %i\n", add(numbers, no_of_numbers));
    }
    else
    {
        printf("The result is: %i\n", mul(numbers, no_of_numbers));
    }
    return 0;
}
