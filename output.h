#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include <fstream>
#include "half_edge_structure.h"
#include "elar_operator.h"

using namespace std;

class Output
{
public:
	void printPoint(Vertex *vertex)
	{
		printf("%d %lf %lf %lf\n", vertex->id, \
			vertex->coordinate[0], \
			vertex->coordinate[1], \
			vertex->coordinate[2]);
	}

	void printLoop(Loop *loop, ofstream &out)
	{
		HalfEdge *ha = loop->halfedges;
		Vertex *vertex = ha->sv;

		int cnt = 1;
		ha = ha->next;
		while (ha->sv != vertex)
		{
			++cnt;
			ha = ha->next;
		}
		out << cnt;
		out << " " << vertex->id;
		ha = ha->next;
		while (ha->sv != vertex)
		{
			out << " " << ha->sv->id;
			ha = ha->next;
		}
		out << endl;
	}

	void write(ElarOperator &elar)
	{
		Solid *solid = elar.get_solid();
		Face *face = solid->faces;
		vector<Loop *> lvec = elar.getLoop_list();
		vector<Loop *>::iterator lbeg;

		ofstream out;
		out.open("D:/solid.brp");

		out << "BRP\n";
		//printf("BREP\n");
		out << solid->vnum << " " << lvec.size() << " " << solid->fnum << " " << 1 << endl;
		//printf("%d %d\n", solid->vnum, solid->lnum);

		vector<Vertex *> vvec = elar.getV_list();
		vector<Vertex *>::iterator vbeg;

		for (vbeg = vvec.begin(); vbeg != vvec.end(); ++vbeg)
		{
			out << (*vbeg)->coordinate[0] << " " << (*vbeg)->coordinate[1] << " " << (*vbeg)->coordinate[2] << endl;
		}

		

		for (lbeg = lvec.begin(); lbeg != lvec.end(); ++lbeg)
		{
			printLoop((*lbeg), out);
		}

		//out << "i am test\n";

		while (face != NULL)
		{
			out << face->out_lp->id << " " << face->innum;
			
			if (face->innum != 0)
			{
				Loop *lp = face->inner_lp;
				while (lp != NULL)
				{
					out << " " << lp->id;
					lp = lp->next;
				}
			}
			out << " " << solid->id;
			out << endl;
			face = face->next;
		}

		printf("Build solid.brp successiful!\nDirection : D:/solid.brp!!\n");

	}
};
#endif