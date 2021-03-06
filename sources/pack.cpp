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
		//  Проверяем наличие адреса файла
		if(argc == 1)
			throw std::runtime_error("Error: does not have any path...");

		std::string filePath = argv[1];

		//  Проверяем существование файла по адресу
		if(!exists(filePath) )
            		throw std::runtime_error("\tError: did not found any files");

		//  Создаем структуру и заполняем поля
		Person Obj;

		std::cout << "Enter data to fields of the Person structure." << std::endl;
		std::cout << "First name:" << std::endl;
		std::cout << "Uliana" << std::endl;
		// std::cin >> Obj.first_name;
		Obj.first_name = "Uliana";
		std::cout << "Last name:" << std::endl;
		std::cout << "Koshkina" << std::endl;
		// std::cin >> Obj.last_name;
		Obj.last_name = "Koshkina";
		std::cout << "Email:" << std::endl;
		std::cout << "uliana_k@gmail.com" << std::endl;
		getEmail(Obj);
		std::cout << "Age(optional):" << std::endl;
		std::cout << "19" << std::endl;
		// std::cin >> Obj.age;
		Obj.age = 19;
		std::cout << "Phone(optional):" << std::endl;
		std::cout << "8(495)-123-45-67" << std::endl;
		// std::cin >> Obj.phone;
		Obj.phone = "8(495)-123-45-67";

		//  Создаем объект json в виде структуры и заполняем его данными из объекта Person
		json serialization = {
			{ "Fisrt name",	Obj.first_name },
			{ "Last name",	Obj.last_name },
			{ "Email",		Obj.email.nickname + Obj.email.server },
			{ "Age",		Obj.age },
			{ "Phone",		Obj.phone }
		};

		//  Записываем данные в конфигурационный файл json
		std::ofstream output( argv[1] );
		output << serialization << std::endl;
		output.close();

	} catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return 0;
}

//  Функция для разделение почтового адреса
void getEmail(Person & _obj) {
	std::string console_email = "uliana_k@gmail.com";
  	// std::cin >> console_email;

  	std::string::size_type symbol = console_email.find("@");

  	if(symbol == std::string::npos)
  		throw std::runtime_error("Error: email address does not exist...");

	_obj.email.nickname = console_email.substr(0, symbol);
	_obj.email.server = console_email.substr(symbol);
}
