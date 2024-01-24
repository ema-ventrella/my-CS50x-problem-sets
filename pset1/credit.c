#include <cs50.h>
#include <math.h>
#include <stdio.h>

int check(long n, int count);
string text(int response, long n, int count);

int main(void)
{
    long n = get_long("Number: ");
    int count = floor(log10(n)) + 1;
    int value = check(n, count);
    string response = text(value, n, count);
    printf("%s\n", response);
}

int check(long n, int count)
{
    if (count == 13 || count == 14 || count == 15 || count == 16)
    {
        long a = n;
        int b = 0;
        int c = 0;
        int d = 0;

        for (int i = 0; i < 8; i++)
        {
            b = (a % 10) + b;
            a = a / 10;
            d = (a % 10) * 2;

            if (d <= 9)
            {
                c += d;
            }
            else if (d > 9)
            {
                int e = d / 10;
                int f = d % 10;
                c += e + f;
            }

            a = a / 10;
        }
        return b + c;
    }
    return 0;
}

string text(int response, long n, int count)
{
    if ((response % 10) != 0)
    {
        return "INVALID";
    }

    int firstDigit = 0;
    int secondDigit = 0;
    long v = n;

    while (n != 0)
    {
        firstDigit = n % 10;
        n /= 10;
    }

    while (v > 10)
    {
        secondDigit = v % 10;
        v /= 10;
    }

    if (firstDigit == 3 && count == 15 && (secondDigit == 4 || secondDigit == 7))
    {
        return "AMEX";
    }
    else if (firstDigit == 4 && (count == 13 || count == 16))
    {
        return "VISA";
    }
    else if (firstDigit == 5 && count == 16 &&
             (secondDigit == 1 || secondDigit == 2 || secondDigit == 3 || secondDigit == 4 || secondDigit == 5))
    {
        return "MASTERCARD";
    }

    return "INVALID";
}
