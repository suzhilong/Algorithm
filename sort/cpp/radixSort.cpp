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
#include <cmath>

void radixSort(std::vector<int> &nums, int radix = 10)
{
	/*radix是基数，可以为任意进制，缺省10
	此方法为LSD
	此方法不能处理负数，序列有负数还需进一步改进*/
	if (nums.size() < 2)
		return;

	int maxn = 0;
	for(int n:nums)
		maxn = std::max(maxn, n);
	
	int K = 0;
	while(maxn>0){
		K++;
		maxn /= radix;
	}

	for (int i = 1; i <= K;i++){
		std::vector<std::vector<int> > buckets(radix);
		for(int n:nums){
			int j = (n % (int)pow(radix, i)) / (int)pow(radix, i - 1);
			buckets[j].push_back(n);
		}
		nums.clear();
		for(auto bucket:buckets){
			for(int n:bucket)
				nums.push_back(n);
		}
	}
	return;
}
