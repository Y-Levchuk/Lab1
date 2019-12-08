#pragma once
#include"Graph.h"
#include"UserDate.h"
#include <vector>

class ArcGraph;

class MatrixGraph : Graph {
private:
	UserDate*** graph;
	int nvertex;
public:
	MatrixGraph(int n);
	~MatrixGraph();
	void SetNvertex(int nvertex) { this->nvertex = nvertex; }
	int CountVertex() const { return nvertex; }
	int ShortWay(int v1, int v2);
	void AddArc(int v1, int v2, UserDate* date);
	UserDate* HasArc(int v1, int v2) const;
};