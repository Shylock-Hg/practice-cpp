#include <iostream>
#include <iterator>
#include <pqxx/pqxx>

int main()
{
    try {
        pqxx::connection C("dbname=db-shylock");
        std::clog << "Connected to " << C.dbname() << std::endl;
        pqxx::work W(C);

	//< create table cities and weathers
	W.exec("CREATE TABLE cities ("
	       "    name      varchar(80),"
	       "    location  point"
	       ");");
	W.exec("CREATE TABLE weathers ("
               "city     varchar(80),"
               "temp_lo  int,        "//"   -- low temperature"
               "temp_hi  int,        "//"   -- high temperature"
               "prcp     real,       "//"   -- precipitation"
               "date     date"
	       ");");

        std::clog << "Insert new raw ..." << std::endl;
        W.exec("INSERT INTO cities VALUES ('shanghai', '(1.1, 2.2)'), "
			"('sichuan', '(1.1, 2.2)');");
	
	W.exec("INSERT INTO weathers VALUES "
			"('shanghai', '22', '33', '3.3', '(1992, 2, 13)'), "
			"('sichuan', '22', '33', '3.3', '(1992, 2, 13)');");
	W.commit();


	pqxx::nontransaction N(C);
	pqxx::result R = N.exec("SELECT name, date FROM cities, weathers;");
	std::clog << "Found " << R.size() << " Items:" << std::endl;
	for (const auto& row : R) {
		//std::clog << row[0] << "  " << row[1] << std::endl;
		for (const auto& item : row) {
			std::clog << item << "  ";
		}
		std::clog << std::endl;
	}

	pqxx::result R2 = N.exec("SELECT * FROM cities;");
	std::clog << "Found " << R2.size() << " Items:" << std::endl;
	for (const auto& row : R2) {
		//std::clog << row[0] << "  " << row[1] << std::endl;
		for (const auto& item : row) {
			std::clog << item << "  ";
		}
		std::clog << std::endl;
	}

	C.disconnect();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
