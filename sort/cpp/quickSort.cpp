/*
* 快排：
* 普通的快排（需要额外的存储空间）：选定一个基准值pivot，
*									遍历序列把比pivot小的放在一个序列less，
*									比pivot大的放在另一个序列greater，
*									再连起来(less,pivot,greater)，递归处理less和greater
* Partition函数：
*
* 注意：pivot最好随机选择。如果只选择第一个数作为pivot，容易退化为O(n^2)的复杂度
*
* 时间复杂度：  最好 O(nlogn)
*				最坏 O(n^2)
*				平均 O(nlogn)
*
* 空间复杂度： O(nlogn)
*
* 稳定性：不稳定
*/

#include <vector>

int Partition(std::vector<int> &nums, int start, int end)
{
	if (nums.size() < 2 || start<0 || end>nums.size())
		return -1;

	int idx = start + std::rand() % (end - start + 1);//随机生成一个[start,end]的整数
	int pivot = nums[idx];
	nums[idx] = nums[0];//相当于把nums[idx]换到首位
	while (start < end) {
		while (start < end && nums[end] >= pivot)
			end--;
		nums[start] = nums[end];
		while (start < end && nums[start] <= pivot)
			start++;
		nums[end] = nums[start];
	}
	nums[start] = pivot;
	return start;
}

void quickSortCore(std::vector<int> &nums, int start, int end)
{
	int mid = Partition(nums, 0, nums.size() - 1);
	if (mid > start)
		quickSortCore(nums, start, mid - 1);
	if (mid < end)
		quickSortCore(nums, mid + 1, end);
}

void quickSort(std::vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	
	quickSortCore(nums, 0, nums.size() - 1);
	return;
}