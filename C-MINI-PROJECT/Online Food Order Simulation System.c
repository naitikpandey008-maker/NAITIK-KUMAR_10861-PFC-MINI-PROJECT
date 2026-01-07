#include <stdio.h>

float calcItemTotal(float price, int qty) {
    return price * qty;
}

float calcBill(float burgerP, int burgerQ,
               float pizzaP,  int pizzaQ,
               float friesP,  int friesQ) {
    float total = 0;
    total += calcItemTotal(burgerP, burgerQ);
    total += calcItemTotal(pizzaP,  pizzaQ);
    total += calcItemTotal(friesP,  friesQ);
    return total;
}

int main() {
    int burgerQty = 0, pizzaQty = 0, friesQty = 0, choice, qty;
    float burgerPrice = 120.0f;
    float pizzaPrice  = 250.0f;
    float friesPrice  = 80.0f;
    float totalBill;

    printf("Welcome to Simple Online Food Order System\n");
    printf("-----------------------------------------\n");

    do {
        printf("\nMenu:\n");
        printf("1. Burger  (Rs %.2f)\n", burgerPrice);
        printf("2. Pizza   (Rs %.2f)\n", pizzaPrice);
        printf("3. Fries   (Rs %.2f)\n", friesPrice);
        printf("4. Checkout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            printf("Enter quantity: ");
            scanf("%d", &qty);
            if (qty < 0) {
                printf("Quantity cannot be negative.\n");
                continue;
            }
        }

        switch (choice) {
            case 1:
                burgerQty += qty;
                printf("Burger added. Total burgers: %d\n", burgerQty);
                break;
            case 2:
                pizzaQty += qty;
                printf("Pizza added. Total pizzas: %d\n", pizzaQty);
                break;
            case 3:
                friesQty += qty;
                printf("Fries added. Total fries: %d\n", friesQty);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    totalBill = calcBill(burgerPrice, burgerQty,
                         pizzaPrice,  pizzaQty,
                         friesPrice,  friesQty);

    printf("\nYour Order Summary:\n");
    printf("Burgers: %d\n", burgerQty);
    printf("Pizzas : %d\n", pizzaQty);
    printf("Fries  : %d\n", friesQty);
    printf("Total Bill = Rs %.2f\n", totalBill);

    printf("\nThank you for ordering. Have a nice day!\n");

    return 0;
}