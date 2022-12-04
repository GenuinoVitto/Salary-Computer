/*
	C Program that computes the salary of employee/s according to Philippine Law
	
	Author : Jose Mari Victorio G. Genuino
	Date Created : November 7, 2022
	Date Accomplished : December 4, 2022
	Purpose : CCPROG1 S27 - Machine Project - Salary Computer	

	13 functions in total including main function and 723 lines of code
	
	Disclaimers :
		Throughout the program you will say lines of code surrounded by "checkers" that are commented out. If one wants to see the 
		result of different "minor" functions in the program (especially within the computeTotalSalaryForShifts(); function), 
		you may remove comment lines from the code and run the program to see what the different printf functions will display.
	
	Issues : 
		Under the "Not working on a regular holiday" condition:
		"but since in total this employee only worked 5 hours total during the regular holiday, the employee should still receive additional
		3 hours pay in the computation of their total salary (regular rate) since the employee must be paid for a minimum of 8 hours for the 
		regular holiday."
		This condition has not been met by the program.
*/

#include <stdio.h> // standard header file
#include <stdlib.h> // allows this program to use system("cls"); function into program without there being a warning


// Function that returns the day value of the month and day given by the employee/s
int 
daysChecker(int month, int day)
{
	int actualDay=0;
	switch(month)
	{
		case 1: 
			if(day>0&&day<=31)
				actualDay+=day;
			else
				actualDay=0;
			break;
		case 2: 
			if(day>0&&day<=28)
				actualDay+=(31+day);
			else
				actualDay=0;
			break;
		case 3:
			if(day>0&&day<=31)
				actualDay+=(59+day);
			else
				actualDay=0;
			break;
		case 4:
			if(day>0&&day<=30)
				actualDay+=(90+day);
			else
				actualDay=0;
			break;
		case 5:
			if(day>0&&day<=31)
				actualDay+=(120+day);
			else
				actualDay=0;
			break;
		case 6:
			if(day>0&&day<=30)
				actualDay+=(151+day);
			else
				actualDay=0;
			break;
		case 7:
			if(day>0&&day<=31)
				actualDay+=(181+day);
			else
				actualDay=0;
			break;	
		case 8:
			if(day>0&&day<=31)
				actualDay+=(212+day);
			else
				actualDay=0;
			break;
		case 9:
			if(day>0&&day<=30)
				actualDay+=(243+day);
			else
				actualDay=0;
			break;
		case 10:
			if(day>0&&day<=31)
				actualDay+=(273+day);
			else
				actualDay=0;
			break;
		case 11:
			if(day>0&&day<=30)
				actualDay+=(304+day);
			else
				actualDay=0;
			break;
		case 12:
			if(day>0&&day<=31)
				actualDay+=(334+day);
			else
				actualDay=0;
			break;
	}
	return actualDay;
}

// Function that allows the employee/s to input the starting date of the time period they wish to compute their salary
int
timePeriodStart()
{	
	int start,month,day;
	do
	{
	system("cls");
	printf("\n   ------------------	------------------\n");
	printf("   |     Months     |   |      Days      |  \n");
	printf("   ------------------	------------------\n");
	printf("   | 01 - January   |   |    01 - 31     |\n");
	printf("   | 02 - February  |   |    01 - 28     |\n");
	printf("   | 03 - March     |   |    01 - 31     |\n");
	printf("   | 04 - April     |   |    01 - 30     |\n");
	printf("   | 05 - May       |   |    01 - 31     |\n");
	printf("   | 06 - June      |   |    01 - 30     |\n");
	printf("   | 07 - July      |   |    01 - 31     |\n");
	printf("   | 08 - August    |   |    01 - 31     |\n");
	printf("   | 09 - September |   |    01 - 30     |\n");
	printf("   | 10 - October   |   |    01 - 31     |\n");
	printf("   | 11 - November  |   |    01 - 30     |\n");
	printf("   | 12 - December  |   |    01 - 31     |\n");
	printf("   ------------------   ------------------\n");
	printf("\n   Please input the Starting date for your salary computation.\n");
	printf("\n   Month : ");
	scanf("%d", &month);
	printf("\n   Day of the Month: ");
	scanf("%d", &day);
	start = daysChecker(month,day);
	}while(start==0);
	return start;
}

