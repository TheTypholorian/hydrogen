#include "hydrogen.hpp"
#include <string>

using namespace std;

namespace H {
    template <typename T>
    static string toBinary(T t) {
        int len = sizeof(T) * 8;
        string string(len, '0');

        for (int i = 0; i < len; i++) {
            string[len - i - 1] = ((t >> i) & 1) ? '1' : '0';
        }

        return string;
    }
}