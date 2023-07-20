#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <algorithm> // pangtransform to lower/uppercase
#include <cctype>
#include <limits>

using namespace std;

struct Node* head = nullptr;

struct Node2* head2 = nullptr;


struct Book {
    string title;
    string author;
    string genre;
};

// NOde for the available books
struct Node {
    Book value;
    Node* next = nullptr;
};

// NOde for the unavailable books
struct Node2 {
    Book value2;
    Node2* next = nullptr;
};

// Insert a node to the available books
void insert_Node(const Book& book) {
    struct Node* new_node = new Node;
    new_node->value = book;
    new_node->next = head;
    head = new_node;
}

// Insert a node to the unavailable books
void insert_Node2(const Book& book) {
    struct Node2* new_node = new Node2;
    new_node->value2 = book;
    new_node->next = head2;
    head2 = new_node;
}

void display_all_nodes() {
    // Used to display both available and unavailable books.
    if (head == nullptr && head2 == nullptr) {
        cout << "No books available at the moment.\n\n";
    }
    else {
        // For diplaying the available books.
        cout << "The available books are:\n";
        struct Node* temp = head;
        while (temp != nullptr) {
            cout << "Title: " << temp->value.title << ", Author: " << temp->value.author << ", Genre: " << temp->value.genre << endl;
            temp = temp->next;
        }
        cout << endl;

        // For diplaying the unavailable books.
        cout << "The unavailable books are:\n";
        struct Node2* temp2 = head2;
        while (temp2 != nullptr) {
            cout << "Title: " << temp2->value2.title << ", Author: " << temp2->value2.author << ", Genre: " << temp2->value2.genre << endl;
            temp2 = temp2->next;
        }
        cout << endl;
    }
}

void deletes() {
    string bookins;
    cout << "Delete book\n";
    cin >> bookins;
    int i = 0;
    int u = 0;

    // Find the index of the book
    Node* travis = head;
    while (travis != nullptr && travis->value.title != bookins) {
        travis = travis->next;
        i++;
    }

    // Delete the book if it's not in the beginning
    if (i > 0) {
        Node* temp2 = head;
        int j = 1;
        while (j != i && temp2 != nullptr) {
            temp2 = temp2->next;
            j++;
        }

        if (temp2->next != nullptr) {
            Node* temp = temp2->next;
            temp2->next = temp->next;

            delete temp;
            cout << "\nYou have successfully deleted a book\n\n";
            system("PAUSE");
            system("cls");
        }
        else if (temp2->next == nullptr) {


            // Find the index of the book
            Node2* traver = head2;
            while (traver != nullptr && traver->value2.title != bookins) {
                traver = traver->next;
                u++;
            }

            // Delete the book if it's not in the beginning
            if (u > 0) {
                Node2* tempo2 = head2;
                int k = 1;
                while (k != u && tempo2 != nullptr) {
                    tempo2 = tempo2->next;
                    k++;
                }

                if (tempo2->next != nullptr) {
                    Node2* temp3 = tempo2->next;
                    tempo2->next = temp3->next;

                    delete temp3;
                    cout << "\nYou have successfully borrowed " << bookins << "\n\n";
                    system("PAUSE");
                    system("cls");
                }
                else if (tempo2->next == nullptr) {
                    cout << "Book is not from this Library\n";
                    system("PAUSE");
                    system("cls");
                }
            }
            // Delete Beginning
            else if (u == 0) {
                if (head2 != nullptr) {
                    Node2* temps = head2;
                    Node2* temps2 = temps;
                    head2 = head2->next;
                    delete temps2;
                    cout << "\nYou have successfully borrowed a book\n\n";
                    system("PAUSE");
                    system("cls");
                }
                else if (head2 == nullptr) {
                    cout << "Theres nothing to be deleted here\n";
                    system("PAUSE");
                    system("cls");
                }
            }
        }
    }
    // Delete Beginning
    else if (i == 0) {
        if (head != nullptr) {
            Node* temp = head;
            Node* temp2 = temp;
            head = head->next;
            delete temp2;
            cout << "\nYou have successfully deleted a book\n\n";
            system("PAUSE");
            system("cls");
        }
        else if (head == nullptr) {
            cout << "Theres nothing to be deleted here\n";
            system("PAUSE");
            system("cls");
        }
    }
}


