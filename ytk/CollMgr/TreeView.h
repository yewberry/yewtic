#ifndef _TREE_VIEW_H
#define _TREE_VIEW_H

#include <string>
#include <iostream>
#include <FL/Fl_Tree.H>

#include "log.hpp"
#include "tinyxml.h"

class TreeView: public Fl_Tree
{
public:
	TreeView(int x, int y, int w, int h);
	~TreeView(void);

	void load(const char *filepath);

	//callback
	static void onClick(TreeView* o, void* v);
private:
	void addNode(TiXmlElement* el, std::string path);
};

#endif