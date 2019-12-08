#include"MatrixGraph.h"
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

MatrixGraph::MatrixGraph(int n) {
	graph = new UserDate ** [n * n];
	for (int i = 0; i < n; i++) {
		UserDate** row = graph[i] = new UserDate*[n];
		for (int j = 0; j < n; j++) row[j] = nullptr;		
	}
}

MatrixGraph::~MatrixGraph() {
	//for (int j = 0; j < nvertex; j++) for (int i = 0; i < nvertex; i++) if(graph[i][j]!=0)delete graph[i][j];
	for (int i = 0; i < nvertex; i++) delete graph[i];
	//delete[] graph;
}

int MatrixGraph::ShortWay(int s, int v2)
{
	//UserDate*** graph = this->GetGraph();
	int n = this->CountVertex();
	int g[10][10]; 
	for (size_t i = 0; i < n; i++) 
		for (size_t j = 0; j < n; j++) {
			int tmp = !(graph[i][j] == nullptr);
			g[i][j] = tmp;
		}
	queue<int> q;
	q.push(s);
	vector<bool> used(n);
	vector<int> d(n), p(n);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t i = 0; i < n; ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}
	//if (!used[v2]) return -1;
	//else 
	{
		int path = 0;
		for (int v = v2; v != -1; v = p[v]) path++;
		return path;
	}
}

void MatrixGraph::AddArc(int v1, int v2, UserDate* date)
{
	if (v1 < 0 || v2 >= nvertex || v2 < 0 || v1 >= nvertex) return;
	graph[v1][v2] = date;
}

UserDate* MatrixGraph::HasArc(int v1, int v2) const
{
	if (v1 < 0 || v2 >= nvertex || v2 < 0 || v1 >= nvertex) return nullptr;
	else return graph[v1][v2];
}