#include<stdio.h>
#include<string.h>

#define CONTACTS 10

struct Contact
{
   char name[50],email[30], phone[15];
};

struct Contact contacts[CONTACTS];
int count=0;

void menu()
{
    printf("1.Add Contact\n");
    printf("2.View Contacts\n");
    printf("3.Delete Contact\n");
    printf("4.Edit Contact\n");
    printf("5.Find Contact\n");
    printf("6.Exit\n");
    printf("\n");
}

void add()
{
    if (count>=CONTACTS)
    {
        printf("Contact list is full\n");
        return;
    } 
    struct Contact c;
    printf("Enter name: ");
    scanf("%s",c.name);
    printf("Enter phone number: ");
    scanf("%s",c.phone);
    if(strlen(c.phone)!=10)
	{
		printf(" entered number is invalid and re-enter the phone number\n");
		printf("Re-enter the phone number: ");
		scanf("%s",c.phone);
	}
    printf("Enter email: ");
    scanf("%s",c.email);
    if(strlen(c.phone)==10)
    {
      contacts[count++] = c;
    }
    printf("\n");
    
}

void view()
{
	int i;
	if(count!=0)
	{
        for (i=0;i<count;i++)
        {
            printf("name=%s\tphoneno=%s\tEmail=%s\n",contacts[i].name,contacts[i].phone,contacts[i].email);       
        }
    }
    else
       printf("\n no contacts are there\n");
       printf("\n");
}

void del()
{
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i,found=0;
    for (i=0;i<count; i++)
    {
        if (strcmp(contacts[i].name, name) == 0)
        {
        	int j;
            for ( j=i;j<count-1;j++)
            {
                contacts[j]=contacts[j + 1];
            }
            count--;
            found=1;
            printf("Contact deleted successfully\n");
            break;
        }
    }
    if(!found)
    {
        printf("Contact not found\n");
    }
    printf("\n");
}


void edit()
{
    char name[50];
    printf("Enter name to edit: ");
    scanf("%s", name);
    int i,found = 0;
    for (i=0;i<count;i++)
    {
        if (strcmp(contacts[i].name,name) == 0)
        {
            printf("Enter new name: ");
            scanf("%s", contacts[i].name);
            printf("Enter new phone number: ");
            scanf("%s", contacts[i].phone);
            if(strlen(contacts[i].phone)!=10)
            {
            	printf(" entered number is invalid and re-enter the phone number\n");
	        	printf("Re-enter the phone number: ");
        		scanf("%s",contacts[i].phone);
			}
            printf("Enter new email: ");
            scanf("%s", contacts[i].email);
            found = 1;
            printf("Contact edited successfully\n");
            break;
        }
    }
    if (!found)
        {
            printf("Contact not found\n");
        }
        printf("\n");
}


void find()
{
    char name[50],number[15];  
    int ch;
        printf("enter 1 to find name else enter 2 to find number:  ");
        scanf("%d ",&ch);
        switch(ch)
        {
    	    case 1 :  scanf("%s", name);
    	              break;
        	case 2 :  scanf("%s",number);
         	          break;
            default:  printf("error");
                      break;
	    }
    int i,found = 0;
    for (i=0;i<count;i++)
    {
        if (strcmp(contacts[i].name,name)==0 || strcmp(contacts[i].phone,number)==0)
        {
            printf("Contact was found\n");
            printf("Name=%s\tPhone No=%s\tEmail=%s\n", contacts[i].name,contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found\n");
    }
    printf("\n");
}



int main()
{
    int choice;
    do
    {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
            {
                case 1:  add();
                         break;
                case 2:  view();
                         break;
                case 3:  del();
                         break;
                case 4:  edit();
                         break;
                case 5:  find();
                         break;
                case 6:  printf("Exit\n");
                         break;
                default:  printf("Invalid choice\n");
                          printf("\n");
                          break;
            }
    } while (choice!=6);
    return 0;
}
