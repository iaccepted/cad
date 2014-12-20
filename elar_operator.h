#ifndef __ELAR_OPERATOR__
#define __ELAR_OPERATOR__

#include "half_edge_structure.h"
#include <vector>

using namespace std;

class ElarOperator
{
public:
	ElarOperator()
	{
		v_list.clear();
		sweep_list.clear();
		l_list.clear();
		solid = NULL;
	}

	std::vector<Vertex *> getV_list()
	{
		return v_list;
	}

	std::vector<Face *> getSweep_list()
	{
		return sweep_list;
	}

	std::vector<Loop *> getLoop_list()
	{
		return l_list;
	}

	Solid *get_solid()
	{
		return solid;
	}

	void addEdgeIntoSolid(Edge *edge);
	void addFaceIntoSolid(Face *face);
	void addLoopIntoFace(Loop *loop, Face *face);
	Solid *mvfs(double point[3], Vertex *&vertex);
	HalfEdge *mev(Vertex *sv, double point[3], Loop *lp);
	Loop *mef(Vertex *sv, Vertex *ev, Loop *lp, bool mark);
	Loop *kemr(Vertex *sv, Vertex *ev, Loop *lp);
	void kfmrh(Face *fa, Face *fb);
	void sweep(double dir[3], double dist);

private:
	std::vector<Vertex *> v_list;
	std::vector<Loop *> l_list;
	std::vector<Face *> sweep_list;
	Solid *solid;
};

#endif
