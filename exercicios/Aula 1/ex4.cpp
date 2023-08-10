#include <stdio.h>

int computeSum(int arr[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    sum += arr[i];
  }
  return sum;
}
int main()
{
  int nums[] = {2, 4, 6, 8, 10};
  int size = sizeof(nums) / sizeof(nums[0]);
  int result = computeSum(nums, size);
  printf("%d\n", result);
  return 0;
}