// Function that allows the employee/s to input the ending date of the time period they wish to compute their salary
int 
timePeriodEnd()
{
	int end,month,day;
	do
	{
	system("cls");
	printf("\n   ------------------	------------------\n");
	printf("   |     Months     |   |      Days      |  \n");
	printf("   ------------------	------------------\n");
	printf("   | 01 - January   |   |    01 - 31     |\n");
	printf("   | 02 - February  |   |    01 - 28     |\n");
	printf("   | 03 - March     |   |    01 - 31     |\n");
	printf("   | 04 - April     |   |    01 - 30     |\n");
	printf("   | 05 - May       |   |    01 - 31     |\n");
	printf("   | 06 - June      |   |    01 - 30     |\n");
	printf("   | 07 - July      |   |    01 - 31     |\n");
	printf("   | 08 - August    |   |    01 - 31     |\n");
	printf("   | 09 - September |   |    01 - 30     |\n");
	printf("   | 10 - October   |   |    01 - 31     |\n");
	printf("   | 11 - November  |   |    01 - 30     |\n");
	printf("   | 12 - December  |   |    01 - 31     |\n");
	printf("   ------------------   ------------------\n");
	printf("\n   Please input the Ending date for your salary computation.\n");
	printf("\n   Month : ");
	scanf("%d", &month);
	printf("\n   Day of the Month: ");
	scanf("%d", &day);
	end = daysChecker(month,day);
	}while(end==0);
	system("cls");
	return end;
}

// Function that allows the employee/s to input how many total salaries will be computed
int
numberOfSalaries()
{
	int num;
	printf("\n   Please input the number of salaries the employee/s wish to compute : ");
	scanf("%d", &num);
	return num;
}

// Function that allows the employee/s to input their daily salary rate and returns their hourly rate
float 
hourlySalaryRate(int i)
{
	float dailySalaryRate,hourlyRate;
	if(i==0)
	{
		printf("\n   Please input the Daily Salary Rate of the first user, User %d : \n", i);
		scanf("%f", &dailySalaryRate);
	}
	else
	{
		printf("\n   Please input the Daily Salary Rate of the next user, User %d : \n", i);
		scanf("%f", &dailySalaryRate);
	}
	hourlyRate=dailySalaryRate/8;
	
	/*v checker v*/
//	printf("\n   Current employee hourly rate is Php %.2f\n",hourlyRate);
	/*^ checker ^*/
	
	return hourlyRate;
}

// Function that allows the employee/s to input how many rest days they have
int
numRestDay()
{
	int numRestDays;
// variable declaration
	system("cls");
	printf("\n   ---------------------------------------\n");
	printf("   |             Amount in Days          |\n");
	printf("   |               (max 10)              |\n");
	printf("   ---------------------------------------\n");
	
	printf("\n   How many rest days do you have? : ");
	scanf("%d", &numRestDays);
	system("cls");
	return numRestDays;
}

