#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int T, vector<int>& house, int d) {
    int n = house.size();
    int groups = 0;
    int current_l = 0;

    while (current_l < n) {
        groups++;
        if (groups > d) return false;

        int max_r = current_l;
        int next_l = current_l;

        while (next_l < n) {
            int k = next_l - current_l + 1;
            if (house[next_l] + 2 * k <= T) {
                max_r = next_l;
                next_l++;
            } else {
                break;
            }
        }

        int k_group = max_r - current_l + 1;
        if (house[max_r] + 2 * k_group > T) {
            return false;
        }

        current_l = max_r + 1;
    }
    return true;
}

int computeMinTime(vector<int> house, int d) {
    sort(house.begin(), house.end());
    int n = house.size();

    if (d >= n) {
        return house.back() + 2;
    }

    int low = 0, high = 2 * n + house.back();

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid, house, d)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
int f(int x){cout<<x;cout<<"\n"; return x;}
int g(int y){cout<<y;cout<<"\n"; return y;}
// Example usage:
void fun(int x,int y){  
    f(x);
    g(y);
}
int main() {
    //  fun(f(10),g(20));
    // phle 20 wala
    // cout<<
    int a=log2(2)+1;
    cout<<a;

    return 0;
}
