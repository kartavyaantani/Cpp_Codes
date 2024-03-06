//Make anarray in class and sort in ascending or descending as per user's choice
#include <iostream.h>
#include <conio.h>
	class sort
	{
		private:
		int a[10];

		public:
		void read(void) ;
		void sortA(void);
		void sortD(void);
		void display(void);

};
void sort::read (void)
{
			int i;
			cout << "\nEnter numbers : \n" ;

			for (i=0 ; i < 10 ; i++)
			{
				cout << "\nEnter data : " ;
				cin >> a[i];
			}

}
	void sort::sortA (void)
		{
			int x,y,tmp;

			for(x=1 ; x <= 10 ; x++)
			{
				for(y = 0 ; y < 9 ; y++)
				{
				       if(a[y] > a[y+1])
				       {
						tmp = a[y];
						a[y] = a[y+1];
						a[y+1] = tmp;
					}


				}
			}
		}

		void sort::sortD (void)
		{
		      int x,y,tmp;

		      for(x=1 ; x <= 10 ; x++)
		      {
			       for(y = 0 ; y < 9 ; y++)
			       {

					if (a[y] < a[y+1])
					{
							tmp = a[y];
							a[y] = a[y+1];
							a[y+1] = tmp;
					}


				}
			}
		}

		void sort::display (void)
		{
			int i;

			for(i = 0 ; i < 10 ; i++)
			{
				cout << "\nSorted Data = " << a[i];
			}
		}

main()
{
	sort obj;
	int x;

	clrscr();

	obj.read();

	cout << "Enter 1 to sort in ascending ";
	cout << "\nEnter 2 to sort in descending";
	cout << "\nEnter Choice : " ;
	cin >> x;

	if (x == 1)
		obj.sortA();
	else if (x == 2)
		obj.sortD();
	obj.display();
	getch();


}


