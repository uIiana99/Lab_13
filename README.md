[![Build Status](https://travis-ci.org/uIiana99/Lab_13.svg?branch=master)](https://travis-ci.org/uIiana99/Lab_13)
# Lab_13

## Задание

Написать программы на **C++** для сериализации и десериализации структуры `Person`.

Структура `Person` определяется следующим образом:

```cpp
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
```

Пример сериализации структуры `Person` 
```ShellSession
$ ./pack /path/to/file
Enter data to fields of the Person structure.
First name:
Petr↵
Last name:
Ivanov↵
Email:
ivanov_petr_97@gmail.com
Age(optional):
20↵
Phone (optional):
↵
```

Пример десериализации структуры `Person` 
```ShellSession
$ ./unpack /path/to/file
[Person]
Fisrt name: Petr
Last name:  Ivanov
Email:      ivanov_petr_97@gmail.com
Age:        20
```

Формат сериализации и десериалиализации зависит от порядкового номера в *Цифровом журнале* и
вычисляется следующим образом:
```cpp
// i - порядковый номер (начиная с 1)
// v - номер варианта
// f - format
v = i % 3;
switch(v) {
  case 0: f = "json"; break;
  case 1: f = "yaml"; break;
  case 2: f = "xml"; break;
}
``` 

 Пример сериализации в формате *yaml*:
```ShellSession
$ cmake -H. -B_builds
$ cmake --build _builds
$ cd _builds
$ ./pack person1.yml
...
$ cat person1.yml
```

```yaml
person:
  firstname: Ivan
  lastname: Petrov
  email: petrov_ivan_98@ya.ru
  age: 19
  phone: +7(900) 000 12-34
```

## Требования

1. Программа должна иметь открытый исходный код, расспаложенный внутри репозитория
на одном из сервисе совместной разработки: **GitHub** или **GitLab**.

2. Структура репозитория должна иметь следующий вид:
```
cmake/HunterGate.cmake
sources/
- pack.cpp 
- unpack.cpp
CMakeLists.txt
```

3. Сериализованные данные должны пройти проверку валидатора соответствующего варианту формата
- [yamllint](https://github.com/adrienverge/yamllint)
- [jsonlint](https://github.com/zaach/jsonlint)
- [xmllint](http://xmlsoft.org/xmllint.html)

4. Результаты проверки валидности должны быть добавлены в отчет.

5. Необходимо составить отчет о проделанной работе, разместить его на сервисе быстрой публикации фрагментов кода **Gist.GitHub**
и прислать ссылку на отчет личным сообщением в **Slack**.

## Ссылки
Библиотеки для работы с различными форматами данных:
- [json](https://github.com/nlohmann/json)
- [yaml](https://github.com/jbeder/yaml-cpp)
- [xml](https://github.com/zeux/pugixml)
- [protobuf](https://github.com/google/protobuf)
