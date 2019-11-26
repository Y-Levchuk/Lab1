#pragma once
#include"UserDate.h"

class Graph {
public:
	virtual ~Graph() {}
	virtual void AddArc(int v1, int v2, UserDate* date) = 0;
	virtual UserDate* HasArc(int v1, int v2 )const = 0;
	virtual int CountVertex()const = 0;
};