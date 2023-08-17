// Aim of the program: Write a menu driven program to sort list of array elements using Merge Sort technique and calculate the execution time only to sort the elements.  Count the number of comparisons.
// Note#
// · To calculate execution time, assume that single program is under execution in the CPU.
// · Number of elements in each input file should vary from 300 to 500 entries.
// · For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., Store the result in “outMergeAsce.dat”.
// · For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outMergeDesc.dat”.
// · For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outMergeRand.dat”

// Sample Input from file:
// MAIN MENU (MERGE SORT)
// 1. Ascending Data
// 2. Descending Data
// 3. Random Data
// 4. ERROR (EXIT)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count = 0;

void merge(int arr[], int l, int m, int r)
{
    int temp[r - l + 1];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
        count++;
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inAsce.dat", "r");
        fp2 = fopen("outMergeAsce.dat", "w");
        int n = 300;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &arr[i]);
        }
        clock_t start, end;
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", arr[i]);
        }
        printf("Time taken to sort the array is %f seconds\n", time_taken);
        printf("Number of comparisons: %d\n", count);
        fclose(fp1);
        fclose(fp2);
        break;
    }

    case 2:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inDesc.dat", "r");
        fp2 = fopen("outMergeDesc.dat", "w");
        int n = 300;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &arr[i]);
        }
        clock_t start, end;
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", arr[i]);
        }
        printf("Time taken to sort the array is %f seconds\n", time_taken);
        printf("Number of comparisons: %d\n", count);
        fclose(fp1);
        fclose(fp2);
        break;
    }

    case 3:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inRand.dat", "r");
        fp2 = fopen("outMergeRand.dat", "w");
        int n = 300;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d, ", &arr[i]);
        }
        clock_t start, end;
        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", arr[i]);
        }
        printf("Time taken to sort the array is %f seconds\n", time_taken);
        printf("Number of comparisons: %d\n", count);
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 4:
    {
        printf("Ending...\n");
        exit(0);
    }

    }
}
