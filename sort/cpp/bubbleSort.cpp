/*
* 冒泡排序：重复地遍历要排序的数列，一次比较两个元素（指针 和 指针+1），如果他们的顺序错误就把他们交换过来;
*			走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。
* 时间复杂度： 最好 O(n)
*				最坏 O(n^2)
*				平均 O(n^2)
*
* 空间复杂度： O(1)
*
* 稳定性：稳定
*/

#include <vector>

void bubbleSort(std::vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	for (int end = nums.size(); end > 0; end--) {
		bool swap = false;
		for (int i = 0; i < end - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				int temp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = temp;
				swap = true;
			}
		}
		if (!swap)
			break;
	}
	return;
}