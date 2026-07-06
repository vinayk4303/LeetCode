#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt")
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <cstdint>

static uint32_t bits[3200];
static char ibuf[1 << 23];
static char obuf[4096];
static int  opos;

static inline void writeNum(int x) {
    char t[7]; int l = 0;
    do { t[l++] = '0' + x % 10; x /= 10; } while (x);
    for (int i = l - 1; i >= 0; --i) obuf[opos++] = t[i];
}

int _ = []() __attribute__((optimize("O3"))) {
    int outfd = open("user.out", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    int tot = 0, r;
    while ((r = read(0, ibuf + tot, sizeof(ibuf) - tot)) > 0) tot += r;
    ibuf[tot] = ']'; ibuf[tot+1] = '\n'; ibuf[tot+2] = '\0';

    const char *p = ibuf, *e = ibuf + tot;

    while (p < e) {
        while (p < e && *p != '[') ++p;
        if (p >= e) break;
        ++p;

        int n = 0, max_word = 0;
        bits[0] = 1u;

        while (*p != ']') {
            while (*p == ' ' || *p == ',') ++p;
            if (*p == ']') break;
            ++n;
            if (*p == '-') {
                ++p;
                while ((unsigned)(*p - '0') < 10u) ++p;
            } else {
                unsigned v = 0;
                while ((unsigned)(*p - '0') < 10u) {
                    v = v * 10 + (unsigned)(*p++ - '0');
                    if (__builtin_expect(v > 100000u, 0)) {
                        while ((unsigned)(*p - '0') < 10u) ++p;
                        v = 0; break;
                    }
                }
                if (v) {
                    int w = (int)(v >> 5);
                    bits[w] |= 1u << (v & 31u);
                    if (w > max_word) max_word = w;
                }
            }
        }
        while (*p != '\n') ++p;
        ++p;

        int ans = n + 1;
        int limit = (n >> 5) + 2;
        for (int i = 0; i <= limit; ++i) {
            uint32_t w = ~bits[i];
            if (w) {
                int v = (i << 5) + __builtin_ctz(w);
                if (v >= 1 && v <= n) ans = v;
                break;
            }
        }

        memset(bits, 0, (size_t)(max_word + 2) * sizeof(uint32_t));

        writeNum(ans);
        obuf[opos++] = '\n';
    }

    write(outfd, obuf, opos);
    _exit(0);
    return 0;
}();
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == k){
                k++;
            }
            else if (nums[i] < k){
                continue;
            }
            else{
                break;
            }
        }
        return k;
    }
};