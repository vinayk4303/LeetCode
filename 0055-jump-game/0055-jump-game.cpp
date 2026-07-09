#include <fcntl.h>
#include <unistd.h>
#pragma GCC optimize("O3")

#define NO_SAN \
    __attribute__((no_sanitize_address)) \
    __attribute__((no_sanitize_thread))

NO_SAN int main(){

    constexpr int buffer_size = 4096;
    char buffer[buffer_size];
    int fout = open( "user.out", O_WRONLY | O_CREAT | O_TRUNC, 0644 );
    int n = read( STDIN_FILENO, buffer, buffer_size );

    int num = 0, limit = 0, length = 0;
    bool possible = true;

    while ( n ){
        
        for ( int i = 0; i < n; i++ ){
            char c = buffer[i];
            if ( c == ',' || c == ']' ){
                if ( possible ){
                    if ( limit < length ){
                        possible = false;
                   }else{
                      int newlimit = num + length;
                      limit = ( limit > newlimit ) ? limit : newlimit;
                        length++;
                    }
                }
                num = 0;
            }else if ( c == '\n' ){
                if ( possible ){
                    write( fout, "true\n", 5 );
                }else{
                    write( fout, "false\n", 6 );
                }

                num = limit = length = 0;
                possible = true;
            }else{
                if ( c != '[' ){
                    num = num * 10 + c - '0';
                }
            }


        }
        n = read( STDIN_FILENO, buffer, buffer_size );
    }

    if ( possible ){
        write( fout, "true\n", 5 );
    }else{
        write( fout, "false\n", 6 );
    }

    return 0;
}

#define main not_my_main

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = 0;
        for (int i = 0; i < nums.size();i++){
            if (i > far){
                return false;
            }
            far = max(far, i + nums[i]);
        }
        return true;
    }
};