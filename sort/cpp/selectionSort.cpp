/*
* 选择排序：从第一个遍历序列，遍历指针右边（含指针所指元素）为待排序序列；
*			从待排序序列中，找到关键字最小的元素；
*			如果最小元素不是待排序序列的第一个元素，将其和第一个元素互换；
*			这样就能保证指针左边为排好序的
* 时间复杂度：  最好 O(n^2)
*				最坏 O(n^2)
*				平均 O(n^2)
*
* 空间复杂度： O(1)
*				
* 稳定性：如果在原数组中进行交换，是不稳定的；
*		  如果新开一个数组，那可能是稳定的，跟比较时“>”或者“>=”有关
*/

#include <vector>

void selectionSort(std::vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	for (int i = 0; i < nums.size()-1; i++) {
		int idxMin = i;
		for (int j = i; j < nums.size(); j++) {
			if (nums[j] < nums[idxMin])
				idxMin = j;
		}
		if (idxMin == i) continue;
		int temp = nums[i];
		nums[i] = nums[idxMin];
		nums[idxMin] = temp;
	}
	return;
}