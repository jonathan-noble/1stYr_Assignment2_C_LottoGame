/* 	Author: 			Jonathan Noble - C15487922 - DT282/1
    Task:               Programming Assignment 2
   	Submission Date:    6/03/16
   	Program Name: 		Lotto Game
   	Requirements:		The program should allow a user to enter their 6 selected numbers and give them a set of options, each performing a
						specific requirement. You must store the 6 numbers in a 1-Dimensional array.

                        OPTIONS OF THE MENU
                    	1.Read the 6 selected numbers from the keyboard. Perform any necessary validation (error-checking) required (e.g. all numbers must be different, range 1-42, etc.).
                    	
                        2. Display the contents of the 1-D array containing your lotto numbers that you entered. 

                    	3. Sort the contents of the array in increasing order (i.e. 1st element = smallest number, 2nd element = 2nd smallest number, etc.). You may use any sorting
                    	algorithm of your choice. 

                    	4. Compare your chosen lotto numbers in the 1-D array with the following winning numbers: 1,3,5,7,9,11 - 42 (Bonus number)

                        5. Display the frequency of the numbers entered each time the user enters a new set of numbers (without exiting the program) on the screen. For example, it
                        might display:
                        number 1 has been selected x times
                        number 7 has been selected x times

                        6. Exit the program
*/

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

#define ENTERED 6		//used for input_nums, display_nums and sort_nums functions
#define WIN 6			//used for compare_nums function
#define SIZE 42         //used for freq_nums function


// Prototypes
void input_nums(int*, int*);		// function for numbers to be entered by user
void display_nums(int*);            // function to display numbers entered
void sort_nums(int*);				// function to sort out numbers by using selection sort algorithm
void compare_nums(int*, int*);		// function to compare two arrays 
void freq_nums(int*);               // function to display how many times a number was entered throughout the rounds

