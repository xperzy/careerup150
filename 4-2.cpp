/*
	Harsh Vardhan (harshvd95@gmail.com)
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[1000];
bool visited[1010];

bool bfs(int start, int end)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty())
	{
		int tmp = q.front();
		q.pop();
		visited[tmp] = true;
		for(int i = 0; i < graph[tmp].size(); i++)
		{
			int curr = graph[tmp][i];
			if(curr == end) return true;
			if(!visited[curr])
			{
				q.push(curr);
			}
		}
	}
	return false;
}


int main() 
{
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
	}
	int start,end;
	cin >> start >> end; 
	if(bfs(start, end))
	{
		cout << "There's a path!";
	}
	else 
	{
		cout << "No path :/";
	}
	return 0;
}