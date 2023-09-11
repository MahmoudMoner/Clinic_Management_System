/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 9/9/2023      *****************/
/*****************    Clinic Management System    **********/
/*****************    Virsion :  1.0          **************/
/***********************************************************/

# include "STD_TYPES.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "Linked_list.h"

static Node *head = NULL;
static Node *current = NULL;


 u32 flag = 0; // num of nodes but i called it at frist flag then i cant change it now because i use it mant times hahah
 
 static u16 slot[5];
 
static  u32 FlagSlot1 = 0;  // if == 1 so the slot is already Reserved
static  u32 FlagSlot2 = 0;  // if == 1 so the slot is already Reserved
static  u32 FlagSlot3 = 0;  // if == 1 so the slot is already Reserved
static  u32 FlagSlot4 = 0;  // if == 1 so the slot is already Reserved
static  u32 FlagSlot5 = 0;  // if == 1 so the slot is already Reserved


/////////////////////////////////////////////////////////////////////////////////////

void ADD_NODE_AT_FRIST	(u8 *value1, u32 value2, u8 *value3,u32 value4)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	
	temp -> NAME		= value1;
	temp -> AGE 		= value2;
	temp -> GENDER		= value3;
	temp -> ID 			= value4;
	
	temp -> Next 		= head;
	head = temp;
	flag++;
	
	
}

/////////////////////////////////////////////////////////////////////////////////////

void ADD_NODE_AT_LAST(u8 *value1, u32 value2, u8 *value3, u32 value4)
{
  Node *temp = (Node*)malloc(sizeof(Node));
  
  // Allocate memory for NAME and GENDER
  temp -> NAME = (u8*)malloc(strlen(value1) + 1);
  temp -> GENDER = (u8*)malloc(strlen(value3) + 1);
  
  // Copy the values into the newly allocated memory
  strcpy(temp -> NAME, value1);
  strcpy(temp -> GENDER, value3);
  
  temp -> AGE = value2;
  temp -> ID = value4;
  temp -> Next = NULL;
  
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    current = head;
    while (current -> Next != NULL) {
      current = current -> Next;
    }
    current -> Next = temp;
  }
  
  flag++;
}
/////////////////////////////////////////////////////////////////////////////////////

