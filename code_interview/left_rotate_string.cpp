#include <iostream>
#include <assert.h>
#include <string.h>
#include <string>
void reverse(char *beg, char *end)
{
    if (beg == nullptr || end == nullptr)
    {
        return;
    }
    while (beg < end)
    {
        char temp = *beg;
        *beg = *end;
        *end = temp;
        beg++;
        end--;
    }
}

void left_rotate_string(char *s, int k)
{
    if (s == nullptr)
    {
        return;
    }
    int len = strlen(s);
    if (len <= 0 || k <= 0 || k > len)
    {
        return;
    }
    // 先翻转左边和右边
    reverse(s, s + k - 1);
    reverse(s + k, s + len - 1);
    // 再整个翻转过来
    reverse(s, s + len - 1);
}

int main()
{
    char arr[] = "abcdefg";
    char target[] = "cdefgab";
    left_rotate_string(arr, 2);
    std::cout << "actual: " << std::string(std::begin(arr), std::end(arr)) << std::endl;
    std::cout << "target: " << std::string(std::begin(target), std::end(target)) << std::endl;
    assert(strcmp(arr, target) == 0);

    std::cout << "finish" << std::endl;
}