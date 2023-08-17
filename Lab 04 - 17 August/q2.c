// Aim of the program: Write a menu driven program to sort a list of elements in ascending order using Quick Sort technique. Each choice for the input data has its own disc file.  A separate output file can be used for sorted elements. After sorting display the content of the output file along with number of comparisons. Based on the partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or worst-case partitioning.
// Note#
// · The worst-case behavior for quicksort occurs when the partitioning routine produces one subproblem with n-1 elements and one with 0 elements. The best-case behaviour occurred in most even possible split, PARTITION produces two subproblems, each of size no more than n/2.
// · Number of elements in each input file should vary from 300 to 500 entries.
// · For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., Store the result in “outQuickAsce.dat”.
// · For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outQuickDesc.dat”.
// · For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outQuickRand.dat”
// Sample Input from file:
// MAIN MENU (QUICK SORT)
// 1. Ascending Data
// 2. Descending Data
// 3. Random Data
// 4. ERROR (EXIT)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;

// quick sort

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1, j;
    for (j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    count++;
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main(){
    int choice;
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        {
            FILE *in = fopen("inAsce.dat", "r");
            FILE *out = fopen("outQuickAsce.dat", "w");
            int n=400;
           
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                fscanf(in, "%d, ", &arr[i]);
            }
            clock_t start = clock();
            quickSort(arr, 0, n - 1);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(out, "Sorted array: ");
            for (int i = 0; i < n; i++)
            {
                fprintf(out, "%d ", arr[i]);
            }
            fprintf(out, "\nNumber of comparisons: %d\n", count);
            fprintf(out, "Execution time: %f\n", time);
            fclose(in);
            fclose(out);
            break;
        }
        case 2:
        {
            FILE *in = fopen("inDesc.dat", "r");
            FILE *out = fopen("outQuickDesc.dat", "w");
            int n=400;
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                fscanf(in, "%d, ", &arr[i]);
            }
            clock_t start = clock();
            quickSort(arr, 0, n - 1);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(out, "Sorted array: ");
            for (int i = 0; i < n; i++)
            {
                fprintf(out, "%d ", arr[i]);
            }
            fprintf(out, "\nNumber of comparisons: %d\n", count);
            fprintf(out, "Execution time: %f\n", time);
            fclose(in);
            fclose(out);
            break;
        }
        case 3:
        {
            FILE *in = fopen("inRand.dat", "r");
            FILE *out = fopen("outQuickRand.dat", "w");
            int n=400;
            int arr[n];
            for (int i = 0; i < n; i++)
            {
                fscanf(in, "%d, ", &arr[i]);
            }
            clock_t start = clock();
            quickSort(arr, 0, n - 1);
            clock_t end = clock();
            double time = (double)(end - start) / CLOCKS_PER_SEC;
            fprintf(out, "Sorted array: ");
            for (int i = 0; i < n; i++)
            {
                fprintf(out, "%d ", arr[i]);
            }
            fprintf(out, "\nNumber of comparisons: %d\n", count);
            fprintf(out, "Execution time: %f\n", time);
            fclose(in);
            fclose(out);
            break;
        }
        case 4:
        {
            printf("Ending...\n");
            break;
        }
    }

    
    
}