#include <stdio.h>

int main()
{
    printf("Initial triangle:\n");
    printf("       O\n");
    printf("      O O\n");
    printf("     O O O\n");
    printf("    O O O O\n");

    printf("\nMinimum moves = 3\n");

    printf("\nMove 1: Move top coin to bottom.\n");
    printf("Move 2: Move bottom-left coin to upper-left.\n");
    printf("Move 3: Move bottom-right coin to upper-right.\n");

    printf("\nInverted triangle:\n");
    printf("    O O O O\n");
    printf("     O O O\n");
    printf("      O O\n");
    printf("       O\n");

    return 0;
}