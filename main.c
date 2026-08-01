#include <stdio.h>
#include <string.h>
#include <strings.h> // for strcasecmp (Linux/Mac). On Windows use _stricmp instead.

#define ROWS 5
#define COLS 10

typedef struct {
    int status;      // 0 = available, 1 = sold
    char name[50];
    char id[20];
} Seat;

Seat seating[ROWS][COLS];

// 1. Initialize all seats
void initializeSeats() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++) {
            seating[i][j].status = 0;
            seating[i][j].name[0] = '\0';
            seating[i][j].id[0] = '\0';
        }
}

// 2. Display seats
void displaySeats() {
    printf("\n   ");
    for(int j=0;j<COLS;j++)
        printf("%2d ", j+1);
    printf("\n");
    for(int i=0;i<ROWS;i++) {
        printf("R%d ", i+1);
        for(int j=0;j<COLS;j++) {
            if(seating[i][j].status == 0)
                printf(" O "); // Available
            else
                printf(" X "); // Sold
        }
        printf("\n");
    }
}

// 3. Purchase ticket
void purchaseTicket() {
    int row, col;
    char name[50], id[20];

    printf("Enter Row (1-%d): ", ROWS); scanf("%d", &row);
    printf("Enter Column (1-%d): ", COLS); scanf("%d", &col);

    if(row<1 || row>ROWS || col<1 || col>COLS) {
        printf("Invalid seat!\n"); return;
    }
    if(seating[row-1][col-1].status == 1) {
        printf("Seat already sold!\n"); return;
    }

    printf("Enter Name: "); scanf(" %[^\n]", name);
    printf("Enter ID: "); scanf(" %[^\n]", id);

    seating[row-1][col-1].status = 1;
    strcpy(seating[row-1][col-1].name, name);
    strcpy(seating[row-1][col-1].id, id);

    printf("Ticket purchased for Row %d, Col %d!\n", row, col);
}

// 4. Cancel ticket
void cancelTicket() {
    int row, col;
    printf("Enter Row (1-%d) to cancel: ", ROWS); scanf("%d", &row);
    printf("Enter Column (1-%d) to cancel: ", COLS); scanf("%d", &col);

    if(row<1 || row>ROWS || col<1 || col>COLS) {
        printf("Invalid seat!\n"); return;
    }
    if(seating[row-1][col-1].status == 0) {
        printf("Seat is already available!\n"); return;
    }

    seating[row-1][col-1].status = 0;
    seating[row-1][col-1].name[0] = '\0';
    seating[row-1][col-1].id[0] = '\0';

    printf("Ticket canceled for Row %d, Col %d.\n", row, col);
}

// 5. Edit ticket info
void editTicket() {
    int row, col;
    printf("Enter Row (1-%d) to edit: ", ROWS); scanf("%d", &row);
    printf("Enter Column (1-%d) to edit: ", COLS); scanf("%d", &col);

    if(row<1 || row>ROWS || col<1 || col>COLS) {
        printf("Invalid seat!\n"); return;
    }
    if(seating[row-1][col-1].status == 0) {
        printf("Seat not booked yet!\n"); return;
    }

    printf("Enter new Name: "); scanf(" %[^\n]", seating[row-1][col-1].name);
    printf("Enter new ID: "); scanf(" %[^\n]", seating[row-1][col-1].id);

    printf("Ticket info updated for Row %d, Col %d.\n", row, col);
}

// 6. Search ticket by Name/ID
void searchTicket() {
    char query[50];
    printf("Enter Name or ID to search: "); scanf(" %[^\n]", query);
    int found = 0;

    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            if(seating[i][j].status == 1 &&
               (strcasecmp(seating[i][j].name, query)==0 || strcasecmp(seating[i][j].id, query)==0)) {
                printf("Found: Row %d, Col %d, Name: %s, ID: %s\n",
                       i+1, j+1, seating[i][j].name, seating[i][j].id);
                found = 1;
            }
        }
    }
    if(!found) printf("Ticket not found!\n");
}

// 7. Show summary
void showSummary() {
    int sold=0, available=0;
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            (seating[i][j].status==1) ? sold++ : available++;

    printf("\n===== Seat Summary =====\n");
    printf("Total Seats: %d\n", ROWS*COLS);
    printf("Available: %d\n", available);
    printf("Sold: %d\n", sold);
    printf("=======================\n");
}

// 8. Save seats to file
void saveSeatsToFile() {
    FILE *fp = fopen("seats.dat", "wb");
    if(fp==NULL) { printf("Error saving file!\n"); return; }
    fwrite(seating, sizeof(Seat), ROWS*COLS, fp);
    fclose(fp);
}

// 9. Load seats from file
void loadSeatsFromFile() {
    FILE *fp = fopen("seats.dat", "rb");
    if(fp==NULL) { initializeSeats(); return; }
    fread(seating, sizeof(Seat), ROWS*COLS, fp);
    fclose(fp);
}

int main() {
    int choice;
    loadSeatsFromFile();

    do {
        printf("\n===== Movie Ticket System =====\n");
        printf("1. Display Seating Chart\n");
        printf("2. Purchase Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Edit Ticket Info\n");
        printf("5. Show Available & Sold Count\n");
        printf("6. Search Ticket by Name/ID\n");
        printf("7. Reset Seating\n");
        printf("8. Save & Exit\n");
        printf("===============================\n");

        printf("Enter choice: "); scanf("%d", &choice);

        switch(choice) {
            case 1: displaySeats(); break;
            case 2: purchaseTicket(); break;
            case 3: cancelTicket(); break;
            case 4: editTicket(); break;
            case 5: showSummary(); break;
            case 6: searchTicket(); break;
            case 7: initializeSeats(); printf("All seats reset!\n"); break;
            case 8: saveSeatsToFile(); printf("Data saved. Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 8);

    return 0;
}
