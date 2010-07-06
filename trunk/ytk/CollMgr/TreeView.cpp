#include "TreeView.h"

TreeView::TreeView(int x, int y, int w, int h, const char* title)
: Fl_Tree(x, y, w, h, title)
{
	m_hm = new std::map<std::wstring, std::wstring>;
}

TreeView::~TreeView(void)
{
	delete m_hm;
}

void TreeView::load(){
	std::cout<<"in load"<<std::endl;
	char* path = "etc/catalog.xml";
	TiXmlDocument doc( path );
	bool loadOkay = doc.LoadFile();
	if(!loadOkay){
		std::cerr<<"Failed to load file "<<path<<std::endl;
		return;
	}

	TiXmlHandle hDoc(&doc);
	TiXmlHandle hRoot(0);
	TiXmlElement* el = 0;

	{
		el = hDoc.FirstChildElement().Element();
		if(!el) return;
		hRoot=TiXmlHandle(pElem);
	}

	std::cout<<el->Value()<<std::endl;
	/*
	this->begin();
	for(node = node->FirstChild("data")->FirstChild("node");
		node;
		node = node->NextSibling("node") )
	{
		//elem = node->ToElement();
		this->add(node->value());
	}
	this->end();
	*/
}