#include <iostream>
#include <vector>
using namespace std;
// slow and fast pointer approach

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0], fast = nums[0];

    do
    {
        slow = nums[slow];       // +1
        fast = nums[nums[fast]]; // +2
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow]; // +1
        fast = nums[fast]; // +1
    }

    return slow;
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};

    cout << findDuplicate(nums) << endl;

    return 0;
}