#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <cmath>
using namespace std;

bool verify(vector<vector<int>> &heights, int height)
{
    vector<pair<int, int>> changes{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int row = heights.size();
    const int col = heights[0].size();
    vector<int> visited(row * col, 0);
    queue<int> que;
    que.push(0);
    visited[0] = 1;
    while (!que.empty())
    {
        int r = que.front() / col;
        int c = que.front() % col;
        if (r == row - 1 && c == col - 1)
        {
            return true;
        }
        que.pop();
        for (auto &change : changes)
        {
            int nr = r + change.first;
            int nc = c + change.second;
            if (nr < 0 || nc < 0 || nr >= row || nc >= col)
            {
                continue;
            }
            int idx = nr * col + nc;
            if (!visited[idx] && abs(heights[r][c] - heights[nr][nc]) <= height)
            {
                visited[idx] = 1;
                que.push(idx);
            }
        }
    }
    return false;
}

int minimum_effort_path(vector<vector<int>> &heights)
{
    int beg = 0;
    int end = 999999;
    while (beg < end)
    {
        int mid = (beg + end) >> 1;
        bool is_verify = verify(heights, mid);
        if (!is_verify)
        {
            beg = mid + 1;
            continue;
        }
        if (!mid || !verify(heights, mid - 1))
        {
            return mid;
        }
        end = mid - 1;
    }
    return end;
}

int main()
{
    // test 01
    {
        vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
        int target = 2;
        int actual = minimum_effort_path(heights);
        assert(actual == target);
    }
    // test 02
    {
        vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
        int target = 1;
        int actual = minimum_effort_path(heights);
        assert(actual == target);
    }
    // test 03
    {
        vector<vector<int>> heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
        int target = 0;
        int actual = minimum_effort_path(heights);
        assert(actual == target);
    }
    // test 03
    {
        vector<vector<int>> heights = {{3}};
        int target = 0;
        int actual = minimum_effort_path(heights);
        assert(actual == target);
    }
    cout << "finish" << endl;
}
