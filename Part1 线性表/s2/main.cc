#include <iostream>
#include <vector>


using namespace std;

namespace x212 {

	class Solution {
	public:
		/**
		 * @brief 经典双指针解法 (推荐)
		 * index 是写入指针，i 是读取指针。
		 * 只有当 nums[i] 与已确认的有效数组的倒数第二个元素 nums[index-2] 不同时，
		 * 才说明 nums[i] 是一个可以被接纳的元素。
		 */
		int removeDuplication(vector<int>& nums)
		{
			if (nums.size() <= 2) return nums.size();
			int index = 2; // index 指向下一个可以写入的位置
			for (int i = 2; i < nums.size(); ++i)
			{
				if (nums[i] != nums[index - 2])
				{
					nums[index++] = nums[i];
				}
			}
			return index;
		}

		/**
		 * @brief 另一种思路的解法
		 * 遍历数组，识别出那些“连续三个或以上相同元素”中的“中间元素”，然后跳过它们。
		 * 比如在 [1,1,1] 中，第二个 1 会被跳过。
		 * 这种方法也是正确的，但逻辑稍微绕一点。
		 */
		int v2(vector<int>& nums)
		{
			const int n = nums.size();
			int index = 0;
			for (int i = 0; i < n; ++i)
			{
				// 如果当前元素是连续三个或更多相同元素的其中一个 (不是第一个也不是最后一个)，则跳过
				if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
					continue;
				
				// 否则，将该元素保留
				nums[index++] = nums[i];
			}
			return index;
		}
	};

} // namespace x212

// 辅助函数，用于打印 vector 的前 len 个元素
void printVector(const string& label, const vector<int>& nums, int len) {
	cout << label;
	cout << "[";
	for (int i = 0; i < len; ++i) {
		cout << nums[i];
		if (i < len - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}


int main() {
	x212::Solution s;

	// --- 创建一些测试用例 ---
	vector<vector<int>> testCases = {
		{1, 1, 1, 2, 2, 3},              // 题目示例
		{0, 0, 1, 1, 1, 1, 2, 3, 3, 3},  // 更复杂的重复
		{},                               // 空数组
		{1},                              // 单个元素
		{1, 1},                           // 两个元素
		{1, 1, 1, 1, 1},                  // 所有元素都一样
		{1, 2, 3, 4, 5}                   // 没有重复元素
	};

	int testNum = 1;
	for (auto& original_nums : testCases) {
		cout << "=============== Test Case " << testNum++ << " ===============\n";
		printVector("Original array: ", original_nums, original_nums.size());
		cout << endl;

		// 因为函数会原地修改数组，所以为每个方法创建一个副本
		vector<int> nums_for_v1 = original_nums;
		vector<int> nums_for_v2 = original_nums;

		// --- 测试你的第一个方法: removeDuplication ---
		cout << "--- Testing removeDuplication (your primary solution) ---" << endl;
		int len1 = s.removeDuplication(nums_for_v1);
		cout << "Return length: " << len1 << endl;
		printVector("Modified array: ", nums_for_v1, len1);
		cout << endl;

		// --- 测试你的第二个方法: v2 ---
		cout << "--- Testing v2 ---" << endl;
		int len2 = s.v2(nums_for_v2);
		cout << "Return length: " << len2 << endl;
		printVector("Modified array: ", nums_for_v2, len2);

		cout << "=============================================\n\n";
	}

	return 0;
}