#include <iostream>
#include <pqxx/pqxx>

int main()
{
    try
    {
        pqxx::connection C("dbname=db-shylock");
        std::clog << "Connected to " << C.dbname() << std::endl;
        pqxx::work W(C);

        pqxx::result R = W.exec("SELECT name FROM cities");

        std::clog << "Found " << R.size() << " cities:" << std::endl;
        for (auto row: R)
            std::clog << row[0].c_str() << std::endl;

        //std::clog << "Doubling all employees' salaries..." << std::endl;
        //W.exec("UPDATE employee SET salary = salary*2");

        std::clog << "Insert new raw ..." << std::endl;
        W.exec("INSERT INTO cities VALUES ('shanghai', '(1.1, 2.2)')");

        std::clog << "Making changes definite: ";
        W.commit();
        std::clog << "OK." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
