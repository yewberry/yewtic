#include "TreeView.h"

TreeView::TreeView(int x, int y, int w, int h, const char* title)
: Fl_Tree(x, y, w, h, title)
{
}

TreeView::~TreeView(void)
{
}

void TreeView::load(){

	this->add("eMuleDl");
	char s[20];
	char* str = "´ó¹úÑ§A";
	std::cout<<strlen(str)<<std::endl;
	fl_utf8from_mb(s, 20,str,strlen(str));

	this->add(s);
	this->add("eMuleDl/IT");
	return;

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
		hRoot=TiXmlHandle(el);
	}

	{
		el = hRoot.FirstChildElement("data").Element()->FirstChildElement("node")->ToElement();
		for( el; el; el=el->NextSiblingElement()){
			addNode(el, "");
		}
	}

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

void TreeView::addNode(TiXmlElement* el, std::string path){
	const char *id = el->Attribute("id");
	const char *label = el->Attribute("text");

	std::string p = path + "/" + label;
	Fl_Tree_Item* item = this->add(p.c_str());

	char s[256];
	fl_utf8from_mb(s, 256, label, strlen(label));
	item->label(s);
	std::cout<<"Path, Label:"<<p<<","<<s<<std::endl;
	//item->user_data( (void*)id );

	TiXmlElement* child = el->FirstChildElement("node");
	if(child != 0){                   
		for( child; child; child=child->NextSiblingElement()){
			addNode(child, p);
		}
	}

}