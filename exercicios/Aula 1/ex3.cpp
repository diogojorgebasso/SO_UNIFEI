#include <stdio.h>

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main()
{
  int nums[] = {4, 1, 7, 3, 9};
  int size = sizeof(nums) / sizeof(nums[0]);
  printArray(nums, size);
  return 0;
}