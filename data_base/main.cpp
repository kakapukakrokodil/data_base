#include ".\controller\XML\xml.cpp"
#include ".\controller\XML\create_document.cpp"


int main (){
    string user_choise;
	system("cls");
    do{
		string file_name;
        cout << "Welcome to data base!\n\n"
        "1 - Create a database SQLite\n"
        "2 - Create a database XML\n"
        "3 - Open an existing database SQLite\n"
        "4 - Open an existing database XML\n>>";

        cin >> user_choise;
        cout << "Enter the name of the database\n>>";
        cin >> file_name;
		system("cls");
		
        if(user_choise == "1");
        else if(user_choise == "2") create_database(file_name += ".xml");
        else if(user_choise == "3");
        else if(user_choise == "4") run_xml(file_name += ".xml");
    }while(user_choise != "0");
	system("pause");
}