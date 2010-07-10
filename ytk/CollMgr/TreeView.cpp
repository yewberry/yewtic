#include "TreeView.h"

TreeView::TreeView(int x, int y, int w, int h)
: Fl_Tree(x, y, w, h)
{
	this->showroot(0);
	this->callback((Fl_Callback*)onClick);
}

TreeView::~TreeView(void)
{
}

void TreeView::load(const char *filepath){
	TiXmlDocument doc( filepath );
	bool loadOkay = doc.LoadFile();
	if(!loadOkay){
		std::cerr<<"Failed to load file "<<filepath<<std::endl;
		return;
	}

	TiXmlHandle hDoc(&doc);
	TiXmlHandle hRoot(0);
	TiXmlElement* el = 0;

	{
		el = hDoc.FirstChildElement().Element();
		if(!el) return;
		hRoot=TiXmlHandle(el);
	}

	this->begin();
	{
		el = hRoot.FirstChildElement("data").Element()->FirstChildElement("node")->ToElement();
		for( el; el; el=el->NextSiblingElement()){
			addNode(el, "");
		}
	}
	this->end();
}

void TreeView::addNode(TiXmlElement* el, std::string path){
	const char *id = el->Attribute("id");
	const char *label = el->Attribute("text");

	std::string p = path + "/" + label;
	Fl_Tree_Item* item = this->add(p.c_str());
	item->user_data( (void*)(new std::string(id)) );//TODO rmb to delete user_data

	TiXmlElement* child = el->FirstChildElement("node");
	if(child != 0){                   
		for( child; child; child=child->NextSiblingElement()){
			addNode(child, p);
		}
	}

}

void TreeView::onClick(TreeView* o, void* v){
	Fl_Tree_Item *item = o->item_clicked();
	if ( item ) {
		fprintf(stderr, "label='%s' userdata=%s\n",
			item->label(),
			((std::string*)item->user_data())->c_str());
	} else {
		fprintf(stderr, "no item (probably multiple items were changed at once)\n");
	}
}
/*
int TreeView::handle(int e){
	const char *nm = fl_eventnames[e];
	std::string str = "in tree view handle: ";
	str.append(nm);
	LogInfo(( str.c_str() ));
	
	return 0;
}
*/