/*Write a menu driven program to sort a list of elements in ascending order using Insertion Sort technique. The nature of the input data is choice based and a distinct file is considered for each choice. The sorted elements can be stored in a separate output file. After sorting display the content of the output file along with number of comparisons. Based on the number of comparisons, conclude the input scenario is either best or worst case.
 
Note#
· Number of elements in each input file should vary from 300 to 500 entries.
· For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40 ….., Store the result in “outInsAsce.dat”.
· For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outInsDesc.dat”.
· For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outInsRand.dat”
Sample Input from file:
MAIN MENU (INSERTION SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)*/


#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[], int n)
{
    int count = 0;
    int temp=0, j=0;
    for (int i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            count++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Number of comparisons made: %d\n", count);
}                                   


int main(){
    printf("MAIN MENU (INSERTION SORT)\n");
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
        fp2 = fopen("outInsAsce.dat", "w");
        int n;
        fscanf(fp1, "%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d", &a[i]);
        }
        insertionSort(a, n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", a[i]);
        }
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 2:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inDesc.dat", "r");
        fp2 = fopen("outInsDesc.dat", "w");
        int n;
        fscanf(fp1, "%d", &n);      
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d", &a[i]);
        }
        insertionSort(a, n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", a[i]);
        }
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 3:
    {
        FILE *fp1, *fp2;
        fp1 = fopen("inRand.dat", "r");
        fp2 = fopen("outInsRand.dat", "w");
        int n;
        fscanf(fp1, "%d", &n);
        int a[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fp1, "%d", &a[i]);
        }
        insertionSort(a, n);
        for (int i = 0; i < n; i++)
        {
            fprintf(fp2, "%d ", a[i]);
        }
        fclose(fp1);
        fclose(fp2);
        break;
    }
    case 4:
    {
        exit(0);
        break;
    }
    default:
    {
        printf("Invalid choice\n");
        break;
    }
    }   
    return 0;
}