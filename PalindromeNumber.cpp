#include <iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        int y = x;
        int z = 0;
        while (y > 9)
        {
            z *= 10;
            z += y % 10;
            y /= 10;
        }

        cout<<z<<" "<<y;
        return z == x / 10 && y == x % 10;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(1001);
    cout << "Hello world!" << endl;
    return 0;
}
