#include "Levels.h"
#include "CryptoTestEasy.h"
#include "Ciphers.h"



static std::vector<std::string> encryptedMessages;

static void printHex(const std::string& s) {
    for (unsigned char c : s) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
    }
    std::cout << std::dec;
}

static void printStored() {
    if (encryptedMessages.empty()) {
        std::cout << "Нет сохранённых зашифрованных сообщений.\n";
        return;
    }
    std::cout << "Сохранённые зашифрованные сообщения:\n";
    for (size_t i = 0; i < encryptedMessages.size(); ++i) {
        std::cout << i + 1 << ": ";
        printHex(encryptedMessages[i]);
        std::cout << "\n";
    }
}

static std::string getInput(const std::string& prompt) {
    std::cout << prompt;
    std::string s;
    Getline(s);
    return s;
}

static int getChoice(const std::string& prompt, int min, int max) {
    while (true) {
        std::string s = getInput(prompt);
        if (s == "exit" || s == "Exit") return -1;
        if (!IsNumber(s)) {
            Err();
            continue;
        }
        int val = std::stoi(s);
        if (val >= min && val <= max) return val;
        Err();
    }
}

static void caesarHandler(int level) {
    int action = getChoice("1 – зашифровать, 2 – расшифровать, 0 – назад: ", 0, 2);
    if (action == 0) return;
    if (action == 1) {
        std::string text = getInput("Введите текст: ");
        int shift = (level == 2) ? 3 : getChoice("Введите сдвиг (1-25): ", 1, 25);
        if (shift == -1) return;
        std::string enc = caesarEncrypt(text, shift);
        encryptedMessages.push_back(enc);
        std::cout << "Зашифровано: ";
        printHex(enc);
        std::cout << " (номер " << encryptedMessages.size() << ")\n";
    }
    else {
        if (encryptedMessages.empty()) {
            std::cout << "Нет сохранённых сообщений.\n";
            return;
        }
        printStored();
        int idx = getChoice("Выберите номер: ", 1, encryptedMessages.size());
        if (idx == -1) return;
        int shift = (level == 2) ? 3 : getChoice("Введите сдвиг (1-25): ", 1, 25);
        if (shift == -1) return;
        std::string dec = caesarDecrypt(encryptedMessages[idx - 1], shift);
        std::cout << "Расшифровано: " << dec << "\n";
    }
}

static void atbashHandler(int level) {
    int action = getChoice("1 – зашифровать, 2 – расшифровать, 0 – назад: ", 0, 2);
    if (action == 0) return;
    if (action == 1) {
        std::string text = getInput("Введите текст: ");
        std::string enc = atbash(text);
        encryptedMessages.push_back(enc);
        std::cout << "Зашифровано: ";
        printHex(enc);
        std::cout << " (номер " << encryptedMessages.size() << ")\n";
    }
    else {
        if (encryptedMessages.empty()) {
            std::cout << "Нет сохранённых сообщений.\n";
            return;
        }
        printStored();
        int idx = getChoice("Выберите номер: ", 1, encryptedMessages.size());
        if (idx == -1) return;
        std::string dec = atbash(encryptedMessages[idx - 1]);
        std::cout << "Расшифровано: " << dec << "\n";
    }
}

static void xorHandler(int level) {
    int action = getChoice("1 – зашифровать, 2 – расшифровать, 0 – назад: ", 0, 2);
    if (action == 0) return;
    if (action == 1) {
        std::string text = getInput("Введите текст: ");
        std::string enc;
        if (level == 2) {
            char key = 'K';
            enc = xorEncrypt(text, key);
        }
        else {
            std::string key = getInput("Введите ключ-строку: ");
            enc = text;
            for (size_t i = 0; i < text.size(); ++i)
                enc[i] = text[i] ^ key[i % key.size()];
        }
        encryptedMessages.push_back(enc);
        std::cout << "Зашифровано: ";
        printHex(enc);
        std::cout << " (номер " << encryptedMessages.size() << ")\n";
    }
    else {
        if (encryptedMessages.empty()) {
            std::cout << "Нет сохранённых сообщений.\n";
            return;
        }
        printStored();
        int idx = getChoice("Выберите номер: ", 1, encryptedMessages.size());
        if (idx == -1) return;
        std::string cipher = encryptedMessages[idx - 1];
        std::string dec;
        if (level == 2) {
            char key = 'K';
            dec = xorDecrypt(cipher, key);
        }
        else {
            std::string key = getInput("Введите ключ-строку: ");
            dec = cipher;
            for (size_t i = 0; i < cipher.size(); ++i)
                dec[i] = cipher[i] ^ key[i % key.size()];
        }
        std::cout << "Расшифровано: " << dec << "\n";
    }
}

