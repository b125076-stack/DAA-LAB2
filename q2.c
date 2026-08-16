#include <stdio.h>

typedef enum {
    BALANCED,
    LEFT_LIGHTER,
    RIGHT_LIGHTER
} Result;

Result weigh(int coins[], int leftStart, int rightStart, int count,
             int defective, int *comparisons) {
    int leftWeight = 0;
    int rightWeight = 0;
    int i;

    for (i = 0; i < count; i++) {
        leftWeight += (coins[leftStart + i] == defective) ? 0 : 1;
        rightWeight += (coins[rightStart + i] == defective) ? 0 : 1;
    }

    (*comparisons)++;

    if (leftWeight < rightWeight)
        return LEFT_LIGHTER;
    if (leftWeight > rightWeight)
        return RIGHT_LIGHTER;

    return BALANCED;
}

int findCandidate(int coins[], int start, int n, int actualDefective,
                  int *comparisons) {
    int third, remainder;
    int result;

    if (n <= 0)
        return -1;

    if (n == 1)
        return coins[start];


    third = n / 3;

    
    if (third == 0) {
        result = weigh(coins, start, start + 1, 1,
                       actualDefective, comparisons);

        if (result == LEFT_LIGHTER)
            return coins[start];

        if (result == RIGHT_LIGHTER)
            return coins[start + 1];

        return -1;
    }

    remainder = n - 2 * third;

    result = weigh(coins, start, start + third, third,
                   actualDefective, comparisons);

    if (result == LEFT_LIGHTER)
        return findCandidate(coins, start, third,
                             actualDefective, comparisons);

    if (result == RIGHT_LIGHTER)
        return findCandidate(coins, start + third, third,
                             actualDefective, comparisons);

    /*
     * Equal pans:
     * The defective coin, if present, must be in group C.
     */
    return findCandidate(coins, start + 2 * third, remainder,
                         actualDefective, comparisons);
}

int validateCandidate(int candidate, int genuine,
                      int actualDefective, int *comparisons) {
    (*comparisons)++;

    if (candidate == -1)
        return -1;


    if (candidate == actualDefective)
        return candidate;

    return -1;
}

int main(void) {
    int coins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(coins) / sizeof(coins[0]);

   
    int actualDefective = 7;

    int comparisons = 0;
    int candidate;
    int defective;

    int genuine = 1;

    candidate = findCandidate(coins, 0, n,
                              actualDefective, &comparisons);

    defective = validateCandidate(candidate, genuine,
                                  actualDefective, &comparisons);

    if (defective == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin: %d\n", defective);

    printf("Number of weighings: %d\n", comparisons);

    return 0;
}
