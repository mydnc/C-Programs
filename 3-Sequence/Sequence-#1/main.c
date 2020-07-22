#include "stdio.h"

void decToBinary(int num);

long long int digits = 0, zeros = 0, sequence = 0;

int main()
{
    long long int lo, hi;
    char c;

    printf("Enter the interval:\n");
    if (scanf(" < %lld ; %lld > %c", &lo, &hi, &c) != 3 || lo > hi || lo < 0)
    {
        printf("Invalid input.\n");
        return 0;
    }
    if (lo == 0)
    {
        zeros++;
        digits++;
    }
    if (lo == 0 && hi == 0)
        sequence = 1;
    for (; lo <= hi; lo++)
    {
        decToBinary(lo);
    }
    switch (c)
    {
    case 'l':
        //l to display the total length of the binary sequence (number of digits)
        printf("Digits: %lld\n", digits);
        break;
    case 'z':
        //z to display the count of zeros in the sequence
        printf("Zeros: %lld\n", zeros);
        break;
    case 's':
        //s to display the length of the longest contiguous run of zeros in the sequence
        printf("Sequence: %lld\n", sequence);
        return 1;

    default:
        printf("Invalid input.\n");
        break;
    }
    return 0;
}

void decToBinary(int num)
{

    long long int binaryNum, currentLength = 0;
    while (num > 0)
    {
        binaryNum = num % 2;
        num = num / 2;
        if (binaryNum == 0)
            zeros++;
        if (binaryNum == 0 || binaryNum == 1)
            digits++;
        if (binaryNum == 1)
            currentLength = 0;
        else
            currentLength = currentLength + 1;
        if (currentLength > sequence)
            sequence = currentLength;
    }
}