/*
* 堆排序：
* 大根堆：每个节点的值都大于或等于其子节点的值，用于升序排列；
* 小根堆：每个节点的值都小于或等于其子节点的值，用于降序排列。
*	1. 将序列建立成大顶堆
*	2. 取根节点（最大值）与末尾元素交换
*	3. 将交换后的n-1和序列调整成大顶堆
*	一直重复2、3步骤
* 
* 时间复杂度：  最好 O(nlogn)
*				最坏 O(nlogn)
*				平均 O(nlogn)
*
* 空间复杂度： O(1)
*
* 稳定性：不稳定
*/

#include <vector>

void adjustHeap(std::vector<int> &nums, int parents, int end)
{
	/*
	将以parents为根节点的子树调整为大根堆，
	因为每调整一次，就有一个最大值到位，
	end是nums中待排堆d的尾序号;
	可以用递归和循环实现，但是递归容易栈溢出。
	*/
	//非叶子结点parents的两个子节点（假设都存在）
	int lchild = 2 * parents + 1;
	int rchild = 2 * parents + 2;
	int maxIdx = parents;
	if (lchild <= end && nums[maxIdx] < nums[lchild]) 
		maxIdx = lchild;
	if (rchild <= end && nums[maxIdx] < nums[rchild])
		maxIdx = rchild;
	if (maxIdx != parents) {
		int temp = nums[parents];
		nums[parents] = nums[maxIdx];
		nums[maxIdx] = temp;
		//交换之后，nums[maxIdx]应该是较小的元素，所以应该向下继续调整
		adjustHeap(nums, maxIdx, end);
	}
}


void buildHeap(std::vector<int> &nums)
{//建堆
	for (int i = nums.size() / 2 - 1; i >= 0; i--) {
		//从倒数第一个非叶子结点开始调整
		adjustHeap(nums, i, nums.size() - 1);
	}
}


void heapSort(std::vector<int> &nums)
{//以大根堆为例
	if (nums.size() < 2)
		return;

	buildHeap(nums);

	for (int i = nums.size() - 1; i > 0; i--) {
		//从最后一个索引往前遍历，依次把大根堆的最大元素与指针交换
		int temp = nums[i];
		nums[i] = nums[0];
		nums[0] = temp;
		//交换之后待排序序列中的最大值放到指针处，调整堆时待排序列最后索引end要减1
		adjustHeap(nums, 0, i - 1);
	}
	return;
}