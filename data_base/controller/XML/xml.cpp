#include <cstdio>
#include <iostream>
#include <string>
#include "tinyxml2.cpp"

using namespace std;
using namespace tinyxml2;

void run_xml();

struct ID{
public:
	string prod_id;
};

class Manager_xml{
public:
	XMLDocument doc;
	ID id;
	string file_name;
	
	Manager_xml(string file_name){
		this->file_name = file_name;
		doc.LoadFile(file_name.c_str());
		doc.SaveFile(file_name.c_str());
	}
	int add_id(XMLElement* root, XMLElement* item, string id, string title, string foo_id){

		
		
		if(foo_id == "0"){
			item->SetAttribute("name", title.c_str());
    		item->SetAttribute("id", id.c_str());
			root->InsertEndChild(item);
			return stoi(id);
		} 
		else {
			return stoi(foo_id);
		}

	}
	string check_id(XMLElement* root, string verified_name){ 
		for( XMLNode* a = root->FirstChild(); a != NULL; a = a->NextSibling()){
			string name = a->ToElement()->Attribute( "name" );
			string id = a->ToElement()->Attribute( "id" );
		
			if (name == verified_name) {
				
				return id;
			}
		}
		return "0";
	}

	int auto_inkrement(XMLElement* root){
		if (root->NoChildren() == true) return 1;
		int id = stoi(root->LastChildElement("Object")->Attribute("id"));
		id += 1;
		return id;
	}

	int add_product(){
		string title;

		try {
    		if (!doc.FirstChildElement()) throw std::runtime_error("Empty document");
  		}
  		catch (const std::exception& e) {
    		cerr << "Error: " << e.what() << endl;
			remove(file_name.c_str());
			return 1;
 		}
		system("cls");
		cout << "Enter a Product name\n>>";
		cin >> title;

		XMLElement* root = doc.FirstChildElement("Main")->FirstChildElement("Product");
    	XMLElement* newItem = doc.NewElement("Object");

		id.prod_id = to_string(auto_inkrement(root));

		newItem->SetAttribute("name", title.c_str());
    	newItem->SetAttribute("id", id.prod_id.c_str());
		system("cls");
		
		newItem->SetAttribute("seller_id", add_seller());
		newItem->SetAttribute("brend_id", add_brend());
		newItem->SetAttribute("category_id", add_category());

		root->InsertEndChild(newItem);
		doc.SaveFile(file_name.c_str());
	}

	int add_seller(){
		string title;
		try {
    		if (!doc.FirstChildElement()) throw std::runtime_error("Empty document");
  		}
  		catch (const std::exception& e) {
    		cerr << "Error: " << e.what() << endl;
			remove(file_name.c_str());
			return 1;
 		}
		cout << "Enter the seller title\n>>";
		cin >> title;

		XMLElement* root = doc.FirstChildElement("Main")->FirstChildElement("Seller");
    	XMLElement* newItem = doc.NewElement("Object");

		id.prod_id = to_string(auto_inkrement(root));
		string foo_id = check_id(root, title);

		int identificator = add_id(root, newItem, id.prod_id, title, foo_id);
		doc.SaveFile(file_name.c_str());
		system("cls");
		return identificator;

	}
	
	int add_brend(){
		string title;
		try {
    		if(!doc.FirstChildElement()) throw std::runtime_error("Empty document");
  		}
  		catch (const std::exception& e) {
    		cerr << "Error: " << e.what() << endl;
			remove(file_name.c_str());
			return 1;
 		}
		cout << "Enter the brend title\n>>";
		cin >> title;

		XMLElement* root = doc.FirstChildElement("Main")->FirstChildElement("Brend");
    	XMLElement* newItem = doc.NewElement("Object");


		id.prod_id = to_string(auto_inkrement(root));
		string foo_id = check_id(root, title);

		int identificator = add_id(root, newItem, id.prod_id, title, foo_id);
		doc.SaveFile(file_name.c_str());
		system("cls");
		return identificator;
	}

	int add_category(){
		string title;

		try {
    		if (!doc.FirstChildElement()) throw std::runtime_error("Empty document");
  		}
  		catch (const std::exception& e) {
    		cerr << "Error: " << e.what() << endl;
			remove(file_name.c_str());
			return 1;
 		}
		cout << "Enter the category title\n>>";
		cin >> title;

		XMLElement* root = doc.FirstChildElement("Main")->FirstChildElement("Category");
    	XMLElement* newItem = doc.NewElement("Object");

		id.prod_id = to_string(auto_inkrement(root));
		string foo_id = check_id(root, title);

		int identificator = add_id(root, newItem, id.prod_id, title, foo_id);
		doc.SaveFile(file_name.c_str());
		system("cls");
		return identificator;
	}
	string show(XMLElement* root, string verified_id){

		for( XMLNode* a = root->FirstChild(); a != NULL; a = a->NextSibling()){
			string name = a->ToElement()->Attribute( "name" );
			string id = a->ToElement()->Attribute( "id" );
		
			if (id == verified_id) return name;
		}
		return "s";
	}
	int show_product(){
		string title;
		try {
    		if(!doc.FirstChildElement()) throw std::runtime_error("Empty document");
  		}
  		catch (const std::exception& e) {
    		int user_choise;

    		cerr << "Error: " << e.what() << endl;
			remove(file_name.c_str());
			return 1;
 		}
		
		cout << "Enter the Product name\n>>";
		cin >> title;
			
		XMLElement* root = doc.FirstChildElement("Main")->FirstChildElement("Product");
		system("cls");
		for( XMLNode* a = root->FirstChild(); a != NULL; a = a->NextSibling()){

			string name = a->ToElement()->Attribute( "name" );
			string id = a->ToElement()->Attribute( "id" );
			string seller_id = a->ToElement()->Attribute( "seller_id" );
			string brend_id = a->ToElement()->Attribute( "brend_id" );
			string category_id = a->ToElement()->Attribute( "category_id" );

			if (name == title) {
				cout << "\n------------------------------------------------------\n";
				cout << id << ' ' << name << ' ' << show(doc.FirstChildElement("Main")->FirstChildElement("Seller"), seller_id) << ' '
				<< show(doc.FirstChildElement("Main")->FirstChildElement("Brend"), brend_id) << ' ' 
				<< show(doc.FirstChildElement("Main")->FirstChildElement("Category"), category_id) << '\n';
				cout << "------------------------------------------------------\n\n";
			}
		}
		
	}

	~Manager_xml(){
		cout << "connection has been disconect!" << "\n";
	}
};

void run_xml(string file_name){
	string user_choise;
	int red = 0;
	Manager_xml* manager_xml = new Manager_xml(file_name);
	do{
		cout << "1 - Enter the product\n"
		"2 - Enter the seller\n"
		"3 - Enter the brend\n"
		"4 - Enter the category\n"
		"5 - Close a data base\n"
		"9 - Show a products\n"
		"0 - Exit the programm\n>>";
		cin >> user_choise;
		system("cls");
		
		if(user_choise == "1") red = manager_xml->add_product();
		else if(user_choise == "2") red = manager_xml->add_seller();
		else if(user_choise == "3") red = manager_xml->add_brend();
		else if(user_choise == "4") red = manager_xml->add_category();
		else if(user_choise == "5") delete(manager_xml);
		else if(user_choise == "9") red = manager_xml->show_product();
		if(red == 1) break;
	}while(user_choise != "0");
}