main()
{
	// Initialize variables
	int lottery[ENTERED];
	int win_array[] = {1, 3, 5, 7, 9, 11, 42};	
	int frequency[SIZE + 1] = {0};

	int options;
	int opt_2 = 0;
	int opt_3 = 0;
	int opt_4 = 0;
	int opt_5 = 0;



	// do-while loop is used to execute the option
	do
	{
		  // Menu starts here
			puts("-------------------------------------------");
            printf("           LOTTO GAME           \n");
            puts("\n Please choose an option from 1-4:  ");
            puts("1. ENTER your six lucky numbers! ");
            puts("2. DISPLAY the lotto numbers entered ");
            puts("3. SORT OUT the lotto numbers entered!");
            puts("4. COMPARE the lotto numbers ");
            puts("5. DISPLAY the FREQUENCY of numbers entered! ");
            puts("6. EXIT the program! ");
            puts("-------------------------------------------");
            scanf("%d", &options);


           
            system ("cls");


		switch(options)
		{
			case 1:
				    {
				       // First function executes here
						input_nums(lottery, frequency);	
					 
                        // These variables are incremented to ensure that the other options won't execute until option 1 is finished
					 	opt_2++;
					 	opt_3++;
					 	opt_4++;
					 	opt_5++;
					 
						break;
							
				    } // end case 1 
				

				
			case 2:
				    {			
						// If-else statement is used to make sure the program will only start after case 1 is executed					                            
                        if( opt_2 > 0)
						{
								
                            //Inner if-else statement ensures that the program will not run other options unless all user's numbers are entered
							if  (*(lottery + 0) >= 1 && *(lottery + 0) <= 42 &&  
                                 *(lottery + 1) >= 1 && *(lottery + 1) <= 42 && 
                                 *(lottery + 2) >= 1 && *(lottery + 2) <= 42 && 
                                 *(lottery + 3) >= 1 && *(lottery + 3) <= 42 &&  
                                 *(lottery + 4) >= 1 && *(lottery + 4) <= 42 &&
                                 *(lottery + 5) >= 1 && *(lottery + 5) <= 42  )
                            {

                                display_nums(lottery);

                            }	// end inner if
                            
                            else
                            {

                                puts(" You have entered an invalid option. Try again!");
                                puts("You must do option 1 first before proceeding to the advanced options.");
                               
                            } // end inner else

                        } // end outer if
                        
                        else
                        {

                            puts(" You have entered an invalid option. Try again!");
                            puts("You must do option 1 first before proceeding to the advanced options.");

                        } // end outer else
                         
                    

					break;

				    } // end case 2

				
				
			case 3:
				    {	
                        // If-else statement is used to make sure the program will only start after case 1 is executed
                        if( opt_3 >0)
						  {
									
                                //Inner if-else statement ensures that the program will not run other options unless all user's numbers are entered
    							if  (*(lottery + 0) >= 1 && *(lottery + 0) <= 42 &&  
                                     *(lottery + 1) >= 1 && *(lottery + 1) <= 42 && 
                                     *(lottery + 2) >= 1 && *(lottery + 2) <= 42 && 
                                     *(lottery + 3) >= 1 && *(lottery + 3) <= 42 &&  
                                     *(lottery + 4) >= 1 && *(lottery + 4) <= 42 &&
                                     *(lottery + 5) >= 1 && *(lottery + 5) <= 42  )
                                    {

                                       	sort_nums(lottery);

                                    }	// end inner if
                                        
                                 else
                                    {

                                        puts(" You have entered an invalid option. Try again!");
                                        puts("You must do option 1 first before proceeding to the advanced options.");
                                   
                                    }

                                } // end first outer if
                                
                            else
                            {

                                    puts(" You have entered an invalid option. Try again!");
                                    puts("You must do option 1 first before proceeding to the advanced options.");	
    						
                            } // end outer else

                         

                            break;

				    } // end case 3



			case 4:
				    {
                        // If-else statement is used to make sure the program will only start after case 1 is executed
                        if( opt_4 >0)
							{
								
                                //Inner if-else statement ensures that the program will not run other options unless all user's numbers are entered
								 if (*(lottery + 0) >= 1 && *(lottery + 0) <= 42 &&  
                                     *(lottery + 1) >= 1 && *(lottery + 1) <= 42 && 
                                     *(lottery + 2) >= 1 && *(lottery + 2) <= 42 && 
                                     *(lottery + 3) >= 1 && *(lottery + 3) <= 42 &&  
                                     *(lottery + 4) >= 1 && *(lottery + 4) <= 42 &&
                                     *(lottery + 5) >= 1 && *(lottery + 5) <= 42  )

                                {

                                   	compare_nums(win_array, lottery);

                                }	// end inner if
                                
                                else
                                {

                                    puts(" You have entered an invalid option. Try again!");
                                    puts("You must do option 1 first before proceeding to the advanced options.");
                                
                                }

                            } // end outer if
                        
                        else
                        {

                                    puts(" You have entered an invalid option. Try again!");
                                    puts("You must do option 1 first before proceeding to the advanced options.");
                        
                        } // end outer else
						
						break; 

			 	   } // end case 4


            case 5:
                   {
                        // If-else statement is used to make sure the program will only start after case 1 is executed
                        if( opt_5 >0)
                            {
                                
                                //Inner if-else statement ensures that the program will not run other options unless all user's numbers are entered
                                 if (*(lottery + 0) >= 1 && *(lottery + 0) <= 42 &&  
                                     *(lottery + 1) >= 1 && *(lottery + 1) <= 42 && 
                                     *(lottery + 2) >= 1 && *(lottery + 2) <= 42 && 
                                     *(lottery + 3) >= 1 && *(lottery + 3) <= 42 &&  
                                     *(lottery + 4) >= 1 && *(lottery + 4) <= 42 &&
                                     *(lottery + 5) >= 1 && *(lottery + 5) <= 42  )

                                {

                                    freq_nums(frequency);

                                }   // end inner if
                                
                                else
                                {

                                    puts(" You have entered an invalid option. Try again!");
                                    puts("You must do option 1 first before proceeding to the advanced options.");
                                
                                }

                            } // end outer if
                        
                        else
                        {

                                    puts(" You have entered an invalid option. Try again!");
                                    puts("You must do option 1 first before proceeding to the advanced options.");
                        
                        } // end outer else
                        
                        break; 

                   } // end case 5

             case 6:
            {
                // exit option of the game
                
                puts("Win or lose, thank you for trying! The program will now exit!");
                
                break;
            } // end case 6

			default:
						 puts("Please select the options from 1-6. Try again!");
                        break;

		} // end option switch


	}// end do loop

	while(options!=6);

getchar();
getchar();


} //end main()



/* Implement function input_nums */

void input_nums(int *lucky_num, int *frequency)		
{
	int i, j, swap;

	puts("Please enter your desired six numbers (range: 1-42) ");

	for(i=0; i<ENTERED; i++)
    {   
        scanf("%d", & *(lucky_num + i));

        /* the if statement  ensures if the user inputs numbers inside the range 1 - 42 */
        if (*(lucky_num + i) >= 1 && *(lucky_num + i) <= 42)
        {
    
	            /* this error-checks if the user inputs the same number inside the array */
	            for (j=0; j < i; j++)
	            {
	                if( *(lucky_num + i) == *(lucky_num + j) )
	                {

	                    puts("Sorry but you cannot enter the same number again");
	                    puts("The program will now restart. Try again!");
	                    return; 	//it returns back to the options if the user inputs the same number

	            	}//end inner if

	            	
            	}//end inner for loop for checking
	        
        }//end inner if


        /* the else statement confirms that the user input numbers inside the range 1 - 42 */
        else
        {

            puts("Please enter your lucky numbers ONLY within the range of 1-42.");
            printf("The program will now restart. Try again! \n\n");

     		return;	//it returns back to the options if the user inputs numbers outside the range

        }//end else
        

        swap = *(lucky_num + i);       

        *(frequency + swap) = *(frequency + swap) + 1;      

    }//end outer for

    printf("\nThank you! Now select option 2 to display your lucky numbers! \n\n");

} // end function lucky_numbers


