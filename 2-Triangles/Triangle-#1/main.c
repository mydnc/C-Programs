#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main()
{
    //inputs
    long double t1_a1, t1_a2, t1_b1, t1_b2, t1_c1, t1_c2;
    long double t1_ab, t1_ac, t1_bc, sum_t1;
    long double slope1_ab, slope1_ac, slope1_bc;
    long double t2_a1, t2_a2, t2_b1, t2_b2, t2_c1, t2_c2;
    long double t2_ab, t2_ac, t2_bc, sum_t2;
    long double slope2_ab, slope2_ac, slope2_bc;
    long double min;
    //input validations
    printf("Triangle #1:\n");
    printf("Vertex A:\n");
    if (scanf("%Lf %Lf", &t1_a1, &t1_a2) != 2)
    {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Vertex B:\n");
    if (scanf("%Lf %Lf", &t1_b1, &t1_b2) != 2)
    {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Vertex C:\n");
    if (scanf("%Lf %Lf", &t1_c1, &t1_c2) != 2)
    {
        printf("Invalid input.\n");
        return 0;
    }
    //slopes of first triange
    slope1_ab = (t1_a2 - t1_b2) / (t1_a1 - t1_b1);
    slope1_ab = floor(10000 * slope1_ab) / 10000;
    slope1_ac = (t1_a2 - t1_c2) / (t1_a1 - t1_c1);
    slope1_ac = floor(10000 * slope1_ac) / 10000;
    slope1_bc = (t1_b2 - t1_c2) / (t1_b1 - t1_c1);
    slope1_bc = floor(10000 * slope1_bc) / 10000;

    if (fabs(slope1_ab) == fabs(slope1_ac) && fabs(slope1_ab) == fabs(slope1_bc))
    {
        printf("The points do not form a triangle.\n");
        return 0;
    }
    printf("Triangle #2:\n");
    printf("Vertex A:\n");
    if (scanf("%Lf %Lf", &t2_a1, &t2_a2) != 2)
    {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Vertex B:\n");
    if (scanf("%Lf %Lf", &t2_b1, &t2_b2) != 2)
    {
        printf("Invalid input.\n");
        return 0;
    }
    printf("Vertex C:\n");
    if (scanf("%Lf %Lf", &t2_c1, &t2_c2) != 2)
    {
        printf("Invalid input.\n");
        return 0;
    }
    //slopes of second triange
    slope2_ab = (t2_a2 - t2_b2) / (t2_a1 - t2_b1);
    slope2_ab = floor(10000 * slope2_ab) / 10000;
    slope2_ac = (t2_a2 - t2_c2) / (t2_a1 - t2_c1);
    slope2_ac = floor(10000 * slope2_ac) / 10000;
    slope2_bc = (t2_b2 - t2_c2) / (t2_b1 - t2_c1);
    slope2_bc = floor(10000 * slope2_bc) / 10000;

    if (fabs(slope2_ab) == fabs(slope2_ac) && fabs(slope2_ab) == fabs(slope2_bc))
    {
        printf("The points do not form a triangle.\n");
        return 0;
    }
    //calculate distance of vertices of first triangle
    t1_ab = fabs(sqrt(((t1_a1 - t1_b1) * (t1_a1 - t1_b1)) + ((t1_a2 - t1_b2) * (t1_a2 - t1_b2))));
    t1_ac = fabs(sqrt(((t1_a1 - t1_c1) * (t1_a1 - t1_c1)) + ((t1_a2 - t1_c2) * (t1_a2 - t1_c2))));
    t1_bc = fabs(sqrt(((t1_b1 - t1_c1) * (t1_b1 - t1_c1)) + ((t1_b2 - t1_c2) * (t1_b2 - t1_c2))));
    //sums of first triange's sides
    sum_t1 = (double)t1_ab + t1_ac + t1_bc;

    //calculate distance of vertices of second triangle
    t2_ab = fabs(sqrt(((t2_a1 - t2_b1) * (t2_a1 - t2_b1)) + ((t2_a2 - t2_b2) * (t2_a2 - t2_b2))));
    t2_ac = fabs(sqrt(((t2_a1 - t2_c1) * (t2_a1 - t2_c1)) + ((t2_a2 - t2_c2) * (t2_a2 - t2_c2))));
    t2_bc = fabs(sqrt(((t2_b1 - t2_c1) * (t2_b1 - t2_c1)) + ((t2_b2 - t2_c2) * (t2_b2 - t2_c2))));
    //sums of second triange's sides
    sum_t2 = (double)t2_ab + t2_ac + t2_bc;

    //min
    min = (sum_t1 < sum_t2) ? sum_t1 : sum_t2;

    //compare
    if (fabs(sum_t1 - sum_t2) <= 1e-12 * min)
    {
        if (((t1_ab == t2_ab) && (t1_ac == t2_ac) && (t1_bc == t2_bc)) || ((t1_ab == t2_ac) && (t1_ac == t2_bc) && (t1_bc == t2_ab)) || ((t1_ab == t2_bc) && (t1_ac == t2_ab) && (t1_bc == t2_ac)))
        {
            printf("The triangles are identical.\n");
            return 0;
        }
        else
        {
            printf("The triangles are not identical, however, they have the same circumference.\n");
            return 0;
        }
    }
    else
    {
        if (fabs(sum_t1) > fabs(sum_t2))
        {
            printf("Triangle #1 has a longer circumference.\n");
            return 0;
        }
        else
        {
            printf("Triangle #2 has a longer circumference.\n");
            return 0;
        }
    }
    return 0;
}