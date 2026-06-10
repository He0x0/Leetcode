#include <iostream>
#include <vector>


using namespace std;


namespace x213 {
    class Solution {
        public:
        int search(const vector<int>& nums, int target)
        {
            int first = 0, last = nums.size();
            while (first != last)
            {
                int mid = first + (last - first) / 2;
                if (nums[first] <= nums[mid])
                {
                    if (nums[first] < target && target < nums[mid])
                    {
                        last = mid;
                    } else {
                        first = mid + 1;
                    }
                    
                } else {
                    if (nums[mid] < target && target < nums[last - 1])
                    {
                       first = mid + 1;
                    } else {
                        last = mid;
                    }
                    
                }
                
            }
            return -1;
            
        }
    };
}