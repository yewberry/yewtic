#ifndef _TABLE_VIEW_H
#define _TABLE_VIEW_H

#include <FL/fl_draw.H>
#include <FL/Fl_Table_Row.H>

class TableView : public Fl_Table_Row
{
public:
	TableView(int x, int y, int w, int h, const char *l=0);
	~TableView(void);

	void draw_cell(TableContext context,  		// table cell drawing
		int R=0, int C=0, int X=0, int Y=0, int W=0, int H=0);
};

#endif