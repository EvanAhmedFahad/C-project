#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void recipt();



};
void shopping::menu()
{ m:
    int choice;
    string email;
    string password;


    cout<<"\t\t\t\t___________________________\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t     SUPER MARKET          \n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t___________________________\n";
    cout<<"\t\t\t\t                           \n";
    cout<<"\t\t\t\t|    1=>Administrator   |\n";
    cout<<"\t\t\t\t|    2=>Buyer           |\n";
    cout<<"\t\t\t\t|    3=>Exit            |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|   Please select ";
    cin>>choice;
switch (choice)
{
case 1:
    {
        cout<<"\t\t\t\t Please login \n";
    cout<<"\t\t\t\t Enter email:";
    cin>>email;
    cout<<"\n Enter password:";
    cin>>password;

    if(email=="abc" && password=="123")
    {
        administrator();
    }
    else
    {
        cout<<"invalid ";
    }

    }
    break;


case 2:
    {
        buyer();
    }
//case 3:
    //{
    //    exit(0);
   // }
default :
    {
        cout<<"please select form the given option:";
    }
}
goto m;
}


void shopping :: administrator()
{
    m:
    int choice;
    cout<<" Administrator menu :\n";
    cout<<" 1=> Add the product :\n";
    cout<<" 2=> modify the product :\n";
    cout<<" 3 => delete the product :\n";
    cout<<"4=> back to main menu :\n";

    cout<<"enter you choice :";

    cin>>choice;
    switch(choice)
    {
    case 1:
        {
        add();
        break;

        }

    case 2:
        {
        edit();
        break;
        }
    case 3:
        {
        rem();
         break;
        }

    case 4:
        {
        menu();
        break;
        }

    default :
        {
            cout<<"invalid ";
        }
    }

     goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<" buyer \n";
    cout<<" 1=>buy product\n";
    cout<< " 2=>go back\n";
    cout<<"enter you choice ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            recipt();
        break;
        }

    case 2:
        {
        menu();
        break;
        }
    default :
        {
             cout<<"invalid";
        }


    }
 goto m;
}

void shopping ::add()
{
    m:
    fstream data;
    int c;
    int token;
    float p;
    float d;
    string n;

    cout<<"add new product :";
    cout<<"Product code of the product ";
    cin>>pcode;
    cout<<"name of the product ";
    cin>>pname;
    cout<<"Price of the product ";
    cin>>price;
    cout<<"enter the discount :";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis;
        data.close();
    }
    else
    {

        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis;
        data.close();
    }
    cout<<"recored inserted :";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"  modify the recored ";
    cout<<"  product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<" file doesn't exits";
    }
    else{
      data.open("database1.txt",ios::app|ios::out);
      data>>pcode>>pname>>price>>dis;
      while(!data.eof())
      {
          if(pkey==pcode)
          {
              cout<<"  product new code :";
              cin>>c;
              cout<<"    new of the product :";
              cin>>n;
              cout<<"    price :";
              cin>>p;
              cout<<"   discount :";
              cin>>d;
              data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
              cout<<"  recored ";
              token++;


          }
          else
              {
                  data1<<" "<<pcode<<" "<<pname<<" " <<price<<" " <<dis<<"\n";
              }
              data>>pcode>>pname>>price>>dis;
      }
      data.close();
      data1.close();

      remove("database.txt");
      rename("database1.txt","database.txt");
      if(token==0)
      {
          cout<<"    recored not found sorry";
      }
    }
}
void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"   dalete product";
    cout<<"product code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"file doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"product deleted successfully";
                token++;

            }
            else{
                data1<< " "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"  recored not found ";
        }

    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"                         ";
    cout<<"prono\t\tName\t\tprice";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}
void shopping::recipt()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;
    cout<<"\t\t receipt ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"empty database";

    }
    else{
        data.close();
        list();
        cout<<"------------------------\n";
        cout<<"\n-----------------------\n";
        cout<<"please place the order ";
        cout<<"\n------------------------\n";
        do{
            cout<<"enter the product code";
            cin>>arrc[c];
            cout<<"enter the quantity ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"duplicate product code";
                    goto m;
                }
            }
            c++;
            cout<<"do you buy another product if yes press y else no";
            cin>>choice;

        }
        while(choice=='y');
        cout<<"\t\t\t\t-------receipt-----\n";
        cout<<"\t\t product no \t\t product name \t\tproduct quantity\t\tprice\t\tamount with discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount==price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<pname<<arrq[i]<<price<<amount<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }
    }
    cout<<"\n total amount "<<total;




}

int main()
{
    shopping s;
    s.menu();
}
