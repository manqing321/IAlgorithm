#include <iostream>
#include <math.h>

int g_max_value = 6;

void print_probability(int number)
{
    if (number < 1)
    {
        return;
    }
    int *probabilities[2];
    probabilities[0] = new int[g_max_value * number + 1];
    probabilities[1] = new int[g_max_value * number + 1];
    for (int i = 0; i < g_max_value * number + 1; i++)
    {
        probabilities[0][i] = 0;
        probabilities[1][i] = 0;
    }

    int flag = 0;

    for (int i = 1; i <= g_max_value; i++)
    {
        probabilities[flag][i] = 1;
    }
    for (int k = 2; k <= number; k++)
    {
        for (int i = 0; i < k; i++)
        {
            probabilities[1 - flag][i] = 0;
        }
        for (int i = k; i <= g_max_value * k; i++)
        {
            probabilities[1 - flag][i] = 0;
            for (int j = 1; j <= i && j <= g_max_value; j++)
            {
                probabilities[1 - flag][i] += probabilities[flag][i - j];
            }
        }
        flag = 1 - flag;
    }

    double total = pow((double)g_max_value, number);
    for (int i = number; i <= g_max_value * number; i++)
    {
        double ratio = (double)(probabilities[flag][i] / total);
        std::cout << i << ": " << ratio << "\n";
    }
    delete probabilities[0];
    delete probabilities[1];
}

int main()
{
    g_max_value = 6;
    print_probability(2);
}