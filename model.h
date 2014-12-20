#ifndef __MODEL_H__
#define __MODE_H__

#include <fstream>
#include <iostream>
#include "half_edge_structure.h"
#include "elar_operator.h"

using namespace std;

class Model
{
public:
	void set_point(double x, double y, double z)
	{
		p[0] = x;
		p[1] = y;
		p[2] = z;
	}

	void create_model(ElarOperator &elar)
	{
		fstream in;
		in.open("input.txt");

		int cnt_point, cnt_inloop, d;
		double x, y, z;
		double dir[3];
		Vertex *vertex, *invertex;
		HalfEdge *he;

		vertex = NULL;
		invertex = NULL;

		in >> cnt_point;

		if (cnt_point < 3)
		{
			cout << "Data Error!\n" << endl;
			exit(-1);
		}

		
		in >> x >> y >> z;
		
		set_point(x, y, z);
		Solid *solid = elar.mvfs(p, vertex);

		Loop *loop = solid->faces->out_lp;
		
		in >> x >> y >> z;
		set_point(x, y, z);
		he = elar.mev(vertex, p, loop);

		for (int i = 2; i < cnt_point; ++i)
		{
			in >> x >> y >> z;
			set_point(x, y, z);
			he = elar.mev(he->ev, p, loop);
		}

		elar.mef(he->ev, vertex, loop, true);

		in >> cnt_inloop;

		for (int i = 0; i < cnt_inloop; ++i)
		{
			in >> cnt_point;

			if (cnt_point < 3)
			{
				cout << "Data Error!\n";
				exit(-1);
			}

			for (int j = 0; j < cnt_point; ++j)
			{
				in >> x >> y >> z;
				set_point(x, y, z);

				if (j == 0)
				{
					he = elar.mev(vertex, p, loop);
					invertex = he->ev;
					continue;
				}

				he = elar.mev(he->ev, p, loop);
			}

			elar.mef(he->ev, invertex, loop, true);
			elar.kemr(vertex, invertex, loop);
		}

		in >> dir[0] >> dir[1] >> dir[2];
		in >> d;

		elar.sweep(dir, d);

		vector<Face *> face_list = elar.getSweep_list();
		int size = face_list.size();

		for (int i = 1; i < size; ++i)
		{
			elar.kfmrh(face_list[0], face_list[i]);
		}

	}
private:
	double p[3];
};

#endif