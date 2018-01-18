#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct client
{
	string name;
	int priority;
};

struct Compare{
    bool operator()(const client& a,const client& b)
    {
        return a.priority > b.priority;
    }
};




int main (void)
{
    priority_queue<client, vector <client>, Compare> q;

	client c;

	c.name = "Mridha";
	c.priority = 1;
	q.push(c);

	c.name = "Chowdhury";
	c.priority = 3;
	q.push(c);

	c.name = "Ibtasham";
	c.priority = 1;
	q.push(c);

	c.name = "Noshin";
	c.priority = 4;
	q.push(c);

	c.name = "Anika";
	c.priority = 4;
	q.push(c);

	while(!q.empty())
	{
		client c1= q.top();
		cout << c1.name << " " << c1.priority << endl;
		q.pop();
	}

	/*
	priority_queue <int> pQ;
	pQ.push(4);
	pQ.push(11);
	pQ.push(3);
	pQ.push(15);
	pQ.push(1);

	cout << pQ.size() << endl;
	 mypq.push(40);
	while(!pQ.empty())
	{
		cout << pQ.top() << endl;
		pQ.pop();
	}
	*/

	return 0;
}