// Function that allows employee/s to input the specific rest days he/she/they have given the amount of rest days they have
int
restDays(int startDay, int endDay)
{
	int restDate,i,month,day;
	char proceed;
	do
	{
		printf("\n   ------------------	------------------\n");
		printf("   |     Months     |   |      Days      |  \n");
		printf("   ------------------	------------------\n");
		printf("   | 01 - January   |   |    01 - 31     |\n");
		printf("   | 02 - February  |   |    01 - 28     |\n");
		printf("   | 03 - March     |   |    01 - 31     |\n");
		printf("   | 04 - April     |   |    01 - 30     |\n");
		printf("   | 05 - May       |   |    01 - 31     |\n");
		printf("   | 06 - June      |   |    01 - 30     |\n");
		printf("   | 07 - July      |   |    01 - 31     |\n");
		printf("   | 08 - August    |   |    01 - 31     |\n");
		printf("   | 09 - September |   |    01 - 30     |\n");
		printf("   | 10 - October   |   |    01 - 31     |\n");
		printf("   | 11 - November  |   |    01 - 30     |\n");
		printf("   | 12 - December  |   |    01 - 31     |\n");
		printf("   ------------------   ------------------\n");
		printf("\n   Enter rest day within time period");
		printf("\n   Month : ");
		scanf("%d", &month);
		printf("\n   Day : ");
		scanf("%d", &day);
		restDate=daysChecker(month,day);
		if(restDate>=startDay&&restDate<=endDay)
		{
			printf("\n   You have entered a valid rest date. Nice!");
			i=0;
		}
		else
		{
			printf("\n   You have entered an invalid rest date.\n");
			printf("\n   Please type 'a' to enter another rest date! : ");
			scanf(" %c", &proceed);
			system("cls");
			i++;
		}
	}while(i!=0);
	printf("\n   Please type 'a' to proceed! : ");
	scanf(" %c", &proceed);
	system("cls");
	return restDate;
}


// Function that computes for the actual rate of the employee given the current day they are inputting shift times for 
float 
aRate(int i, int restDate1, int restDate2, int restDate3, int restDate4, int restDate5, int restDate6, int restDate7, int restDate8, int restDate9, int restDate10, float hourlyRate)
{
	float actualRate=0;
		if((i==1 || i==99 || i==104 || i==105 || i==121 || i==123 || i==163 || i==190 || i==241 || i==334 || i==359 || i==364)&&(i==restDate1 || i==restDate2 || i==restDate3 || i==restDate4 || i==restDate5 || i==restDate6 || i==restDate7 || i==restDate8 || i==restDate9 || i==restDate10))
		{// regular holiday && rest day
			printf("\n    -------------------------------------------------------------------");
			printf("\n      Current shift is on a Regular Holiday that is also your Rest Day.");
			printf("\n      We are on Day %d.", i);
			actualRate=hourlyRate*2.6;
			printf("\n      Actual rate for this shift is Php %.2f.", actualRate);
			printf("\n    -------------------------------------------------------------------\n");
		}
		else if((i==32 || i==56 || i==106 || i==129 || i==233 || i==305 || i==306 || i==342 || i==358 || i==365)&&(i==restDate1 || i==restDate2 || i==restDate3 || i==restDate4 || i==restDate5 || i==restDate6 || i==restDate7 || i==restDate8 || i==restDate9 || i==restDate10))
		{// special day && rest day
			printf("\n    ----------------------------------------------------------------");
			printf("\n      Current shift is on a Special Day that is also your Rest Day.");
			printf("\n      We are on Day %d.", i);
			actualRate=hourlyRate*1.5;
			printf("\n      Actual rate for this shift is Php %.2f.", actualRate);
			printf("\n    ----------------------------------------------------------------\n");
		}
		else if(i==1 || i==99 || i==104 || i==105 || i==121 || i==123 || i==163 || i==190 || i==241 || i==334 || i==359 || i==364)
		{// regular holiday
			printf("\n    ----------------------------------------------");
			printf("\n      Current shift is on a Regular Holiday only.");
			printf("\n      We are on Day %d.", i);
			actualRate=hourlyRate*2;
			printf("\n      Actual rate for this shift is Php %.2f.", actualRate);
			printf("\n    ----------------------------------------------\n");
		}
		else if(i==32 || i==56 || i==106 || i==129 || i==233 || i==305 || i==306 || i==342 || i==358 || i==365)
		{// special day
			printf("\n    ----------------------------------------------");
			printf("\n      Current shift is on a Special Day.");
			printf("\n      We are on Day %d.", i);
			actualRate=hourlyRate*1.3;
			printf("\n      Actual rate for this shift is Php %.2f. ", actualRate);
			printf("\n    ----------------------------------------------\n");
		}
		else if(i==restDate1 || i==restDate2 || i==restDate3 || i==restDate4 || i==restDate5 || i==restDate6 || i==restDate7 || i==restDate8 || i==restDate9 || i==restDate10)
		{// rest day
			printf("\n    ----------------------------------------------");
			printf("\n      Current shift is on a Rest Day.");
			printf("\n      We are on Day %d.", i);
			actualRate=hourlyRate*1.3;
			printf("\n      Actual rate for this shift is Php %.2f.", actualRate);
			printf("\n    ----------------------------------------------\n");
		}
		else
		{// regular working day
			printf("\n    ----------------------------------------------");
			printf("\n      Current shift is on a Regular Day.");
			printf("\n      We are on Day %d.", i);
			actualRate=hourlyRate*1;
			printf("\n      Actual rate for this shift is Php %.2f.", actualRate);
			printf("\n    ----------------------------------------------\n");
		}
	return actualRate;
}


