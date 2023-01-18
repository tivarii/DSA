#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

int lastIndex,capacity,*ptr;
bool isEmpty()
{
    if (lastIndex == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if (lastIndex == capacity)
    {
        return true;
    }
    return false;
}
// edit(int index,int data){
//     if(index>=0 && index<=(lastIndex+1)){
//         ptr[index]=data;
//         return;
//     }
//     else{
//         cout<<"Invalid index.";
//     }
// }

// insert(int index,int data){
//     lastIndex++;
//     void doubleArray();
//     if(index>=0 && index<=(lastIndex+1)){
//         for(int i=lastIndex;i>=index;i--){
//             ptr[i+1]=ptr[i];
//         }
//         ptr[index]=data;
//         return;
//     }
//     else{
//         cout<<"Invalid index.";
//     }
// }

void doubleArray()
{
    if (isFull())
    {
        int capacity = capacity * 2;
        int *ptrN = ptr;
        ptr = (int *)malloc(capacity*sizeof(int));
        for (int i = 0; i <= lastIndex; i++)
        {
            ptr[i] = ptrN[i];
        }
        free(ptr);
        return;
    }
    return;
}

void halfArray(){
    if((lastIndex+1)==(capacity/2)&&(capacity>4)){
       int capacity = capacity / 2;
        int *ptrN = ptr;
        ptr = (int *)malloc(capacity*sizeof(int));
        for (int i = 0; i <= lastIndex; i++)
        {
            ptr[i] = ptrN[i];
        }
        free(ptrN);
        return; 
    }
    return;
}

void append(int data)
{
    doubleArray();
    lastIndex++;
    ptr[lastIndex] = data;
    return;
}

