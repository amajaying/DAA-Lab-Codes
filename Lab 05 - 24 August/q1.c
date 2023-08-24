#include <stdio.h>
char line[1000];
struct person
{
    int id;
    char name[20];
    int age;
    int height;
    int weight;
};

int main()
{

    FILE *fp = fopen("detail.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    printf("MAIN MENU (HEAP)\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on the age\n");
    printf("3. Create a Max-heap based on the weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Insert a new person into the Min-heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");

    int n = 7;
    struct person s[n];
    int num = 0;

    while (fgets(line, sizeof(line), fp) && num < n)
    {
        sscanf(line, "%d, %[^,], %d, %d, %d\n", &s[num].id, s[num].name, &s[num].age, &s[num].height, &s[num].weight);
        num++;
    }
    int again = 1;
    while (again)
    {
        int option;
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {

            printf("Data read successfully\n");
            printf("ID\tName\t\tAge\tHeight\tWeight\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d\t%s\t%d\t%d\t%d\n", s[i].id, s[i].name, s[i].age, s[i].height, s[i].weight);
            }
            printf("\nChoose option again? (0/1): ");
            scanf("%d", &again);
            break;
        }

        case 4:
        {
            int min = s[0].age;
            int index = 0;
            for (int i = 1; i < n; i++)
            {
                if (s[i].age < min)
                {
                    min = s[i].age;
                    index = i;
                }
            }
            printf("Weight of the age: %d\t youngest person: %d\n", s[index].age, s[index].weight);
            printf("\nChoose option again? (0/1): ");
            scanf("%d", &again);
            break;
        }
        }
    }
}