u8 SEARCH_VALUE		(u32 ID)
{
	 u8 searchfalg = 0;
	printf("\n\n----------------------\n");
	
	if(flag > 0)
	{
		current = head;	
		u8 findflag = 0 ;
		int i  ;
		
		for (i = 0; i < flag; i++)
		{
			
		if ( current -> ID == ID )
			{
				findflag = 1;
				break;
			}
			else
			{
				current = current -> Next;
			}
		}
		
		
		if(findflag == 1)
		{
			printf("ID is found in node num %d\n",i+1 );
			 searchfalg = 1;
			  
		}
		else
			{
				printf("ID is not exists in the list\n");
				 searchfalg = 0;
			}

	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");
	return searchfalg;
}

/////////////////////////////////////////////////////////////////////////////////////

u32 LIST_SIZE			(void)
{
	printf("\n\n----------------------\n");
	
	u16 Local_u16SizeOfNode = sizeof(Node);
	
	printf("----------------------\n\n\n");
	
	return Local_u16SizeOfNode;
}	 

/////////////////////////////////////////////////////////////////////////////////////

void PRINT_LIST(void)
{
	
		printf("\n\n----------------------\n");
		

	if(flag > 0)
	{
		current = head;
		u32 i = 1;
		printf("Node Number %d NAME   = %s\n", i,     current -> NAME);
		printf("Node Number %d AGE    = %d\n", i,     current -> AGE);
		printf("Node Number %d GENDER = %s\n", i,     current -> GENDER);
		printf("Node Number %d ID     = %d\n", i,     current -> ID);
		printf("\n");
		printf("\n");
		while(current -> Next != NULL)
		{
			i++;
			current = current -> Next;
			printf("Node Number %d NAME   = %s\n", i, current -> NAME );
			printf("Node Number %d AGE    = %d\n", i, current -> AGE);
			printf("Node Number %d GENDER = %s\n", i, current -> GENDER );
			printf("Node Number %d ID     = %d\n", i, current -> ID);
			printf("\n");
			printf("\n");
		}
	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");

}

/////////////////////////////////////////////////////////////////////////////////////

void UPDATE 			(u32 node_id, u8 *New_value1, u32 New_value2, u8 *New_value3,u32 New_value4)
{
	printf("\n\n----------------------\n");
	
	if(flag > 0)
	{
		current = head;	
		u8 findflag = 0 ;
		int i  ;
		
		for (i = 0; i < flag; i++)
		{
			
		if ( current -> ID == node_id )
			{
				findflag = 1;
				break;
			}
			else
			{
				current = current -> Next;
			}
		}
		
		
		if(findflag == 1 )
		{
			
			// Allocate memory for NAME and GENDER
			current -> NAME = (u8*)malloc(strlen(New_value1) + 1);
			current -> GENDER = (u8*)malloc(strlen(New_value3) + 1);
  
			// Copy the values into the newly allocated memory
			strcpy(current -> NAME, New_value1);
			strcpy(current -> GENDER, New_value3);
  
			current -> AGE = New_value2;
			current -> ID  = New_value4;
			
			printf("Data in node num %d is updated succssfully \n",i+1 );
		}
		else
			{
				printf("Try again\n");	
			}

	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////

void Reserve_slot 		(u32 node_id, u32 slot_num)
{
	
	
	printf("\n\n----------------------\n");
	
	if(flag > 0)
	{
		current = head;	
		u8 findflag = 0 ;
		int i  ;
		
		for (i = 0; i < flag; i++)
		{
			
		if ( current -> ID == node_id )
			{
				findflag = 1;
				break;
			}
			else
			{
				current = current -> Next;
			}
		}
		
		
		if(findflag == 1)
		{
			//////////////////////////////////////////
			//////////////////////////////////////////
			
			if( FlagSlot1 == 0 && slot_num == slot1)
			{
				printf("Ok sir u have reserved a Slot num 1 from 2pm to 2:30pm\n");
				FlagSlot1 = 1;
				 slot[0] = node_id;
			} 								
			else if( FlagSlot2 == 0 && slot_num == slot2)                     
			{                                        
				printf("Ok sir u have reserved a Slot num 2 from 2:30pm to 3pm\n");
				FlagSlot2 = 1;
				 slot[1] = node_id;
			}					
			else if ( FlagSlot3 == 0 && slot_num == slot3)                    
			{                                        
				printf("Ok sir u have reserved a Slot num 3 from 3pm to 3:30pm\n");
				FlagSlot3 = 1;
				 slot[2] = node_id;
			}                                        			
			else if ( FlagSlot4 == 0 && slot_num == slot4)                   
			{                                        
				printf("Ok sir u have reserved a Slot num 4 from 4pm to 4:30pm\n");
				FlagSlot4 = 1;
				 slot[3] = node_id;
			}                                        			
			else if ( FlagSlot5 == 0 && slot_num == slot5)                    
			{                                        
				printf("Ok sir u have reserved a Slot num 5 from 4:30pm to 5pm\n");
				FlagSlot5 = 1;
				 slot[4] = node_id;
			}
			else
			{
				printf("Sorry sir that Slot is not available\n");
			}		

		}
		else
			{
				printf("ID is not exists in the list\n");
				
			}

	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");
	
}

/////////////////////////////////////////////////////////////////////////////////////

void Available_slot 	(u32 node_id)
{
	printf("\n\n----------------------\n");
	
	if(flag > 0)
	{
		current = head;	
		u8 findflag = 0 ;
		int i  ;
		
		for (i = 0; i < flag; i++)
		{
			
		if ( current -> ID == node_id )
			{
				findflag = 1;
				break;
			}
			else
			{
				current = current -> Next;
			}
		}
		
		
		if(findflag == 1)
		{
			//printf("ID is found in node num %d\n",i+1 );
			
			printf("The available slots is: \n");
			
			if( FlagSlot1 == 0 )
			{
				printf("Slot num 1 from 2pm to 2:30pm\n");
			}                                        
			
			if( FlagSlot2 == 0 )                     
			{                                        
				printf("Slot num 2 from 2:30pm to 3pm\n");
			}                                        
			
			if ( FlagSlot3 == 0 )                    
			{                                        
				printf("Slot num 3 from 3pm to 3:30pm\n");
			}                                        
			
			 if ( FlagSlot4 == 0 )                   
			{                                        
				printf("Slot num 4 from 4pm to 4:30pm\n");
			}                                        
			
			if ( FlagSlot5 == 0 )                    
			{                                        
				printf("Slot num 5 from 4:30pm to 5pm\n");
			}	
				printf("Chose the Num of slot that u want to Reserve : \n");
		}
		else
			{
				
			}

	}
	else
	{
		printf("The list is Empty\n");
	}
	
	//printf("----------------------\n\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////
void Cancel_reservation	(u32 node_id)
{
	printf("\n\n----------------------\n");
	
	if(flag > 0)
	{
		current = head;	
		u8 findflag = 0 ;
		int i  ;
		
		for (i = 0; i < flag; i++)
		{
			
		if ( current -> ID == node_id )
			{
				findflag = 1;
				break;
			}
			else
			{
				current = current -> Next;
			}
		}
		
		
		if(findflag == 1)
		{
			printf("ID is found in node num %d\n",i+1 );
			
			if( FlagSlot1 == 1 && slot[0] == node_id)
			{
				printf("Ok sir , i canceled your reserved  Slot from 2pm to 2:30pm\n");
				FlagSlot1 = 0;
				 slot[0] = 0;
			} 
						
			
			if( FlagSlot2 == 1 && slot[1] == node_id)                     
			{                                        
				printf("Ok sir , i canceled your reserved  Slot from 2:30pm to 3pm\n");
				FlagSlot2 = 0;
				 slot[1] = 0;
			}
				
			
			if ( FlagSlot3 == 1 && slot[2] == node_id)                    
			{                                        
				printf("Ok sir , i canceled your reserved  Slot from 3pm to 3:30pm\n");
				FlagSlot3 = 0;
				 slot[2] = 0;
			}                                        
				
			
			 if ( FlagSlot4 == 1 && slot[3] == node_id)                   
			{                                        
				printf("Ok sir , i canceled your reserved  Slot from 4pm to 4:30pm\n");
				FlagSlot4 = 0;
				 slot[3] = 0;
			}                                        
			
			
			if ( FlagSlot5 == 1 && slot[4] == node_id)                    
			{                                        
				printf("Ok sir , i canceled your reserved  Slot from 4:30pm to 5pm\n");
				FlagSlot5 = 0;
				 slot[4] = 0;
			}
			

		}
		else
			{
				printf("ID is not exists in the list\n");
				
			}

	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}

/////////////////////////////////////////////////////////////////////////////////////

void Print_Patient_Record	(u32 ID)
{
	 
	printf("\n\n----------------------\n");
	
	if(flag > 0)
	{
		current = head;	
		u8 findflag = 0 ;
		int i  ;
		
		for (i = 0; i < flag; i++)
		{
			
		if ( current -> ID == ID )
			{
				findflag = 1;
				break;
			}
			else
			{
				current = current -> Next;
			}
		}
		
		
		if(findflag == 1)
		{
			printf("ID is found in node num %d\n\n",i+1 );
			printf("NAME   = %s\n", current -> NAME);
			printf("AGE    = %d\n", current -> AGE);
			printf("GENDER = %s\n", current -> GENDER);
			printf("ID     = %d\n\n", current -> ID);
			static u8 slotflag = 1;
			for(u8 c = 0; c < 5; c++ )
			{
				if(slot[c] == ID)
				{
					printf("This client have reserved a Slot num %d \n", c+1);
					slotflag = 1;
					break;
				}
				else
				{
					 slotflag = 0;
				}
					
			}
			
			if( slotflag == 0 )
			{
				printf("This client didn't reserved a Slot \n");
			}
				
			printf("\n");
			  
		}
		else
			{
				printf("ID is not exists in the list\n");
				 
			}

	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");
	
}

/////////////////////////////////////////////////////////////////////////////////////

void View_reservations	(void)
{
	 
	printf("\n\n----------------------\n");
		

	if(flag > 0)
	{
		current = head;

		for(u8 c = 0; c < 5; c++ )
			{
				if(slot[c] != 0)
				{
					printf("Slot num %d is reserved by Clint wit ID %d\n", c+1, slot[c]);									
				}
	
			}
		
	}
	else
	{
		printf("The list is Empty\n");
	}
	
	printf("----------------------\n\n\n");
	
}
/////////////////////////////////////////////////////////////////////////////////////