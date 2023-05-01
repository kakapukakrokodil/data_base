#include "create_document.h"

void create_database(string file_name){
    XMLDocument doc;
    doc.LoadFile(file_name.c_str());

    XMLElement* new_item = doc.NewElement("Main");
    doc.InsertEndChild(new_item);

    new_item = doc.NewElement("Product");
    new_item->SetText("");
    doc.FirstChildElement("Main")->InsertEndChild(new_item);

    new_item = doc.NewElement("Seller");
    new_item->SetText("");
    doc.FirstChildElement("Main")->InsertEndChild(new_item);

    new_item = doc.NewElement("Brend");
    new_item->SetText("");
    doc.FirstChildElement("Main")->InsertEndChild(new_item);

    new_item = doc.NewElement("Category");
    new_item->SetText("");
    doc.FirstChildElement("Main")->InsertEndChild(new_item);

    doc.SaveFile(file_name.c_str());
}