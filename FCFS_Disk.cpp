#include <iostream>
#include <algorithm>
int fcfs(int a[], int n, int pt)
{
    int t = 0, i;
    std::cout << "\nTrack movements are as follows : " << std::endl<< pt;
    for (i = 0; i < n; i++)
    {
        t += (pt < a[i] ? a[i] - pt : pt - a[i]);
        pt = a[i];
        std::cout << " -> " << pt;
    }
    return t;
}
int sstf(int a[], int n, int pt)
{
    int t = 0, i, j, min;
    int b[100];
    for (j = 0; j < n; j++)
    {
        b[j] = a[j];
    }
    std::cout << "\nTrack movements are as follows : " << std::endl
              << pt;
    while (n != 0)
    {
        min = 199;
        for (j = 0; j < n; j++)
        {
            if ((pt < b[j] ? b[j] - pt : pt - b[j]) < min)
            {
                min = (pt < b[j] ? b[j] - pt : pt - b[j]);
                i = j;
            }
        }
        pt = b[i];
        for (j = i; j < n - 1; j++)
        {
            b[j] = b[j + 1];
        }
        n -= 1;
        t += min;
        std::cout << " -> " << pt;
    }
    return t;
}
int scan_look(int a[], int n, int pt, char c, char k)
{
    int t = 0, i, j;
    int b[100];
    for (j = 0; j < n; j++)
    {
        b[j] = a[j];
    }
    b[n] = pt;
    int head = pt;
    if (k != 'l')
    {
        b[n + 1] = 0;
        b[n + 2] = 199;
        n += 2;
    }
    std::sort(b, b + n + 1);
    std::cout << "\nTrack movements are as follows : " << std::endl
              << pt;
    if (c == 'u')
    {
        for (i = 0; i < n + 1; i++)
        {
            if (b[i] >= head)
            {
                t += (pt < b[i] ? b[i] - pt : pt - b[i]);
                pt = b[i];
                std::cout << " -> " << pt;
            }
        }
        if (k == 'c')
        {
            for (i = 0; i < n + 1; i++)
            {
                if (b[i] == head)
                {
                    break;
                }
                t += (pt < b[i] ? b[i] - pt : pt - b[i]);
                pt = b[i];
                std::cout << " -> " << pt;
            }
            return t;
        }
        for (i = n; i >= 0; i--)
        {
            if (b[i] >= head)
            {
                continue;
            }
            if (i == 0 && k != 'l')
            {
                break;
            }
            t += (pt < b[i] ? b[i] - pt : pt - b[i]);
            pt = b[i];
            std::cout << " -> " << pt;
        }
    }
    else
    {
        for (i = n; i >= 0; i--)
        {
            if (b[i] > head)
            {
                continue;
            }
            t += (pt < b[i] ? b[i] - pt : pt - b[i]);
            pt = b[i];
            std::cout << " -> " << pt;
        }
        if (k == 'c')
        {
            for (i = n; i >= 0; i--)
            {
                if (b[i] == head)
                {
                    break;
                }
                t += (pt < b[i] ? b[i] - pt : pt - b[i]);
                pt = b[i];
                std::cout << " -> " << pt;
            }
            return t;
        }
        for (i = 0; i < n + 1; i++)
        {
            if (b[i] <= head)
            {
                continue;
            }
            if (i == n + 1 && k != 'l')
            {
                break;
            }
            t += (pt < b[i] ? b[i] - pt : pt - b[i]);
            pt = b[i];
            std::cout << " -> " << pt;
        }
    }
    return t;
}
int main()
{
    int s, a[100], pt, n, i, t;
    char c;
    std::cout << "Number of requests : ";
    std::cin >> n;
    std::cout << "\nWrite all requests one by one (tracks are from 0-199): ";
    for (i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cout << "\nHead is currently at : ";
    std::cin >> pt;
    while (true)
    {
        std::cout << "\nWhat algorithm to use?" << std::endl;
        std::cout << "1)FCFS\n2)SSTF\n3)SCAN\n4)CSCAN\n5)LOOK" << std::endl;
        std::cout << "Your choice : ";
        std::cin >> s;
        switch (s)
        {
        case 1:
            t = fcfs(a, n, pt);
            std::cout << "\nTotal seek time is: " << t;
            break;
        case 2:
            t = sstf(a, n, pt);
            std::cout << "\nTotal seek time is: " << t;
            break;
        case 3:
            std::cout << "\nDirection (u = up & d = down): ";
            std::cin >> c;
            t = scan_look(a, n, pt, c, 's');
            std::cout << "\nTotal seek time is: " << t;
            break;
        case 4:
            std::cout << "\nDirection (u = up & d = down): ";
            std::cin >> c;
            t = scan_look(a, n, pt, c, 'c');
            std::cout << "\nTotal seek time is: " << t;
            break;
        case 5:
            std::cout << "\nDirection (u = up & d = down): ";
            std::cin >> c;
            t = scan_look(a, n, pt, c, 'l');
            std::cout << "\nTotal seek time is: " << t;
            break;
        default:
            exit(0);
            break;
        }
    }
}
