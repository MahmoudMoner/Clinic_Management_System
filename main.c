/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 29/9/2023    *****************/
/*****************    Clinic Management System    **********/
/*****************    Virsion :  1.0          **************/
/***********************************************************/

# include "STD_TYPES.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "Linked_list.h"


int main()
{
	u8 choice; 
	u32	value2, value4, val_id, slot_num;			
	u8  value1[50],  value3[20];		
	u32 new_value2, new_value4;
	u8  new_value1[50],  new_value3[20];
	while(1)
   {		
		u8 ModeChoice; 
		static u8 PassBeforeFlag = 0;// IF == 0 THEN ITS FRIST TIME TO ENTER PASS
		u16 PassWordEnter;
		printf("\nChoose an Option: \n");
		printf("1-Admin mode.  2-User mode. 3-Close the program\n");
		scanf("%d", &ModeChoice);
		
		if( ModeChoice == 1 )
		{
			if( PassBeforeFlag == 0 )
			{
				printf("You are in Admin mode \n");
				printf("Please enter the password\n");
				scanf("%d",&PassWordEnter);
			
				u8 count = 0;
				while( (PassWordEnter != 1234) && (count < 2) )
				{
					printf("The password is wrong enter it again \n");	
					scanf("%d",&PassWordEnter);
					count++;
				}
				
				if( PassWordEnter != 1234 )
				{
					printf("Sorry u have entered the password 3 times incorrectly the system will close \n");	
					return 0;
				}
			}
			
			if(PassWordEnter == 1234) ///Admin mode
			{
				PassBeforeFlag = 1;
				printf("\nTo add patient Enter 0\n");
				printf("To print the linked list Enter 1\n");
				printf("To search a ID Enter 2\n");
				printf("To Edit patient record Enter 3\n");
				printf("To Reserve a slot with the doctor Enter 4\n");
				printf("To Cancel reservation Enter 5\n");
				printf("To exit Enter 6\n");
				////
				while(1)
				{
					printf("\nInter your choice: ");
					scanf("%d",&choice);
					if(choice == 0)
					{
						printf("Please Enter Node data: \n");
						
						printf("Please Enter Name: \n");
						scanf("%s",value1 );
						printf("Please Enter AGE: \n");
						scanf("%d",&value2 );
						printf("Please Enter GENDER: \n");
						scanf("%s",value3 );
						printf("Please Enter ID: \n");
						scanf("%d",&value4);
						
						ADD_NODE_AT_LAST( value1 ,  value2,  value3 , value4);
						
						printf("Node Added Thank You \n\n\n");
		
					}
					else if (choice == 1)
					{
						PRINT_LIST();
					}
					else if(choice == 2)
					{
						printf("Inter the ID u want to search: ");
						scanf("%d",&val_id);
						SEARCH_VALUE(val_id);
					}
					else if(choice == 3)
					{
						printf("Enter the ID that u want to edit its data ,and Enter New data : \n");
						
						scanf("%d",&val_id);
						u8 ss = SEARCH_VALUE(val_id);
						if(ss == 1)
						{
						printf("Please Enter new Name: \n");
						scanf("%s",new_value1);
						printf("Please Enter new AGE: \n");
						scanf("%d",&new_value2);
						printf("Please Enter new GENDER: \n");
						scanf("%s",new_value3);
						printf("Please Enter new ID: \n");
						scanf("%d",&new_value4);
						}
						
						
						UPDATE(val_id, new_value1, new_value2, new_value3 , new_value4 );
					}
					else if (choice == 4)
					{
						printf("Enter the ID of patient that want to Reserve slot : ");
						scanf("%d",&val_id);
						u8 ss = SEARCH_VALUE(val_id);
						if(ss == 1)
						{
							Available_slot 	(val_id);
							///printf("Chose the Num of slot that u want to Reserve : ");
							scanf("%d",&slot_num);
							printf("----------------------\n\n\n");
							Reserve_slot(val_id, slot_num );	
						}
						
					}
					else if (choice == 5)
					{
						printf("Enter the ID of patient that want to cancel his Reserved slot : ");
						scanf("%d",&val_id);
						Cancel_reservation(val_id);
					}
					else if (choice == 6)
					{
						
						printf("Thank You :)\n\n");
						break;
					}
					else
					{
						printf("Invalid Choice :( please try again\n");
					}
						
				}
			
					}
		}
		else if( ModeChoice == 2 ) ///User mode
		{
			printf("\nTo view patient record Enter 1\n");
			printf("To view today’s reservations Enter 2\n");
			printf("To exit Enter 3\n");
			
			while(1)
			{
				printf("\nInter your choice: ");
				scanf("%d",&choice);
				if( choice == 1 )
				{
					printf("Enter The ID of the Patient:\n");
					scanf("%d", &val_id);
					Print_Patient_Record	( val_id );
				}
				else if( choice == 2 )
				{
					 View_reservations	();
				}
				else if( choice == 3 )
				{
					printf("Thank You :)\n\n");
					break;
				}
			}
				
				
		}
		else if( ModeChoice == 3 )
		{
			printf("Thank You :)\nGoodbye\n");
			break;
		}

    }	
	 
	return 0;
}