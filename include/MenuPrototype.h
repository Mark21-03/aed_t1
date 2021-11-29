#ifndef AED_T1_MENUPROTOTYPE_H
#define AED_T1_MENUPROTOTYPE_H



#include <iostream>

//WORK IN PROGRESS MENU EXAMPLE

using namespace std;

//Sets CLEAR variable for cleaning terminal GUI for linux and window
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif


string trimStr(string str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ')+1);
    return str;
}

bool emptyCin() {
    string bufferContent;
    getline(cin, bufferContent);
    trimStr(bufferContent);
    if (bufferContent.empty())
        return true;
    return false;
}

void giveMenuInputError(string &s){
    s =  "Invalid input was given.\nPlease provide a number from the menu.\n\n";
}


void subMenu(const string& menuTitle) {
    char userInput;
    string inputError;

    while (true) {
        system(CLEAR);

        if(!inputError.empty())
            cout<<inputError;
        inputError = "";

        //Start of MENU
        cout << "=================" << endl;
        cout << menuTitle<< endl;
        cout << "=================" << endl;
        cout << "  1)  Create" << endl;
        cout << "  2)  Read" << endl;
        cout << "  3)  Update" << endl;
        cout << "  4)  Delete" << endl;
        cout << "  5)  Go Back" << endl;
        cout << "  0)  Exit" << endl;
        cout << "================" << endl;
        cout << " > ";
        //End of MENU

        if ((cin >> userInput))
        {
            //raises error if more than 1 char is written by user
            if (!emptyCin()) {
                giveMenuInputError(inputError);
                continue;
            }

            //START OF MENU SELECTION
            switch (userInput)
            {
                case '0'://EXIT
                    cout<<"End of program.\n";
                    exit(1);

                case '1'://CREATE

                    break;
                case '2'://READ

                    break;
                case '3'://UPDATE

                    break;
                case '4'://DELETE

                    break;
                case '5'://Go Back
                    goto END_MENU;
                default:
                    giveMenuInputError(inputError);
                    break;
            }
            //END OF MENU SELECTION

            continue;

        }else
        {
            //deals with errors when trying to get the char
            if (cin.eof()){
                cout<<"\nEnd of program.\n";
                exit(1); //detects CTRL+Z
            }

            cin.clear();cin.ignore(1000, '\n');
            giveMenuInputError(inputError);
            continue;
        }

        END_MENU:break;
    }
}


void mainMenu() {
    char userInput;
    string inputError;

    while (true) {
        system(CLEAR);

        if(!inputError.empty())
            cout<<inputError;
        inputError = "";

        //Start of MENU
        cout << "=================" << endl;
        cout << "       Menu      " << endl;
        cout << "=================" << endl;
        cout << "  1)  Create" << endl;
        cout << "  2)  Read" << endl;
        cout << "  3)  Update" << endl;
        cout << "  4)  Delete" << endl;
        cout << "  0)  Exit" << endl;
        cout << "================" << endl;
        cout << " > ";
        //End of MENU

        if ((cin >> userInput))
        {
            //raises error if more than 1 char is written by user
            if (!emptyCin()) {
                giveMenuInputError(inputError);
                continue;
            }

            //START OF MENU SELECTION
            switch (userInput)
            {
                case '0'://EXIT
                    cout<<"End of program.\n";
                    exit(1);
                case '1'://CREATE
                    subMenu("   CREATE MENU");
                    break;
                case '2'://READ
                    subMenu("   READ MENU");
                    break;
                case '3'://UPDATE
                    subMenu("  UPDATE MENU");
                    break;
                case '4'://DELETE
                    subMenu("  DELETE MENU");
                    break;
                default:
                    giveMenuInputError(inputError);
                    break;
            }
            //END OF MENU SELECTION

            continue;

        }else
        {
            //deals with errors when trying to get the char
            if (cin.eof()){
                cout<<"\nEnd of program.\n";
                exit(1); //detects CTRL+Z
            }

            cin.clear();cin.ignore(1000, '\n');
            giveMenuInputError(inputError);
            continue;
        }
    }
}



#endif //AED_T1_MENUPROTOTYPE_H