void borrow() {
    string bookins;
    cout << "Borrow a book: \n";
    cin.ignore();
    getline(cin, bookins);
    int i = 0;

    // Find the index of the book
    Node* travis = head;
    while (travis != nullptr && travis->value.title != bookins) {
        travis = travis->next;
        i++;
    }

    // Check Node* has more than 1 value.
    if (i > 0) {
        Node* temp2 = head;
        int j = 1;
        while (j != i && temp2 != nullptr) {
            temp2 = temp2->next;
            j++;
        }

        // Check if the book is not in the beginning.
        if (temp2->next != nullptr) {
            Node* temp = temp2->next;
            temp2->next = temp->next;

            struct Node2* new_node = new Node2;
            new_node->value2 = temp->value;
            new_node->next = head2;
            head2 = new_node;

            delete temp;
            cout << "\nYou have successfully borrowed a book\n\n";
            system("PAUSE");
            system("cls");
        }

        // When the book can't be found in the Node (available)
        else if (temp2->next == nullptr) {

            // Loop through Node2 to see if its unavailable
            Node2* travis2 = head2;
            bool unavailable = false;

            while (travis2 != nullptr) {
                if (bookins == travis2->value2.title) {
                    unavailable = true;
                }
                travis2 = travis2->next;
            }
            if (unavailable) {
                cout << "Book is currently unavailable\n";
                system("PAUSE");
                system("cls");
                return;
            }
            else {
                cout << "Book is not from this Library\n";
                system("PAUSE");
                system("cls");
            }
            delete travis2;
        }

    }
    // Delete Beginning
    else if (i == 0) {
        if (head != nullptr) {
            Node* temp = head;
            Node* temp2 = temp;

            struct Node2* new_node = new Node2;
            new_node->value2 = temp->value;
            new_node->next = head2;
            head2 = new_node;

            head = head->next;

            delete temp2;
            cout << "\nYou have successfully borrowed a book\n\n";
            system("PAUSE");
            system("cls");

        }
        else if (head == nullptr) {
            cout << "Theres nothing to be borrowed here\n";
            system("PAUSE");
            system("cls");
        }
    }
}

void returnBook() {
    string bookins;
    cout << "Return a book: \n";
    cin.ignore();
    getline(cin, bookins);
    int i = 0;

    // Find the index of the book
    Node2* travis = head2;
    while (travis != nullptr && travis->value2.title != bookins) {
        travis = travis->next;
        i++;
    }

    // Check Node2* has more than 1 value.
    if (i > 0) {
        Node2* temp2 = head2;
        int j = 1;
        while (j != i && temp2 != nullptr) {
            temp2 = temp2->next;
            j++;
        }

        // Check if the book is not in the beginning.
        if (temp2->next != nullptr) {
            Node2* temp = temp2->next;
            temp2->next = temp->next;

            struct Node* new_node = new Node;
            new_node->value = temp->value2;
            new_node->next = head;
            head = new_node;

            delete temp;
            cout << "\nYou have successfully returned a book\n\n";
            system("PAUSE");
            system("cls");
        }

        // When the book can't be found in the Node2 (unavailable)
        else if (temp2->next == nullptr) {

            // Loop through Node2 to see if its available
            Node* travis2 = head;
            bool unavailable = false;

            while (travis2 != nullptr) {
                if (bookins == travis2->value.title) {
                    unavailable = true;
                }
                travis2 = travis2->next;
            }
            if (unavailable) {
                cout << "Book is still in the library.\n";
                system("PAUSE");
                system("cls");
                return;
            }
            else {
                cout << "Book is not from this Library\n";
                system("PAUSE");
                system("cls");
            }
            delete travis2;
        }

    }
    // Delete Beginning
    else if (i == 0) {
        if (head2 != nullptr) {
            Node2* temp = head2;
            Node2* temp2 = temp;

            struct Node* new_node = new Node;
            new_node->value = temp->value2;
            new_node->next = head;
            head = new_node;

            head2 = head2->next;

            delete temp2;
            cout << "\nYou have successfully returned a book\n\n";
            system("PAUSE");
            system("cls");

        }
        else if (head2 == nullptr) {
            cout << "We don't have any unavailable books\n";
            system("PAUSE");
            system("cls");
        }
    }
}


