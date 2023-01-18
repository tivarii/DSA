#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return;
}

void insert(int *arr)
{
    int value;
    int index;
    cout << "Enter the value: ";
    cin >> value;
    cout << "\tPlease enter the index in between 0 to 9.\nEnter the index:\n ";
    cin >> (index);
    if (index < 10)
    {
        arr[index] = value;
        cout << "\t New array after insertion.\n";
        printArray(arr, 10);
    }
    else
    {
        cout << "You have enter invalid index.\n";
    }
    return;
}

void deletion(int *arr,int size){
    printArray(arr,size);
    cout <<"Enter index number of element to delete: ";
    int index;
    cin>>index;
    for(int i=index;i<(size-1);i++){
        arr[i]=arr[i+1];
    }
    cout<<"\t Element deleted successfully \n";
    printArray(arr,(size-1));
}

int main()
{
    int arr[] = {10, 2, 13, 4, 5, 16, 7, 8, 19, 10};  
    int choice;
    bool con = true;
    while (con)
    {
        cout << " 1:Print \n 2:Insert \n 3: Delete \n 4: Exit \n";
        cout << "Enter the action you want to perform: ";
        cin >> choice;
        switch (choice)
        {
        case (1):
            printArray(arr, 10);
            break;
        case (2):
            insert(arr);
            break;
        case (3):
            deletion(arr,10);
            break;
        case (4):
            con = false;
            break;
        default:
            cout << "Enter invalid input";
            break;
        }
    }
}