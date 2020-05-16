#include<iostream>                 
#include<conio.h>                  
#include<fstream>
using namespace std;

class allocation
{
	int Press, seat, number, i, j, a;
	char name[30];
   public:
	void bookingseat();
   	void seatavailable();
};

void allocation::bookingseat()
{  
	int num, b=0, c=0;
   	ofstream outf("allocation.txt", ios::app);
	cout << "How many seat you want to book";
	outf << "\nHow many seat you want to book";
	cin >> seat;
    	outf << " " << seat;
	outf << "Enter the seat number you wish to book";
	
	for (i=1; i<=seat; i++)
	{
	        cout << "Enter the seat" << i << " number you wish to book";
	        cin >> a;
	        outf << "\nEnter the seat" << i << " number you wish to book";
	        outf << " " << a;
	}
	
	cout << "From which name you wish to book";
	outf << "\nFrom which name you wish to book";
	cin >> name;
	outf << " " << name;
	cout << "Congratulation your seat are booked.";
	outf.close();
   }
  
int b = 100;

void allocation::seatavailable()
{
	ofstream outf;
	outf.open("allocation.txt", ios::app);
	int m, n, u=0;
	n = u+seat;
	m = b-n;
	cout << "Seat are available :" << m;
	outf << "\n Seat are available :" << m;
	a = n;
	b = m;
	outf.close();
}

class SEAT
{
	int row, col;
	int total_seats, a, b, r[2], c[2];
	public:
		SEAT()                   
		{
		    row = 10;
		    col = 10;
    	}
		void book()      
		{			
			char s[11][11];
			for (int i=1; i<=row; i++)
				for (int j=1; j<=col; j++)
						s[i][j] = '*';
			cout << "* MEANS EMPTY SEATS \t\t B MEANS BOOKED SEATS" << endl;
		    cout << "\t\t\t\tSEATS:100" << endl;
			cout << "\n\n\t\t";
			for (int i=1; i<=col; i++)
			{
				cout << "Col" << i << " ";
			}
			cout << endl;
			for (int i=1; i<=row; i++)
			{
				cout << "\tRow" << i << "\t";
				for (int j=1; j<=col; j++)
				{
					cout << " " << s[i][j] << "   ";
				}
			    cout << endl << endl;
			}
			cout << endl;
			cout << "How many seats you want to book?"<<endl;
			cin >> total_seats;
			for (int i=1; i<=total_seats; i++)
			{
				cout << endl << "book your seat: " << endl;
				cout << "ROW: ";
				cin >> r[i];
				a = r[i];
				cout << "COLUMN: ";
				cin >> c[i];
		    		b = c[i];
				s[a][b] = 'B';
				for (int j=1; j<i; j++)
				{
					if ((r[j]==r[i]) && (c[j]==c[i]))
					{
						cout << "\nSorry, You have to enter another seat. This seat is already booked. " << endl;
				    	total_seats += 1;
					}
				}
			}	
			cout << endl << "TOTAL COST FOR BOOKING SEAT:\tRs." << total_seats*50 << endl;          //total cost
			cout << "\nBooked Seats: " << endl;
			cout << "\t\t\  REMAINING SEATS:" << endl;
			cout << "\n\n\t\t";

			for (int i=1; i<=col; i++)
			{
				cout << "Col" << i << " ";
			}
			cout << endl;
			for (int i=1; i<=row; i++)
			{
				cout << "\tRow" << i << "\t";
				for (int j=1; j<=col; j++)
				{
					cout << " " << s[i][j] << "   ";
				}
			    cout << endl << endl;
			}
		}		
};
int main()
{
	SEAT c;
	char select;
	cout << "\tSEAT ALLOCATION PROGRAM OF AUDITORIUM" << endl;
	cout << "\t\tPER SEAT RATE: Rs50" << endl;
	do
	{
		c.book();
		cout << "Do you wish to booking seat again(Y/N):\t";
		cin >> select;
    	}
    	while (select=='Y'||select=='y');
	getch();
}
