#include ".\controller\XML\xml.cpp"
#include ".\controller\XML\create_document.cpp"


int main (){
    string file_name;
    int user_choise;

    do{
        cout << "Welcome to data base!\n\n"
        "1 - Create a database SQLite\n"
        "2 - Create a database XML\n"
        "3 - Open an existing database SQLite\n"
        "4 - Open an existing database XML\n>>";

        cin >> user_choise;
        cout << "Enter the name of the database\n>>";
        cin >> file_name;

        if(user_choise == 1);
        else if(user_choise == 2) create_database(file_name);
        else if(user_choise == 3);
        else if(user_choise == 4) run_xml(file_name);
    }while(user_choise != 0);
}