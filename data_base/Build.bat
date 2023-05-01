echo off
set choose_path=%1
::don't forget to add %choose_path% for your compilation command!
:: example - g++ %choose_path%/main.cpp -o %choose_path%/main

g++ -I ./controller/sqlite/include -L ./controller/sqlite/lib -static %choose_path%/main.cpp -lsqlite3.dll -o %choose_path%/main 
