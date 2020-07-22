#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decToAny(int num, int radix);
void Print(char c);
long long int digits = 0, zeros = 0, sequence = 0;
long long int lo, hi;
int radix;
int main()
{
    char c, c2 = 0;
    printf("Enter the intervals:\n");
    while ((scanf(" %c", &c2) != EOF))
    {
        if (c2 == 'r')
        {
            if ((scanf("%d : < %lld ; %lld > %c", &radix, &lo, &hi, &c)) != 4 || radix < 2 || radix > 36 || (c != 'l' && c != 'z' && c != 's'))
            {
                printf("Invalid input.\n");
                return 0;
            }
            else
            {
                if (lo > hi || lo < 0)
                {
                    printf("Invalid input.\n");
                    return 0;
                }

                digits = 0, zeros = 0, sequence = 0;
                if (lo == 0)
                {
                    zeros++;
                    digits++;
                    sequence++;
                }
                for (; lo <= hi; lo++)
                {
                    decToAny(lo, radix);
                }
                Print(c);
            }
        }
        else if (c2 == '<')
        {
            if ((scanf(" %lld ; %lld > %c", &lo, &hi, &c)) != 3 || lo > hi || lo < 0)
            {
                printf("Invalid input.\n");
                return 0;
            }
            else
            {
                if (lo > hi || lo < 0)
                {
                    printf("Invalid input.\n");
                    return 0;
                }
                radix = 10;
                digits = 0, zeros = 0, sequence = 0;
                if (lo == 0)
                {
                    zeros++;
                    digits++;
                    sequence++;
                }
                for (; lo <= hi; lo++)
                {
                    decToAny(lo, radix);
                }
                Print(c);
            }
        }
        else
        {
            printf("Invalid input.\n");
            return 0;
        }
    }
}
void decToAny(int num, int radix)
{
    long long int result, currentLength = 0;

    while (num != 0)
    {
        result = num % radix;
        num = num / radix;
        digits++;
        if (result == 0)
        {
            zeros++;
            currentLength = currentLength + 1;
            if (currentLength > sequence)
                sequence = currentLength;
        }
        else
        {
            currentLength = 0;
        }
    }
    currentLength = 0;
}
void Print(char c)
{
    if ((lo == 0) && (hi == 0))
        sequence = 1;

    switch (c)
    {
    case 'l':
        printf("Digits: %lld\n", digits);
        break;
    case 'z':
        printf("Zeros: %lld\n", zeros);
        break;
    case 's':
        printf("Sequence: %lld\n", sequence);
        break;
    default:
        printf("Invalid input.\n");
        break;
    }
}