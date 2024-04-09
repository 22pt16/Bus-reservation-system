#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<conio.h>

using namespace std;

class calendar
{
public:
        int year,month,day;
        int n;//CHECKING WEEKEND//
        calendar()
        {
                cout<<" \nEnter the year of journey to view calendar\n:(20xx)\n";
                cin>>year;
                 while(year!=2023)
                {
                    cout<<"\nEnter an valid year\n";
                    cin>>year;
                }
                cout << "Enter a month of journey to view calendar\n:(Month(1 -12)\n:";
                cin >> month;


                if( month>9 || year>2023 )
                {
                        cout<<"Sorry! No buses scheduled yet.\nTRY WITH A DIFFRENT DATE\n";
                        exit(0);
                }
        }
//---------------------------------------------------
        int dayNumber(int day,int month, int year)
        {
        //      int n;
                static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
                year -= month < 3;
                n=( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;

                return n;
        }


   string getMonthName(int monthNumber)
        {
                string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
                return (months[monthNumber]);
        }
  int numberOfDays (int monthNumber, int year)
        {
                switch(monthNumber)
                {
                        case 0 :
                        case 2 :
                        case 4 :
                        case 6 :
                        case 7 :
                        case 9 :
                        case 11: return(31);
                                break;
                        case 1 :
                                if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0))
                                        return (29);
                                else
                                        return (28);
                                 break;
                        case 3 :
                        case 5 :
                        case 8 :
                        case 10 : return(30);
                                break;
                }
        }

        void print(int year)
        {
           ("cls");
                cout<<"\t\t\t Calendar - Year "<<year;
                int days;
                int current = dayNumber (1, month, year);
                      days = numberOfDays (month-1,year);
                      cout<<endl<<"\t\t ----X----"<<getMonthName (month-1).c_str()<<"----X---- \t\t"<<endl;
                      cout<<"\t Sun\tMon\tTue\tWed\tThu\tFri\tSat \n";
                      int k;
                      for (k = 0; k < current; k++)
                         cout<<"\t";
                      for (int j = 1; j <= days; j++)
                      {
                                cout<<"\t "<<j;
                                if (++k > 6)
                                {
                                    k = 0;
                                    cout<<endl;
                                 }
                      }

                      if (k)
                      {
                         cout<<endl;
                         current = k;
                      }

                cout<<"\nEnter the date of journey (dd)\n";
                cin>>day;
            while(day<1 || day>days)
            {
                cout<<"Enter a valid date from calendar\n";
                cin>>day;
            }
        }
//------------------------------------------
        void weekend(int n)
        {
                if(n==0 || n==6)
                        cout<<"weekend\n";
                else
                        cout<<"weekday\n";
        }
};
/**************************************************************************/
class bus //: public calendar
{
public:
        string bus_no;
        int seats,rating, seat_no[30] ,ac,s_no/*1 or 0*/;       //rating 1 to 5 stars// //total 30 seats//
        float fare1,fare2,fare3;//window,rear,sleeper
        char pick[30],drop[30],stype[10];
        char bus_name[30],driver[30];
        int time[2];

        bus()
        {//CALLED BY DESTINATION
                cout<<"\nEnter the type of bus you wish to book from the list\n";
                //--------------FILTERS---------------
                cout<<"TOTAL SEATS:30\t\t-----------------SEATING ARRANGEMENT------------\n";
                for(int i=1;i<=30;i++)
                        seat_no[i-1]=i;

                cout<<"WINDOW SEAT:\t";
                for(int i=10;i>=1;i--)
                        cout<<"<"<<i<<">\t";

                cout<<"\nREAR SEAT:\t";
                for(int i=20;i>=11;i--)
                        cout<<"<"<<i<<">\t";

                cout<<endl<<"\nSLEEPER:\t";
                for(int i=30;i>=21;i--)
                        cout<<"<"<<i<<">\t";

                cout<<"|(o)| DRIVER\n";


                cout<<"\nEnter the seat number\n";
                cin>>s_no;
        //----------------EXCEPTION---------------------
                        if(s_no<1 || s_no>30)
                                throw std::invalid_argument("ERROR! Enter a valid seat number\n");
        }


