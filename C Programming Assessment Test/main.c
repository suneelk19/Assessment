#include <stdio.h>

int main()
{
    int choice, qty;
    int totalBill = 0;
    int amount = 0;
    char more;

    printf("\n=====================================\n");
    printf("      WELCOME TO FOOD BILLING\n");
    printf("=====================================\n");

    do
    {
        printf("\n----------- MENU -----------\n");
        printf("1. Pizza   Price = 180 Rs/pcs\n");
        printf("2. Burger  Price = 100 Rs/pcs\n");
        printf("3. Dosa    Price = 120 Rs/pcs\n");
        printf("4. Idli    Price = 50 Rs/pcs\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        printf("Enter Quantity : ");
        scanf("%d", &qty);

        switch(choice)
        {
            case 1:
                amount = qty * 180;
                printf("\nYou have selected Pizza.\n");
                break;

            case 2:
                amount = qty * 100;
                printf("\nYou have selected Burger.\n");
                break;

            case 3:
                amount = qty * 120;
                printf("\nYou have selected Dosa.\n");
                break;

            case 4:
                amount = qty * 50;
                printf("\nYou have selected Idli.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
                amount = 0;
        }

        printf("Amount = %d\n", amount);

        totalBill = totalBill + amount;

        printf("Total Bill = %d\n", totalBill);

        printf("\nDo you want to place more orders? (y/n): ");
        scanf(" %c", &more);

    } while(more == 'y' || more == 'Y');

    printf("\n=====================================\n");
    printf("         FINAL BILL RECEIPT\n");
    printf("=====================================\n");
    printf("Total Amount = %d Rs\n", totalBill);
    printf("Thank You! Visit Again.\n");
    printf("=====================================\n");

    return 0;
}