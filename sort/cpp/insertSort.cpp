/*
* 直接插入排序：遍历元素，把每个待排序元素插入到前面有序列表里
* 时间复杂度： 最好 O(n)
*				最坏 O(n^2)
*				平均 O(n^2)
* 
* 空间复杂度： O(1)
*
* 稳定性：稳定
*/

#include <vector>

void insertSort(std::vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	for (int i = 1; i < nums.size(); i++) {
		int temp = nums[i];
		int j = i;
		while (j > 0 && nums[j - 1] > temp) {
			nums[j] = nums[j - 1];
			j--;
		}
		nums[j] = temp;
	}
	return;
}