// Function that takes into account rest days, special days, and holidays. And returns their respective multipliers on the employee's hourly rate
float
nightDifferentialMultiplier(int i,int restDate1, int restDate2, int restDate3, int restDate4, int restDate5, int restDate6, int restDate7, int restDate8, int restDate9, int restDate10)
{
	float multiplier;
	// holiday
	if(i==1 || i==99 || i==104 || i==105 || i==121 || i==123 || i==163 || i==190 || i==241 || i==334 || i==359 || i==364)
		{
			multiplier=1.2;
		}
	// special day / rest day
	else if(i==32 || i==56 || i==106 || i==129 || i==233 || i==305 || i==306 || i==342 || i==358 || i==365 || i==restDate1 || i==restDate2 || i==restDate3 || i==restDate4 || i==restDate5 || i==restDate6 || i==restDate7 || i==restDate8 || i==restDate9 || i==restDate10)
		{
			multiplier=0.43;
		}
	// regular day
	else
		{
			multiplier=0.1;
		}
	return multiplier;
}


// Function that checks if there are hours worked eligible for a night differential pay within the shift if the time in is less than time out 
float
nightDifferential(int time, int i, float rate, int restDate1, int restDate2, int restDate3, int restDate4, int restDate5, int restDate6, int restDate7, int restDate8, int restDate9, int restDate10)
{
	int hoursDifferential;
	float differentialPay, multiplier;
	multiplier=nightDifferentialMultiplier(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
	if(time>1320)
	{
		printf("\n   There is a Night Differential pay within the current shift.");
		hoursDifferential=time-1320;
		printf("\n   Minutes eligible for Night Differential pay = %d", hoursDifferential);
		differentialPay=hoursDifferential*(rate*multiplier); 
		printf("\n   Night Differential pay = Php %.2f", differentialPay);
		return differentialPay;
	}	
	else
	{
		printf("\n   There is no Night Differential pay within the current shift.");
		return 0;
	}
}


// Function that checks if day 'i' is a holiday, if so it will add the corresponding salary for the employee's hours not worked
float
holidayChecker(int i, float hourlyRate, float minutesNotWorked)
{
	float salaryForHoliday;
	if(i==1 || i==99 || i==104 || i==105 || i==121 || i==123 || i==163 || i==190 || i==241 || i==334 || i==359 || i==364)
		{	
			salaryForHoliday=(hourlyRate/60)*minutesNotWorked;
			printf("\n   Since it is Day %d. It is a holiday. You will still receive your regular salary for hours not worked.", i);
		}
	else
			salaryForHoliday=0;
	return salaryForHoliday;
}


// Function that computes for the salary given all the conditions (MAIN CHUNK OF THE PROGRAM)
float
computeTotalSalaryForShifts(int x, int y, float hourlyRate, int restDate1, int restDate2, int restDate3, int restDate4, int restDate5, int restDate6, int restDate7, int restDate8, int restDate9, int restDate10)
{
	int i,in,out,minutesWorkedForDayRemaining,minutesIn,minutesOut,minutesWorked,minutesNotWorked,excessMinutes;
	float actualRate,minuteRate,excessSalaryGiven,salaryForShift=0,totalSalary=0,salaryForDayRemaining=0,differentialPay=0,nightDifferentialForDayRemaining=0,salaryForMinutesNotWorked=0,salaryForNextDay=0,multiplier;
	char proceed;
	
	for(i=x; i<=y; i++)
	{
		actualRate = aRate(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10,hourlyRate);
		printf("\n   Input Time In for day %d (in military time): ", i);
		scanf("%d", &in);
		printf("   Input Time Out for day %d (in military time): ", i);	
		scanf("%d", &out);
		minuteRate=actualRate/60;
		minutesIn=((in/100)*60)+(in%100);
		minutesOut=((out/100)*60)+(out%100);
		minutesWorked=minutesOut-minutesIn;
		
		if((in>=0&&!(in%100>59))&&(out>=0&&!(out%100>59)))
		{
			if(in<out)
			{
				//employee works overtime
				if(minutesWorked>480)
				{
					differentialPay=nightDifferential(minutesOut,i,hourlyRate/60,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
					excessMinutes=minutesWorked-480;
					
					printf("\n   Employee has worked overtime. We're proud of you!");
					/*v checker v*/
					printf("\n   Excess minutes of work = %d", excessMinutes);
					/*^ checker ^*/
					excessSalaryGiven=excessMinutes*(minuteRate*0.25);
					/*v checker v*/
					printf("\n   Excess Salary for your hard work! = Php %.2f\n", excessSalaryGiven);
					/*^ checker ^*/
					salaryForShift=(minutesWorked*minuteRate)+excessSalaryGiven+differentialPay;
					printf("\n   Total Salary for shift = Php %.2f\n", salaryForShift);
					printf("\n   Please type 'a' to proceed! : ");
					scanf(" %c", &proceed);
					system("cls");
				}
				//employee works undertime
				else if(minutesWorked<480&&minutesWorked>0) 
				{
					//if holiday
					minutesNotWorked=480-minutesWorked;
					salaryForMinutesNotWorked=holidayChecker(i,hourlyRate,minutesNotWorked);
					printf("\n   Salary for hours not worked = Php %.2f\n", salaryForMinutesNotWorked);
						
					//if night differential
					differentialPay=nightDifferential(minutesOut,i,hourlyRate/60,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
					
					printf("\n   Employee has worked undertime.");
					printf("\n   There is no excess for this shift.\n");
					salaryForShift=minutesWorked*minuteRate+differentialPay+salaryForMinutesNotWorked;
					printf("\n   Total Salary for shift = Php %.2f\n", salaryForShift);
					printf("\n   Please type 'a' to proceed! : ");
					scanf(" %c", &proceed);
					system("cls");
					
				}
				//employee works exactly 8 hours
				else
				{
					differentialPay=nightDifferential(minutesOut,i,hourlyRate/60,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
					printf("\n   Employee has worked 8 hours. Nice!\n");
					salaryForShift=minutesWorked*minuteRate+differentialPay;
					printf("\n   Total Salary for shift = Php %.2f\n", salaryForShift);
					printf("\n   Please type 'a' to proceed! : ");
					scanf(" %c", &proceed);
					system("cls");	
				}
			}
			//employee does not work 
			else if(in==out)
			{
				printf("\n   You did not work today.\n");
				// check if day is holiday
				salaryForShift=holidayChecker(i,hourlyRate,480);
				printf("\n   Total Salary for shift = Php %.2f\n", salaryForShift);
				printf("\n   Please type 'a' to proceed! : ");
				scanf(" %c", &proceed);
				system("cls");
			}
			else // (out<in) 
			{
				salaryForDayRemaining=0;
				nightDifferentialForDayRemaining=0;
				minutesWorked = ((minutesOut+1440)-minutesIn);
				
				//employee works overtime
				if(minutesWorked>480)
				{
					printf("\n   You have worked overtime.\n");
					excessMinutes=minutesWorked-480;
					
					/*v checker v*/
					//printf("\n   excess hours = %.2f", excessHours);
					/*^ checker ^*/
					
					excessSalaryGiven=excessMinutes*(minuteRate*0.25);
					
					/*v checker v*/
					//printf("\n   excess salary = %.2f", excessSalaryGiven);
					/*^ checker ^*/
					
				}
				//employee works undertime
				else if(minutesWorked<480&&minutesWorked>0)
				{	
					printf("\n   Employee has worked undertime.");
					printf("\n   No excess for this shift.\n");
					excessSalaryGiven=0;
				}
				//employee works exactly 8 hours
				else
				{
					printf("\n   Employee has worked 8 hours. Nice!\n");
					excessSalaryGiven=0;
				}
				// takes into account salary for remaining day  
				minutesWorkedForDayRemaining=1440-minutesIn;
				printf("\n   Minutes for day remaining = %d\n", minutesWorkedForDayRemaining);
				if(minutesWorkedForDayRemaining>120)
				{
					printf("\n   Wow, you worked in the night shift.\n");
					salaryForDayRemaining=(minutesWorkedForDayRemaining-120)*minuteRate;
					
					/*v checker v*/
					//printf("\n   Salary for day remaining = Php %.2f.\n", salaryForDayRemaining);
					/*^ checker ^*/
					
					multiplier=nightDifferentialMultiplier(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
					nightDifferentialForDayRemaining=120*((hourlyRate/60)*multiplier);
					
					/*v checker v*/
					//printf("\n   Night Differential For Day Remaining %.2f.", nightDifferentialForDayRemaining);
					/*^ checker ^*/
					
					salaryForDayRemaining+=nightDifferentialForDayRemaining;
					
					/*v checker v*/
					//printf("\n   Salary for day remaining with night differential %.2f.", salaryForDayRemaining);
					/*^ checker ^*/
				}
				else
				{
					printf("\n   Wow, you worked in the night shift!\n");
					multiplier=nightDifferentialMultiplier(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
					nightDifferentialForDayRemaining=minutesWorkedForDayRemaining*((hourlyRate/60)*multiplier);
					
					/*v checker v*/
					//printf("\n   Night Differential For Day Remaining %.2f.", nightDifferentialForDayRemaining);
					/*^ checker ^*/
					
					salaryForDayRemaining+=nightDifferentialForDayRemaining;
					
					/*v checker v*/
					//printf("\n   Salary for day remaining with night differential %.2f.", salaryForDayRemaining);
					/*^ checker ^*/
			}
			//after getting the salary remaining for the day during a night shift, this program gets the salary for the next day as well
			salaryForDayRemaining+=minutesWorkedForDayRemaining*minuteRate;
			printf("\n   Salary for day remaining = Php %.2f\n",salaryForDayRemaining);
			i++;   
			printf("\n   You have worked on the next day, Day %d in this shift.\n", i);
			actualRate=aRate(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10,hourlyRate);
			
			/*v checker v*/
			//printf("\n   The actual rate for this shift will be = Php %.2f.\n", actualRate);
			/*^ checker ^*/
			
			//if statement that checks if salary for next day will include hours not in the night shift
			if(minutesOut>=360)
			{
				multiplier=nightDifferentialMultiplier(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
				differentialPay=360*((hourlyRate/60)*multiplier);
				printf("\n   Night Differential pay = Php %.2f\n", differentialPay);
				salaryForNextDay=(minutesOut*minuteRate)+differentialPay;
				printf("\n   Salary for the next day = Php %.2f\n", salaryForNextDay);
			}
			else
			{
				multiplier=nightDifferentialMultiplier(i,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);/////////////////////////////
				differentialPay=minutesOut*((hourlyRate/60)*multiplier);
				salaryForNextDay=(minutesOut*minuteRate)+differentialPay;
			}
			
			//decrement day for the next shift employee has to input times for
			i--;
			
			salaryForShift=salaryForDayRemaining+salaryForNextDay+excessSalaryGiven;
			printf("\n   Total Salary for current shift = Php %.2f\n", salaryForShift);
			printf("\n   Please type 'a' to proceed! : ");
			scanf(" %c", &proceed);
			system("cls");
			
			/*v checker v*/
//			printf("\n   %d",i);
			/*^ checker ^*/
			
			}	
		}
		else
		{
			printf("\n   Atleast one of the times inputted not valid.\n");
			i--;
			printf("\n   Please type 'a' to input another set of times : ");
			scanf(" %c", &proceed);
			system("cls");
		}
			
		totalSalary+=salaryForShift;
	}
	printf("\n  ------------------------------------------------------");
	printf("\n   The Total Salary for Current Employee = Php %.2f", totalSalary);
	printf("\n  ------------------------------------------------------");
	return 0;
}


//	Main Function where the SKELETON of the program is
int
main()
{
	int startDay,endDay,numSalaries,i,numRestDays,j=1;
	// variable declaration for rest days
	int restDate1=0,restDate2=0,restDate3=0,restDate4=0,restDate5=0,restDate6=0,restDate7=0,restDate8=0,restDate9=0,restDate10=0;
	float hourlyRate;
	char proceed;
	
	//ask for time period 
	do
	{
		startDay = timePeriodStart();
		endDay = timePeriodEnd();
		if(endDay<startDay)
		{
			printf("\n   Sorry, you have inputted an invalid Time Period.\n");
			printf("\n   Please type 'a' to input different Time Period : ");
			scanf(" %c", &proceed);
		}
	}while(endDay<startDay);
	
	printf("\n  ----------------------------------------------------------------------------");
	printf("\n  |    The Time Period for Salary computation Starts at Day %3d of 2022      |", startDay);
	printf("\n  |                                                                          |");
	printf("\n  |    The Time Period for Salary computation Ends at Day   %3d of 2022      |", endDay);
	printf("\n  ----------------------------------------------------------------------------\n");

	//ask for how many salaries to be computed
	numSalaries = numberOfSalaries();
	/*for the number of salaries to be computed, repeat the main chunk of the program 
	until all users have been able to input*/
	for(i=0; i<numSalaries;i++)
	{
		hourlyRate = hourlySalaryRate(i);
		//ask for rest days in time period
		numRestDays=numRestDay();
		if(numRestDays==0)
			printf("\n   This is to acknowledge that the current employee has no rest days.");
		else if(numRestDays>10)
			{
				do
				{
					printf("\n   Invalid number of Rest Days.\n");
					printf("\n   Please enter a number of Rest Days not exceeding 10.\n");
					printf("\n   Please type 'a' to proceed! : ");
					scanf(" %c", &proceed);
					numRestDays=numRestDay();
				}while(numRestDays>10);
			}
		while(j<=numRestDays)
		{
			switch(j)
			{
				//store rest day date in variable, according to how many the current user has
				case 1:restDate1=restDays(startDay,endDay);break;
				case 2:restDate2=restDays(startDay,endDay);break;
				case 3:restDate3=restDays(startDay,endDay);break;
				case 4:restDate4=restDays(startDay,endDay);break;
				case 5:restDate5=restDays(startDay,endDay);break;
				case 6:restDate6=restDays(startDay,endDay);break;
				case 7:restDate7=restDays(startDay,endDay);break;
				case 8:restDate8=restDays(startDay,endDay);break;
				case 9:restDate9=restDays(startDay,endDay);break;
				case 10:restDate10=restDays(startDay,endDay);break;//add reset counter for rest days
			}
			j++;
		}
		
		/*v checker v*/
	  /*printf("\n   restDate1 = %d", restDate1);
		printf("\n   restDate2 = %d", restDate2);
		printf("\n   restDate3 = %d", restDate3);
		printf("\n   restDate4 = %d", restDate4);
		printf("\n   restDate5 = %d", restDate5);
		printf("\n   restDate6 = %d", restDate6);
		printf("\n   restDate7 = %d", restDate7);
		printf("\n   restDate8 = %d", restDate8);
		printf("\n   restDate9 = %d", restDate9);
		printf("\n   restDate10 = %d", restDate10);*/
		/*^ checker ^*/
		
		//computes the salary of the employee according to certain conditions
		computeTotalSalaryForShifts(startDay,endDay,hourlyRate,restDate1,restDate2,restDate3,restDate4,restDate5,restDate6,restDate7,restDate8,restDate9,restDate10);
		j=0;
	}
	//return statement
	return 0;
}
