//迪杰斯特拉优化 
#include<iostream>
#include <queue>
#include<string.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1000010;
int book[100000];
int exists[100000];

struct qnode
{
	int v;
	int c;
	qnode(int _v=0,int _c=0):v(_v),c(_c){
	}
	bool operator <(const qnode &r)const
	{
		return c>r.c;
	}
};

struct Edge
{
	int v,cost;
	Edge(int _v,int _cost):v(_v),cost(_cost){
	}
};

vector<Edge> E[MAXN];
bool vis[MAXN];
int dist[MAXN];

void Dijkstra(int n,int start)
{
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		dist[i] = INF;
		
	priority_queue<qnode> que;
	while(!que.empty())
	{
		que.pop();
	}
	
	dist[start] = 0;
	que.push(qnode(start,0));
	qnode tmp;
	
	while(!que.empty())
	{
		tmp = que.top();
		que.pop();
		int u = tmp.v;
		if(vis[u])
			continue;
		vis[u] = true;
		
		for(int i=0;i<E[u].size();i++)
		{
			int v = E[tmp.v][i].v;
			int cost = E[u][i].cost;
			if(!vis[v]&&dist[v]>dist[u]+cost)
			{
				dist[v] = dist[u] + cost;
				que.push(qnode(v,dist[v]));
			}
		}
	}
}

void addedge(int u,int v,int w)
{
	E[u].push_back(Edge(v,w));
}

int main()
{
	int n,k,x,y,p,q;
	cin >> n >> k;
	for(int i=0;i<k;i++)
	{
		cin >> x >> y;
		addedge(x,y,1);
		if(y==1)
		{
			book[x] = 1;
		}
	}	

	Dijkstra(n,1);
	
	int minpoint;
	int mins = 100000;
	for(int j=2;j<=n;j++)
	{
		//cout << dist[j] << endl;
		if(dist[j]<mins&&book[j])
		{
			mins = dist[j];
			minpoint = j;
		}			
	}
	cout << dist[minpoint]+1 << endl;
	
} 