void saveBooksToFile(const string& filename) {
    ofstream file(filename);
    // Checking if file was successfully open.
    if (file.is_open()) {
        Node* temp = head;
        // Iterating until the end of the linked list
        while (temp != nullptr) {
            file << temp->value.title << "," << temp->value.author << "," << temp->value.genre << endl;
            temp = temp->next;
        }
        // Closing the file after writing all the data.
        file.close();
    }
    else {
        // Display an error message if the file could not be opened
        cout << "Error opening file: " << filename << endl;
        Sleep(3000);

    }
}

void saveBooksToFile2(const string& filename) {
    ofstream file2(filename);
    // Checking if file was successfully open.
    if (file2.is_open()) {
        Node2* temp = head2;
        // Iterating until the end of the linked list
        while (temp != nullptr) {
            file2 << temp->value2.title << "," << temp->value2.author << "," << temp->value2.genre << endl;
            temp = temp->next;
        }
        // Closing the file after writing all the data.
        file2.close();
    }
    else {
        // Display an error message if the file could not be opened
        cout << "Error opening file: " << filename << endl;
        Sleep(3000);

    }
}

void loadBooksFromFile(const string& filename) {
    ifstream file(filename);
    // Checking if the file was successfully opened
    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            Book book;

            // Find the first comma in the line
            size_t pos1 = line.find(",");

            // Find the second comma after the first one
            size_t pos2 = line.find(",", pos1 + 1);

            // Extract the book's title, author, and genre from the line using substrings
            book.title = line.substr(0, pos1);
            book.author = line.substr(pos1 + 1, pos2 - pos1 - 1);
            book.genre = line.substr(pos2 + 1);

            insert_Node(book);
        }
        // Close the file after reading all the book data
        file.close();
    }
    else {
        cout << "Error opening file: " << filename << endl;
        Sleep(3000);
    }
}


void loadBooksFromFile2(const string& filename) {
    ifstream file2(filename);

    // Checking if the file was successfully opened
    if (file2.is_open()) {
        string line;
        while (getline(file2, line)) {
            Book book;

            // Find the first comma in the line
            size_t pos1 = line.find(",");

            // Find the second comma after the first one
            size_t pos2 = line.find(",", pos1 + 1);

            // Extract the book's title, author, and genre from the line using substrings
            book.title = line.substr(0, pos1);
            book.author = line.substr(pos1 + 1, pos2 - pos1 - 1);
            book.genre = line.substr(pos2 + 1);

            insert_Node2(book);
        }
        file2.close();
    }
    else {
        cout << "Error opening file: " << filename << endl;
        Sleep(3000);

    }
}

void display(Book& book) {
    if (book.title.empty()) {
        cout << "There are no books available at the moment.\n\n";
    }
    else {
        cout << "Book Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Genre: " << book.genre << endl;
        cout << "\n";
    }
}

void search(string wordz) {
    ifstream myFile("books.txt");
    if (myFile.is_open()) {
        string line;
        transform(wordz.begin(), wordz.end(), wordz.begin(), ::tolower);
        bool bookFound = false;
        while (getline(myFile, line)) {
            transform(line.begin(), line.end(), line.begin(), ::tolower);

            size_t pos = line.find(wordz);
            if (pos != string::npos) {
                // If the search word is found sa isang line kasi ginawa kong format ay 1 line per class instance para mas madali madetermine ang isang instance

                // Split the line into title, author, and genre gamit ang delimiter (comma sa case na to)
                size_t delimiterPos1 = line.find(',');
                size_t delimiterPos2 = line.find(',', delimiterPos1 + 1);
                if (delimiterPos1 != string::npos && delimiterPos2 != string::npos) {
                    // when both delimiters are found

                    // pag extract ng strings
                    string title = line.substr(0, delimiterPos1);
                    transform(title.begin(), title.end(), title.begin(), ::toupper);
                    string author = line.substr(delimiterPos1 + 1, delimiterPos2 - delimiterPos1 - 1);
                    transform(author.begin(), author.end(), author.begin(), ::toupper);
                    string genre = line.substr(delimiterPos2 + 1);
                    transform(genre.begin(), genre.end(), genre.begin(), ::toupper);
                    //magiging uppercase ang output naten

                    Book book = { title, author, genre };
                    display(book);
                    bookFound = true;
                }
            }

        }

        myFile.close();

        // After the loop, check if any book is found
        if (!bookFound) {
            cout << "\nNo books found. Try again.\n\n";
            system("PAUSE");
            system("cls");
            return;
        }
        system("PAUSE");

    }
    else {
        cout << "Error opening the library at the moment. Try again." << endl;
        system("PAUSE");
        system("cls");
        return;
    }
}

