#include <stdio.h>

#define BUDGET 100

int main() {
    float a, b, c;
    float x, y, z; // x = stake for Win, y = stake for Draw, z = stake for Loss
    float total_investment;
    float total_stake;  // To store the total stake
    float profit_win, profit_draw, profit_lose;

    // Getting the odds for the three outcomes
    printf("Enter the odds for a Win: ");
    scanf("%f", &a);
    printf("Enter the odds for a Draw: ");
    scanf("%f", &b);
    printf("Enter the odds for a Loss: ");
    scanf("%f", &c);

    // Calculate the total sum of the inverses of the odds
    total_investment = (1/a) + (1/b) + (1/c);

    // Check if arbitrage betting is possible
    if (total_investment < 1) {
        printf("Arbitrage Betting is possible!\n");

        // Calculate the stakes for each outcome using x, y, and z
        x = (BUDGET / a) / total_investment;  // Stake for Win
        y = (BUDGET / b) / total_investment;  // Stake for Draw
        z = (BUDGET / c) / total_investment;  // Stake for Loss

        // Calculate the total stake before scaling
        total_stake = x + y + z;

        // Normalize the stakes so the total is less than or equal to the budget
        if (total_stake > BUDGET) {
            float scale_factor = BUDGET / total_stake;
            x *= scale_factor;
            y *= scale_factor;
            z *= scale_factor;
        }

        // Ensure the total stake does not exceed the budget
        printf("Place %.2f on Win\n", x);
        printf("Place %.2f on Draw\n", y);
        printf("Place %.2f on Loss\n", z);

        // Calculate the guaranteed profit
        profit_win = x * a - BUDGET;
        profit_draw = y * b - BUDGET;
        profit_lose = z * c - BUDGET;

        // Ensure profit from any outcome
        printf("Guaranteed profit on Win: %.2f\n", profit_win);
        printf("Guaranteed profit on Draw: %.2f\n", profit_draw);
        printf("Guaranteed profit on Loss: %.2f\n", profit_lose);
    } else {
        printf("Arbitrage Betting is not possible!\n");
    }

    return 0;
}
