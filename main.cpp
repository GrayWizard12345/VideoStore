#include <iostream>
#include <climits>
#include <algorithm>
#include "Category.h"
#include "Admin.h"


using std::cout;
using std::cin;
using std::string;

bool is_numeric(string& str){
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
int get_int_input(string& message, int lower_bound = INT_MIN, int upper_bound = INT_MAX)
{
    string input;
    int num;
    do
    {
        cout << message;
        cin >> input;
        cin.ignore();
        if (not is_numeric(input))
            cout << "Only numeric input allowed. Try again.\n";
        else {
            num = std::stoi(input);
            if (num < lower_bound){
                cout << "Input is too small.\n";
                continue;
            }
            else if (num > upper_bound){
                cout << "Input is too large.\n";
                continue;
            } else break;
        };
    } while (true);

    return num;
}

#define ADMIN_COUNT 2
Admin* createAdmins(){
    string id = "Dima";
    string pwd = "123";
    string id1 = "John";
    string pwd1 = "321";
    Admin a(id, pwd);
    Admin b(id1, pwd1);
    Admin static admins[] = {a, b};
    return admins;
}

Video* createVideo()
{
    string title = "Venom";
    string star1 = "Tom Hardy";
    string star2 = "Riz Ahmed";
    string director = "Direcotr";
    string stars[2] = {star1, star2};
    auto v = new Video(Categories::Action, title, 140, stars, director);
    return v;
}

Admin* authentication_loop(Admin* admins, int len){
    string id;
    string pwd;
    Admin* authenticated = nullptr;
    do {
        cout << "Please Enter user id:";
        cin >> id;
        cin.ignore();
        cout << "Please Enter password:";
        cin >> pwd;
        cin.ignore();
        for (int i = 0; i < len; ++i) {
            if(admins[i].authenticate(id, pwd))
            {
                authenticated = &admins[i];
            }
        }

        if (authenticated != nullptr)
            break;
        cout << "Please enter correct ID/Password to proceed. or Ctrl+C to exit.\n";
    } while (true);

    return authenticated;
}



int main() {
    std::cout << "Welcome to the Dmitriy's Video Store Management app!" << std::endl;
    Admin* admins = createAdmins();
    Admin* admin = authentication_loop(admins, ADMIN_COUNT);

    string video_store_info = "******************************************************************************\n"
                              "*\t\t\tKENZ Videos & Records Sdn Bhd \t\t\t\t                      *\n"
                              "*\t\t\t21 & 21M, Jalan 6/11, Taman Kommersial Pandan Indah,\t\t          * \n"
                              "*\t\t\tPandan Indah,55100 Kuala Lumpur, Malaysia.\t\t\t          *\n"
                              "*\t\t\tContact: +603-4296 0377\t\t\t\t\t\t          *\n"
                              "*\t\t\tWebsite: http://www.kenz.com.my/\t\t\t\t\t          *                ******************************************************************************";
    cout << video_store_info;

    bool exit = false;
    do {
        string message = "Available categories:\n"
                "1.Action\n"
                "2.Adventure\n"
                "3.Comedy\n"
                "4.Exit\n";
        int choice = get_int_input(message, 1, 4);

        if (choice == 4)
        {
            cout << "Bye!";
            break;
        }



    }



    return 0;
}
