#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace Hex0x1 {
    class Solution {
    public: 
    int removeDuplication(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        int index = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
};
}

namespace Hex0x3 {
    class Solution {
        public:
        int removeDuplication(vector<int>& nums)
        {
            return std::distance(nums.begin(), std::unique(nums.begin(), nums.end()));
        }
    };
}


namespace Hex0x2 {
    class Solution {
        public:
        int removeDuplication(vector<int>& nums)
        {
            if(nums.size() < 2) return nums.size();
            int index = 1;
            for(int i = 1; i < nums.size(); ++i)
            {
                if (nums[i] != nums[i-1])
                {
                    nums[index] = nums[i];
                    index++;
                }
                
            }
            return index;
        }
    };
}

int main()
{
    Hex0x1::Solution sol1;
    Hex0x2::Solution sol2;
    // 1. 定义一个原始的、不可变的测试数据
    const std::vector<int> original_nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // 2. 为第一个测试创建一个副本
    std::vector<int> nums1 = original_nums;
    std::cout << "--- Testing Hex0x1 ---" << std::endl;
    std::cout << "Original vector size: " << nums1.size() << std::endl;
    int len1 = sol1.removeDuplication(nums1);
    std::cout << "len1: " << len1 << std::endl;
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < len1; ++i) {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl << std::endl;
    // 3. 为第二个测试创建另一个全新的副本
    std::vector<int> nums2 = original_nums;
    std::cout << "--- Testing Hex0x2 ---" << std::endl;
    std::cout << "Original vector size: " << nums2.size() << std::endl;
    int len2 = sol2.removeDuplication(nums2);
    std::cout << "len2: " << len2 << std::endl;
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < len2; ++i) {
        std::cout << nums2[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}