/* Implement function display_nums to display entered numbers */
void display_nums(int *expo)
{

    int i;
    int order = 1;  // integer order is used to make the program look neater
	
	printf("Lucky numbers you entered are: \n");
	for (i=0; i<ENTERED; i++)
	{

	   printf("%d) \t %d \n", order++, *(expo+i) );

	}	// end for

    printf("\nThank you! Now select option 3 to sort out your lucky numbers! \n\n");

}	// end function display_nums 



/* Implement function sort_nums to sort out the numbers */
void sort_nums(int *A_nums)
{

  	int min; 	//integer min looks for the smallest number in the array and places it in the first element
    int swap; 	//integer swap is a temporary variable to swap numbers
    int i, j;
    
    //Selection sort will start here - it looks throughout the array to find the smallest number and sorts it in an ascending order  
    for(i=0; i<ENTERED-1; i++)
    {

        min = i;

        for(j= i+1; j<ENTERED; j++)
        {
            if(A_nums[j] < A_nums[min])
            {
                min = j;
            }

        }//end for
        swap = A_nums[min];
        A_nums[min] = A_nums[min];
        A_nums[min] = A_nums[i];
        A_nums[i] = swap;

    } // end for
    
    printf("The sorted numbers are: \n");
    for(i=0; i<ENTERED; i++)
    {

        printf("%d ", *(A_nums + i) ); //it aranges the numbers in ascending formation
        printf("\n");

    } //end for

    printf("\nThank you! Now select option 4 to play the lotto! \n\n");

} // end function sort_nums



/* Implement function compare_nums to compare the desired numbers to the winning numbers */
void compare_nums(int *first_A, int *second_A)
{

    int i, j;
    int match = 0;
    int bonus = *(first_A + 6);
    int bonus_count = 0;

    // The prizes for getting the winning prizes over the entered numbers are displayed here
    puts("-----------------------------------------------");
    puts("| Match 6:                 JACKPOT!           |");
    puts("| Match 5 + Bonus:         New Car!           |");
    puts("| Match 5:                 Holiday            |");
    puts("| Match 4 + Bonus:         Weekend Away       |");
    puts("| Match 4:                 Night Out          |");
    puts("| Match 3:                 Cinema Ticket      |");
    puts("----------------------------------------------");
    printf("\n");
    printf("The winning numbers are: 1,3,5,7,9,11 - 42 (Bonus number) \n");

    // For loop compares the entered numbers over the winning numbers
    for(i=0; i<WIN; i++)
    {
    	for (j=0; j<WIN; j++)
    	{
    		if ( *(first_A + j) == *(second_A + i) )
    		{

    			match++; 

    		} // end if

    	} // end inner for loop

        // When bonus number 42 is entered, this will be executed
        if( *(second_A + i) == bonus)
        {
            printf("Wow! You got the bonus number 42! \n");
        } // end if


    } // end outer for


    /*Matches and their Bonus Numbers are implemented here */
    if (match == 6)
    {
        puts("Congrats! You've won the JACKPOT!");
    } // end if

    else if (match == 5 && bonus_count == 1)
    {
        puts("Wonderful! You've won a NEW CAR!");
    } // end else if

    else if (match == 5)
    {
        puts("Wow! You've won a Holiday at Majorca!");
    } // end else if

    else if (match == 4 && bonus_count == 1)
    {
        puts("Amazing! You've won a Weekend Away at Donegal!");
    } // end else if

    else if (match == 4)
    {
        puts("Splendid! You've won a Night Out at Hilton Hotel!");
    } // end else if

    else if (match == 3 && bonus_count == 1)
    {
        puts("Nice one! You've won a Cinema Ticket at Cineworld!");
    } // end else if

    else if (match == 3 || match == 2 || match == 1)
    {
        puts("Sorry you didn't win anything. Better luck next time!");
    } // end else if


    printf("\nThank you! Now select option 5 to check out how many times a number was entered!\n\n");
    

}	// end function compare_nums


/* Implement function freq_nums to display how many times a number was entered throughout the rounds */
void freq_nums (int *frequency)
{
    int i;

    printf("Do you want to see how many times you've entered a particular number? \n");

    // For loop ensures that the number entered from "lottery" array is read by adding in +1 from SIZE
    for (i=0; i < SIZE + 1; i++)
    {
        // When a number is not entered, the frequency function will not be able to input that number
        if ( *(frequency + i) != 0)
        {
            printf("number %d has been %d times \n", i, *(frequency + i) );
        } // end if 

    } // end for

    printf("\nThank you! Now select option 6 to exit! \n\n");

} // end function freq_nums
