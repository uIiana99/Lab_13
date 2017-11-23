#include "json.hpp"
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

std::string getNickname(std::string _email);
std::string getServer(std::string _email);

int main(int argc, char const *argv[]) {
	try {
		if(argc == 1)
			throw std::runtime_error("\tERROR: have no any path...");

		std::string filePath = argv[1];
		if(!exists(filePath) )
            throw std::runtime_error("\tERROR: Wrong address! File does not exist!");
		
		std::ifstream input( argv[1] );
		json deserialization;
		input >> deserialization;
		input.close();

		Person Obj;

		Obj.first_name = deserialization["Fisrt name"];
		Obj.last_name = deserialization["Last name"];
		Obj.email.nickname = getNickname(deserialization["Email"]);
		Obj.email.server = getServer(deserialization["Email"]);
		Obj.age = deserialization["Age"];
		Obj.phone = deserialization["Phone"];

		std::cout << "[Person]\n";
		std::cout << "Fisrt name:\t" << Obj.first_name << "\n";
		std::cout << "Last name:\t" << Obj.last_name << "\n";
		std::cout << "Email:\t\t" << Obj.email.nickname << Obj.email.server << "\n";
		std::cout << "Age:\t\t" << Obj.age << "\n";
		std::cout << "Phone:\t\t" << Obj.phone << "\n";

	} catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return 0;
}

std::string getNickname(std::string _email) {
  	std::string::size_type symbol = _email.find("@");

  	if(symbol == std::string::npos)
  		throw std::runtime_error("\tERROR: incorret email address...");

	return _email.substr(0, symbol);
}

std::string getServer(std::string _email) {
	std::string::size_type symbol = _email.find("@");

  	if(symbol == std::string::npos)
  		throw std::runtime_error("\tERROR: incorret email address...");

	return _email.substr(symbol);
}