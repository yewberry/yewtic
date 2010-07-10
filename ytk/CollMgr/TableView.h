#ifndef _TABLE_VIEW_H
#define _TABLE_VIEW_H

#include <iostream>
#include <FL/Fl_Table_Row.H>
#include <FL/fl_draw.H>

class TableView :
	public Fl_Table_Row
{
public:
	TableView(int x, int y, int w, int h, const char *l=0);
	~TableView(void);

	void draw_cell(TableContext context, int R, int C, int X, int Y, int W, int H);
};

#endif