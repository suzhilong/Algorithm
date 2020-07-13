/*
* 希尔排序：将待排序数组按照步长step进行分组，然后将每组的元素利用直接插入排序的方法进行排序；
*			step初始一般为列表长度的一半；
*			每次将step折半减小，循环上述操作；
*			当step=1时，用直接插入排序完成排序
* 时间复杂度：  最好 O(n*logn)
*				最坏 O(n*(logn)^2)
*				平均 O(n*(logn)^2)
* 空间复杂度： 
*				
* 稳定性：不稳定
*/

#include <vector>

void shellSort(std::vector<int> &nums)
{
	if (nums.size() < 2)
		return;
	int step = nums.size() / 2;
	for (; step > 0; step/=2) {//控制步长
		for (int i = 0; i < step; i++) {//控制组数
			for (int j = i + step; j < nums.size(); j += step) {//组内直接插入排序
				int temp = nums[j];
				while (j > i && nums[j - step] > temp) {
					nums[j] = nums[j - step];
					j -= step;
				}
				nums[j] = temp;
			}
		}
	}
	return;
}