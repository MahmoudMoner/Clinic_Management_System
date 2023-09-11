/***********************************************************/
/*****************    Name : Mahmoud Moner *****************/
/*****************    Date : 9/9/2023      *****************/
/*****************    Clinic Management System    **********/
/*****************    Virsion :  1.0          **************/
/***********************************************************/

# ifndef Linked_List_h
# define Linked_List_h

typedef struct Node
{
	u8 *NAME ; 	
	u32 AGE;
	u8 *GENDER ;
	u32 ID;
	
	struct Node *Next;
}Node;



# define 	slot1       1      //2pm to 2:30pm
# define 	slot2       2     //2:30pm to 3pm
# define 	slot3       3    //3pm to 3:30pm
# define 	slot4       4   //4pm to 4:30pm
# define 	slot5       5  //4:30pm to 5pm
	
	


void ADD_NODE_AT_FRIST	(u8 *value1, u32 value2, u8 *value3,u32 value4);

void ADD_NODE_AT_LAST	(u8 *value1, u32 value2, u8 *value3,u32 value4);

u8 SEARCH_VALUE		( u32 ID);

u32 LIST_SIZE			(void);	 

void PRINT_LIST			(void);

void UPDATE 			(u32 node_id, u8 *New_value1, u32 New_value2, u8 *New_value3,u32 New_value4);

void Reserve_slot 		(u32 node_id, u32 slot_num);

void Available_slot 	(u32 node_id);

void Cancel_reservation	(u32 node_id);

void Print_Patient_Record	(u32 ID);


#endif