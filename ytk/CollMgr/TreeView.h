#ifndef _TREE_VIEW_H
#define _TREE_VIEW_H

#include <map>
#include <string>
#include <iostream>
#include <FL/Fl_Tree.H>
#include "tinyxml.h"

class TreeView: public Fl_Tree
{
public:
	TreeView(int x, int y, int w, int h, const char* title);
	~TreeView(void);

	void load();
private:
	void addNode(TiXmlElement* el, std::string path);
};

#endif