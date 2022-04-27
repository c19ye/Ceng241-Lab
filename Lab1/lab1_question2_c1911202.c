#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("Input total number of elements(1 to 100): ");
    int number, temp, i;
    scanf("%d", &number);
    temp = -9999;
    int *ptr = (int *)malloc(sizeof(int) * number);
    for (i = 0; i < number; i++)
    {
        printf("Number %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }
    for (i = 0; i < number; i++)
    {
        if (temp < ptr[i])
        {
            temp = ptr[i];
        }
    }

    printf("The Largest element is : %d", temp);
    free(ptr);
    return 0;
}
