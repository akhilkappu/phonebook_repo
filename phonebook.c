/********************************************************************************************************************
 * File Name   : phonebook.c
 * Version     : 1.0
 * Description : By using this file we can save contacts and do these operations in it.
                    1) view all contacts.
                    2) add a contact.
                    3) search details of any contact number.
                    4) remove a contact.
                    5) update details of any contact.
                    6) delete whole phonebook (delete all contacts present in phonebook).
*********************************************************************************************************************
Author                  Date
---------------------------------------------------------------------------------------------------------------------
AKHIL K A               23-03-2023
********************************************************************************************************************/

/********************************************************************************************************************
* Includes <System Includes> , "Project Includes"
 *******************************************************************************************************************/
#include "phonebook.h"
/*******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : removeWholeContacts() */
/********************************************************************************************************************
 * @brief       This function will clear all the data of phonebook.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void removeWholeContacts()
{
    system("clear");
    remove("phonebook_db");
    printf("All data in the phonebook deleted sucessfully\n");
    printf("Press Enter to continue....\n");
}
/********************************************************************************************************************
 * End of function removeWholeContacts()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : updateAContact() */
/********************************************************************************************************************
 * @brief       This function will update contact information.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void updateAContact()
{
    system("clear");
    char cContactName[SIZE];

    printf("Enter contact name of the person you want to Update :");
    scanf("%s", cContactName);

    FILE *pFileOpen, *pTemporaryFileOpen;   //FILE operations

    pFileOpen = fopen("phonebook_db", "rb");   //Open file for reading in binary mode.
    pTemporaryFileOpen = fopen("temporary_db", "wb+");  // Create an empty binary file for both reading and writing

    if (pFileOpen == NULL)
    {
        printf("Error in file opening. Please try again !\n");
        printf("Press Enter to continue....\n");
        return;
    }   //End of if

    else
    {
        while (fread(&p, sizeof(p), 1, pFileOpen) == 1) 
        {
            if (strcmp(p.cName, cContactName) == 0)  //string comparison between saved data and user input
            {
                insertContactDetails();
                fwrite(&p, sizeof(p), 1, pTemporaryFileOpen);
                system("clear");
                printf("Data update sucessfully\n");
                giFlag= 1;
            }   //End of if

            else
            {
                fwrite(&p, sizeof(p), 1, pTemporaryFileOpen); 
            }   //End of else
                 
        }

        if (giFlag== 0) //checking the flag status based on user input and ensure no record found.
        {
            system("clear");
            printf("No record found for %s number \n", cContactName);
        }   //End of if

        //closing both files
        fclose(pFileOpen); 
        fclose(pTemporaryFileOpen);

        remove("phonebook_db");
        rename("temporary_db", "phonebook_db");
        printf("Press Enter to continue....\n");
    }   //End of else
}
/********************************************************************************************************************
 * End of function updateAContact()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : removeAContact() */
/********************************************************************************************************************
 * @brief       This function will remove contact from phonebook.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void removeAContact()
{
    system("clear");
    char cContactName[SIZE];
    printf("Enter contact name of the person you want to remove :");
    scanf("%s", cContactName);

    FILE *pFileOpen, *pTemporaryFileOpen;

    pFileOpen = fopen("phonebook_db", "rb");    //Open file for reading in binary mode.
    pTemporaryFileOpen = fopen("temporary_db", "wb+");  // Create an empty binary file for both reading and writing

    if (pFileOpen == NULL)
    {
        printf("Error in file opening. Please try again !\n");
        printf("Press Enter to continue....\n");
        return;
    } //End of if

    else
    {
        while (fread(&p, sizeof(p), 1, pFileOpen) == 1)
        {

            if (strcmp(p.cName, cContactName) == 0)  //string comparison between saved data and user input
            {
                system("clear");
                printf("Person removed sucessfully\n");
                giFlag= 1;
            } //End of if

            else
            {
                fwrite(&p, sizeof(p), 1, pTemporaryFileOpen);
            } //End of else
                
        } //End of while

        if (giFlag== 0)
        {
            system("clear");
            printf("No record found for %s number \n", cContactName);
        } //End of if

        //closing both files
        fclose(pFileOpen);
        fclose(pTemporaryFileOpen);

        remove("phonebook_db");
        rename("temporary_db", "phonebook_db");
        printf("Press Enter to continue....\n");
    } //End of else
}
/********************************************************************************************************************
 * End of function removeAContact()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : searchAContact() */
/*******************************************************************************************************************
 * @brief       This function will search contact in phonebook.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/

void searchAContact()
{
    system("clear");
    char cContactName[SIZE];
    printf("Enter contact name of the person you want to search :");
    scanf("%s", cContactName);

    FILE *pFileOpen;
    pFileOpen = fopen("phonebook_db", "rb");    ////Open file for reading in binary mode.

    if (pFileOpen == NULL)
    {
        printf("Error in file opening. Please try again !\n");
        printf("Press Enter to continue....\n");
        return;
    } //End of if

    else
    {

        while (fread(&p, sizeof(p), 1, pFileOpen) == 1)
        {

            if (strcmp(p.cName, cContactName) == 0) //string comparison between saved data and user input
            {
                printf("NAME\t\tCOUNTRY CODE\t\tPHONE NO\t\tSEX\t\tEMAIL\n");
                printf("--------------------------------------------------------------------------------------------\
                -----------\n");
                printf("%s\t\t", p.cName);
                printf("%s\t\t\t", p.cCountryCode);
                printf("%ld\t\t", p.lMobileNumber);
                printf("%s\t\t", p.cSex);
                printf("%s\n", p.cMailId);

                giFlag= 1;
                break;
            } //End of if

            else
            {
                continue;
            }   //End of else
                
        }   //End of while

        if (giFlag== 0)
        {
            system("clear");
            printf("Person is not in the Phonebook\n");
        }   //End of if

        fclose(pFileOpen); //closing file

        printf("Press Enter to continue....\n ");
    } //End of else
}
/********************************************************************************************************************
 * End of function searchAContact()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : viewAllContacts() */
