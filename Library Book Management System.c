/*Library Book Management System
You are developing a simple Library Book Management System that keeps track of books
available in a library. The system should allow the following operations:
1. Add a new book to the collection.
2. Remove a book by its unique book ID.
3. Search for a book by its ID.
4. Display all books in sorted order by book ID.*/


#include <stdio.h>
#define maxBooks 999

struct book {
    int book_id;
    char title[100];
    char author[100];
};

struct book lib[maxBooks];
int count = 0;

int id_exists(int id) {
    for (int i = 0; i < count; i++) {
        if (lib[i].book_id == id) {
            return 1;
        }
    }
    return 0;
}

void add_new_book() {
    if (count >= maxBooks) {
        printf("\nThe library is full\n");
        return;
    }

    int id;
    while (1) {
        printf("Enter Book ID: ");
        scanf("%d", &id);

        if (id_exists(id)) {
            printf("Error: Book ID %d already exists. Please enter a unique ID.\n", id);
        } else {
            break;
        }
    }

    lib[count].book_id = id;

    printf("Enter Book Title: ");
    scanf(" %[^\n]", lib[count].title);

    printf("Enter Book Author: ");
    scanf(" %[^\n]", lib[count].author);

    count++;
    printf("Book added\n");
}

void remove_the_book() {
    int i, j, found = 0, id;
    printf("Enter the book ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (lib[i].book_id == id) {
            found++;
            for (j = i; j < count - 1; j++) {
                lib[j] = lib[j + 1];
            }
            count--;
            printf("Book has been removed.\n");
            break;
        }
    }
    if (found == 0) {
        printf("Not found!\n");
    }
}

void search() {
    int id, low = 0, high = count - 1, mid, found = 0;
    printf("Enter the book ID to search: ");
    scanf("%d", &id);

    while (low <= high) {
        mid = (low + high) / 2;

        if (lib[mid].book_id == id) {
            printf("\nBook Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", lib[mid].book_id, lib[mid].title, lib[mid].author);
            found++;
            break;
        }
        if (lib[mid].book_id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!found) {
        printf("Book not found!\n");
    }
}

void display_all_books() {
    if (count == 0) {
        printf("EMPTY.\n");
        return;
    }

    for (int i = 1; i < count; i++) {
        struct book key = lib[i];
        int j = i - 1;
        while (j >= 0 && lib[j].book_id > key.book_id) {
            lib[j + 1] = lib[j];
            j--;
        }
        lib[j + 1] = key;
    }

    printf("\nList of books: \n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d || Title: %s || Author: %s\n", lib[i].book_id, lib[i].title, lib[i].author);
    }
}

int main() {
    int choice;

    do {
        printf("\nLibrary Book Management System \n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Display Books\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_new_book();
                break;
            case 2:
                remove_the_book();
                break;
            case 3:
                search();
                break;
            case 4:
                display_all_books();
                break;
            case 5:
                printf("\nExiting the system!\n");
                break;
            default:
                printf("\nERROR! Please enter a number between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}
