#include <bits/stdc++.h>
using namespace std;

int num_elems, num_queries;
long long bit[300005];

void add(int idx, int val)
{
    while (idx <= num_elems)
    {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}

long long query(int idx)
{
    long long ret = 0;
    while (idx)
    {
        ret += bit[idx];
        idx -= (idx & (-idx));
    }
    return ret;
}

int main()
{

    vector<long long> divs(1000005, 0);

    for (int i = 1; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            divs[j]++;
        }
    }

    cin >> num_elems >> num_queries;
    set<int> pos;
    vector<long long> arr(num_elems + 5);
    for (int i = 1; i <= num_elems; i++)
    {
        cin >> arr[i];
        add(i, arr[i]);
        if (arr[i] > 2)
        {
            pos.insert(i);
        }
    }

    while (num_queries--)
    {

        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1)
        {

            auto it = pos.lower_bound(l);
            while (it != pos.end() && *it <= r)
            {
                int i = *it;
                long long last = arr[i];
                long long next = divs[arr[i]];
                add(i, next - last);
                arr[i] = next;
                if (next <= 2)
                {
                    it = pos.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        else
        {
            cout << query(r) - query(l - 1) << endl;
        }
    }

    return 0;
}