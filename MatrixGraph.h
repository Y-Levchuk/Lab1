#pragma once
#include"Graph.h"
#include"UserDate.h"

class ArcGraph;

class MatrixGraph : Graph {
private:
	UserDate*** graph;
	int nvertex;
public:
	MatrixGraph(int n);
	~MatrixGraph();
	int CountVertex() const { return nvertex; }
	void AddArc(int v1, int v2, UserDate* date);
	UserDate* HasArc(int v1, int v2) const;
};