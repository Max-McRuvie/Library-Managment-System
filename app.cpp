#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

class Book
{
    private:
        string isbn, title, author, edition, publication; // private vars
    public:
        // setters - assigning user val to private vars
        void setIsbn(string a){isbn = a;}; 
        void setTitle(string b){title = b;};
        void setAuthor(string c){author = c;};
        void setEdition(string d){edition = d;};
        void setPublication(string e){publication = e;};
        // getters - getting values fromn private vars
        string getIsbn(){return isbn;};
        string getTitle(){return title;};
        string getAuthor(){return author;};
        string getEdition(){return edition;};
        string getPublication(){return publication;};
};

// initializing functions
void addBook(int book_counter);
void deleteBook(int book_counter);
void editBook(int book_counter);
void searchBook(int book_counter);
void displayAllBooks(int book_counter);
void quit();

int book_counter = 0; // global var

string buffer_clear; // to clear buffer

// function to increment book counter
void incrementBookCounter(int incrementValue)
{
    incrementValue++;
    book_counter = incrementValue;
}

// function to decrement book counter
void decrementBookCounter(int decrementValue)
{
    decrementValue--;
    book_counter = decrementValue;
}

// Book class array initialization
Book books[10]; 

// main function
int main()
{
    int choice;

    while(true){
        // Main Menu
        cout << "\n\n\
        1. Add Book\n\
        2. Delete Book\n\
        3. Edit Book\n\
        4. Search Book\n\
        5. Display All Books\n\
        6. Quit\n\
        Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addBook(book_counter);
                break;
            case 2:
                deleteBook(book_counter);
                break;
            case 3:
                editBook(book_counter);
                break;
            case 4:
                searchBook(book_counter);
                break;
            case 5:
                displayAllBooks(book_counter);
                break;
            case 6:
                quit();
                break;
            default:
                cout << "Invalid choice \n";
                break;
        }
    }
}

void addBook(int book_counter)
{   
    if(book_counter >= 10)
    {
        cout << "Library is full \n Press any key to continue...";
        main();
    } 

    Book newBook; // create new object
    string isbn, title, author, edition, publication;
    
    getline(cin, buffer_clear); // clear buffer

    // get user input and assign to object
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    newBook.setIsbn(isbn);
    
    cout << "Enter Title: ";
    getline(cin, title);
    newBook.setTitle(title);
    
    cout << "Enter Author: ";
    getline(cin, author);
    newBook.setAuthor(author);

    cout << "Enter Edition: ";
    getline(cin, edition);
    newBook.setEdition(edition);
    
    cout << "Enter Publication: ";
    getline(cin, publication);
    newBook.setPublication(publication);
    
    books[book_counter] = newBook; // add new book to array of objects
    incrementBookCounter(book_counter); // increment book counter
    cout << "Book Added Successfully \n Press any key to continue...";

    _getch();
    main();
}

void deleteBook(int book_counter)
{
    if(book_counter <= 0)
    {
        cout << "Library is empty \n Press any key to continue...";
        _getch();
        main();
    }

    getline(cin, buffer_clear); // clear buffer

    string isbn;
    cout << "Enter ISBN: ";
    getline(cin, isbn);

    for(int i = 0; i < book_counter; i++){
        if(books[i].getIsbn() == isbn)
        {
            for(int j = i; j < book_counter; j++)
            {
                books[j] = books[j+1];
            }

            books[book_counter - 1] = {}; // Clear last element

            decrementBookCounter(book_counter);

            cout << "Book Deleted Successfully \n";
        } 
        else 
        {
            cout << "Book not found \n";
        }
    }

    cout << "Press any key to continue...";
    _getch();
    main();
}

void editBook(int book_counter)
{
    string edit_isbn, edit_choice;
    string isbn, title, author, edition, publication;

    if(book_counter <= 0)
    {
        cout << "Library is empty, cannot edit \n Press any key to continue...";
        _getch();
        main();
    }

    getline(cin, buffer_clear); // clear buffer

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    for(int i = 0; i < book_counter; i++)
    {
        if(books[i].getIsbn() == isbn)
        {
            cout << "Book found \n";
            cout << "ISBN: " << books[i].getIsbn() << "\n";
            cout << "Title: " << books[i].getTitle() << "\n";
            cout << "Author: " << books[i].getAuthor() << "\n";
            cout << "Edition: " << books[i].getEdition() << "\n";
            cout << "Publication: " << books[i].getPublication() << "\n";
            cout << "\nDo you want to edit?\n[1]Yes, [2]No\nEnter your choice: ";

            getline(cin, edit_choice);
            if(edit_choice == "1")
            {
                cout << "Enter ISBN: ";
                getline(cin, edit_isbn);
                books[i].setIsbn(edit_isbn);
                
                cout << "Enter Title: ";
                getline(cin, title);
                books[i].setTitle(title);
                
                cout << "Enter Author: ";
                getline(cin, author);
                books[i].setAuthor(author);

                cout << "Enter Edition: ";
                getline(cin, edition);
                books[i].setEdition(edition);
                
                cout << "Enter Publication: ";
                getline(cin, publication);
                books[i].setPublication(publication);
                
                cout << "Book Edited Successfully \n Press any key to continue...";
                _getch();
                main();
            } 
            else 
            {
                main();
            }
        } 
    }

    cout << "Book not found \n Press any key to continue...";
    _getch();
    main();
}

void searchBook(int book_counter)
{
    string isbn;
    bool found = false;

    if(book_counter <= 0)
    {
        cout << "Library is empty, cannot search \n Press any key to continue...";
        _getch();
        main();
    }

    getline(cin, buffer_clear); // clear buffer

    cout << "Enter ISBN: ";
    getline(cin, isbn);

    for(int i = 0; i < book_counter; i++){
        if(books[i].getIsbn() == isbn)
        {
            cout << "\n\n\
            ISBN: " << books[i].getIsbn() << "\n\
            Title: " << books[i].getTitle() << "\n\
            Author: " << books[i].getAuthor() << "\n\
            Edition: " << books[i].getEdition() << "\n\
            Publication: " << books[i].getPublication() << "\n";
            found = true;
        } 
    }

    if(!found)
    {
        cout << "Book not found \n";
    }

    cout << "Press any key to continue...";
    _getch();
    main();
}

void displayAllBooks(int book_counter)
{
    if(book_counter <= 0) 
    {
        cout << "No books to display, the library is empty \n";
    } 
    else 
    {
        for(int i = 0; i < book_counter; i++) {
        cout << "\n\n\
        ISBN: " << books[i].getIsbn() << "\n\
        Title: " << books[i].getTitle() << "\n\
        Author: " << books[i].getAuthor() << "\n\
        Edition: " << books[i].getEdition() << "\n\
        Publication: " << books[i].getPublication() << "\n";
        }
    }

    cout << "Press any key to continue...";
    _getch();
    main();
}

void quit()
{
    // exit function
    exit(1);   
}
