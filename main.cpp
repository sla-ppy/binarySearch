#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                          20}; // 22 elements,   0 - 21 in array
    int target{19};

    // check if target exists
    bool targetExists{false};

    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (*it == target) {
            targetExists = true;
        }
    }

    // get middle ground
    int half = nums.size() / 2;     // 5
    std::cout << "Size of array: " << half << std::endl;

    bool targetFound{false};
    while (!targetFound) {
        if (targetExists) {
            // check which half to take
            if (half > target) {
                std::cout << "Target is lower." << std::endl;

                // get remainder
                int remainder = nums.size() - half;

                half -= remainder / 2;       // 3
            } else if (half < target) {
                std::cout << "Target is higher." << std::endl;

                int remainder = nums.size() - half;

                half += remainder / 2;       // 7
            } else {
                std::cout << std::endl;
                std::cout << "Target exists!" << std::endl;
                std::cout << "Target was: " << nums[half + 1] << std::endl;
                std::cout << "Target's index value: " << half + 1 << std::endl;

                targetFound = true;
            }
        } else {
            return -1;
        }
    }
    return 0;
}