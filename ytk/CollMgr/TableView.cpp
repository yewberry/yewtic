#include "TableView.h"

TableView::TableView(int x, int y, int w, int h, const char *l)
: Fl_Table_Row(x,y,w,h,l)
{
}

TableView::~TableView(void)
{
}


void TableView::draw_cell(Fl_Table::TableContext context, 
						  int R, int C, int X, int Y, int W, int H)
{
	switch ( context ){
		case CONTEXT_COL_HEADER:
			fl_push_clip(X, Y, W, H);
			{
				fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, col_header_color());
				fl_color(FL_BLACK);
				fl_draw("abc", X, Y, W, H, FL_ALIGN_CENTER);
			}
			fl_pop_clip();
			return;
		case CONTEXT_CELL:
		{
			fl_push_clip(X, Y, W, H);
			{
			// TEXT

			fl_draw("def", X, Y, W, H, FL_ALIGN_CENTER);


			}
			fl_pop_clip();
			return;
		}
	}
}
