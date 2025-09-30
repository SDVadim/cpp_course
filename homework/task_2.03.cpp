#include <iostream>

int main() 
{
  char num;
  std::cin >> num;
  switch (num)
  {
    case 'a' ... 'z': 
    {
      std::cout << "Это строчная буква \n";
      break;
    }

    case 'A' ... 'Z':
    {
      std::cout << "Это заглавная буква \n";
      break;
    }

    case '0' ... '9':
    {
      std::cout << "Это цифра \n";
      break;
    }

    [[likely]] case '!':
    [[likely]] case ',':
    [[likely]] case '.':
    [[likely]] case ':' ... ';':
    [[likely]]case '?':
    {
      std::cout << "Это знак препинания \n";
      break;
    }

    default: { std::cout << "Это другой символ \n"; }
  }
}