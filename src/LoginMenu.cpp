#include "../include/LoginMenu.h"

void LoginMenu::displayLogin(ostream &os) const {
    out::Modifier red(out::FG_RED);
    out::Modifier green(out::FG_GREEN);
    out::Modifier defaultc(out::FG_DEFAULT);
    out::Modifier bold(out::BOLD);
    out::Modifier reset(out::RESET);


    os << bold ;
    for (auto &c: menuImage) {
        if (c == 'g') {
            os << green;
        } else if (c == 'r') {
            os << red;
        } else {
            os << c;
        }
    }

    os << "                    Transportadora Aérea Feupiana                        \n";

    os << defaultc << reset;

}

LoginMenu::LoginMenu() {
    menuImage = std::string{
            "g        _____                    _____r                    _____          \n"
            "g       /\\    \\                  /\\    \\r                  /\\    \\         \n"
            "g      /::\\    \\                /::\\    \\r                /::\\    \\        \n"
            "g      \\:::\\    \\              /::::\\    \\r              /::::\\    \\       \n"
            "g       \\:::\\    \\            /::::::\\    \\r            /::::::\\    \\      \n"
            "g        \\:::\\    \\          /:::/\\:::\\    \\r          /:::/\\:::\\    \\     \n"
            "g         \\:::\\    \\        /:::/__\\:::\\    \\r        /:::/__\\:::\\    \\    \n"
            "g         /::::\\    \\      /::::\\   \\:::\\    \\r      /::::\\   \\:::\\    \\   \n"
            "g        /::::::\\    \\    /::::::\\   \\:::\\    \\r    /::::::\\   \\:::\\    \\  \n"
            "g       /:::/\\:::\\    \\  /:::/\\:::\\   \\:::\\    \\r  /:::/\\:::\\   \\:::\\    \\ \n"
            "g      /:::/  \\:::\\____\\/:::/  \\:::\\   \\:::\\____\\r/:::/  \\:::\\   \\:::\\____\\\n"
            "g     /:::/    \\::/    /\\::/    \\:::\\  /:::/    /r\\::/    \\:::\\   \\::/    /\n"
            "g    /:::/    / \\/____/  \\/____/ \\:::\\/:::/    /  r\\/____/ \\:::\\   \\/____/ \n"
            "g   /:::/    /                    \\::::::/    /r            \\:::\\    \\     \n"
            "g  /:::/    /                      \\::::/    /r              \\:::\\____\\    \n"
            "g  \\::/    /                       /:::/    /r                \\::/    /    \n"
            "g   \\/____/                       /:::/    /r                  \\/____/     \n"
            "g                                /:::/    /r                               \n"
            "g                               /:::/    /r                                \n"
            "g                               \\::/    /r                                 \n"
            "g                                \\/____/r                                  \n"
            "                                                                         \n"

    };
}
