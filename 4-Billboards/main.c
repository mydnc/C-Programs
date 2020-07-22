#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int bb[MAX];
int len, dist, t;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int billboard(int arr[], int n, int length, int distance)
{
    int new_dist, position, beginning, billboard;
    billboard = position = beginning = 0;
    new_dist = distance;

    if (distance > length)
    {
        return 0;
    }

    if (distance == length)
    {
        return 0;
    }
    else if (distance >= bb[n - 1])
    {
        return 1;
    }

    do
    {
        int j = n - 1;
        for (; beginning <= j; j--)
        {
            if (new_dist >= arr[j])
            {
                position = arr[j];
                new_dist = position + distance;
                beginning = j;
                billboard++;
            }
        }
    } while (length > new_dist && length > position);

    return billboard;
}

int main()
{
    int counter = 0, scan;
    char c, c2;

    //input
    printf("Suitable positions:\n");
    scan = scanf(" %d %c %c", &len, &c, &c2);

    if (scan != 3)
    {
        printf("Invalid input.\n");
        return 0;
    }
    if (len > 0)
    {
        if (c == ':')
        {
            if (c2 == '{')
            {
                for (int i = 0; i < MAX; i++)
                {
                    if ((scan = scanf(" %d %c", &t, &c2)) == 2)
                    {
                        if (scan == EOF)
                        {
                            return 0;
                        }
                        if (t < 1 || t >= len || counter > 1000000)
                        {
                            printf("Invalid input.\n");
                            return 0;
                        }
                        if (t > len)
                        {
                            printf("Invalid input.\n");
                            return 0;
                        }
                        if (c2 == ',')
                        {
                            bb[i] = t;
                            counter++;
                        }
                        else if (c2 == '}')
                        {
                            bb[i] = t;
                            counter++;
                            break;
                        }
                        else
                        {
                            printf("Invalid input.\n");
                            return 0;
                        }
                    }
                    else
                    {
                        printf("Invalid input.\n");
                        return 0;
                    }
                }
            }
            else
            {
                printf("Invalid input.\n");
                return 0;
            }
        }
        else
        {
            printf("Invalid input.\n");
            return 0;
        }
        // -- Sorting given values
        bubbleSort(bb, counter);
        // -- Distance reading
        printf("Distances:\n");
        while (1)
        {
        HERE:
            scan = scanf("%d", &dist);
            if (scan == EOF)
                return 0;

            if ((scan != 1 && scan != EOF) || dist < 1)
            {
                printf("Invalid input.\n");
                return 0;
            }

            if (bb[0] > dist || len - bb[counter - 1] > dist)
            {
                printf("N/A\n");
                goto HERE;
            }

            for (int i = 0; i < counter; i++)
            {
                //int tmp=arr[i+1]-arr[i];
                if ((bb[i] + dist) < bb[i + 1])
                {
                    printf("N/A\n");
                    goto HERE;
                }
            }

            if (len > (bb[counter - 1] + dist))
            {
                printf("N/A\n");
                goto HERE;
            }

            // -- Passing the values to the function billboard();
            printf("Billboards: %d\n", billboard(bb, counter, len, dist));
        }
    }
    else
    {
        printf("Invalid input.\n");
        return 0;
    }

    return 0;
}