/********************************************************************************************************************
 * @brief       This function will list contact available in phonebook.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void viewAllContacts()
{
    system("clear");
    FILE *pFileOpen;
    pFileOpen = fopen("phonebook_db", "ab+"); //Open file for both reading and appending in binary mode.

    if (pFileOpen == NULL)
    {
        printf("Error in file opening. Please try again !\n");
        printf("Press Enter to continue....\n");
        return;
    } //End of if

    else
    {
        printf("\n**************************************************************************************************"
        "*****\n");
        printf("*                          Here is all records listed in phonebook                                  "
        "  *\n");
        printf("****************************************************************************************************"
        "***\n\n\n");
        printf("NAME\t\tCOUNTRY CODE\t\tPHONE NO\t\tSEX\t\tEMAIL\n");
        printf("----------------------------------------------------------------------------------------------------"
        "---\n");

        while (fread(&p, sizeof(p), 1, pFileOpen) == 1)
        {
            printf("%s\t\t", p.cName);
            printf("%s\t\t\t", p.cCountryCode);
            printf("%ld\t\t", p.lMobileNumber);
            printf("%s\t\t", p.cSex);
            printf("%s\n", p.cMailId);
        } //End of while

        fclose(pFileOpen); //file closing

        printf("Press Enter to continue....\n ");

    } //End of else
}
/********************************************************************************************************************
 * End of function viewAllContacts()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : insertContactDetails() */
/********************************************************************************************************************
 * @brief       By this we take contact information.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void insertContactDetails()
{
    system("clear");
    getchar();

    printf("Enter name : ");
    scanf("%[^\n]s", p.cName);

    printf("Enter country code : ");
    scanf("%s", p.cCountryCode);

    printf("Enter mobile number : ");
    scanf("%ld", &p.lMobileNumber);

    printf("Enter sex : ");
    scanf("%s", p.cSex);

    printf("Enter email : ");
    scanf("%s", p.cMailId);
}
/********************************************************************************************************************
 * End of function  insertContactDetails()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : addAContact() */
/********************************************************************************************************************
 * @brief       This function will add contact into phonebook.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void addAContact()
{
    system("clear");
    FILE *pFileOpen;
    pFileOpen = fopen("phonebook_db", "ab+");   //Open file for both reading and appending in binary mode.

    if (pFileOpen == NULL)
    {
        printf("Error in file opening. Please try again !\n");
        printf("Press Enter to continue....\n");
        return;
    } //End of if

    else
    {
        insertContactDetails();
        fwrite(&p, sizeof(p), 1, pFileOpen);
        fclose(pFileOpen);

        system("clear");
        printf("Record added Sucessfully\n");
        printf("Press Enter to continue....\n");
    } //End of else

}
/********************************************************************************************************************
 * End of function addAContact()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : viewAllPhonebookOptions() */
/********************************************************************************************************************
 * @brief       This will print main menu.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void viewAllPhonebookOptions()
{
    system("clear");
    printf("********************************************************************************************\n\n");
    printf("***                              Welcome to My Phone Book                                ***\n\n");
    printf("********************************************************************************************\n\n");
    printf("\t1) View all Contacts.\n\n");
    printf("\t2) Add a Contact.\n\n");
    printf("\t3) Search details of any Contact number.\n\n");
    printf("\t4) Remove a Contact.\n\n");
    printf("\t5) Update details of any Contact.\n\n");
    printf("\t6) Delete whole Phonebook\n\n");
    printf("\t7) Exit Phonebook\n\n");
    printf("\t\t Enter your Choice :");
}
/********************************************************************************************************************
 * End of function viewAllPhonebookOptions()
 *******************************************************************************************************************/

/*******************************************************************************************************************/
/* Function Name : start() */
/********************************************************************************************************************
 * @brief       This function will start our program.
 * @param[in]   none
 * @param[out]  none
 * @retval      none
 *******************************************************************************************************************/
void start()
{
    int iChoice;
    
    while (RUN)
    {
        viewAllPhonebookOptions();
        scanf("%d", &iChoice);

        switch (iChoice)     // user choice for selecting the available options.
        {
            case VIEW_ALLCONTACTS:
                    viewAllContacts();
                    getchar();
                    getchar();
                    break;

            case ADD_ACONTACT:
                    addAContact();
                    getchar();
                    getchar();
                    break;

            case SEARCH_ACONTACT:
                    searchAContact();
                    getchar();
                    getchar();
                    break;

            case REMOVE_ACONTACT:
                    removeAContact();
                    getchar();
                    getchar();
                    break;

            case UPDATE_ACONTACT:
                    updateAContact();
                    getchar();
                    getchar();
                    break;

            case REMOVE_WHOLECONTACTS:
                removeWholeContacts();
                getchar();
                getchar();
                break;
                
            default:
                system("clear");
                printf("Thanks for using phonebook visit again :");
                exit(1);

        }
    } //End of while
}
/********************************************************************************************************************
 * End of function start()
 *******************************************************************************************************************/

int main() // Program starts here.
{
    start();
    return 0;
}
/********************************************************************************************************************
 * End of of main () function *
*********************************************************************************************************************/

