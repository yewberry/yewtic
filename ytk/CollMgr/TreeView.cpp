#include "TreeView.h"

TreeView::TreeView(int x, int y, int w, int h, const char* title)
: Fl_Tree(x, y, w, h, title)
{
	m_hm = new std::map<wstring, wstring>;
}

TreeView::~TreeView(void)
{
	delete m_hm;
}

void TreeView::load(){
	TiXmlDocument doc( "ect/catalog.xml" );
	bool loadOkay = doc.LoadFile();

	TiXmlNode* node = 0;
	TiXmlElement* elem = 0;
	node = doc.RootElement();

	this->begin();
	for(node = node->FirstChild("data")->FirstChild("node");
		node;
		node = node->NextSibling("node") )
	{
		elem = node->ToElement();
		std::cout<<
	}
	this->end();
}