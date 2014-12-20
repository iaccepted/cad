#ifndef __HALF_EDGE_STRUCTURE__
#define __HALF_EDGE_STRUCTURE__

#include <stdlib.h>

struct Solid;
struct Face;
struct Loop;
struct HalfEdge;
struct Vertex;
struct Edge;

struct Solid
{
	int id;
	Face *faces; // list of all faces to construct this solid
	Edge *edges; // list of all edges to construct this solid->to build the frame
	Solid *next;
	Solid *pre;

	int vnum;//the count of all vertexs
	int fnum;//the count of all faces
	int lnum;//the count of all loops


	Solid() : id(0), faces(NULL), edges(NULL), next(NULL), pre(NULL), fnum(0), vnum(0), lnum(0){}
};

struct Face
{
	int id;
	Solid *solid; // the solid which the face belong to
	Loop *out_lp; // out loop of the face--construct the face
	Loop *inner_lp;//inner_lp of the face--inner loop
	Face *next;
	Face *pre;
	int innum;//the count of inner loops

	Face() : id(0), solid(NULL), out_lp(NULL), next(NULL), pre(NULL), inner_lp(NULL), innum(0){}
};

struct Loop
{
	int id;
	HalfEdge *halfedges; // list of all halfeges to construct this loop 
	Face *face; // the face that constructed by this loop
	Loop *next;
	Loop *pre;

	Loop() : id(0), halfedges(NULL), face(NULL), next(NULL), pre(NULL){}
};

struct Edge
{
	HalfEdge *half_l; //the edge's left halfedge
	HalfEdge *half_r; //the edge's right halfedge
	Edge *next;
	Edge *pre;

	Edge() : half_l(NULL), half_r(NULL), next(NULL), pre(NULL){}
};

struct HalfEdge
{
	Edge *edge; //this halfedge belong to which edge
	Vertex *sv; //the start vertex of this halfedge
	Vertex *ev; //the end vertex of this halfedge
	Loop *lp; //pointer to the loop that this halfedge belong to
	HalfEdge *next;
	HalfEdge *pre;
	HalfEdge *brother;

	HalfEdge() : edge(NULL), sv(NULL), lp(NULL), next(NULL), pre(NULL), brother(NULL){}
};

struct Vertex
{
	int id;
	double coordinate[3];//coordinate of the vertex (x, y, z)
	Vertex *next;
	Vertex *pre;

	Vertex(double x, double y, double z) : id(0), next(NULL), pre(NULL)
	{
		coordinate[0] = x;
		coordinate[1] = y;
		coordinate[2] = z;
	}
};

#endif
