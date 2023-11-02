#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using std::bind;
using std::count_if;
using std::equal_to;
using std::map;
using std::string;
using std::vector;
int count_points(string rings)
{
    int R = 1;
    int G = 1 << 1;
    int B = 1 << 2;
    map<int, int> pos_color_dict;
    for (int i = 0; i < rings.size(); ++i)
    {
        char color = rings[i];
        char position = rings[++i];
        switch (color)
        {
        case 'R':
            pos_color_dict[position] |= R;
            break;
        case 'G':
            pos_color_dict[position] |= G;
            break;
        case 'B':
            pos_color_dict[position] |= B;
            break;
        default:
            break;
        }
    }
    auto equal_rgb = [=](std::pair<int, int> p)
    { return p.second == (R | G | B); };
    int cnt = count_if(pos_color_dict.begin(), pos_color_dict.end(), equal_rgb);
    return cnt;
}

int main()
{
    {
        string s = "B0B6G0R6R0R6G9";
        assert(count_points(s) == 1);
    }
    {
        string s = "B0R0G0R9R0B0G0";
        assert(count_points(s) == 1);
    }
    {
        string s = "G4";
        assert(count_points(s) == 0);
    }
    std::cout << "finish" << std::endl;
}