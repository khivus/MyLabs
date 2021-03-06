// Phone book manager by queue
// version 1.2.1
// 2022
// Kharin Aleksey
// Variant 14
// 1.)	Составить программу, которая содержит сведения телефонной книжки.
// Каждая запись включает :
// •	фамилия, имя;
// •	номер телефона;
// •	день рождения(массив из трех чисел).
// 2.)	Программа должна обеспечивать :
// •	хранение всех записей в виде односвязного списка(очередь);
// •	добавление новой записи;
// •	удаление из списка информации о человеке, день рождения которого приходится на дату, введенную с клавиатуры;
// •	вывод информации обо всех номерах телефонов;
// •	по запросу выводится информация о человеке, чья фамилия введена с клавиатуры.
// 3.)	Программа должна обеспечивать диалог с помощью меню.

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include<algorithm>

#define QUEUE struct list

using namespace std;

struct queue {
    char first_name[20];
    char last_name[20];
    double phone_number;
    int birthday_date[3];
};

QUEUE{
    queue items;
    QUEUE *next;
};

void insert(QUEUE** q, queue item) {
    QUEUE* current = *q;
    QUEUE* previous = 0;
    QUEUE* new_node;
    while (current) {
        previous = current;
        current = current->next;
    }
    new_node = (QUEUE*)malloc(sizeof(QUEUE));
    new_node->items = item;
    if (previous) {
        new_node->next = previous->next;
        previous->next = new_node;
    }
    else {
        *q = new_node;
        (*q)->next = 0;
    }
}

queue take_out(QUEUE** q) {
    queue value;
    QUEUE* old_header = *q;
    value = old_header->items;
    *q = (*q)->next;
    free(old_header);
    return value;
}

bool check_file_data(string word, int mode) {
    string sym0 = "qwertyuiopasdfghjklzxcvbnm";
    string sym1 = "0123456789";
    unsigned int i, j;
    bool check = false, mark;
    switch (mode) {
    case 0: // word mode
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        for (i = 0; i < word.length(); i++) {
            mark = false;
            for (j = 0; j < sym0.length(); j++) {
                if (word[i] == sym0[j]) {
                    mark = true;
                }
            }
            if (mark) check = true;
            else check = false;
        }
        break;
    case 1: // number mode
        for (i = 0; i < word.length(); i++) {
            mark = false;
            for (j = 0; j < sym1.length(); j++) {
                if (word[i] == sym1[j]) {
                    mark = true;
                }
            }
            if (mark) check = true;
            else check = false;
        }
        break;
    }
    return check;
}

void output_person(queue person) {
    cout << "First name:     " << person.first_name << endl <<
            "Last name:      " << person.last_name << endl <<
            "Phone number:   " << person.phone_number << endl <<
            "Birthday day:   " << person.birthday_date[0] << endl <<
            "Birthday month: " << person.birthday_date[1] << endl <<
            "Birthday year:  " << person.birthday_date[2] << endl << endl;
}

void menu_output() {
    cout << "=============================================\n"
        "Menu: \n"
        "[1] Input info\n"
        "[2] Delete info about person by birtday date\n"
        "[3] Output all info\n"
        "[4] Output info by person's last name\n"
        "[5] About program\n"
        "[6] Save and exit\n"
        "=============================================\n\n";
}

int menu() {
    int point;
    while (!_kbhit());
    point = _getch() - 48;
    system("cls");
    menu_output();
    return point;
}

