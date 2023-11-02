#include <iostream>
#include <Windows.h>
#include <string>
#include <map>
#include <fstream>
std::string cin() {
    std::string data;
    std::cin.ignore();
    std::getline(std::cin, data);
    return data;
}
void reverse(std::string& string) {
    std::string ts;
    for (int i = 0; i < string.size(); i++) {
        ts += string[string.size() - 1 - i]; // size - 1 cuz size returns starting from 1 but index starts from 0 so ye
    }
    string = ts;
}
void encrypt(std::string& data) {
    std::string td;
    for (int i = 0; i < data.size(); i++) {
        char fc = data[i];
        int sc = (int)fc;
        std::string ti = std::to_string(sc - 1);
        int tioti = std::stoi(ti);
        td += (char)tioti;
    }
    reverse(td);
    data = td;
}
//ballin
//1 2 3 4 5 6
//"0" "1" "2" "3" "4" "5"


void decrypt(std::string& data) {
    std::string td;
    for (int i = 0; i < data.size(); i++) {
        int fc = (int)data[i];
        std::string ti = std::to_string(fc + 1);
        int tioti = std::stoi(ti);
        td += (char)tioti;
    }
    reverse(td);
    data = td;
}
//(char)string (no)
//(int)char, then string ok = "";, then for (int i = 0; i < int; i++){ ok.append(stoi(intToString[i]) - 1) }, then reverse ok string, then convert string to int, then (char)int, then save to file;
int main()
{
    std::string foption;
    std::cout << "1 = encrypt \n2 =  decrypt\n";
    std::cin >> foption;
    if (foption == "1") {
        std::cout << "\n1 = file \n2 = string\n";
        std::string soption;
        std::cin >> soption;
        if (soption == "1") {
            std::cout << "\nenter name of file: ";
            std::string toption = cin();
            //LPCWSTR conv = std::wstring(toption.begin(), toption.end()).c_str();
            
            std::cout << "\nenter string for encryption: ";
            std::string foption = cin();
            std::ofstream file(toption + ".txt");
            encrypt(foption);
            file << foption;
            file.close();
            /*
            HANDLE txt = CreateFile(conv, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ENCRYPTED, NULL);
            DWORD br;
            WriteFile(txt, foption.c_str(), br, &br, NULL);*/
        }
        if (soption == "2") {
            std::cout << "\nenter data:";
            std::string data = cin();
            encrypt(data);
            std::cout << "\n" << data;
        }
    }
    if (foption == "2") {
        std::cout << "\n1 = file \n2 = string\n";
        std::string soption;
        std::cin >> soption;
        if (soption == "1") {
            std::cout << "\nenter name of file: ";
            std::string toption;
            std::cin >> toption;
            //LPCWSTR conv = std::wstring(toption.begin(), toption.end()).c_str();
            std::ifstream ifile(toption + ".txt");
            std::string decryptstr = "";
            std::getline(ifile, decryptstr);
            decrypt(decryptstr);
            std::ofstream file;
            file.open(toption + ".txt");
            file << decryptstr;
            file.close();
            ifile.close();
            /*
            HANDLE txt = CreateFile(conv, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ENCRYPTED, NULL);
            DWORD br;
            WriteFile(txt, foption.c_str(), br, &br, NULL);*/
        }
        if (soption == "2") {
            std::cout << "\nenter data:";
            std::string data = cin();
            decrypt(data);
            std::cout << "\n" << data;
        }
    }    
}
