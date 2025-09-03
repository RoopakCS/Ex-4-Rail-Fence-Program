#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, len, rails, count;
    char str[1000];
    int code[100][1000]; // Matrix to hold characters

    printf("Enter a Secret Message\n");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    // Remove trailing newline from fgets if present
    if (str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }

    printf("Enter number of rails\n");
    scanf("%d", &rails);

    // Initialize the code matrix with zeros
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            code[i][j] = 0;
        }
    }

    count = 0;
    j = 0;

    // Fill the matrix in zigzag pattern
    while (j < len)
    {
        if (count % 2 == 0)
        {
            for (i = 0; i < rails && j < len; i++)
            {
                code[i][j] = (int)str[j];
                j++;
            }
        }
        else
        {
            for (i = rails - 2; i > 0 && j < len; i--)
            {
                code[i][j] = (int)str[j];
                j++;
            }
        }
        count++;
    }

    // Print the encrypted message by reading the matrix row-wise
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (code[i][j] != 0)
            {
                printf("%c", code[i][j]);
            }
        }
    }
    printf("\n");

    return 0;
}
