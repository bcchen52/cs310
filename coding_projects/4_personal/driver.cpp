#include <iostream>
using namespace std;
#include <string>
#include <cassert>

#include "Voter.h"
#include "RegisterVoter.h"

int main(){
    RegisterVoter voters;
    bool quit = false;
    string command;
    string first;
    string last;
    int age;
    double num;

    while(!quit){
        cout << ": ";
        cin >> command;
        if(command == "quit"){
            break;
        } else if (command == "show-impact"){
            voters.show_impact();
        } else if (command == "chauffeur"){
            voters.chauffeur();
        }else if (command == "voter"){
            if (std::cin.peek() != '\n') {
                cin >> first;
            } else {
                cout << "No first name, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cin >> last;
            } else {
                cout << "No name, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cin >> age;
            } else {
                cout << "No age, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cout << "Invalid input, too many parameters." << endl;
            } else {
                voters.voter(first, last, age);
            }
        } else if (command == "voted"){
            if (std::cin.peek() != '\n') {
                cin >> first;
            } else {
                cout << "No first name, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cin >> last;
            } else {
                cout << "No name, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cin >> age;
            } else {
                cout << "No age, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cout << "Invalid input, too many parameters." << endl;
            } else {
                voters.voted(first, last, age);
            }
        } else if (command == "support"){
            if (std::cin.peek() != '\n') {
                cin >> first;
                if (std::cin.peek() != '\n') {
                    cin >> last;
                    if (std::cin.peek() != '\n') {
                        cin >> num;
                        if (std::cin.peek() != '\n') {
                            cout << "Invalid input, too many parameters." << endl;
                        } else {
                            voters.support(first, last, num);
                        }
                    } else {
                        cout << "No num, invalid" << endl;
                    }
                } else {
                    cout << "No name, invalid" << endl;
                }
            } else {
                cout << "No first name, invalid" << endl;
            }
        } else if (command == "reduce-likelihood"){
            if (std::cin.peek() != '\n') {
                cin >> first;
            } else {
                cout << "No first name, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cin >> last;
            } else {
                cout << "No name, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cin >> num;
            } else {
                cout << "No num, invalid" << endl;
            }
            if (std::cin.peek() != '\n') {
                cout << "Invalid input, too many parameters." << endl;
            } else {
                voters.reduce_likelihood(first, last, num);
            }
        } else {
            cout << "invalid command." << endl;
        }
    }

    /*
    voters.voter("Mike", "Lewis", 15);
    voters.voter("ike", "Lewis", 15);
    voters.voter("ike", "Lewis", 25);
    voters.voter("ike", "Lewis", 18);
    voters.voter("Ike", "Lewis", 15);
    voters.voter("Ike", "Lewis", 15);
    voters.voter("Ike", "Lewis", 17);
    voters.voter("Ike", "Lewis", 18);
    

    voters.show_impact();
    voters.support("ike", "Lewis", 15, 20);

    voters.chauffeur();
    voters.chauffeur();
    voters.chauffeur();

    */

    return 0;
}