#include <stdio.h>

void reverseArray(int arr[], int size)
{
  for (int i = 0; i < size / 2; i++)
  {
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }
}

int main()
{
  int nums[] = {1, 2, 3, 4, 5};
  int size = sizeof(nums) / sizeof(nums[0]);
  reverseArray(nums, size);

  for (int i = 0; i < size; i++)
  {
    printf("%d ", nums[i]);
  }

  return 0;
}