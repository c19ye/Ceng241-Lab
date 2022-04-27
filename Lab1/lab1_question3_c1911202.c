#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char name[50];
    int price;

} components;
typedef struct
{
    components component[10];
} user;

int main(int argc, char const *argv[])
{
    user users;
    int i, numberproduct;
    printf("Enter the number of products you want to add: ");
    scanf("%d", &numberproduct);
    for (i = 0; i < numberproduct; i++)
    {
        printf("Enter product id and product name and price:\n");
        scanf("%d %s %d", &users.component[i].id, users.component[i].name, &users.component[i].price);
    }
    printf("Displaying Information:\n");
    for (i = 0; i < numberproduct; i++)
    {
        printf("name: %s        id: %d        price: %d\n", users.component[i].name, users.component[i].id, users.component[i].price);
    }

    int press;
    printf("Press 1 if you want to continue: ");
    scanf("%d", &press);

    while (press == 1)
    {
        for (i = 0; i < numberproduct; i++)
        {
            printf("name: %s        id: %d        price: %d\n", users.component[i].name, users.component[i].id, users.component[i].price);
        }
        printf("Press 1 if you want to continue: ");
        scanf("%d", &press);
    }
    for (i = 0; i < numberproduct; i++)
    {
        printf("Your order:\n");
        printf("id: %d item: %s price: %d\n", users.component[i].id, users.component[i].name, users.component[i].price);
    }
    int bill = 0;
    for (i = 0; i < numberproduct; i++)
    {
        bill = bill + users.component[i].price;
    }
    printf("Bill: %d$", bill);
    return 0;
}
