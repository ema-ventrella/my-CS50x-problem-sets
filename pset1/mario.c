#include <cs50.h>
#include <stdio.h>

void space(int v);
void blocks(int e);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        int value = n - i;
        space(value);
        blocks(i + 1);
        printf("  ");
        blocks(i + 1);
        printf("\n");
    }
}

void space(int v)
{
    for (int a = 1; a < v; a++)
    {
        printf(" ");
    }
}

void blocks(int e)
{
    for (int b = 0; b < e; b++)
    {
        printf("#");
    }
}
