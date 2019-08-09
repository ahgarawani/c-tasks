#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int add(int *numbers, int length) //The function that calculates the sum of the numbers in an array called 'numbers'
{
    int result = 0;
    for (int i = 0; i < length; i++) //The sum is calculated by iterating over each element of the array and adding them to the variable 'result'
    {
        result = result + numbers[i];
    }
    return result;
}

int mul(int *numbers, int length) //The function that calculates the product of the numbers in an array called 'numbers'
{
    int result = 1;
    for (int i = 0; i < length; i++) //The product is calculated by iterating over each element of the array and adding them to the variable 'result'
    {
        result = result * numbers[i];
    }
    return result;
}

char *lowered(char *str) //A function that makes every letter in a string lowercase
{
    int l = strlen(str);
    char *low_str;
    low_str = malloc((l + 1) * sizeof(char)); //Allocate a space in the memory for the new string
    if (low_str == NULL) // Check if allocation wasn't successful
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    for (int i = 0; i < l; i++) //Iterate over each character and convert it to lowercase
    {
        low_str[i] = tolower(str[i]);
    }
    return low_str;
}

int main(int argc, char *argv[])
{
    //check if a command isn't entered as an argument
    if (argc < 2)
    {
        printf("Hello, please enter a command and try again.\n");
        return 1;
    }

    //Allocate a space in the memory for the lowered case string of the command
    char *command;
    command = (char*) malloc((strlen(argv[1]) + 1) * sizeof(char));
    // Check if allocation wasn't successful
    if (command == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    // convert the entered command to lowercase
    command = lowered(argv[1]);

    //check if the entered command is one of the available commands
    if (strcmp(command, "add") != 0 && strcmp(command, "mul") != 0)
    {
        printf("Unavailable command, available commands are : \"[Add, Mul]\"\n");
        return 1;
    }

    //Allocate a space in the memory for the array that will contain the numbers
    int *numbers;
    numbers = (int*) malloc((argc - 2) * sizeof(int));
    // Check if allocation wasn't successful
    if (numbers == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    int no_of_numbers = 0; //the size of the 'numbers' array

    //check if there isn't a sufficient number of 'number' entered as arguments
    if (argc < 4)
    {
        printf("command {%s} should have at least two numbers, but you enterd: %i number\n", argv[1], argc - 2);
        numbers = realloc(numbers, 2 * sizeof(int));

        /*
          check wether the user entered one number or none at all and then ask for more numbers
          to reach the lower limit of the required numbers and store them in the 'numbers' array
        */
        if (argc == 3)
        {
            //if the user entered one number ask for another
            numbers[0] = atoi(argv[2]);
            printf("Please enter a second number: ");
            scanf("%i", numbers + 1);
        }
        else
        {
            //if the user entered none ask for two numbers
            printf("Please enter a first number: ");
            scanf("%i", numbers);
            printf("Please enter a second number: ");
            scanf("%i", numbers + 1);
        }
        no_of_numbers = 2;
    }

    /*
      if a sufficient number of 'numbers' is entered (at least two)
      convert them to ints and put them in an array
    */
    else
    {
        no_of_numbers = argc - 2;
        for (int i = 0; i < no_of_numbers; i++)
        {
            numbers[i] = atoi(argv[i + 2]);
        }
    }

    //excute the entered command
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
