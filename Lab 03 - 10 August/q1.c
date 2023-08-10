#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int x;
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    int l = 0, r = n - 1, mid, pos = -1, count = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == x)
        {
            pos = mid;
            r = mid - 1;
        }
        else if (a[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        count++;
    }

    if (pos == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at position %d\n", pos);
    }
    printf("Number of comparisons made: %d\n", count);
}