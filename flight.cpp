#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
char fname[20]="file.txt";
char fn[20]="ticket.txt";

struct record
{
 	char name[15],number[15],date[15],src[15],dest[15],price[10];
 };

class flight
{
             public: void pack(record r);
	            record unpack(char a[]);
	            void adddetails();
	            void displaydetails();
				void modification();
				void searchdetails();
				void flightbooking();
				void alltickets();
};

class payment
{
protected:
	unsigned long long card;
    int choice1,bank,date,cvv,user_id;
    char password[10];
public:
    void pay_detail()
    {     cout << "\n\n\nHow would you like to pay?:\n";
        cout << "\n1.Debit Card \n2.Credit Card \n3.Net Banking";
        cout << "\n\nEnter your choice : ";
        cin >> choice1;
        switch(choice1)
        {
        case 1:
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter CVV no.:";
            cin >> cvv;
            cout << "\nTransaction Successful\n";
            break;
        case 2:
            cout << "\nEnter card no.:";
            cin >> card;
            cout << "\nEnter expiry date:";
            cin >> date;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
            break;
        case 3:
            cout << "Banks Available: \1.HDFC \2.CANARA \3.ALLAHABAD";
            cout << "\nSelect your bank:";
            cin >> bank;
            cout << "\nYou have selected:" << bank;
            cout << "\nEnter user id:";
            cin >> user_id;
            cout << "\nEnter password:";
            cin >> password;
            cout << "\nTransaction Successful\n";
			cout<<"\nYour ticket is booked successfully!!!!!!";
            break;
        default:
            cout << "\nWrong input entered.\nTry again\n\n";
            return pay_detail();
        }
    }

};




void flight ::pack(record r)
{
             fstream fp;
             fp.open(fname,ios::out|ios::app);
             if(fp==NULL)
            {
		cout<<"\nCannot open file";
		exit(0);
             }
             char buff[90];
             strcpy(buff,r.name);
             strcat(buff,"|");
             strcat(buff,r.number);
             strcat(buff,"|");
			 strcat(buff,r.date);
     	     strcat(buff,"|");
             strcat(buff,r.src);
             strcat(buff,"|");
     	strcat(buff,r.dest);
     	strcat(buff,"|");
     	strcat(buff,r.price);
     	strcat(buff,"|");
     	for(int i=0;i<90-strlen(buff);i++)
     	strcat(buff,"|");
     	fp<<buff<<endl;
     	fp.close();
}


