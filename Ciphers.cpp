#include "Ciphers.h"

// Объявления всех криптографических функций.



// Шифр Цезаря: каждая буква сдвигается на shift позиций (по модулю 26)
std::string caesarEncrypt(const std::string& text, int shift) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A'; // регистр и сдвиг по модулю
            result += (c - base + shift) % 26 + base;
        }
        else {
            result += c; // возвращаем как есть
        }
    }
    return result;
}
// Расшифровка Цезаря: обратный сдвиг (26 - shift)
std::string caesarDecrypt(const std::string& cipher, int shift) {
    return caesarEncrypt(cipher, 26 - shift); // регистр и сдвиг по модулю обратно
}

// Шифр Атбаш: замена a->z, b->y и т.д. (обратим)
std::string atbash(const std::string& text) {
    std::string result;
    for (char c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A'; // зеркальное отоброжение
            result += base + (25 - (c - base));
        }
        else {
            result += c; 
        }
    }
    return result;
}
// XOR-шифрование с одним символом ключа (обратимо)
std::string xorEncrypt(const std::string& text, char key) {
    std::string result = text;
    for (char& c : result) c ^= key;
    return result;
}

std::string xorDecrypt(const std::string& cipher, char key) {
    return xorEncrypt(cipher, key);
}
// Перестановка тетрад: меняем местами старшие и младшие 4 бита каждого байта
std::string swapNibbles(const std::string& text) {
    std::string result;
    for (unsigned char c : text) {
        unsigned char swapped = ((c & 0x0F) << 4) | ((c & 0xF0) >> 4);
        result += static_cast<char>(swapped);
    }
    return result;
}
// Простейший режим "CBC": каждый символ XOR-ится с предыдущим зашифрованным символом.
// Для первого символа используется вектор инициализации (iv).
std::string cbcEncrypt(const std::string& text, char iv) {
    std::string result;
    char prev = iv;
    for (char c : text) {
        char encrypted = c ^ prev;
        result += encrypted;
        prev = encrypted;
    }
    return result;
}

std::string cbcDecrypt(const std::string& cipher, char iv) {
    std::string result;
    char prev = iv;
    for (char c : cipher) {
        char decrypted = c ^ prev;
        result += decrypted;
        prev = c;
    }
    return result;
}