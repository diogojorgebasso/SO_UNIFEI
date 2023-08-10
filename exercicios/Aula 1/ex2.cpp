#include <stdio.h>

void selectionSort(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    int min = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
  // Imprime o array ordenado
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main()
{
  int nums[] = {5, 2, 8, 1, 3};
  int size = sizeof(nums) / sizeof(nums[0]);
  selectionSort(nums, size);
  return 0;
}