void suggest() {
    fstream suggestFile;
    string suggestTitle, suggestAuthor, suggestGenre;
    system("cls");
    cout << "SUBMIT BOOK SUGGESTIONS !" << endl;
    cout << "Book title: ";
    cin.ignore();
    getline(cin, suggestTitle);
    cout << "Author: ";
    getline(cin, suggestAuthor);
    cout << "Genre: ";
    getline(cin, suggestGenre);

    suggestFile.open("suggest.txt", ios::out | ios::app);
    if (suggestFile.is_open()) {
        suggestFile << "\t - " << suggestTitle << " " << "by " << suggestAuthor << " " << "(" << suggestGenre << ")\n\n";
        suggestFile.close();
    }
}

string login() {
    string user, pass, u, p;
    int count = 0;
    fstream myFile;
    cout << "\t\t\t===============   Enter login credentials   =================\n\n\n";
    cout << "\t\t\t USERNAME: ";
    getline(cin, user);
    cout << "\t\t\t PASSWORD: ";
    getline(cin, pass);
    myFile.open("Forms.txt", ios::in);
    while (myFile >> u >> p) {
        if (u == user && p == pass) {
            count = 1;
            system("cls");
            break;
        }
    }
    myFile.close();
    if (count == 1) {
        cout << "LOGIN SUCCESSFUL\n" << "Welcome " << user << " !\n\n";
        system("PAUSE");
        system("cls");
        return user;
    }
    else {
        system("cls");
        cout << "ERROR!\nIncorrect username/password.\n\n";
        system("PAUSE");
        system("cls");
        return "";
    }
}

void registerd() {
    fstream myFile;
    string user, pass;
    system("cls");
    cout << "\t\t\t===============   Create your account   =================\n\n\n";
    cout << "\t\t\t USERNAME: ";
    getline(cin, user);
    myFile.open("Forms.txt", ios::in);
    string existingUser;
    bool userExists = false;
    while (myFile >> existingUser >> pass) {
        if (existingUser == user) {
            userExists = true;
            break;
        }
    }
    myFile.close();

    if (userExists) {
        cout << "\nUsername is already taken. Please choose a different username.\n\n";
        system("PAUSE");
        system("cls");
        return;
    }
    cout << "\t\t\t PASSWORD: ";
    getline(cin, pass);

    myFile.open("Forms.txt", ios::out | ios::app);
    if (myFile.is_open()) {
        myFile << user << " " << pass << endl;
        myFile.close();
    }
    system("cls");
}


