#include <iostream>
#include <deque>
#include <assert.h>
using std::deque;
template <typename T>
class queue_with_max
{
public:
    queue_with_max() : current_index(0) {}
    void push_back(T number)
    {
        while (!maxs.empty() && maxs.back().number < number)
        {
            maxs.pop_back();
        }
        internal_data inter_data{number, current_index};
        datas.push_back(inter_data);
        maxs.push_back(inter_data);
        current_index++;
    }
    void pop_front()
    {
        if (maxs.empty())
        {
            throw "queue is empty";
        }
        if (maxs.front().index == datas.front().index)
        {
            maxs.pop_front();
        }
        datas.pop_front();
    }
    T max() const
    {
        return maxs.front().number;
    }

private:
    struct internal_data
    {
        T number;
        int index;
    };
    deque<internal_data> datas;
    deque<internal_data> maxs;
    int current_index;
};

int main()
{
    queue_with_max<int> que;
    que.push_back(9);
    que.push_back(1);
    que.push_back(3);
    que.push_back(7);
    que.push_back(5);
    auto max1 = que.max();
    assert(max1 == 9);
    que.pop_front();
    auto max2 = que.max();
    assert(max2 == 7);

    std::cout << "finish" << std::endl;
}