int main() {
    cout.precision(10);

    unsigned int point, persons = 0, i = 1, tmp_minus, person_found;
    int for_delete[3], num_for_del, index, minus;
    bool first_read = true, person_deleted, mark = false, not_delete, all_deleted;
    char search_last_name[20], sure;
    string word;
    queue person;
    QUEUE* q1 = 0, * q2 = 0;
    ifstream file;

    menu_output();

    file.open("phone_book.txt", ifstream::in);
    file.seekg(0, ios::end);

    if (!file.is_open()) { // file is not open
        cout << "File does not exist!\n"
            "Use \"[1] Input info\" first.\n";
    }
    else if (file.tellg() != 0) { // file is open and not empty
        // get data from file when program is strating
        file.seekg(0, ios_base::beg);

        do {
            if (first_read) first_read = false;
            else file.seekg(-2, ios_base::cur);
            try {
                file >> word;
                if (!check_file_data(word, 0)) throw NULL;
                strcpy_s(person.first_name, word.c_str());
                file >> word;
                if (!check_file_data(word, 0)) throw NULL;
                strcpy_s(person.last_name, word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.phone_number = atof(word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.birthday_date[0] = atoi(word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.birthday_date[1] = atoi(word.c_str());
                file >> word;
                if (!check_file_data(word, 1)) throw NULL;
                person.birthday_date[2] = atoi(word.c_str());
            }
            catch (...) {
                cout << "File is broken.\n"
                    "You need to use \"[1] Input info\" first.\n";
                mark = true;
            }
            if (!mark) {
                insert(&q1, person);
                persons++;
                file.seekg(2, ios_base::cur);
            }
            else file.seekg(0, ios_base::end);
        } while (file.peek() != EOF);
        if (!mark) {
            cout << "Found saved data.\n"
                "There are " << persons << " saved persons\n";
        }
        file.close();
    }
    else { // file is empty
        cout << "No saved data!\n"
            "You need to use \"[1] Input info\" first.\n";
        file.close();
    }

    do { // menu
        point = menu();
        switch (point) {

        case 1: // Input case
            do {
                cout << "Input first name:     ";
                cin >> person.first_name;
            } while (!check_file_data(person.first_name, 0));
            do {
                cout << "Input last name:      ";
                cin >> person.last_name;
            } while (!check_file_data(person.last_name, 0));
            do {
                cout << "Input phone number:   ";
                cin >> word;
                person.phone_number = atof(word.c_str());
            } while (atof(word.c_str()) < 1 || atof(word.c_str()) > 1e10 || !check_file_data(word, 1));
            do {
                cout << "Input birthday day:   ";
                cin >> word;
                person.birthday_date[0] = atoi(word.c_str());
            } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 31 || !check_file_data(word, 1));
            do {
                cout << "Input birthday month: ";
                cin >> word;
                person.birthday_date[1] = atoi(word.c_str());
            } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 12 || !check_file_data(word, 1));
            do {
                cout << "Input birthday year:  ";
                cin >> word;
                person.birthday_date[2] = atoi(word.c_str());
            } while (atoi(word.c_str()) < 1900 || atoi(word.c_str()) > 2022 || !check_file_data(word, 1));

            cout << "\nYou printed:\n\n";
            output_person(person);
            insert(&q1, person);
            persons++;
            break;

        case 2: // Delete a person by birth date case

            if (persons != 0) {
                person_deleted = false;
                not_delete = false;
                tmp_minus = 0;
                index = 1;
                minus = 0;
                all_deleted = false;

                do {
                    cout << "Input birthday day:   ";
                    cin >> word;
                    for_delete[0] = atoi(word.c_str());
                } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 31 || !check_file_data(word, 1));
                do {
                    cout << "Input birthday month: ";
                    cin >> word;
                    for_delete[1] = atoi(word.c_str());
                } while (atoi(word.c_str()) < 1 || atoi(word.c_str()) > 12 || !check_file_data(word, 1));
                do {
                    cout << "Input birthday year:  ";
                    cin >> word;
                    for_delete[2] = atoi(word.c_str());
                } while (atoi(word.c_str()) < 1900 || atoi(word.c_str()) > 2022 || !check_file_data(word, 1));

                cout << "\nYou printed:\n"
                    "Birthday day:   " << for_delete[0] << endl <<
                    "Birthday month: " << for_delete[1] << endl <<
                    "Birthday year:  " << for_delete[2] << endl << endl;
                
                for (i = 0; i < persons; i++) {
                    person = take_out(&q1);
                    if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                        person_deleted = true;
                        cout << "[" << tmp_minus + 1 << "] Person\n\n";
                        output_person(person);
                        tmp_minus++;
                    }
                    insert(&q1, person);
                }
                
                if (person_deleted) {
                    cout << "Whom you want to delete?\n"
                        "Print [0] if you want to delete all people in this list.\n"
                        "Print person's number to delete him.";
                    while (!_kbhit());
                    num_for_del = _getch() - 48;
                    for (i = 0; i < persons; i++) {
                        if (!not_delete) {
                            person = take_out(&q1);
                            if (for_delete[0] == person.birthday_date[0] && for_delete[1] == person.birthday_date[1] && for_delete[2] == person.birthday_date[2]) {
                                if (num_for_del == 0) {
                                    minus++;
                                    index++;
                                    all_deleted = true;
                                }
                                else if (num_for_del == index) {
                                    cout << "[" << index << "] Person\n\n";
                                    output_person(person);
                                    cout << "Are you sure you want to delete this person? [y/n]: ";
                                    cin >> sure;
                                    if (sure == 'y') {
                                        cout << "Person succesfully deleted.\n";
                                        minus++;
                                        not_delete = true;
                                    }
                                    else {
                                        cout << "\nPerson won't be deleted.";
                                        insert(&q1, person);
                                        not_delete = true;
                                    }
                                }
                                else {
                                    insert(&q1, person);
                                    index++;
                                }
                            }
                            else {
                                insert(&q1, person);
                            }
                        }
                    }
                    if (all_deleted) {
                        cout << "\n\nPersons succesfully deleted.\n";
                    }
                }
                else {
                    cout << "This person not found!\n";
                }
                persons = persons - minus;
            }
            else {
                cout << "There is no persons to wipe out!\n"
                    "Please use the \"[1] Input info\" first\n";
            }
            break;

        case 3: // Output all info
            if (persons != 0) {
                cout << "All persons:\n\n";
                for (i = 0; i < persons; i++) {
                    person = take_out(&q1);
                    insert(&q1, person);
                    output_person(person);
                }
            }
            else {
                cout << "There is no data!\n"
                    "Please use the \"[1] Input info\" first";
            }
            break;

        case 4: // Output info by last name
            if (persons != 0) {
                person_found = 0;

                cout << "Input last name for search: ";
                cin >> search_last_name;
                cout << "\nYou printed:\n"
                    "Last name: " << search_last_name << "\n\n";

                for (i = 0; i < persons; i++) {
                    person = take_out(&q1);
                    insert(&q1, person);
                    if (strcmp(search_last_name, person.last_name) == 0) {
                        person_found++;
                        insert(&q2, person);
                    }
                }
                if (person_found != 0) {
                    cout << "Found person:\n\n";
                    for (i = 0; i < person_found; i++) {
                        person = take_out(&q2);
                        output_person(person);
                    }
                }
                else {
                    cout << "This person not found!\n";
                }
            }
            else {
                cout << "There is no data!\n"
                    "Please use the \"[1] Input info\" first";
            }
            break;

        case 5: // About program
            cout << "Phone book manager\n"
                "Version 1.2.1\n"
                "2022\n"
                "Aleksey Kharin\n";
            break;

        case 6: // Exit
            cout << "Program succsessfully completed.\n";
            break;

        default:
            cout << "Wrong input!\n";
            break;
        }
    } while (point != 6);

    // write data in file before close the program
    ofstream to_file;   
    to_file.precision(10);
    to_file.open("phone_book.txt", ofstream::trunc | ofstream::out);

    for (i = 0; i < persons; i++) {
        person = take_out(&q1);
        to_file << person.first_name << ' ' << person.last_name << ' ' << person.phone_number << ' ' << person.birthday_date[0] << ' ' << person.birthday_date[1] << ' ' << person.birthday_date[2] << '\n';
    }

    to_file.close();

    cout << "Press any key to continiue...\n";
    while (!_kbhit());

    return 0;
}