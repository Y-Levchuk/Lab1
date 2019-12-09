#include "ArcGraph.h"

/*
	Деструктор класу ArcGraph
	Не приймає параметрів
*/
ArcGraph::~ArcGraph() {
	Arc* current = first;
	Arc* prev = 0;
	while (current) {
		prev = current;
		current = current->next;
		delete prev;
	}
}

/*
	Додавання нового ребра до графу
	Приймає як параметри: номер першої і другої вершини
*/
void ArcGraph::AddArc(int v1, int v2) {
	if (v1 < 0 || v2 < 0 || v1 >= vnumber || v2 >= vnumber) return;
	Arc* newArc = new Arc(v1, v2);
	if (last) last->next = newArc;
	else first = newArc;
	last = newArc;
	count++;
}

/*
	Превірка на існування ребра в графі
	Приймає як параметри: номер першої і другої вершини
*/
bool ArcGraph::HasArc(int v1, int v2) const {
	Arc* current;
	for (current = first; current; current = current->next) if (current->beg == v1 && current->end == v2) return true;
	return false;
}