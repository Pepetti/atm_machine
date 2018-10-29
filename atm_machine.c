#include <stdio.h>
#include <stdlib.h>

int choice, k;

char transaction ='y';

void cashLogic(unsigned long amount, unsigned long withdraw){
	int cash20 = 0, cash50 = 0;
	int withdrawAmount = withdraw;
	
	if (withdrawAmount >= 50){
		cash50 = withdrawAmount / 50;
		withdrawAmount -= (50 * cash50);

	}
	if (withdrawAmount >= 20){
		cash20 = withdrawAmount / 20;
		withdrawAmount -= (20 * cash20);	
	}
	int tempWithdrawAmount = 20 * cash20 + 50 * cash50;

	printf("You'll get %d 50 bills and %d 20 bills", cash50, cash20);
}
		
void printMenu() {
	printf("\n");
	printf("********Welcome to ATM Service**************\n");
	printf("1. Check Balance\n");
	printf("2. Withdraw Cash\n");
	printf("3. Deposit Cash\n");
	printf("4. Quit\n");
	printf("***********************************************\n\n");
	printf("Enter your choice: ");
}

int pinCheck(){
	char var[10];
	int pin;

	FILE *fp = fopen("pin.txt", "r");
	fgets(var, sizeof(var), fp);
	int pinVar = atoi(var);

	while (pin != pinVar ){
		printf("ENTER YOUR SECRET PIN NUMBER:");
		scanf("%d", &pin);
		if (pin != pinVar)
		printf("PLEASE ENTER VALID PASSWORD\n");
	}
	return pin;
}

void main(){
	unsigned long amount=1000, deposit, withdraw;

	pinCheck();
	do{
		printMenu();
		scanf("%d", &choice);

		switch (choice){

		case 1:
			printf("\n YOUR BALANCE IN Rs : %lu ", amount);
			break;

		case 2:
			printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
			scanf("%lu", &withdraw);
			if (withdraw > amount){
                printf("NOT ENOUGH MONEY");
            }
			else if (withdraw >= 40 && withdraw % 10 != 0){
                printf("Please withdraw 20 or 50 euros");
            }
            else if (withdraw < 40 && withdraw != 20){
                    printf("Please withdraw 20 or 50 euros");
            }
            else if (withdraw > 1000){
                "Too big withdraw amount (max 1000e/withdraw)";
            }
            else{
				amount = amount - withdraw;
				cashLogic(amount, withdraw);
				printf("\n\n PLEASE COLLECT CASH");
				printf("\n YOUR CURRENT BALANCE IS%lu", amount);
			}			
            break;

		case 3:
			printf("\n ENTER THE AMOUNT TO DEPOSIT");
			scanf("%lu", &deposit);
			amount = amount + deposit;
			printf("YOUR BALANCE IS %lu", amount);
			break;

		case 4:
			printf("\n THANK U USING ATM");
			break;
		
		default:
			printf("\n INVALID CHOICE");
		}

		printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
		fflush(stdin);
		scanf("%c", &transaction);
		if (transaction == 'n'|| transaction == 'N')
                    k = 1;
	} while (!k);
	printf("\n\n THANKS FOR USING OUT ATM SERVICE");
}

