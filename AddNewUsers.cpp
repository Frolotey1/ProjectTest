#include "AddNewUsers.h"
#include "Windows.h"
#include <unordered_set>
bool CheckLogin(const std::string& str)
{
    for (size_t i = 0; i < userSize; i++)
    {
        if (str == loginArr[i])
        {
            std::cout << "Такой пользователь существует!\n";
            Sleep(1500);
            return false;
        }
    }

    if (str.size() < 5 || str.size() >= 20)
    {
       
        std::cout << "Недопустимая длина логина. От 5 до 20 символов\n";
      
        Sleep(1500);
        return false;
    }

    std::unordered_set<char> specialSymbols;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        specialSymbols.insert(i);
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        specialSymbols.insert(i);
    }

    for (char symb : str)
    {
        if (!specialSymbols.count(symb))
        {
           
            std::cout << "Некорректные символы в логине\n\n";
           
            Sleep(1500);
            return false;
        }
    }
    return true;
}

bool CheckPass(const std::string& str)
{
    if (str.size() < 5 || str.size() >= 64)
    {

        std::cout << "Недопустимая длина пароля! От 5 до 64 символов\n";

        Sleep(1500);
        return false;
    }

    int symbolsCount = 0;
    std::unordered_set<char> specialSymbols;
    std::unordered_set<char> passSymbols{ '!', '@', '#', '%', '^', '&', '*', '(',')', '-', '_', '=', '+', '/', '?', '|', '\\', '\"', '\'', ',', '.', '>', '<', '~', '`', ':', ';', '{','}', '[', ']' };

    for (char i = '!'; i <= '~'; i++)
    {
        specialSymbols.insert(i);
    }

    for (char symb : str)
    {
        if (!specialSymbols.count(symb))
        {

            std::cout << "Некорректные символы в пароле\n\n";

            Sleep(1500);
            return false;
        }
    }

    for (char symb : str)
    {
        if (passSymbols.count(symb))
        {
            symbolsCount++;
            if (symbolsCount == 3)
            {
                return true;
            }
        }
    }

    std::cout << "Требуется минимум 3 специальных символа\n\n";
    Sleep(1500);
    return false;
}

    void AddNewUser()
    {
        std::string newLogin, newPass, newRole, choose;
        bool exit = true;

        while (true)
        {
            exit = true;

            // Ввод логина
            while (true)
            {
                system("cls");
                std::cout << "\tСоздание нового пользователя\n";
                std::cout << "Введите логин нового пользователя или \"exit\": ";
                Getline(newLogin);
                if (newLogin == "exit")
                {
                    std::cout << "Операция добавления пользователя прервана!\n\n";
                    Sleep(1500);
                    exit = false;
                    break;
                }

                if (CheckLogin(newLogin))
                {
                    break;
                }
            }
            if (!exit) break;

            // Ввод пароля
            while (true)
            {
                system("cls");
                std::cout << "\tСоздание нового пользователя\n";
                std::cout << "Введите пароль нового пользователя или \"exit\": ";
                Getline(newPass);
                if (newPass == "exit")
                {
                    std::cout << "Операция добавления пользователя прервана!\n\n";
                    Sleep(1500);
                    exit = false;
                    break;
                }
                if (CheckPass(newPass))
                {
                    break;
                }
            }
            if (!exit) break;

            // Выбор роли
            while (true)
            {
                system("cls");
                std::cout << "\tСоздание нового пользователя\n";
            
                Getline(choose);
                if (choose == "exit")
                {
                    std::cout << "Операция добавления пользователя прервана!\n\n";
                    Sleep(1500);
                    exit = false;
                    break;
                }
                if (choose == "1")
                {
                    newRole = userStatus[1];
                    break;
                }
                else if (choose == "2")
                {
                    newRole = userStatus[2];
                    break;
                }
                else
                {
                    Err();
                }
            }
            if (!exit) break;

            // Подтверждение
            while (true)
            {
                system("cls");
                std::cout << "Пользователь: " << newLogin << "\n";
                std::cout << "Пароль: " << newPass << "\n";
                std::cout << "Роль: " << newRole << "\n\n";
                std::cout << "Подтвердить?\n1 - Да\n2 - Нет\nВыбор: ";
                Getline(choose);
                if (choose == "1")
                {
                    userSize++;
                    std::string* loginArrTemp = new std::string[userSize];
                    std::string* passArrTemp = new std::string[userSize];
                    std::string* statusArrTemp = new std::string[userSize];
                   

                    SwapArr(loginArrTemp, loginArr, userSize - 1);
                    SwapArr(passArrTemp, passArr, userSize - 1);
                    SwapArr(statusArrTemp, statusArr, userSize - 1);
                  

                    loginArrTemp[userSize - 1] = newLogin;
                    passArrTemp[userSize - 1] = newPass;
                    statusArrTemp[userSize - 1] = newRole;
                 

                    delete[] loginArr;
                    delete[] passArr;
                    delete[] statusArr;
                   

                    loginArr = loginArrTemp;
                    passArr = passArrTemp;
                    statusArr = statusArrTemp;
                  

          
                    std::cout << "Пользователь успешно добавлен!\n\n";
                   
                    Sleep(1500);
                    break;
                }
                else if (choose == "2")
                {
                    std::cout << "Отмена\n";
                    Sleep(1500);
                    break;
                }
                else
                {
                    Err();
                }
            }
            break;
        }
    }
}