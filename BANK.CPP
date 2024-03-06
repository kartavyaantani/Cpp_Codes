#include <iostream.h>
#include <conio.h>
#include <process.h>
int exist(int n);
int findac(int n);
int totac = -1,ch,tmpacno,pos,amt;
	class bank
	{
		int acno,balance;
		char name[15];

		public:

			void newac (void)
			{
			   cout << "\n\nEnter account number : " ;
			   cin  >> tmpacno;

			   if (exist(tmpacno))
			   {
			    cout << "\nDuplicate account no ";
			    totac--;
			    acno = 0 ;
			    getch();
			    return;
			   }
			   acno = tmpacno ;

			   cout << "\nEnter name : ";
			   cin  >> name;

			   cout << "\nEnter balance : ";
			   cin  >> balance;

			}

			void disp (void)
			{
			   cout << "\n\nAccount number : " << acno;
			   cout << "\nName : " << name;
			   cout << "\nAccount balance : " << balance;
			}

			void deposit(int r)
			{
				balance += r;
				disp();
			}

			void withdraw(int r)
			{
				if (balance - r < 100)
				{
					cout << "\nNot sufficient balance";
					getch();
				}
				else
				{
					balance -= r;
				}
				disp();
			}

			int sayacno (void)
			{
				return acno;
			}

	};



	bank b[5];

main()
{	clrscr();
	while(1)
	{
		cout << "\n1.Open Account";
		cout << "\n2.Deposit";
		cout << "\n3.Withdraw";
		cout << "\n4.Balance Inquiry";
		cout << "\n5.Exit";
		cout << "\nEnter choice : ";
		cin >> ch;

		switch (ch)
		{
			case 1 : if(totac == 4)
				{
					cout << "\nUnable to open new account";
					break;
				}
				totac++;
				b[totac].newac();
				break;
			case 2 : cout << "\nEnter Account no. : ";
				cin >> tmpacno;
				pos = findac(tmpacno);
				if(pos == -1)
				{
					cout << "\nInvalid Account number ";
					getch();
					break;
				}
				cout << "\nEnter deposit amount : ";
				cin  >> amt;
				b[pos].deposit(amt);
				break;

			case 3 : cout << "\nEnter Account no. : ";
				cin >> tmpacno;
				pos = findac(tmpacno);
				if(pos == -1)
				{
					cout << "\nInvalid Account number ";
					getch();
					break;
				}
				cout << "\nEnter withdraw amount : ";
				cin  >> amt;
				b[pos].withdraw(amt);
				break;


			case 4 : cout << "\nEnter Account no. : ";
				cin >> tmpacno;
				pos = findac(tmpacno);
				if(pos == -1)
				{
					cout << "\nInvalid Account number ";
					getch();
					break;
				}
				b[pos].disp();
				break;

			case 5 : exit(0);

			default : cout << "\n\n Invalid choice";
					break;

		}
	}
}

int exist (int n)
{
	int i;
	if(totac == 0)
	{
		return (0);
	}


	for(i = 0 ; i <= totac ; i++)
	{
	     if(n == b[i].sayacno())
	     {
		return (1);
	     }
	}

	return (0);
}
int findac (int n)
{
	int i;

	for(i = 0 ; i <= totac ; i++)
	{
		if(n == b[i].sayacno())
		{
			return i;
		}
	}
	return -1;
}

