/*
* 基数排序：将数按位数切割成不同的数字，然后按每个位数分别比较
* 
* 基数排序有两种方法：
*	MSD（主位优先法）：从高位开始进行排序，再逐个对各分组按次高位进行子排序
*	LSD（次位优先法）：从低位开始进行排序
*
* 时间复杂度：  最好 O(nk) k是基数的底
*				最坏 O(nk)
*				平均 O(nk)
*
* 空间复杂度： O(1)
*
* 稳定性：稳定
*/

#include <vector>

void radixSort(std::vector<int> &nums, int radix = 10)
{
	/*radix是基数，可以为任意进制，缺省10
	此方法为LSD
	此方法不能处理负数，序列有负数还需进一步改进*/

}