#include <stdio.h>
#include <string.h>

struct Room {
    int number;
    int booked;
    char name[50];
};

struct Room rooms[10];
int count = 0;

void addRoom(int number) {
    rooms[count].number = number;
    rooms[count].booked = 0;
    strcpy(rooms[count].name, "");
    count++;
}

void showAvailable() {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < count; i++) {
        if (rooms[i].booked == 0)
            printf("Room %d\n", rooms[i].number);
    }
}

void bookRoom(int number, char name[]) {
    for (int i = 0; i < count; i++) {
        if (rooms[i].number == number && rooms[i].booked == 0) {
            rooms[i].booked = 1;
            strcpy(rooms[i].name, name);
            printf("Room %d booked for %s\n", number, name);
            return;
        }
    }
    printf("Room not available\n");
}

void cancelRoom(int number) {
    for (int i = 0; i < count; i++) {
        if (rooms[i].number == number && rooms[i].booked == 1) {
            rooms[i].booked = 0;
            strcpy(rooms[i].name, "");
            printf("Booking canceled for room %d\n", number);
            return;
        }
    }
    printf("Room is not booked\n");
}

void showAll() {
    printf("\nAll Rooms:\n");
    for (int i = 0; i < count; i++) {
        if (rooms[i].booked)
            printf("Room %d - Booked by %s\n", rooms[i].number, rooms[i].name);
        else
            printf("Room %d - Available\n", rooms[i].number);
    }
}

int main() {
    int choice, number;
    char name[50];

    addRoom(101);
    addRoom(102);
    addRoom(103);

    while (1) {
        printf("\n1. View Available Rooms\n2. Book Room\n3. Cancel Booking\n4. View All Rooms\n5. Exit\nChoose: ");
        scanf("%d", &choice);

        if (choice == 1) showAvailable();
        else if (choice == 2) {
            printf("Enter room number: ");
            scanf("%d", &number);
            printf("Enter name: ");
            scanf(" %[^\n]", name);
            bookRoom(number, name);
        }
        else if (choice == 3) {
            printf("Enter room number: ");
            scanf("%d", &number);
            cancelRoom(number);
        }
        else if (choice == 4) showAll();
        else if (choice == 5) break;
        else printf("Invalid choice\n");
    }

    return 0;
}

    