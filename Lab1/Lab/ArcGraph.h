#pragma once
#include<stdlib.h>
#include "Graph.h"
#include"UserDate.h"

class MatrixGraph;

class ArcGraph {
	struct Arc {
		int beg, end;
		Arc* next;
		Arc(int _v1, int _v2, Arc* n = 0) :beg(_v1), end(_v2), next(n) {}
	};
	Arc* first, * last;
	int count;
	int vnumber;
public:
	ArcGraph(int n) : first(0), last(0), count(0), vnumber(n) {}
	virtual ~ArcGraph();
	int CountVertex()const { return vnumber; }
	void  AddArc(int v1, int v2);
	bool HasArc(int v1, int v2) const;
};