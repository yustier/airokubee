#include <stdio.h>

#include "version.h"

typedef enum {
    TODAY,
    RANDOM,
    YESTERDAY,
    DATE,
    CUSTOM,
    UPDATE_DICTIONARY,
    ABOUT,
    QUIT
} Menu;

typedef enum {
    GUESS,
    BEEHIVE,
    WORDS,
    POINTS,
    SHUFFLE,
    GIVEUP
} Game;

void welcome(void) {
    printf("AirokuBee %s\n\n", VERSION);
}

Menu ask_menu(void) {
    int ch;
    while (1) {
        printf("Command? (? for help) ");
        ch = getchar();
        while (getchar() != '\n');
        switch (ch) {
            case 't':
            case 'T':
                return TODAY;
            case 'r':
            case 'R':
                return RANDOM;
            case 'y':
            case 'Y':
                return YESTERDAY;
            case 'd':
            case 'D':
                return DATE;
            case 'c':
            case 'C':
                return CUSTOM;
            case 'u':
            case 'U':
                return UPDATE_DICTIONARY;
            case 'a':
            case 'A':
                return ABOUT;
            case 'q':
            case 'Q':
                return QUIT;
            case '?':
                printf("Commands:\n"
                       "  * Play (t)oday's game\n"
                       "  * Play a (r)andom game\n"
                       "  * Play (y)esterday's game\n"
                       "  * Play a game from a (d)ate\n"
                       "  * Play a (c)ustom game\n"
                       "  * (U)pdate the dictionary\n"
                       "  * (A)bout\n"
                       "  * (Q)uit\n\n");
            default:
                printf("Invalid command. Type ? to view command list again.\n");
        }
    }
}

void print_beehive(char letters[7]) {
    printf("       ___"
           "      /   \\"
           "  ___<  %c  >___"
           " /   \\\\___//   \\"
           "<  %c  >___<  %c  >"
           " \\___//   \\\\___/"
           "  ___<  %c  >___"
           " /   \\\\___//   \\"
           "<  %c  >___<  %c  >"
           " \\___//   \\\\___/"
           "     <  %c  >"
           "      \\___/\n",
           letters[1], letters[6], letters[2], letters[0], letters[5], letters[3], letters[4]);
}

Game ask_game(void) {
    while (1) {
        printf("Make a word or command? (? for help) ");
        (void) fgets(guess, sizeof(guess), stdin);
        switch (guess[0]) {
            case 'b':
            case 'B':
                return BEEHIVE;
            case 'w':
            case 'W':
                return WORDS;
            case 'p':
            case 'P':
                return POINTS;
            case 's':
            case 'S':
                return SHUFFLE;
            case 'g':
            case 'G':
                return GIVEUP;
            case '?':
                printf("Commands:\n"
                       "  * View the (b)eehive\n"
                       "  * View found (w)ords\n"
                       "  * View your (p)oints and the rank\n"
                       "  * (S)huffle\n"
                       "  * (G)ive up\n\n");
            default:
                return GUESS;
        }
    }
}

void game(void) {
    // ゲームする
}

void show_about(void) {
    printf("AirokuBee %s\n\n", VERSION);
    printf("AirokuBee is a tty friendly spelling bee game, inspired by FreeBee, which is\n"
           "a free and open implementation of the New York Times' Spelling Bee.\n"
           "\n"
           "FreeBee is made by Brian Callahan <bcallah@openbsd.org> and shared under\n"
           "ISC license.\n\n");

    printf("Press enter to go back to the menu.");
    while (getchar() != '\n');
}

int main(int argc, char const *argv[]) {

    welcome();

    Menu menu;
    while (menu != QUIT) {
        menu = ask_menu();
        switch (menu) {
            case TODAY:
                play_daily();
                break;
            case RANDOM:
                play_random();
                break;
            case YESTERDAY:
                play_yesterday();
                break;
            case DATE:
                play_date();
                break;
            case CUSTOM:
                play_custom();
                break;
            case UPDATE_DICTIONARY:
                update_dictionary();
                break;
            case ABOUT:
                show_about();
                break;
            case QUIT:
                printf("Thank you for playing!\n");
                break;
        }
    }
    return 0;
}
