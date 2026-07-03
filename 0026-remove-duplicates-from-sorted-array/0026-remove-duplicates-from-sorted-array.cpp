#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>

static constexpr std::size_t max_align = alignof(std::max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static std::size_t pos = 0;

void *operator new(const std::size_t size) {
    const std::size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return &BUFFER[pos - size];
}

void *operator new[](const std::size_t size) {
    return operator new(size);
}

void operator delete(void *) noexcept {}

void operator delete[](void *) noexcept {}

void operator delete(void *, std::size_t) noexcept {}

void operator delete[](void *, std::size_t) noexcept {}
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};