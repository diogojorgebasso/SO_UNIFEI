#include <stdio.h>
void modifyArray(int arr[])
{
  arr[0] = 100;
}
int main()
{
  int nums[] = {10, 20, 30};
  modifyArray(nums);
  printf("%d\n", nums[0]);
  return 0;
}