        void disp()
        {
        cout<<"\n**********************************************************************"<<endl;
        cout<<"BUS No:\nDriver Name:\tArrivaltime:\tDeparture time:\t\n\nFrom:\tTo:\t\n";

        cout<<"\n**********************************************************************"<<endl;
        }



//--------------------HANDLING-----------------------------


/*              if(check())
                      cout<<"\nCongratz! Your seat is booked\nProceed to continue\n";
                else
                        cout<<"\nTry again with different seat!already book";


        void filter()
        {
                cout<<"Choose the bus from the list of available buses\n";
                ifstream b;
        }

        int check()
        {
                int reserve;
                if(seat_no[s_no]==reserve)
                        return 1;
                else
                        return 0;
        }*/

};

void staticfile()
{
    fstream file("details.txt",ios::out);
    if(!file.is_open())
    {
        cout<<"ERROR!!!FILE NOT OPENED";
    }
    else
    {
        file<<"\n";
        file<<"Hema hema";
    }
    file.close();
}

void get()
{
string name,pwd;

    cin.ignore();
    cout<<"\tENTER:\n\tNAME:-\t";
        getline(cin,name);
    cout<<"\tPASSWORD:-\t";
        getline(cin,pwd);
    ofstream file("details.txt",ios::out|ios::app);

if(!file.is_open())
{
    cout<<"ERROR!!!FILE NOT OPENED";
}
else
{
    file<<endl<<name<<" "<<pwd<<endl;
}
file.close();
    cout<<"---ACCOUNT SUCCESSFULLY CREATED!!!---\n";
}



int main()
{

   
    cout<<"\n\nWELCOME TO BUS RESERVATION SYSTEM\n(We make Travelling and Booking convenient)\n"<<endl;
    int choice;
    cout<<"OPTIONS:\n"<<"1.SIGN IN\n2.LOG IN"<<endl;
    cout<<"ENTER THE CHOICE NUMBER:-";
    cin>>choice;
     while(choice <1 || choice>2)
        {
        cout<<"enter a valid choice\n";
        cin>>choice;
        }
    ofstream file;
    file.open("details.txt",ios::out|ios::app);

    if(!file.is_open())
    {
        cout<<"ERROR!!!FILE NOT OPENED";
    }
    else
    {
        if(file.tellp()==0)
        {
            staticfile();
        }
    file.close();
    }

    if(choice==2)
    {
        get();
    }
    if(choice==1)
        {cin.ignore();}


int i=0,flag=0;
    while(i<3 && flag==0)
    {
            if(flag==0)
                cout<<"\t---NUMBER OF ATTEMPTS LEFT "<<3-i<<endl;
        string name,pwd,Name,Pwd;
                cout<<"ENTER:\n\tNAME:-\t";
                getline(cin,name);
                cout<<"\tPASSWORD:-\t";
                getline(cin,pwd);
        ifstream file2("details.txt",ios::in);
        if(!file2.is_open())
        {
            cout<<"ERROR!!!FILE NOT OPENED";
        }
        else
        {
        int flag1=0,flag2=0;
            while(flag==0 && file2.good())
            {
                file2>>Name>>Pwd;
                if(name==Name && pwd==Pwd)
                {
                    flag=1;
                    cout<<"\t***WELCOME "<<name<<"***\n";
                }
                if(name==Name)
                    flag1=1;
                if(pwd==Pwd)
                    flag2=1;
            }
        i++;
        if(flag1==0)
        {
            cout<<"\t---USERID INCORRECT---\t";
        }
        else if(flag2==0)
        {
            cout<<"\t---PASSWORD INCORRECT---\t";
        }
    }


}
   
        calendar c;
        c.print(c.year);
        int n;
        n=c.dayNumber(c.day,c.month,c.year);
        c.weekend(n);
        try
        {
            bus b;
        }
        catch(std::invalid_argument& e)
        {
            cerr<<e.what()<<endl;
        }
return 0;
}

