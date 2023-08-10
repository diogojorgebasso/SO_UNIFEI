#include <stdio.h>
int findMax(int arr[], int size)
{
  int max = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}
int main()
{
  int nums[] = {22, 7, 15, 43, 30};
  int size = sizeof(nums) / sizeof(nums[0]);
  int result = findMax(nums, size);
  printf("%d\n", result);
  return 0;
}