static void swapHandler(int level) {
    int action = getChoice("1 – зашифровать, 2 – расшифровать, 0 – назад: ", 0, 2);
    if (action == 0) return;
    if (action == 1) {
        std::string text = getInput("Введите текст: ");
        std::string enc = swapNibbles(text);
        encryptedMessages.push_back(enc);
        std::cout << "Зашифровано: ";
        printHex(enc);
        std::cout << " (номер " << encryptedMessages.size() << ")\n";
    }
    else {
        if (encryptedMessages.empty()) {
            std::cout << "Нет сохранённых сообщений.\n";
            return;
        }
        printStored();
        int idx = getChoice("Выберите номер: ", 1, encryptedMessages.size());
        if (idx == -1) return;
        std::string dec = swapNibbles(encryptedMessages[idx - 1]);
        std::cout << "Расшифровано: " << dec << "\n";
    }
}

static void cbcHandler(int level) {
    int action = getChoice("1 – зашифровать, 2 – расшифровать, 0 – назад: ", 0, 2);
    if (action == 0) return;
    if (action == 1) {
        std::string text = getInput("Введите текст: ");
        char iv;
        if (level == 2) {
            iv = 'I';
        }
        else {
            std::string ivStr = getInput("Введите IV (один символ): ");
            iv = ivStr.empty() ? 'I' : ivStr[0];
        }
        std::string enc = cbcEncrypt(text, iv);
        encryptedMessages.push_back(enc);
        std::cout << "Зашифровано: ";
        printHex(enc);
        std::cout << " (номер " << encryptedMessages.size() << ")\n";
    }
    else {
        if (encryptedMessages.empty()) {
            std::cout << "Нет сохранённых сообщений.\n";
            return;
        }
        printStored();
        int idx = getChoice("Выберите номер: ", 1, encryptedMessages.size());
        if (idx == -1) return;
        char iv;
        if (level == 2) {
            iv = 'I';
        }
        else {
            std::string ivStr = getInput("Введите IV (один символ): ");
            iv = ivStr.empty() ? 'I' : ivStr[0];
        }
        std::string dec = cbcDecrypt(encryptedMessages[idx - 1], iv);
        std::cout << "Расшифровано: " << dec << "\n";
    }
}

void runLevel(int level) {
    std::cout << "\n=== Песочница (уровень " << level << ") ===\n";
    while (true) {
        std::cout << "\nВыберите шифр:\n";
        std::cout << "1 – Цезарь\n";
        std::cout << "2 – Атбаш\n";
        std::cout << "3 – XOR\n";
        std::cout << "4 – Перестановка тетрад (Swap Nibbles)\n";
        std::cout << "5 – Простой CBC\n";
        std::cout << "0 – Выход в главное меню\n";
        std::cout << "Ваш выбор: ";
        std::string choiceStr;
        Getline(choiceStr);
        if (choiceStr == "exit" || choiceStr == "Exit") return;
        if (!IsNumber(choiceStr)) {
            Err();
            continue;
        }
        int choice = std::stoi(choiceStr);
        if (choice == 0) return;
        switch (choice) {
        case 1: caesarHandler(level); break;
        case 2: atbashHandler(level); break;
        case 3: xorHandler(level); break;
        case 4: swapHandler(level); break;
        case 5: cbcHandler(level); break;
        default: Err(); break;
        }
    }
}