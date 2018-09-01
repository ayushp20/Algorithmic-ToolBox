#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <math.h>

// A structure to represent a struct Point in 2D plane
typedef struct Point
{
    int x, y;
};

int compareX(const void* a, const void* b)
{
    struct Point *p1 = (struct Point *)a,  *p2 = (struct Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    struct Point *p1 = (struct Point *)a,   *p2 = (struct Point *)b;
    return (p1->y - p2->y);
}

float dist(struct Point p1, struct Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}

float bruteForce(struct Point P[], int n)
{
    float min = FLT_MAX;
    int i,j;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float min(float x, float y)
{
    return (x < y)? x : y;
}

float stripClosest(struct Point strip[], int size, float d)
{
    float min = d;
    int i,j;

    qsort(strip, size, sizeof(struct Point), compareY);

    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);

    return min;
}

float closestUtil(struct Point P[], int n)
{

    if (n <= 3)
        return bruteForce(P, n);

    int mid = n/2;
    struct Point midpoint= P[mid];

    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n-mid);


    float d = min(dl, dr);


    struct Point strip[n];
    int j = 0,i;
    for (i = 0; i < n; i++)
        if (abs(P[i].x - midpoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d) );
}


float closest(struct Point P[], int n)
{
    qsort(P, n, sizeof(struct Point), compareX);

    return closestUtil(P, n);
}

void main()
{
    int n;
    scanf('%d',&n);

    struct Point points[n];
    int i;
    for(i=0;i<n;i++){
        scanf('%d',&points[i].x);
        scanf('%d',&points[i].y);
    }
    printf("The smallest distance is %.9f ", closest(points, n));
}