record flight::unpack(char buff[])
{
	record r;
	int i=0,j=0;
	while(buff[j]!='|')
	      r.name[i++]=buff[j++];
	r.name[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.number[i++]=buff[j++];
	r.number[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.date[i++]=buff[j++];
	r.date[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.src[i++]=buff[j++];
	r.src[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.dest[i++]=buff[j++];
	r.dest[i]='\0';
	i=0;
	j++;
	while(buff[j]!='|')
	      r.price[i++]=buff[j++];
	r.price[i]='\0';
	return(r);
}


void flight::adddetails()
{
record r;
     	cout<<"\nENTER FLIGHT NAME: ";
     	cin>>r.name;
     	cout<<"\nENTER FLIGHT NUMBER: ";
     	cin>>r.number;
		cout<<"\nENTER FLIGHT DATE: ";
     	cin>>r.date;
     	cout<<"\nENTER SOURCE POINT: ";
     	cin>>r.src;
     	cout<<"\nENTER DESTINATION POINT: ";
     	cin>>r.dest;
     	cout<<"\nENTER COST: ";
     	cin>>r.price;
     	pack(r);
}


void flight::displaydetails()
{
 	fstream fp;
   	char buff[90];
   	record r;
     	fp.open(fname,ios::in);
     	if(fp==NULL)
       	{
		cout<<"\nCannot open file";
		exit(0);
       	}	
     	cout<<"\n"<<setw(5)<<"#"<<setw(15)<<"NAME"<<setw(15)<<"NUMBER"<<setw(15)<<"DATE"<<setw(15)<<"SOURCE"<<setw(15)<<"DESTNATION"<<setw(10)<<"PRICE\n";
     	int c=1;
     	while(1)
     	{
     	 	fp.getline(buff,90);
       		if(fp.eof())break;
       		r=unpack(buff);
cout<<setw(5)<<c++<<setw(15)<<r.name<<setw(15)<<r.number<<setw(15)<<r.date<<setw(15)<<r.src<<setw(15) <<r.dest<<setw(10)<<r.price<<endl;
              }
     	fp.close();
     	return;
}


void flight ::modification()
{
             fstream fp;
     	char number[15],buff[90];
     	int i,j;
     	record s[100];
     	fp.open(fname,ios::in);
     	if(fp==NULL)
             {
		cout<<"\nCannot open file";
		exit(0);
             }
             cout<<"\nENTER THE FLIGHT NUMBER TO BE MODIFIED: ";
     	cin>>number;
 i=0;
   	while(1)
   	{
       		fp.getline(buff,90);
       		if(fp.eof())break;
       		s[i]=unpack(buff);
       		i++;
              }
   	for(j=0;j<i;j++)
             {
       		if(strcmp(s[j].number,number)==0)
		{
	  		cout<<"\nVALUES OF THE RECORD ARE:\n";
	  		cout<<"\nFLIGHT NAME: "<<s[j].name;
	  		cout<<"\nFLIGHT NUMBER: "<<s[j].number;
	  		cout<<"\nFLIGHT DATE: "<<s[j].date;
	  		cout<<"\nSOURCE LOCATION: "<<s[j].src;
	  		cout<<"\nDESTINATION LOCATION: "<<s[j].dest;
			cout<<"\nPRICE: "<<s[j].price;
	  		cout<<"\nENTER THE NEW VALUES: \n";
	  		cout<<"\nFLIGHT NAME: ";
	  		cin>>s[j].name;
	  		cout<<"\nFLIGHT NUMBER: ";
	  		cin>>s[j].number;
	  		cout<<"\nFLIGHT DATE: ";
	  		cin>>s[j].date;
	  		cout<<"\nSOURCE LOCATION: ";
	  		cin>>s[j].src;
	  		cout<<"\nDESTINATION LOCATION: ";
	  		cin>>s[j].dest;
			cout<<"\nPRICE: ";
	  		cin>>s[j].price;
	  		break;
	}
              }
   	if(j==i)
     	{
      		cout<<"\nRECORD NOT FOUND";
      		return;
     	}	
   	 fp.close();
  	 fstream fd;
 	 fd.open(fname,ios::out|ios::trunc);
 if(fd==NULL)
     	{
      	  	cout<<"\nCannot open file";
      		exit(0);
     	 }
   	for(j=0;j<i;j++)
      		pack(s[j]);
   	fd.close();
}


void flight::searchdetails()
{
 	fstream fp;
 	char number[15],buff[90];
 	int i,j;
 	record s;
      	fp.open(fname,ios::in);
     	if(fp==NULL)
     	{
	 	cout<<"\nCannot open file";
		exit(0);
        }
     	cout<<"\nENTER THE FLIGHT NUMBER TO BE SEARCHED: ";
     	cin>>number;
     	i=0;
   	while(1)
   	{
   		 fp.getline(buff,90);
       		if(fp.eof())break;
       		s=unpack(buff);
       		if(strcmp(s.number,number)==0)
		{
	  	 	cout<<"\nRECORD FOUND\n";
	  		cout<<"\nNAME: "<<s.name;
	  		cout<<"\nFLIGHT NUMBER: "<<s.number;
	  		cout<<"\nFLIGHT DATE: "<<s.date;
	  		cout<<"\nSOURCE LOCATION: "<<s.src;
	  		cout<<"\nDESTINATION LOCATION: "<<s.dest;
			cout<<"\nPRICE: "<<s.price;
	  		return;
	 	}
                }
       	   cout<<"\nRECORD NOT FOUND";
       	   return;
}


void flight::flightbooking()
{
	fstream fp;
 	char number[15],buff[90];
 	int i,j;
 	record s;
      	fp.open(fname,ios::in);
     	if(fp==NULL)
     	{
	 	cout<<"\nCannot open file";
		exit(0);
        }
     	cout<<"\nENTER THE FLIGHT NUMBER TO BE BOOKED: ";
     	cin>>number;
     	i=0;
   	while(1)
   	{
   		 fp.getline(buff,90);
       		if(fp.eof())break;
       		s=unpack(buff);
       		if(strcmp(s.number,number)==0)
		    {
	  		cout<<"\nFLIGHT NAME: "<<s.name;
	  		cout<<"\nFLIGHT NUMBER: "<<s.number;
	  		cout<<"\nFLIGHT DATE: "<<s.date;
	  		cout<<"\nSOURCE LOCATION: "<<s.src;
	  		cout<<"\nDESTINATION LOCATION: "<<s.dest;
			cout<<"\nPRICE: "<<s.price;

	 	    }
      }

	string first_name,last_name,gender,email,class_type,cname,edate,contact;
	int age,passport_no,num,price,tp,cvv;
	char g;
	long int cno;

	ofstream myfile;
    myfile.open("ticket.txt",ios::out|ios::app);

	cout<<"\nENTER THE FIRST NAME: ";
	cin>>first_name;
	myfile<<first_name<<" ";

	cout<<"\nENTER THE LAST NAME : ";
	cin>>last_name;
	myfile<<last_name<<" ";

	cout<<"\nENTER THE GENDER(M/F) : ";
	cin>>g;
	switch(g)
	{
	case 'm':gender="male";
		break;
	case 'f':gender="female";
		break;
	}
	myfile<<gender<<" ";

	cout<<"\nENTER THE AGE : ";
	cin>>age;
	myfile<<age<<" ";

	cout<<"\nENTER THE E-MAIL : ";
	cin>>email;
	myfile<<email<<" ";

	cout<<"\nENTER THE CONTACT NUMBER : ";
	cin>>contact;
	myfile<<contact<<" ";

	cout<<"\nENTER THE CLASS TYPE(business/economic) : ";
	cin>>class_type;
	myfile<<class_type<<" ";

	cout<<"\nENTER THE PASSPORT NUMBER : ";
	cin>>passport_no;
	myfile<<passport_no<<" ";

	cout<<"\nENTER THE TICKET PRICE : ";
	cin>>price;
	myfile<<price<<" ";

	cout<<"\nENTER THE NUMBER OF TICKETS TO BE BOOKED : ";
	cin>>num;
	myfile<<num<<" ";

	tp=price*num*1;
	myfile<<tp<<"\n";

	cout<<"\nThe total amount to be paid is: "<<tp;

	char f;
	cout<<"\nDo you want the to print the ticket details(y/n)??";
	cin>>f;
	if(f=='y')
	{
		fstream fp;
 	char number[15],buff[90];
 	int i,j;
 	record s;
      	fp.open(fname,ios::in);
     	if(fp==NULL)
     	{
	 	cout<<"\nCannot open file";
		exit(0);
        }
     	cout<<"\nENTER THE FLIGHT NUMBER: ";
     	cin>>number;
     	i=0;
   	while(1)
   	{
   		 fp.getline(buff,90);
       		if(fp.eof())break;
       		s=unpack(buff);
       		if(strcmp(s.number,number)==0)
		{
			cout<<"\n\t\t\t===============================================================================================================================================================================";
	  	 	cout<<"\n\t\t\t                                                                     <<<<<<TICKET DETAILS>>>>>>";
			cout<<"\n\t\t\t===============================================================================================================================================================================";
			cout<<"\n\t\t\t\t\t\t\t\t\tCUSTOMER_NAME: "<<first_name<<" " <<last_name;
			cout<<"\n\t\t\t\t\t\t\t\t\tGENDER: "<<gender;
			cout<<"\n\t\t\t\t\t\t\t\t\tAGE: "<<age;
	  		cout<<"\n\t\t\t\t\t\t\t\t\tFLIGHT_NAME: "<<s.name;
	  		cout<<"\n\t\t\t\t\t\t\t\t\tFLIGHT NUMBER: "<<s.number;
	  		cout<<"\n\t\t\t\t\t\t\t\t\tFLIGHT DATE: "<<s.date;
	  		cout<<"\n\t\t\t\t\t\t\t\t\tSOURCE LOCATION: "<<s.src;
	  		cout<<"\n\t\t\t\t\t\t\t\t\tDESTINATION LOCATION: "<<s.dest;
			cout<<"\n\t\t\t\t\t\t\t\t\tPASSPORT_NUMBER: "<<passport_no;
			cout<<"\n\t\t\t\t\t\t\t\t\tCONTACT_NO: "<<number;
			cout<<"\n\t\t\t\t\t\t\t\t\tEMAIL_ID: "<<email;
			cout<<"\n\t\t\t\t\t\t\t\t\tTICKET_PRICE: "<<s.price;
			cout<<"\n\t\t\t\t\t\t\t\t\tNUMBER OF TICKETS BOOKED: "<<num;
			cout<<"\n\t\t\t\t\t\t\t\t\tTOTAL AMOUNT: "<<tp;
	  		return;
	 	}
                }
		   return;
	}

	if(f=='n')
	{
		cout<<"PRODEEDING TO PAYMENT!!!!!!";
	}


}



void flight::alltickets()
{
	char fn[20]="ticket.txt";
	ifstream m;
	m.open(fn);
	
	if(!m.is_open())
	{
		exit(EXIT_FAILURE);
	}
	
	char word[50];
	m>>word;
	
	cout << "\n\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<BOOKED TICKETS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";	
    
	
	cout << "\n\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<  "\n\t\t"<<setw(15)<<"FIRST_NAME"<<setw(15)<<"LAST_NAME"<<setw(15)<<"GENDER"<<setw(15)<<"AGE"<<setw(15)<<"EMAIL_ID"<<setw(18)<<"PHONE"<<setw(15)<<"CLASS"<<setw(20)<<"PASSPORT_NO"<<setw(18)<<"TICKET_PRICE"<<setw(15)<<"NO_OF_TICKETS"<<setw(15)<<"TOTAL_COST";
	cout << "\n\t\t--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	
	
int d;

while(m.good())	
{
	d=0;
	cout<<"\t\t";
	while(d<11){	
	cout<<setw(15)<<word<<"\t";
	m>>word;
	d++;
}

cout<<"\n";	
}	

}


   void delete_line(const char *file_name, int n) 	
	{ 
    // open file in read mode or in mode 
    ifstream is(file_name); 
  
    // open file in write mode or out mode 
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out); 
  
    // loop getting single characters 
    char c; 
    int line_no=1; 
    while (is.get(c)) 
    { 
        // if a newline character 
        if (c=='\n') 
        line_no++; 
  
        // file content not to be deleted 
        if (line_no!=n) 
            ofs<<c; 
    } 
  
    // closing output file 
    ofs.close(); 
  
    // closing input file 
    is.close(); 
  
    // remove the original file 
    remove(file_name); 
  
    // rename the file 
    rename("temp.txt",file_name); 
} 



void main()
{
 	flight obj;
	payment ob;
	string username,password;
	cout<<" \t\t================================================================================================================================================================================\n";
	cout<<" \t\t                                    <<<<<<<<<<<<<<<<<<<<<<<<<<<   WELCOME TO THE FLIGHT TICKET RESERVATION SYSTEM   >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	cout<<" \t\t================================================================================================================================================================================\n";
	cout<<" \t\t                                                                !!!!!!!BOOK YOUR FLIGHTS AT AFFORDABLE PRICES!!!!!!!\n";
	cout<<"\n\t\t                                                                         Please enter your username: ";
	cin>>username;
	cout<<"\n\t\t                                                                         Please enter your password: ";
	cin>>password;
		if(username=="teja"&&password=="123")
		{
        char c,s;
		do
		{
		int ch;
		cout<<"\n \t\t================================================================================================================================================================================";
		cout<<"\n \t\t                                             <<<<<<<<<<<<<<<<<<<<<<<<  RESERVE YOUR TICKETS NOW  >>>>>>>>>>>>>>>>>>>>>>>>>";
		cout<<"\n \t\t================================================================================================================================================================================\n\n";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t1.add flight details\n\t\t\t\t\t\t\t\t\t\t\t2.view flight details\n\t\t\t\t\t\t\t\t\t\t\t3.modify flight information\n\t\t\t\t\t\t\t\t\t\t\t4.search flight details\n\t\t\t\t\t\t\t\t\t\t\t5.book the seat\n\t\t\t\t\t\t\t\t\t\t\t6.cancel flight\n\t\t\t\t\t\t\t\t\t\t\t7.show booked tickets\n\t\t\t\t\t\t\t\t\t\t\t8.exit";
		cout<<"\n\n  ENTER YOUR CHOICE:";
		cin>>ch;
		   switch(ch)
		   {
		    case 1:obj.adddetails();
				   cout<<"\nDo you want to continue(y/n)??";
				   cin>>c;
				  break;
		    case 2:obj.displaydetails();
				   cout<<"\nDo you want to continue(y/n)??";
				   cin>>c;
				  break;
			case 3:obj.modification();
				   cout<<"\nDo you want to continue(y/n)??";
				   cin>>c;
				  break;
            case 4:obj.searchdetails();
				   cout<<"\nDo you want to continue(y/n)??";
				   cin>>c;
				  break;
			case 5:obj.flightbooking();
				   ob.pay_detail();
				  cout<<"\nDo you want to continue(y/n)??";
				   cin>>c;
				  break;
			case 6:obj.displaydetails();
					cout<<"\n\nENTER THE ROW THAT YOU WANT TO DELETE:\t";
					cin>>s;
					delete_line("file.txt",s); 
					cout << "\n ============================================";
					cout << "\n   FLIGHT CANCELLED SUCCESSFULLY  ";
					cout << "\n   THANK YOU ";
					cout << "\n ============================================\n";
					cout<<"\n\nDo you want to continue(y/n)\n";
					cin>>c;
					break;
			case 7:obj.alltickets();
				    cout<<"\n\nDo you want to continue(y/n)\n";
					cin>>c;
					break;
			case 8:exit(0);
				    break;
	        default:cout<<"\nInvalid input";
				  exit(0);
		    }
		}while(c=='y');
		}
		if(username!="teja"&&password!="123")
		{
			cout<<"WRONG CREDENTIALS,PLEASE ENTER CORRECT USER NAME AND PASSWORD!!!!!!!!";
		}
}