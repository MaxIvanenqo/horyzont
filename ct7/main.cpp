#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
struct tour
{
    int start, end;
    bool operator<(const tour &a) const
    {
        return end < a.end;
    }
};

int main()
{
    int n = 0;
    std::cin >> n;
    tour t[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> t[i].start >> t[i].end;
    }
    std::sort(t, t+n);

    int count = 0;

    for (int i = 0, g = 0; i < n; ++i)
    {
        if (g < t[i].start)
        {
            count++;
            g = t[i].end;
        }
    }
    std::cout<<count<<std::endl;

    return 0;
}