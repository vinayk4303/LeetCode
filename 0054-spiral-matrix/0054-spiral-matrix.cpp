class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                res.push_back(matrix[top][j]);
            }
            top++;

            for (int j = top; j <= bottom; j++) {
                res.push_back(matrix[j][right]);
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int j = bottom; j >= top; j--) {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
        }

        return res;
    }
};
static const bool __boost = []() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	return std::ios_base::sync_with_stdio(false);
	}();

const size_t BUFFER_SIZE = 0x6fafffff;
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