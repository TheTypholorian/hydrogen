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

    template <typename T>
    static char toHexChar(T t) {
        switch (t) {
        case 0: {
            return '0';
        }
        case 1: {
            return '1';
        }
        case 2: {
            return '2';
        }
        case 3: {
            return '3';
        }
        case 4: {
            return '4';
        }
        case 5: {
            return '5';
        }
        case 6: {
            return '6';
        }
        case 7: {
            return '7';
        }
        case 8: {
            return '8';
        }
        case 9: {
            return '9';
        }
        case 10: {
            return 'A';
        }
        case 11: {
            return 'B';
        }
        case 12: {
            return 'C';
        }
        case 13: {
            return 'D';
        }
        case 14: {
            return 'E';
        }
        case 15: {
            return 'F';
        }
        }

        return '?';
    }

    template <typename T>
    static string toHex(T t) {
        int len = sizeof(T) * 2;
        string string(len, '0');

        for (int i = 0, j = 0; i < len; i++, j += 4) {
            string[len - i - 1] = toHexChar((t >> j) & 0xF);
        }

        return string;
    }
}