#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// This is a program that creates an itemized bill for a store

int main(){
    std::string names[9] = {"PENCIL", "PEN", "GEOMETRY BOX",  "POUCH", "SHEET(A2 SIZE)", "TAPE", "STICKERS", "MINI DRAFTER", "INK POT"};
    int price[9] = {5, 10, 100, 50, 10 , 15, 10, 250, 30};
    std::string ids[9] = {"ST-001", "ST-002", "ST-003", "ST-004", "ST-005", "ST-006", "ST-007", "ST-008", "ST-009"};
    
    std::ofstream file;
    int total = 0;
    file.open("BILL.txt");

    std::cout << "Enter 1 for pencil." << std::endl;
    std::cout << "Enter 2 for pen." << std::endl;
    std::cout << "Enter 3 for geometery box." << std::endl;
    std::cout << "Enter 4 for pouch." << std::endl;
    std::cout << "Enter 5 for sheet." << std::endl;
    std::cout << "Enter 6 for tape." << std::endl;
    std::cout << "Enter 7 for stickers." << std::endl;
    std::cout << "Enter 8 for mini drafter." << std::endl;
    std::cout << "Enter 9 for ink pot." << std::endl;

    std::string str = "******************** ABC STATIONARY ********************\n";
    file << str;
    file << "\n";
    
    str = "ITEM-ID  ITEM-NAME           PRICE  QUANTITY  AMOUNT\n";
    file << str;
    file << "\n";
    
    int quan[9] = {};

    for(int i = 0; i < 9; i++){
label1:
        std::cout << "How many " << names[i] << " do you want(0-9): ";
        std::cin >> quan[i];
        if(quan[i] > 9 || quan[i] < 0){
            goto label1;
        }
    }

    for (int i = 0; i < 9; i++){
        std::string str;
        if(quan[i] == 0){
            continue;
        }
        file << ids[i];
        str = "   ";
        file << str;

        file << names[i];
        int n = 20 - names[i].size();
        while(n-- > 0){
            file << " ";
        }

        file << std::to_string(price[i]);
        n = 7 - std::to_string(price[i]).size();
        while(n-- > 0){
            file << " ";
        }

        file << std::to_string(quan[i]);
        str = "         ";
        file << str;

        file << std::to_string(price[i]*quan[i]);
        file << "\n";
        total += price[i]*quan[i];
    }
    int n = 38;
    while(n-- > 0){
        file << " ";
    }
    file << "Total - ";
    file << total;


    return 0;
}



