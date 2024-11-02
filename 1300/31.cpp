#include <iostream>
#include <cstring>

const int N = 200200;

int n;
char s[N];

bool read() {
    if (!std::cin.getline(s, N)) return false;
    n = static_cast<int>(std::strlen(s));
    return true;
}

void solve() {
    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && s[j] == s[i]) j++;
        char c = 'a';
        while (c == s[i] || (i > 0 && c == s[i - 1]) || (j < n && c == s[j]))
            c++;
        for (int k = i; k < j; ++k)
            if ((i + k) % 2 == 1)
                s[k] = c;
    }
    std::cout << s << std::endl;
}

int main() {
    while (read()) {
        solve();
    }
    return 0;
}
