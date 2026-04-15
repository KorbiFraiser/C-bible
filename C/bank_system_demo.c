/* bank_system_demo.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "bank.dat"


typedef struct Account
{
    int number;
    char lastname[50];
    char firstname[50];
    double balance;
    struct Account *next;
} Account;


Account* createAccount(int number, char *lastname, char *firstname, double balance);
void insertSorted(Account **head, Account *newAcc);
Account* searchAccount(Account *head, int number);
void deleteAccount(Account **head, int number);
void deposit(Account *head, int number, double amount);
void withdraw(Account *head, int number, double amount);
void printAccounts(Account *head);
void saveToFile(Account *head);
void loadFromFile(Account **head);
void freeList(Account *head);


/* ---------- MAIN ---------- */
int main(void)
{
    Account *list = NULL;
    int choice;

    do
    {
        printf("\n===== BANK SYSTEM =====\n");
        printf("1. Neues Konto\n");
        printf("2. Konto löschen\n");
        printf("3. Konto suchen\n");
        printf("4. Einzahlung\n");
        printf("5. Auszahlung\n");
        printf("6. Alle Konten anzeigen\n");
        printf("7. Speichern\n");
        printf("8. Laden\n");
        printf("0. Beenden\n");
        printf("\n");
        printf("Auswahl: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int nr;
            char fname[50], lname[50];
            double bal;

            printf("Kontonummer: ");
            scanf("%d", &nr);

            printf("Vorname: ");
            scanf("%s", fname);

            printf("Nachname: ");
            scanf("%s", lname);

            printf("Startguthaben: ");
            scanf("%lf", &bal);

            insertSorted(&list, createAccount(nr, lname, fname, bal));
        }

        else if (choice == 2)
        {
            int nr;
            printf("Kontonummer löschen: ");
            scanf("%d", &nr);
            deleteAccount(&list, nr);
        }

        else if (choice == 3)
        {
            int nr;
            printf("Kontonummer suchen: ");
            scanf("%d", &nr);

            Account *acc = searchAccount(list, nr);

            if (acc != NULL)
            {
                printf("Gefunden: %s %s | Balance: %.2f\n",
                       acc->firstname, acc->lastname, acc->balance);
            }
            else
            {
                printf("Nicht gefunden!\n");
            }
        }

        else if (choice == 4)
        {
            int nr;
            double amount;

            printf("Kontonummer: ");
            scanf("%d", &nr);

            printf("Betrag einzahlen: ");
            scanf("%lf", &amount);

            deposit(list, nr, amount);
        }

        else if (choice == 5)
        {
            int nr;
            double amount;

            printf("Kontonummer: ");
            scanf("%d", &nr);

            printf("Betrag auszahlen: ");
            scanf("%lf", &amount);

            withdraw(list, nr, amount);
        }

        else if (choice == 6)
        {
            printAccounts(list);
        }

        else if (choice == 7)
        {
            saveToFile(list);
        }

        else if (choice == 8)
        {
            freeList(list);
            list = NULL;
            loadFromFile(&list);
        }

    } while (choice != 0);

    freeList(list);
    printf("Programm beendet.\n");
    return 0;
}


/* ---------- CREATE ---------- */
Account* createAccount(int number, char *lastname, char *firstname, double balance)
{
    Account *newAcc = malloc(sizeof(Account));

    if (newAcc == NULL)
    {
        printf("Memory error!\n");
        exit(1);
    }

    newAcc->number = number;
    strcpy(newAcc->lastname, lastname);
    strcpy(newAcc->firstname, firstname);
    newAcc->balance = balance;
    newAcc->next = NULL;

    return newAcc;
}


/* ---------- SORTED INSERT ---------- */
void insertSorted(Account **head, Account *newAcc)
{
    Account *current;

    if (*head == NULL || newAcc->number < (*head)->number)
    {
        newAcc->next = *head;
        *head = newAcc;
        return;
    }

    current = *head;

    while (current->next != NULL && current->next->number < newAcc->number)
    {
        current = current->next;
    }

    newAcc->next = current->next;
    current->next = newAcc;
}


/* ---------- SEARCH ---------- */
Account* searchAccount(Account *head, int number)
{
    while (head != NULL)
    {
        if (head->number == number)
            return head;

        head = head->next;
    }

    return NULL;
}


/* ---------- DELETE ---------- */
void deleteAccount(Account **head, int number)
{
    Account *temp = *head;
    Account *prev = NULL;

    while (temp != NULL)
    {
        if (temp->number == number)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Konto gelöscht.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Konto nicht gefunden.\n");
}


/* ---------- DEPOSIT ---------- */
void deposit(Account *head, int number, double amount)
{
    Account *acc = searchAccount(head, number);

    if (acc == NULL)
    {
        printf("Konto nicht gefunden!\n");
        return;
    }

    acc->balance += amount;
    printf("Neuer Kontostand: %.2f\n", acc->balance);
}


/* ---------- WITHDRAW ---------- */
void withdraw(Account *head, int number, double amount)
{
    Account *acc = searchAccount(head, number);

    if (acc == NULL)
    {
        printf("Konto nicht gefunden!\n");
        return;
    }

    if (acc->balance < amount)
    {
        printf("Nicht genug Guthaben!\n");
        return;
    }

    acc->balance -= amount;
    printf("Neuer Kontostand: %.2f\n", acc->balance);
}


/* ---------- PRINT ---------- */
void printAccounts(Account *head)
{
    if (head == NULL)
    {
        printf("Keine Konten vorhanden.\n");
        return;
    }

    while (head != NULL)
    {
        printf("Nr: %d | %s %s | %.2f\n",
               head->number,
               head->firstname,
               head->lastname,
               head->balance);

        head = head->next;
    }
}


/* ---------- SAVE ---------- */
void saveToFile(Account *head)
{
    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL)
    {
        perror("Dateifehler");
        return;
    }

    while (head != NULL)
    {
        fwrite(head, sizeof(Account) - sizeof(Account*), 1, file);
        head = head->next;
    }

    fclose(file);
    printf("Gespeichert.\n");
}


/* ---------- LOAD ---------- */
void loadFromFile(Account **head)
{
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        perror("Dateifehler");
        return;
    }

    Account temp;

    while (fread(&temp, sizeof(Account) - sizeof(Account*), 1, file))
    {
        insertSorted(head, createAccount(
            temp.number,
            temp.lastname,
            temp.firstname,
            temp.balance));
    }

    fclose(file);
    printf("Geladen.\n");
}


/* ---------- FREE ---------- */
void freeList(Account *head)
{
    Account *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}