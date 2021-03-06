#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 

using namespace std;


bool Find_r(char* str, char c) {
    if (str[0] == 0) return false;
    if (str[0] == c) return true;
    if ((str[0] == 'a') || (str[0] == 'b') || (str[0] == 'c')) return Find_r(str + 1, str[0]);
    return Find_r(str + 1, 0);
}

void Process_r(char* str, char* newStr, char& state, int& strPos, int& newStrPos) {
    if (str[strPos] == 0) {
        if (state == 'a') newStr[newStrPos++] = 'a';
        if (state == 'b') newStr[newStrPos++] = 'b';
        if (state == 'c') newStr[newStrPos++] = 'c';
        newStr[newStrPos++] = '\0';
        return;
    }

    switch (str[strPos]) {
    case 'a':
        if (state == 'a') {
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            state = ' ';
        }
        else {
            if (state == 'b') newStr[newStrPos++] = 'b';
            if (state == 'c') newStr[newStrPos++] = 'c';
            state = 'a';
        }
        break;
    case 'b':
        if (state == 'b') {
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            state = ' ';
        }
        else {
            if (state == 'a') newStr[newStrPos++] = 'a';
            if (state == 'c') newStr[newStrPos++] = 'c';
            state = 'b';
        }
        break;
    case 'c':
        if (state == 'c') {
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            newStr[newStrPos++] = '*';
            state = ' ';
        }
        else {
            if (state == 'a') newStr[newStrPos++] = 'a';
            if (state == 'b') newStr[newStrPos++] = 'b';
            state = 'c';
        }
        break;
    default:
        if (state == 'a') newStr[newStrPos++] = 'a';
        if (state == 'b') newStr[newStrPos++] = 'b';
        if (state == 'c') newStr[newStrPos++] = 'c';
        newStr[newStrPos++] = str[strPos];
        state = ' ';
        break;
    }
    strPos++;

    Process_r(str, newStr, state, strPos, newStrPos);
    return;
}

int main() {
    char str[101];
    char newStr[151];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    bool changed = Find_r(str, 0);

    char state = ' ';
    int strPos = 0;
    int newStrPos = 0;

    Process_r(str, newStr, state, strPos, newStrPos);

    cout << "String: " << str << endl << endl;
    if (changed) {
        cout << "String was modified." << endl;
        cout << "Modified string (result): " << newStr << endl;
    }
    else {
        cout << "String was not modified." << endl;
    }

    return 0;
}