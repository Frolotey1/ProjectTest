#include "CryptoTestEasy.h"
#include "Ciphers.h"


static std::string randomWord() {
    static const std::vector<std::string> words = {
        "hello", "world", "crypto", "security", "algorithm", "programming",
        "computer", "science", "encryption", "main", "vector"
    };
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, words.size() - 1);
    return words[dist(gen)];
}

static std::string toLower(const std::string& s) {
    std::string res = s;
    for (char& c : res) c = tolower(c);
    return res;
}

void Test() {
    std::string original = randomWord();
    int shift = rand() % 25 + 1;
    std::string cipher = caesarEncrypt(original, shift);

    std::cout << "\n=== Задача 1: Шифр Цезаря ===\n";
    std::cout << "Зашифрованное слово: " << cipher << "\n";
    std::cout << "Введите расшифрованное слово (или 'exit'): ";
    std::string answer;
    Getline(answer);

    if (answer == "exit" || answer == "Exit") return;
    if (toLower(answer) == original) {
        std::cout << "Правильно!\n";
    }
    else {
        std::cout << "Неправильно.\n";
    }
}

void TestTwo() {
    std::string original = randomWord();
    std::string cipher = atbash(original);

    std::cout << "\n=== Задача 2: Шифр Атбаш ===\n";
    std::cout << "Зашифрованное слово: " << cipher << "\n";
    std::cout << "Введите расшифрованное слово (или 'exit'): ";
    std::string answer;
    Getline(answer);

    if (answer == "exit" || answer == "Exit") return;
    if (toLower(answer) == original) {
        std::cout << "Правильно!\n";
    }
    else {
        std::cout << "Неправильно.\n";
    }
}

void TestFree() {
    char key = 'K';
    std::string original = randomWord();
    std::string cipher = xorEncrypt(original, key);

    std::cout << "\n=== Задача 3: XOR-шифрование ===\n";
    std::cout << "Зашифрованное слово (hex): ";
    for (unsigned char c : cipher) {
        std::cout << std::hex << (int)c << " ";
    }
    std::cout << "\nВведите расшифрованное слово (или 'exit'): ";
    std::string answer;
    Getline(answer);

    if (answer == "exit" || answer == "Exit") return;
    if (toLower(answer) == original) {
        std::cout << "Правильно!\n";
    }
    else {
        std::cout << "Неправильно.\n";
    }
}

void TestFour() {
    std::string original = randomWord();
    std::string cipher = swapNibbles(original);

    std::cout << "\n=== Задача 4: Перестановка тетрад ===\n";
    std::cout << "Зашифрованное слово (hex): ";
    for (unsigned char c : cipher) {
        std::cout << std::hex << (int)c << " ";
    }
    std::cout << "\nВведите расшифрованное слово (или 'exit'): ";
    std::string answer;
    Getline(answer);

    if (answer == "exit" || answer == "Exit") return;
    if (toLower(answer) == original) {
        std::cout << "Правильно!\n";
    }
    else {
        std::cout << "Неправильно.\n";
    }
}

void TestFive() {
    char iv = 'I';
    std::string original = randomWord();
    std::string cipher = cbcEncrypt(original, iv);

    std::cout << "\n=== Задача 5: Блочное шифрование (CBC) ===\n";
    std::cout << "Зашифрованное слово (hex): ";
    for (unsigned char c : cipher) {
        std::cout << std::hex << (int)c << " ";
    }
    std::cout << "\nВведите расшифрованное слово (или 'exit'): ";
    std::string answer;
    Getline(answer);

    if (answer == "exit" || answer == "Exit") return;
    if (toLower(answer) == original) {
        std::cout << "Правильно!\n";
    }
    else {
        std::cout << "Неправильно.\n";
    }
}



