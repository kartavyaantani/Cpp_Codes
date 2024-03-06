//make a class with single variable and two objects of this class
//find which class is bigger
//find the sum of both class (use friend func for overloading)
#include <iostream.h>

	class sample
	{
		private :

			int x;
		public:
			void read (void)
			{
				cout << "Enter value : " ;
				cin >> x;
			}

			int operator > (sample s)
			{
				if (x > s.x)

					return 1;
				else
					return 0;
			}

			friend void addobj(sample s1, sample s2);
};

void addobj(sample s1, sample s2)
{
   int sum;
   sum = s1.x + s2.x;
   cout << "\nSum = " << sum;
   return;
}
main()
{
	sample o1,o2;

	o1.read();
	o2.read();

	if(o1 > o2)

		cout << "\nFirst object is bigger";

	else
		cout << "\nSecond object is bigger";

	addobj(o1,o2);
}