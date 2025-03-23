#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char name[25];
    char phone[15];
    struct Contact* next;
} Contact;

// Buat linked list kontak
Contact* createContactNode(char* name, char* phone) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = NULL;
    return newContact;
}

// Masukin kontak ke linked list
void insertContact(Contact** head, char* name, char* phone) {
    Contact* newContact = createContactNode(name, phone);

    if (*head == NULL || strcmp((*head)->name, name) > 0) {
        newContact->next = *head;
        *head = newContact;
    } else {
        Contact* curr = *head;
        while (curr->next != NULL && strcmp(curr->next->name, name) < 0) {
            curr = curr->next;
        }
        newContact->next = curr->next;
        curr->next = newContact;
    }
}

// gabungin linked list
Contact* mergeContacts(Contact* head1, Contact* head2) {
    Contact* mergedList = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (strcmp(head1->name, head2->name) < 0) {
            insertContact(&mergedList, head1->name, head1->phone);
            head1 = head1->next;
        } 
		else {
            insertContact(&mergedList, head2->name, head2->phone);
            head2 = head2->next;
        }
    }

    while (head1 != NULL) {
        insertContact(&mergedList, head1->name, head1->phone);
        head1 = head1->next;
    }

    while (head2 != NULL) {
        insertContact(&mergedList, head2->name, head2->phone);
        head2 = head2->next;
    }

    return mergedList;
}

// Print kontak
void displayContacts(Contact* head) {
    printf("+------------------------------------+\n");
    printf("|       Contact       |    Phone     |\n");
    printf("+------------------------------------+\n");

    Contact* curr = head;
    while (curr != NULL) {
        printf("| %-20s | %-12s |\n", curr->name, curr->phone);
        curr = curr->next;
    }

    printf("+------------------------------------+\n");
}

// Bersihin memory
void freeContacts(Contact* head) {
    Contact* curr = head;
    while (curr != NULL) {
        Contact* temp = curr;
        curr = curr->next;
        free(temp);
    }
}

// Print menu
void printMenu() {
	printf	("************************************\n" 
			"************************************\n");
	printf	("\t\tMENU\n");
	printf	("************************************\n" 
			"************************************\n\n\n");
    printf("1. Masukkan Kontak di List 1\n");
    printf("2. Masukkan Kontak di List 2\n");
    printf("3. Tampilkan List Kontak 1\n");
    printf("4. Tampilkan List Kontak 2\n");
    printf("5. Gabungkan Kontak\n");
    printf("6. Tampilkan Kontak yang sudah digabungkan\n");
    printf("7. Keluar\n");
    printf("Masukkan pilihan [ 1-7 ]: ");
}

int main() {
	printf	("***********************************************\n" 
			"***********************************************\n");
	printf	("\tSelamat Datang di Contact Merger\n");
	printf	("***********************************************\n" 
			"***********************************************\n");
	system("color 70");
	
    Contact* list1 = NULL;
    Contact* list2 = NULL;
    Contact* mergedList = NULL;
    char name[50];
    char phone[15];
    int choice;

    do {
    	system("pause");
    	system("cls");
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	system("cls");
                printf("Masukkan nama kontak list 1 [Maksimum 20 karakter]: ");
                scanf("%s", name);
                printf("Masukkan nomor telepon list 1 [Maksimum 12 nomor]: ");
                scanf("%s", phone);
                insertContact(&list1, name, phone);
                system("color 70");
                break;
            case 2:
            	system("cls");
                printf("Masukkan nama kontak list 2 [Maksimum 20 karakter]: ");
                scanf("%s", name);
                printf("Masukkan nomor telepon list 2 [Maksimum 12 nomor]: ");
                scanf("%s", phone);
                insertContact(&list2, name, phone);
                system("color 70");
                break;
            case 3:
            	system("cls");
                printf("List 1:\n");
                displayContacts(list1);
                printf("\n");
                system("color 70");
                break;
            case 4:
            	system("cls");
                printf("List 2:\n");
                displayContacts(list2);
                printf("\n");
                system("color 70");
                break;
            case 5:
            	system("cls");
                mergedList = mergeContacts(list1, list2);
                printf("Kontak berhasil digabungkan!\n");
                system("color 70");
				break;
            case 6:
            	system("cls");
                printf("Merged Contact List:\n");
                displayContacts(mergedList);
                printf("\n");
                system("color 70");
                break;
            case 7:
            	system("cls");
                printf("Keluar dari program...\n");
                system("color 70");
                break;
            default:
            	system("cls");
                printf("Input Invalid.\n");
                printf("Silahkan ulangi lagi !\n");
                system("color 70");
        }

    } 
    
	while (choice != 7);

    freeContacts(list1);
    freeContacts(list2);
    freeContacts(mergedList);

    return 0;
}

