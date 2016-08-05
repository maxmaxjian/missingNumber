#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

class solution
{
  public:
    int missingNumber(const std::vector<int> & nums) {
        int xor1 = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        int xor2 = 1;
        for (int i = 2; i <= (int)nums.size();++i)
            xor2 = std::bit_xor<int>()(xor2, i);

        return std::bit_xor<int>()(xor1, xor2);
    }
};

int main()
{
    std::vector<int> nums{0,1,2};

    solution soln;
    int missingNum = soln.missingNumber(nums);

    std::cout << "The missing number is:\n";
    std::cout << missingNum << std::endl;
}
