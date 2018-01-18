#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compar{
    bool operator()(const int& a,const int& b)
    {
        return a < b;
    }
};

int main (void)
{
    priority_queue<int, vector <int>, Compar> q;

    q.push(28);
    q.push(34);
	q.push(23);
    q.push(29);

	while(!q.empty())
	{
		int c1= q.top();
		cout << c1 << " " << endl;
		q.pop();
	}



	return 0;
}


