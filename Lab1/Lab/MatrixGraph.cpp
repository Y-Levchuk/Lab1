#include"MatrixGraph.h"
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

/*
	Конструктор класу MatrixGraph
	Приймає як параметр кількість вершин
*/
MatrixGraph::MatrixGraph(int n) {
	graph = new UserDate ** [n * n];
	for (int i = 0; i < n; i++) {
		UserDate** row = graph[i] = new UserDate*[n];
		for (int j = 0; j < n; j++) row[j] = nullptr;		
	}
}

/*
	Деструктор класу MatrixGraph
	Не приймає параметрів
*/
MatrixGraph::~MatrixGraph() { for (int i = 0; i < nvertex; i++) delete graph[i]; }

/*
	Пошук двжини найкорошогу шляху
	Приймає як параметри: номер першої і другої вершини
*/
int MatrixGraph::ShortWay(int s, int v2)
{
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
	int path = 0;
	for (int v = v2; v != -1; v = p[v]) path++;
	return path;
}

/*
	Додавання нового ребра до графу
	Приймає як параметри: номер першої і другої вершини і екземпляру класу UserDate
*/
void MatrixGraph::AddArc(int v1, int v2, UserDate* date)
{
	if (v1 < 0 || v2 >= nvertex || v2 < 0 || v1 >= nvertex) return;
	graph[v1][v2] = date;
}

/*
	Превірка на існування ребра в графі. Якщо існує то повертає вказівник на екземпляр класу UserDate, інакше nullptr
	Приймає як параметри: номер першої і другої вершини
*/
UserDate* MatrixGraph::HasArc(int v1, int v2) const
{
	if (v1 < 0 || v2 >= nvertex || v2 < 0 || v1 >= nvertex) return nullptr;
	else return graph[v1][v2];
}