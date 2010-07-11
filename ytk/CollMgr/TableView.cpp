#include "TableView.h"

TableView::TableView(int x, int y, int w, int h, const char *l)
: Fl_Table_Row(x,y,w,h,l)
{
}

TableView::~TableView(void)
{
}

void TableView::draw_cell(TableContext context, 
						  int R, int C, int X, int Y, int W, int H)
{
	static char s[40];
	sprintf(s, "%d/%d", R, C);		// text for each cell

	switch ( context )
	{
	case CONTEXT_STARTPAGE:
		fl_font(FL_HELVETICA, 16);
		return;

	case CONTEXT_ROW_HEADER:
	case CONTEXT_COL_HEADER:
		fl_push_clip(X, Y, W, H);
		{
			fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, color());
			fl_color(FL_BLACK);
			fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
		}
		fl_pop_clip();
		return;

	case CONTEXT_CELL:
		{
			fl_push_clip(X, Y, W, H);
			{
				// BG COLOR
				fl_color( row_selected(R) ? selection_color() : FL_WHITE);
				fl_rectf(X, Y, W, H);

				// TEXT
				fl_color(FL_BLACK);
				fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);

				// BORDER
				fl_color(FL_LIGHT2); 
				fl_rect(X, Y, W, H);
			}
			fl_pop_clip();
			return;
		}

	default:
		return;
	}
}
