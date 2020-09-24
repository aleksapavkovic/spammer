#include <iostream>
#include <random>
#include <cstdlib>      
#include <time.h>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

/*
    Made by: @cryptoplusplus
    Support me on:
    Facebook: /aleksa.pavkovic.7
    Instagram: @cryptoplusplus
    Github: crypto-plus-plus
    ENJOY!
*/


string msg;     //Customized message
int num, lenght; //Repeating number of messages, message lenght
char choice, y_n; //Main menu vars

void Start() {      //Begin
    cout << "Made by: @cryptoplusplus" << endl;
    cout << R"(
________                                                 
__  ___/_____________ _______ __________ ________________
_____ \___  __ \  __ `/_  __ `__ \_  __ `__ \  _ \_  ___/
____/ /__  /_/ / /_/ /_  / / / / /  / / / / /  __/  /    
/____/ _  .___/\__,_/ /_/ /_/ /_//_/ /_/ /_/\___//_/     
       /_/                                                  
)" << '\n';
    cout << "" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "|                 Welcome to Spammer!                   |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    Sleep(3000);
    cout << "[To start type Y]                        [To exit type E]" << endl;
    cout << ">> ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {
        goto start;
    }
    else if (choice == 'E' || choice == 'e') {
        cout << "Exiting... " << endl;
        exit(0);
    }
    else {
        cout << "You entered wrong character, exiting... " << endl;
        exit(0);
    }
    start:
    cout << "Please enter amount of messages that are going to be spammed: " << endl;
    cout << ">> ";
    cin >> num;
    cout << "Do you want to spam random message or customized (R - Random, C - Customized): " << endl;
    cout << ">> ";
    cin >> y_n;
    if (y_n == 'C' || y_n == 'c') {     //Customized message case
        cout << "Please specify your string: " << endl;
        cout << ">> ";
        cin.ignore();
        string msg;
        getline(cin, msg);
        cout << "*NOTE* - PUT CURSOR ON TEXT BOX THAT IS GOING TO BE SPAMMED!" << endl;
        Sleep(4000);
        for (int i = 6; i >= 1; i--) {
            cout << "Starting in: " << i << "..." << endl;
            Sleep(900);
        }
        vector<INPUT> vec;
        for (auto ch : msg)
        {
            INPUT input = { 0 };
            input.type = INPUT_KEYBOARD;
            input.ki.dwFlags = KEYEVENTF_UNICODE;
            input.ki.wScan = ch;
            vec.push_back(input);

            input.ki.dwFlags |= KEYEVENTF_KEYUP;
            vec.push_back(input);
        }
        for (int i = 0; i < num; i++) {
            SendInput(vec.size(), vec.data(), sizeof(INPUT));
            keybd_event(VK_RETURN, 0, 0, 0);
            Sleep(200);
        }
    }
    else if (y_n == 'R' || y_n == 'r') {    //Random message case
        cout << "Enter message character length: " << endl;
        cout << ">> ";
        cin >> lenght;
        cout << "*NOTE* - PUT CURSOR ON TEXT BOX THAT IS GOING TO BE SPAMMED!" << endl;
        Sleep(4000);
        for (int i = 6; i >= 1; i--) {
            cout << "Starting in: " << i << "..." << endl;
            Sleep(900);
        }
        int keys[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, VK_MULTIPLY, VK_DIVIDE, VK_ADD, VK_SUBTRACT};
        random_device seed;
        mt19937 engine(seed());
        uniform_int_distribution<int> choose(0, 38 - 1);
        for (int i = 0; i < num; i++) {
            for (int i = 0; i < lenght; i++) {
                keybd_event(keys[choose(engine)], 0, 0, 0);
            }
            keybd_event(VK_RETURN, 0, 0, 0);
        }
    }

    else {
        cout << "\033[0;37;40mYou entered wrong character! Exiting... " << endl;
        exit(0);
    }
}

int main()
{
    Start();
    return 0;
}


