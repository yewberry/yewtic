#ifndef _TREE_VIEW_H
#define _TREE_VIEW_H

#include <FL/Fl_Tree.H>

class TreeView: public Fl_Tree
{
public:
	TreeView(int x, int y, int w, int h);
	~TreeView(void);
};

#endif