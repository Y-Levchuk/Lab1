#include"MatrixGraph.h"

MatrixGraph::MatrixGraph(int n) {
	graph = new UserDate ** [nvertex * n];
	for (int i = 0; i < n; i++) {
		UserDate** row = graph[i] = new UserDate*[n];
		for (int j = 0; j < n; j++) row[j] = nullptr;		
	}
}

MatrixGraph::~MatrixGraph() {
	for (int i = 0; i < nvertex; i++) delete graph[i];
	delete graph;
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