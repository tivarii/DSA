#include <stdio.h>
#include <stdlib.h>
int rows, columns;


void sparse(int sparseArr[][3], int **arr)
{
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] != 0)
            {
                sparseArr[k][0] = i;
                sparseArr[k][1] = j;
                sparseArr[k][2] = arr[i][j];
                k++;
            }
        }
    }
}

int find_Non_Zero(int **array)
{
    int number = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j] != 0)
            {
                number++;
            }
        }
    }
    return number;
}
int main()
{

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int **array = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        array[i] = malloc(columns * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter element (%d,%d): ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    // printing

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    //sparse from the original
    int non_zero = find_Non_Zero(array);
    int sparseArr[non_zero + 1][3];
    sparseArr[0][0] = rows;
    sparseArr[0][1] = columns;
    sparseArr[0][2] = non_zero;

    sparse(sparseArr, array);
    printf("\n");

    for (int i = 0; i < non_zero + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", sparseArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}