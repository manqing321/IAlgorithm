#include <iostream>

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

void reverse_sentence(char *str)
{
    char *beg = str;
    char *end = str;
    while (*end != '\0')
    {
        end++;
    }
    end--;
    reverse(beg, end);
    beg = end = str;
    while (*beg != '\0')
    {
        if (*beg == ' ')
        {
            beg++;
            end++;
        }
        else if (*end == ' ' || *end == '\0')
        {
            reverse(beg, --end);
            beg = ++end;
        }
        else
        {
            end++;
        }
    }
}

int main()
{
    char s[] = "I am a student.";
    std::cout << s << std::endl;
    reverse_sentence(s);
    std::cout << s << std::endl;
}