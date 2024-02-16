#include <iostream>
#include <string>

struct Students {
    std::string *student_name;
    int count;
    int capacity;

    Students() {
        this->count = 0;
        this->capacity = 1;
        this->student_name = (std::string *) malloc(this->capacity * sizeof(std::string));
    }

    void add_name(std::string name) {
        if (this->count < this->capacity) { 
            this->student_name[this->count] = name;
            this->count++;
            return;
        }

        std::string *new_data = (std::string *) realloc(this->student_name, this->capacity * 2 * sizeof(std::string));

        this->student_name = new_data;
        this->capacity = this->capacity * 2;
        this->student_name[this->count] = name;
        this->count++;
    }

    void sort_list() {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count - 1; j++) {
                if(student_name[j + 1] < student_name[j]) {
                    std::string tmp = student_name[j];
                    student_name[j] = student_name[j + 1];
                    student_name[j + 1] = tmp;
                }
            }
        }
    }

    void print_list() {
        for (int i = 0; i < count; i++) {
            std::cout << student_name[i] << std::endl;
        }
    }
};

struct School {
    std::string school_name;
    Students students;

    School() {
        school_name = "";
        Students students;
    }

    School(std::string name) {
        school_name = name;
        Students students;
    }
};

struct School_List {
    School *school;
    int count;
    int capacity;

    School_List() {
        this->count = 0;
        this->capacity = 1;
        this->school = (School *) malloc(this->capacity * sizeof(School));
    }

    void add_school(School name) {
        if (this->count < this->capacity) { 
            this->school[this->count] = name;
            this->count++;
            return;
        }

        School *new_data = (School *) realloc(this->school, this->capacity * 2 * sizeof(School));

        this->school = new_data;
        this->capacity = this->capacity * 2;
        this->school[this->count] = name;
        this->count++;
    }

    int find_school(std::string name_of_school) {
        for (int i = 0; i < count; i++) {
            if (name_of_school == school[i].school_name) {
                return i;
            }
        }
        return -1;
    }

    void sort_list() {
        School tmp;

        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count - 1; j++) {
                if(school[j + 1].school_name < school[j].school_name) {
                    tmp = school[j];
                    school[j] = school[j + 1];
                    school[j + 1] = tmp;
                }
            }
        }
    }

    void print_list() {
        for (int i = 0; i < count; i++) {
            std::cout << school[i].school_name << std::endl;
        }
    }
};

int main() 
{
    School_List List;

    std::string command, name1, name2;

    do {
        std::cin >> command;

        if(command == "ns") {
            std::cin >> name1;

            School school(name1);
            List.add_school(school);

            std::cout << name1 << " was added to the list of schools." << std::endl;
            std::cout << "\n";
        }
        else if (command == "nc"){
            std::cin >> name1;
            std::cin >> name2;

            int x;
            x = List.find_school(name1);

            List.school[x].students.add_name(name2);

            std::cout << name2 << " was added to " << name1 << "'s list of students." << std::endl;  
            std::cout << "\n";
        }
        else if (command == "ps") {
            std::cout << "LIST OF SCHOOLS:" << std::endl;

            List.sort_list();
            List.print_list();

            std::cout << "\n";
        }
        else if (command == "pc") {
            std::cin >> name1;
            std::cout << "STUDENTS ATTENDING " << name1 << ":" << std::endl;

            int x;
            x = List.find_school(name1);

            List.school[x].students.sort_list();
            List.school[x].students.print_list();
            std::cout << "\n";
       }
        else if (command == "q") {
        }
        else {
            std::cout << "ERROR: Invalid input" << std::endl;
            std::cout << "\n";
        }
    }
    while(command != "q");

    return 0;
}