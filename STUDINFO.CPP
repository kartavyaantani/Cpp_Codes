#include <iostream.h>
#include <string.h>
main()
{
	class stud
	{       private:
		int seatno,m1,m2,total;
		char name[15],res[5];
		float per;

		public:
		void read (void)
		{
			cout << "\n\nEnter seat no : " ;
			cin >> seatno;

			cout << "\nEnter name : ";
			cin >> name;

			cout << "\nEnter mark1: ";
			cin >> m1;

			cout << "\nEnter mark2: ";
			cin >> m2;
		}

		void process (void)
		{
			total = m1 + m2;
			per = total/2;

			if( per > 40)
			{
				strcpy(res,"Pass");
			}
			else
			{
				strcpy(res,"Fail");
			}
		}

		void write (void)
		{
			cout << "\nSeat no = " << seatno;
			cout << "\nName    = " << name;
			cout << "\nmark 1  = " << m1;
			cout << "\nmark 2  = " << m2;
			cout << "\nTotal   = " << total;
			cout << "\nPercent = " << per;
			cout << "\nResult  = " << res;
		}
	};


	stud s1,s2;
	s1.read();
	s2.read();
	s1.process();
	s2.process();
	s1.write();
	s2.write();
}
