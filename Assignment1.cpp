#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

queue<int> que[1001];

int main()
{
    int senro = 1;
    int numTeams;
    while (cin >> numTeams, numTeams)
    {
        for (int t = 0; t < numTeams; ++t)
        {
            while (!que[t].empty())
                que[t].pop();
            int numElem;
            cin >> numElem;
            while (numElem--)
            {
                int elem;
                cin >> elem;
                arr[elem] = t;
            }
        }

        queue<int> Q;

        cout << "Scenario #" << senro << '\n';
        senro++ ;

        string str;
        while (cin >> str, str[0] != 'S')
        {
            if (str[0] == 'E')
            {
                int num;
                cin >> num;
                int team = arr[num];
                if (que[team].empty())
                {
                    Q.push(team);
                }
                que[team].push(num);
            }
            else
            {
                int team = Q.front();
                cout << que[team].front() << '\n';
                que[team].pop();
                if (que[team].empty())
                    Q.pop();
            }
        }
        cout << '\n';
    }
}
