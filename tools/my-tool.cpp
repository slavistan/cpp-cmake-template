#include <iostream>

#include <clara.hpp>

class MyClass {
  public:
    int MyAge = 24;
};

int main(int argc, char** argv)
{
  bool showHelp = false;
  int age = 0;
  std::string name;
  auto cli
      = clara::Opt( age, "age" )
          ["-a"]["--age"]
          ("What's your age?")
      | clara::Opt( name, "name" )
          ["-n"]["--name"]
          ("What's your name?")
      | clara::Help(showHelp);

  auto result = cli.parse(clara::Args(argc, argv));

  if(showHelp)
  {
    cli.writeToStream(std::cout);
    return 0;
  }

  if(!result){
    std::cerr << "Error in command line: " << result.errorMessage() << std::endl;
    exit(1);
  }

  std::cout << "Hi " << name << std::endl;
  std::cout << "Are you really " << age << " years old?" << std::endl;
}
