#include <iostream.h>
#include <conio.h>
class club
{
	private:
	int men,women;
	public:
		club ()
		{
			men = 5;
			women = 5;
			cout << "\ndefault constructor called";
		}
		club(int x,int y)
		{
			men = x;
			women = y;
			cout << "\n Parameterized constructor called";
		}
		club(club &c)
		{
			//copy constructor//
			men = c.men;
			women = c.women;
			cout << "\nCopy constructor called";
		}
		~club()
		{
			cout << "\nDestructor called";
		}

		void display (void)
		{
			cout << "\nTotal men = " << men;
			cout << "\nTotal women = " << women;
		}

		club operator ++()
		{
			club c;
			c.men = ++men;
			c.women = ++women;
			cout << "\nPre increment unary";
			return c;

		}

		club operator ++(int)
		{
			club c;
			c.men = men++;
			c.women = women++;
			cout << "\nPost increment binary";
			return c;
		}

		club operator +(club c)
		{
			club tmp;
			tmp.men = men + c.men;
			tmp.women = women + c.women;
			cout << "\nBinary add";
			return tmp;
		}

		club operator -(club c)
		{
			club tmp;
			tmp.men = men - c.men;
			tmp.women = women - c.women;
			cout << "\nBinary subtract";
			return tmp;
		}

		int operator >(club c)
		{
			cout << "\nOverloaded > called";
			if((men > c.men) && (women > c.women))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

};
main()
{
	clrscr();
	club c1,c2(10,10),c3(15,15),c4(c3);


	c1.display();
	c2.display();
	c3.display();
	c4.display();

	c4 = c1++;
	c4.display();

	c1++;
	c1.display();

	c3 = c2 + c1;
	c3.display();

	c4 = c2 - c1;
	c4.display();

	if ( c1 > c2)
	{
		cout << "\nC1 is Bigger";
	}
	else
	{
		cout << "\nC2 is Bigger";
	}
}






