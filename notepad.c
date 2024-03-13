#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *fp;
FILE *temp;

void openFile() {
    char fileName[35];
    char newFileName[35];
    char text[1024];
    int choice;

    printf("Enter the file name you want to open:");
    scanf("%s", &fileName);
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("The file you are looking for cannot be found in the system.");
    }
    do {
        printf("\n1-View File Content\n");
        printf("2-Rename File\n");
        printf("3-Delete File\n");
        printf("4-Main Menu\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                while (fscanf(fp, "%[^\n]\n", text) != EOF) {
                    printf("%s\n", text);
                }
                break;
            case 2:
                system("cls");
                printf("\nEnter the new file name:");
                scanf("%s", &newFileName);
                temp = fopen(newFileName, "a");
                if (temp == NULL) {
                    printf("\nFailed to create a new file.");
                }
                rewind(fp);
                while (fscanf(fp, "%[^\n]\n", text) != EOF) {
                    fprintf(temp, "%s\n", text);
                }
                rename(newFileName, fileName);
                remove(fileName);
                fclose(temp);
                break;
            case 3:
                system("cls");
                rewind(fp);
                fclose(fp);
                if (remove(fileName) == 0) {
                    printf("\n%s file deletion successful.", fileName);
                } else {
                    printf("\nFile deletion failed.");
                }
                break;
            case 4:
                system("cls");
                printf("\nReturning to the main menu.");
                return 0;
            default:
                printf("\n\nInvalid choice, please try again.");
                break;
        }
    } while (choice != 4);
}

void createFile() {
    printf("\nNew Document Creation Page\n");
    char text[1024];
    char fileName[35];
    printf("File name:");
    scanf("%s", &fileName);
    int choice;
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("\n%s file could not be created.", fileName);
    }
    printf("\n%s file has been created.", fileName);
    do {
        printf("\n1-Add Text\n");
        printf("2-View File Content\n");
        printf("3-Clear File Content\n");
        printf("4-Return to Main Menu\n");
        printf("Your choice:");
        scanf("%d", &choice);
    switch (choice) {
        case 1:
            system("cls");
            printf("Enter text:");
            scanf(" %[^\n]", text);
            fp = fopen(fileName, "a");
            fprintf(fp, "%s\n", text);
            fclose(fp);
            printf("\nText successfully added to your file.");
            break;
        case 2:
            system("cls");
            fp = fopen(fileName, "r");
            if (fp == NULL) {
                printf("\nFailed to read file data.");
            }
            while (fscanf(fp, "%[^\n]\n", text) != EOF) {
                printf("%s\n", text);
            }
            fclose(fp);
            break;
        case 3:
            system("cls");
            fclose(fp);
            fp = fopen(fileName, "w");
            if (fp == NULL) {
                printf("\nFailed to clear file content.");
            }
            printf("\nFile content has been successfully cleared.");
            break;
        case 4:
            system("cls");
            printf("\nReturning to the main menu.");
            fclose(fp);
            return;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 4);
}

int menu() {
    int choice;
    do {
        printf("\nNOTEPAD\n");
        printf("1-New\n");
        printf("2-Open\n");
        printf("0-Exit\n");
        printf("Choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                system("cls");
                createFile();
                break;
            case 2:
                system("cls");
                openFile();
                break;
            case 0:
                printf("Exiting.");
                break;
            default:
                printf("\nInvalid choice, please try again.");
                break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
