#include <iostream>
using namespace std;
struct Array
{
    int *array;
    int length;
    int size;
};
void display(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d", arr->array[i]);
        printf("\n");
    }
}

struct Array *reverse(struct Array *arr)
{
    int j = arr->length - 1;
    for (int i = 0; i < j; i++, j--)
    {
        int temp = arr->array[i];
        arr->array[i] = arr->array[j];
        arr->array[j] = temp;
    }
    return arr;
}

int binarySearch(struct Array arr, int key)
{
    int lowest = 0;
    int largest = arr.length - 1;
    while (lowest < largest)
    {
        int middle = (largest + lowest) / 2;
        if (arr.array[middle] == key)
        {
            return middle;
        }
        else if (key < arr.array[middle])
        {
            largest = middle - 1;
        }
        else
        {
            lowest = middle + 1;
        }
    }

    return -1;
}
int main()
{
    struct Array arr;
    arr.size = 10;
    arr.length = 10;
    int ar[] = {12, 15, 23, 45, 65, 43, 54, 67, 87, 100};
    arr.array = ar;
    struct Array *arr1 = reverse(&arr);
    display(arr1);
    return 0;
}