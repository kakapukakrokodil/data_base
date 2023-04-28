#include <iostream>
#include "sqlite3.h"
using namespace std;

void run_sqlite();
void reset_db_sqlite(string file_name);
void create_db_sqlite(string file_name);
struct ID{
	int id = 0;
};
static int call(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}
 static int callback(void *data, int argc, char **argv, char **azColName){
   ID *Id = (ID *)data ;
   printf("\n");
   Id->id = atoi(argv[0]);
   return 0;
}

class Manager{
public:
	sqlite3 *db = 0;

	Manager(const char* db){
		if(sqlite3_open(db, &this->db))
			fprintf(stderr, "ddd", sqlite3_errmsg(this->db));	
	}

	void add_product(){
		string title, request;
		cout << "Enter a Product name\n>>";
		cin >> title;
		
		request = "INSERT INTO Products (name, seller_id, brend_id, categories_id) VALUES ('" + title +
		"', '" + to_string(add_seller()) + "', '" + to_string(add_brend()) + "', '" + to_string(add_category()) + "');";
		sqlite3_exec(db, request.c_str(), 0, 0, 0);
	}

	int add_seller(){
		string title;
		cout << "Enter the seller title\n>>";
		cin >> title;

		string request = "SELECT id from Seller WHERE seller_name='" + title + "'";
		ID Id;

		sqlite3_exec(db, request.c_str(),callback,&Id,0);

		if(Id.id == 0) {
			string str = "INSERT INTO Seller (seller_name) VALUES ('" + title + "');";
			sqlite3_exec(db, str.c_str(), 0, 0, 0);
			sqlite3_exec(db, request.c_str(),callback,&Id,0);
		}
		return Id.id;
	}

	int add_brend(){
		string title;
		cout << "Enter the brend title\n>>";
		cin >> title;

		string request = "SELECT id from Brend WHERE brend_name='" + title + "'";
		ID Id;

		sqlite3_exec(db, request.c_str(),callback,&Id,0);

		if(Id.id == 0) {
			string str = "INSERT INTO Brend (brend_name) VALUES ('" + title + "');";
			sqlite3_exec(db, str.c_str(), 0, 0, 0);
			sqlite3_exec(db, request.c_str(),callback,&Id,0);
		}
		return Id.id;
	}

	int add_category(){
		string title;
		cout << "Enter the category title\n>>";
		cin >> title;

		string request = "SELECT id from Categories WHERE categories_name='" + title + "'";
		ID Id;

		sqlite3_exec(db, request.c_str(),callback,&Id,0);
		if(Id.id == 0) {
			string str = "INSERT INTO Categories (categories_name) VALUES ('" + title + "');";
			sqlite3_exec(db, str.c_str(), 0, 0, 0);
			sqlite3_exec(db, request.c_str(),callback,&Id,0);
		}
		return Id.id;
	}

	void show_products(string name){
		
		
		string query = "SELECT id FROM Products WHERE name = '" + name + "';"
		"SELECT name FROM Products WHERE name = '" + name + "';"
		"SELECT Categories.categories_name FROM Categories "
        "INNER JOIN Products ON Categories.id = Products.categories_id "
		"WHERE Products.name = '" + name + "';"
		"SELECT Brend.brend_name FROM Brend "
        "INNER JOIN Products ON Brend.id = Products.brend_id "
		"WHERE Products.name = '" + name + "';"
		"SELECT Seller.seller_name FROM Seller "
        "INNER JOIN Products ON Seller.id = Products.seller_id "
        "WHERE Products.name = '" + name + "'";
		sqlite3_exec(db, query.c_str(), call, 0, 0);
	}
	void empty_check(string file_name){
		// Выполняем SQL-запрос для проверки базы данных на пустоту
		sqlite3_stmt* stmt;
		const char* query = "SELECT COUNT(*) FROM sqlite_master WHERE type='table' AND name NOT LIKE 'sqlite_%'";
		int rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);



		// Выполняем запрос и получаем количество записей в таблицах
		int count = 0;
		rc = sqlite3_step(stmt);

		if (rc == SQLITE_ROW) {
		count = sqlite3_column_int(stmt, 0);
		}

		sqlite3_finalize(stmt); // освобождаем ресурсы
		
		//if (count == 0) //create_database_sqlite(file_name);
		
		

	}
	~Manager(){
		sqlite3_close(this->db);
	}
};

void run_sqlite(string file_name){
	int user_choise;
	string product_name;
	Manager* manager = new Manager(file_name.c_str());

	manager->empty_check(file_name);

	do{
		cout << "1 - Enter the product\n"
		"2 - Enter the seller\n"
		"3 - Enter the brend\n"
		"4 - Enter the category\n"
		"5 - Close a data base\n"
		"6 - Clear a data base\n"
		"9 - Show a products\n"
		"0 - Exit the programm\n>>";
		cin >> user_choise;
		if(user_choise == 1) manager->add_product();
		else if(user_choise == 2) manager->add_seller();
		else if(user_choise == 3) manager->add_brend();
		else if(user_choise == 4) manager->add_category();
		else if(user_choise == 5) delete(manager);
		else if(user_choise == 6) system("reset_bd");
		else if(user_choise == 9) {
			cout << "Enter the Product name\n>>";
			cin >> product_name;
			manager->show_products(product_name);
		}
	}while(user_choise != 0);
	cout << '\n';
	system("pause");
}

void reset_db_sqlite(string file_name){
	sqlite3 *db = 0;
	sqlite3_open(file_name.c_str(), &db);

	sqlite3_exec(db, "DROP TABLE IF EXISTS Brend", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE IF EXISTS Seller", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE IF EXISTS Categories", 0, 0, 0);
	sqlite3_exec(db, "DROP TABLE IF EXISTS Products", 0, 0, 0);
	
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Products ( id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, categories_id INTEGER, brend_id INTEGER, seller_id INTEGER)", 0, 0, 0);
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Seller ( id INTEGER PRIMARY KEY AUTOINCREMENT, seller_name TEXT)", 0, 0, 0);
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Brend ( id INTEGER PRIMARY KEY AUTOINCREMENT, brend_name TEXT)", 0, 0, 0);
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Categories ( id INTEGER PRIMARY KEY AUTOINCREMENT, categories_name TEXT)", 0, 0, 0);
	
	sqlite3_close(db);
}

void create_db_sqlite(string file_name){
	sqlite3 *db = 0;
	sqlite3_open(file_name.c_str(), &db);

	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Products ( id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, categories_id INTEGER, brend_id INTEGER, seller_id INTEGER)", 0, 0, 0);
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Seller ( id INTEGER PRIMARY KEY AUTOINCREMENT, seller_name TEXT)", 0, 0, 0);
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Brend ( id INTEGER PRIMARY KEY AUTOINCREMENT, brend_name TEXT)", 0, 0, 0);
	sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS Categories ( id INTEGER PRIMARY KEY AUTOINCREMENT, categories_name TEXT)", 0, 0, 0);
	
	sqlite3_close(db);
}