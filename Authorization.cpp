
#include "Authorization.h"
#include "CryptoTestEasy.h"


std::vector<User> users = { {"user", "user", "Клиент"} };
std::string currentUserStatus;

bool CheckLogin(const std::string& str)
{
    // Проверка длины
    if (str.size() < 5 || str.size() > 20) {
        std::cout << "Недопустимая длина логина. От 5 до 20 символов\n";
        Sleep(1500);
        return false;
    }

    // Проверка допустимых символов(только буквы)
    for (char c : str) {
        if (!isalpha(c)) {
            std::cout << "Некорректные символы в логине. Разрешены только буквы A-Z, a-z\n";
            Sleep(1500);
            return false;
        }
    }

    // Уникальность
    for (const auto& user : users) {
        if (user.login == str) {
         
            std::cout << "Пользователь с таким логином уже существует!\n";
         ;
            Sleep(1500);
            return false;
        }
    }
    return true;
}

// Проверка pass
bool CheckPass(const std::string& str) {
    if (str.size() < 5 || str.size() > 64) {
        std::cout << "Недопустимая длина пароля! От 5 до 64 символов\n";
        Sleep(1500);
        return false;
    }

    // символы ascii
    std::unordered_set<char> allowed;
    for (char c = '!'; c <= '~'; ++c) {
        allowed.insert(c);
    }

    for (char c : str) {
        if (allowed.find(c) == allowed.end()) {
            std::cout << "Некорректные символы в пароле. Разрешены только печатные ASCII символы.\n";
            Sleep(1500);
            return false;
        }
    }

    // Специальные символы
    std::unordered_set<char> special = {
        '!', '@', '#', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
        '/', '?', '|', '\\', '\"', '\'', ',', '.', '>', '<', '~', '`', ':',
        ';', '{', '}', '[', ']'
    };

    int specialCount = 0;
    for (char c : str) {
        if (special.count(c)) {
            specialCount++;
            if (specialCount >= 3) break;
        }
    }

    if (specialCount < 3) {
        std::cout << "Требуется минимум 3 специальных символа\n";
        Sleep(1500);
        return false;
    }

    return true;
}

bool Login() {
    std::string choose;
    std::string login, pass;
    while (true)
    {
        std::cout << "\n=== КРИПТОГРАФИЧЕСКИЙ ТРЕНАЖЁР ===\n";
        std::cout << "\n=== Вход в систему ===\n";
        std::cout << "1 – Вход\n";
        std::cout << "2 – Регистрация\n";
        std::cout << "0 – Выход\n";
        std::cout << "Ваш выбор: ";
        Getline(choose);

        if (choose == "0") {
            return false;
        }
        else if (choose == "1") {
            
            
            while (true) {
                std::cout << "Введите логин или \"exit\" для возврата в меню: ";
                Getline(login);
                if (login == "exit") break; 

                std::cout << "Введите пароль: ";
                Getline(pass);

                // Поиск в векторе
                bool found = false;
                for (const auto& user : users) {
                    if (user.login == login && user.password == pass) {
                        currentUserStatus = user.status;
                        std::cout << "\nДобро пожаловать, " << login << "\n";
                        std::cout << "Ваш статус: " << currentUserStatus << "\n";
                        system("pause");
                        return true;
                    }
                }

                if (!found) {
                    std::cout << "Неверный логин или пароль!\n";
                    Err(1500);
                }
            }
        }
        else if (choose == "2") {
            // Регистрация
            RegisterUser();
      
        }
        else {
            Err(); // неверный ввод
        }
    }
}

void RegisterUser()
{
    std::string login, pass;

    // Ввод логина
    while (true) {
        system("cls");
        std::cout << "\t=== Регистрация нового пользователя ===\n";
        std::cout << "Введите логин (от 5 до 20 символов, только буквы) или \"exit\": \n";
        Getline(login);
        if (login == "exit" || login == "Exit") {
            std::cout << "Регистрация отменена.\n";
            Sleep(1500);
            return;
        }
        if (CheckLogin(login)) break;
    }

    // Ввод пароля
    while (true) {
        system("cls");
        std::cout << "\n=== КРИПТОГРАФИЧЕСКИЙ ТРЕНАЖЁР ===\n";
        std::cout << "\t=== Регистрация ===\n";
        std::cout << "Введите пароль (от 5 до 64 символов, минимум 3 спецсимвола) или \"exit\": \n";
      
        Getline(pass);
        if (pass == "exit" || pass == "Exit") {
            std::cout << "Регистрация отменена.\n";
            Sleep(1500);
            return;
        }
        if (CheckPass(pass)) break;
    }

    users.push_back({ login, pass, "Клиент" });

    std::cout << "\nПользователь успешно зарегистрирован\n";
   
    system("pause");
}