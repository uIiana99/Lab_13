#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>

using json = nlohmann::json;
using namespace boost::filesystem;

struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
};

void getEmail(Person & obj);

int main(int argc, char const *argv[]) {
	try {
		if(argc == 1)
			throw std::runtime_error("ERROR: have no any path...");

		std::string filePath = argv[1];
		if(!exists(filePath) )
            throw std::runtime_error("\tERROR: Wrong address! File does not exist!");

		//  Create struct & fill it
		Person Obj;

		std::cout << "Enter data to fields of the Person structure." << std::endl;
		std::cout << "First name:" << std::endl;
		std::cin >> Obj.first_name;
		std::cout << "Last name:" << std::endl;
		std::cin >> Obj.last_name;
		std::cout << "Email:" << std::endl;
		getEmail(Obj);
		std::cout << "Age(optional):" << std::endl;
		std::cin >> Obj.age;
		std::cout << "Phone(optional):" << std::endl;
		std::cin >> Obj.phone;


		json serialization = {
			{ "Fisrt name",	Obj.first_name },
			{ "Last name",	Obj.last_name },
			{ "Email",		Obj.email.nickname + Obj.email.server },
			{ "Age",		Obj.age },
			{ "Phone",		Obj.phone }
		};

		// write prettified JSON to another file
		std::ofstream output( argv[1] );
		output << serialization << std::endl;
		output.close();

	} catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return 0;
}

void getEmail(Person & _obj) {
	std::string console_email;
  	std::cin >> console_email;

  	std::string::size_type symbol = console_email.find("@");

  	if(symbol == std::string::npos)
  		throw std::runtime_error("ERROR: incorret email address...");

	_obj.email.nickname = console_email.substr(0, symbol);
	_obj.email.server = console_email.substr(symbol);
}