int main() {
    string choice;
    string user;
    Node* head = nullptr;

    loadBooksFromFile("books.txt");
    loadBooksFromFile2("books2.txt");

    do {
        string choicee;
        system("cls");
        cout << "\t\t\t===============================================\n\n";
        cout << "\t\t\t            WELCOME TO LibraRIZZ               \n\n";
        cout << "\t\t\t===============================================\n\n";
        cout << "\t\t\t===============   MAIN MENU   =================\n\n\n";
        cout << "\t | Enter 1 to REGISTER            |" << endl;
        cout << "\t | Enter 2 to LOGIN               |" << endl;
        cout << "\t | Enter 3 to EXIT                |\n" << endl;
        cout << "\t  ENTER CHOICE: ";
        getline(cin, choicee);
        if (choicee == "1") {
            registerd();
            system("cls");
            cout << "REGISTRATION SUCCESSFUL.\n\n";
            system("PAUSE");
            system("cls");
            main();
        }
        else if (choicee == "2") {
            system("cls");
            user = login();
            if (user.empty()) {
                cout << "\nLogin failed. Please check your username/password and try again.";
                Sleep(5000);
                system("cls");
            }
            else {
                break;
            }
        }
        else if (choicee == "3") {
            exit(0);
        }
        else {
            system("cls");
            cout << choicee;
            cout << "\nPlease only select from the given options above.\n\n";
            system("PAUSE");
            system("cls");
            main();
        }
    } while (true);

    bool isAdmin = false;
    if (user == "admin123") {
        isAdmin = true;
        cout << "\nYou have admin access.";
        Sleep(3000);
        system("cls");
    }
    else if (!user.empty()) {
        cout << "\nYou are entering as a normal user.";
        Sleep(3000);
        system("cls");
    }

    if (isAdmin == false) {
        do {
            system("cls");
            cout << "\t\t\t===============================================\n\n";
            cout << "\t\t\t            WELCOME TO LibraRIZZ               \n\n";
            cout << "\t\t\t===============================================\n\n";
            cout << "\t\t\t======   Select an action to perform:   =======\n\n\n";
            cout << "\t\t 1. Search for a book\n";
            cout << "\t\t 2. Borrow a book\n";
            cout << "\t\t 3. Return a book\n";
            cout << "\t\t 4. Display books\n";
            cout << "\t\t 5. Submit book suggestions\n";
            cout << "\t\t 6. Exit\n\t\t Choice: ";
            cin >> choice;
            if (choice == "1") {
                string word;
                system("cls");
                cout << "Enter book to search: ";
                cin.ignore();
                getline(cin, word);
                search(word);
            }
            else if (choice == "2") {
                system("cls");
                borrow();
                system("cls");
            }
            else if (choice == "3") {
                system("cls");
                returnBook();
                system("cls");
            }
            else if (choice == "4") {
                system("cls");
                display_all_nodes();
                cout << "\n\n";
                system("PAUSE");
                system("cls");
            }
            else if (choice == "5") {
                suggest();
                cout << "\nBook suggestion submitted. Thank you for helping us expand!\n\n";
                system("PAUSE");
                system("cls");
            }

            else if (choice == "6") {
                exit(0);
            }
            else {
                system("cls");
                cout << "\nPlease only select from the given options above.\n\n";
                system("PAUSE");
                system("cls");
            }
            saveBooksToFile("books.txt");
            saveBooksToFile2("books2.txt");
        } while (true);
    }
    else if (isAdmin == true) {
        string word;
        string choice;

        while (true) {

            system("cls");
            cout << "\t\t\t===============================================\n\n";
            cout << "\t\t\t            WELCOME TO LibraRIZZ               \n\n";
            cout << "\t\t\t===============================================\n\n";
            cout << "\t\t\t======   Select an action to perform:   =======\n\n\n";
            cout << "\t\t 1. Search for a book\n";
            cout << "\t\t 2. Borrow a book\n";
            cout << "\t\t 3. Return a book\n";
            cout << "\t\t 4. Add a book\n";
            cout << "\t\t 5. Delete a book\n";
            cout << "\t\t 6. Display books\n";
            cout << "\t\t 7. View book suggestions\n";
            cout << "\t\t 8. Exit\n\t\t Choice: ";
            cin >> choice;

            if (choice == "1") {
                system("cls");
                cout << "Enter book to search: ";
                cin >> word;
                search(word);
            }
            else if (choice == "2") {
                system("cls");
                borrow();
                system("cls");
            }
            else if (choice == "3") {
                system("cls");
                returnBook();
                system("cls");
            }
            else if (choice == "4") {
                system("cls");
                Book newBook;
                cout << "Enter the title: ";
                cin.ignore();
                getline(cin, newBook.title);
                cout << "Enter the author: ";
                getline(cin, newBook.author);
                cout << "Enter the genre: ";
                getline(cin, newBook.genre);
                insert_Node(newBook);
            }
            else if (choice == "5") {
                system("cls");
                deletes();
            }
            else if (choice == "6") {
                system("cls");
                display_all_nodes();
                cout << "\n\n";
                system("PAUSE");
                system("cls");
            }
            else if (choice == "7") {
                fstream readFile;
                readFile.open("suggest.txt");
                string line;
                system("cls");
                cout << "Here is a list of book suggestions from other users: \n\n";
                while (getline(readFile, line)) {
                    cout << line << endl;
                }
                readFile.close();
                system("PAUSE");
                system("cls");
            }

            else if (choice == "8") {
                exit(0);
            }
            else {
                system("cls");
                cout << "\nPlease only select from the given options above.\n\n";
                system("PAUSE");
                system("cls");
                continue;
            }
            saveBooksToFile("books.txt");
            saveBooksToFile2("books2.txt");
        }
    }
    return 0;
}
