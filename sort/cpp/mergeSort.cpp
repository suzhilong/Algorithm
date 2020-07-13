/*
* 归并排序：采用分治法：
*			分割：递归地把当前序列平均分割成两半。
*			集成：在保持元素顺序的同时将上一步得到的子序列集成到一起（归并）。
* 时间复杂度：  最好 O(nlogn)
*				最坏 O(nlogn)
*				平均 O(nlogn)
*
* 空间复杂度： O(n)
*
* 稳定性：稳定
*/

#include <vector>

std::vector<int> merge2ordered(std::vector<int> &left, std::vector<int> &right)
{
	std::vector<int> res;
	int L = 0, R = 0;
	while (L < left.size() && R < right.size())
	{
		if (left[L] <= right[R]) {
			res.push_back(left[L]);
			L++;
		} else {
			res.push_back(right[R]);
			R++;
		}
	}
	if (L < left.size())
		res.insert(res.end(), left.begin() + L, left.end());
	if (R < right.size())
		res.insert(res.end(), right.begin() + R, right.end());
	return res;
}

void mergeSort(std::vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	int mid = nums.size() / 2;
	std::vector<int> left(nums.begin(), nums.begin() + mid);
	std::vector<int> right(nums.begin() + mid, nums.end());
	mergeSort(left);
	mergeSort(right);
	nums = merge2ordered(left, right);
	return;
}