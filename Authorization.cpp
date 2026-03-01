#include "Authorization.h"
#include "windows.h"
size_t userSize = 1;
std::string userStatus[1] = { "Клиент" };
std::string* loginArr = new std::string[userSize]{ "user","user" };
std::string* passArr = new std::string[userSize]{ "user","user" };
std::string* statusArr = new std::string[userSize]{ userStatus[0]};
std::string currentStatus;
bool Login()
{
	
	std::string choose, login, pass;
	while (true)
	{
		std::cout << "\n=== КРИПТОГРАФИЧЕСКИЙ ТРЕНАЖЁР ===\n";
		std::cout << "\n=== ДЛЯ ПРОХОЖДЕНИЯ ТЕСТОВ НУЖЕН АККАУНТ ===\n";
		std::cout << "Есть два варианта входа:\n1 - Регистрация\n2 - Вход\n\"exit\" для выхода\n";
		std::cout << "Введите номер операции: ";
		Getline(choose);
		if (choose == "exit" || choose == "Exit") return false;

		if (choose == "1")
		{
			std::cout << "Регистрация\n";


		}
		else if (choose == "2")
		{
			std::cout << "Вход в аккаунт\n";
			std::cout << "Введите логин: ";
			Getline(login);
			std::cout << "Введите пароль: ";
			Getline(pass);
			if (login == "exit" || pass == "Exit") return false;
			
			if (login == loginArr[0] && pass == passArr[0])
			{
				std::cout << "Пользователь - " << loginArr[0] << "\n\nДобро пожаловать!\n";
				std::cout << "Ваш статус - " << statusArr[0] << "\n\n";
				currentStatus = statusArr[0];
				system("pause");
				return true;
			}
			
			for (std::size_t i = 0; i < userSize; i++)
			{
				std::cout << "Пользователь - " << loginArr[i] << "\n\nДобро пожаловать!\n";
				std::cout << "Ваш статус - " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				currentId = i;
				system("pause");
				return true;
			}

		}
		std::cout << "Неверный логин или пароль!\n";
		Sleep(1500);
	}

	
}