#include "dynamicARRAY.c"

void insertionSort()
{
    for (int i = 1; i <= lastIndex; i++)
    {
        int j = i - 1;
        int key = ptr[i];
        while ((j >= 0) && (key < ptr[j]))
        {
            ptr[j + 1] = ptr[j];
            j--;
        }
        ptr[j + 1] = key;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort()
{
    int i, j;
    for (i = 0; i <= lastIndex - 1; i++)
        for (j = 0; j <= lastIndex - i - 1; j++)
            if (ptr[j] > ptr[j + 1])
                swap(&ptr[j], &ptr[j + 1]);
}

void shellSort()
{
    int n = lastIndex + 1;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int t = ptr[i];
            int j;
            for (j = i; j >= gap && ptr[j - gap] > t; j -= gap)
            {
                ptr[j] = ptr[j - gap];
                // ptr[j]=t;
            }
            ptr[j] = t;
        }
    }
}

void merge(int arr[], int lb, int m, int ub)
{

    int n1 = m - lb + 1;
    int n2 = ub - m;

    int L[n1], M[n2]; // two sub array

    for (int i = 0; i < n1; i++)
        L[i] = arr[lb + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[m + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = lb;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {

        int m = (lb + ub) / 2;

        mergeSort(arr, lb, m);
        mergeSort(arr, m + 1, ub);

        merge(arr, lb, m, ub);
    }
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = (2 * i);
    int r = (2 * i) + 1;
    if (l <= n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
    // delete
    for (int i = n; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, n, i);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void show(){
    if(isEmpty())
        return;
    for(int i=0;i<=lastIndex;i++){
        printf("%d, ",ptr[i]);
    }
}
int main()
{
    int choice;
    lastIndex=5;
    int arr[]={14,45,2,85,96,25};
    ptr=arr;
    while(1){
    printf("\\n2.Quicksort\n3.heapSort\n4.Mergesort\n5.Shellsort\n6.Bubble Sort\n7.Insertsort\nAnything else to exit");
    printf("\nEnter the choice");
    scanf("%d",&choice);
    switch (choice)
    {
    // case 1:{
    //     int k;
    //     printf("\nEnter element: ");
    //     scanf("%d",&k);
    //     append(k);
    //     show();
    //     break;
    // }
    case 2:{
        if(isEmpty())
            break;
        quickSort(ptr,0,lastIndex);
        show();
        break;
    }
    case 3:{
        if(isEmpty())
            break;
        heapSort(ptr,lastIndex);
        show();
        break;
    }
    case 4:{
        if(isEmpty())
            break;
        mergeSort(ptr,0,lastIndex);
        show();
        break;
    }
    case 5:{
        if(isEmpty())
            break;
        shellSort();
        show();
        break;
    }
    case 6:{
        if(isEmpty())
            break;
        bubbleSort();
        show();
        break;
    }
    case 7:{
        if(isEmpty())
            break;
        insertionSort();
        show();
        break;
    }

    
    default:{
        choice=0;
        break;
    }
    }
    if(!choice)
        break;
    }
}
