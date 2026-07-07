class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long place = 1;
        long long number = 0;
        while(n > 0){
            int digit = n % 10;
            if (digit != 0 ){
                number += digit * place;
                place *= 10;
                sum += digit;
            }
            n /= 10;
        }
        return number * sum;
    }
};
static const bool __boost = []() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return std::ios_base::sync_with_stdio(false);
}();
const size_t BUFFER_SIZE = 0x3000000;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}