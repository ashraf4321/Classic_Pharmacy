#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void delete_m()
{
    fstream med;
    fstream temp;
    med.open("medicine.txt", ios::in);
    temp.open("temp.txt", ios::out);
    char name[50],expiery_date[30], S_name[50],price[10],quantity[10],shelf[10];

    cout<<"\nEnter the name of medicine to delete : ";
    cin.ignore();
    cin.getline(S_name,50);
    bool f=1;
    while(!med.eof())
    {

        med.getline(name,50,'|');
        med.getline(expiery_date,30,'|');
        med.getline(price,10,'|');
        med.getline(quantity,10,'|');
        med.getline(shelf,10);

        if(strcmp(name,S_name)==0)
        {
            f=0;
            continue;

        }
        else
            temp<<name<<'|'<<expiery_date<<'|'<<price<<'|'<<quantity<<'|'<<shelf<<'\n';

    }
    if(f==1)
        cout<<"the medicine is Not found !!!\n";

    temp.close();
    med.close();

    med.open("medicine.txt", ios::out);
    temp.open("temp.text", ios::in);

    while(!temp.eof())
    {

        temp.getline(name,50,'|');
        temp.getline(expiery_date,30,'|');
        temp.getline(price,10,'|');
        temp.getline(quantity,10,'|');
        temp.getline(shelf,10);

        med<<name<<'|'<<expiery_date<<'|'<<price<<'|'<<quantity<<'|'<<shelf<<'\n';
    }
    temp.close();
    med.close();
    remove("temp.txt");
    cout<<"\n done !!\n";
}

void update_m()
{
    fstream med;
    fstream temp;
    med.open("medicine.txt", ios::in);
    temp.open("temp.txt", ios::out);
    char name[50],expiery_date[30], S_name[50],price[10],quantity[10],shelf[10];

    cout<<"\nEnter the name of medicine to update : ";
    cin.ignore();
    cin.getline(S_name,50);
    cout<<"choose the number you will update : \n";
p11:
    cout<<"1- Name \n2- Expiery_date \n3- Price \n4- Quantity \n5- Shelf \n";
    int num=0;
    cin>> num;
    if(num>5 || num<1)
    {
        cout<<"invalid number !!, enter right number"<<endl;
        goto p11;
    }
    bool f=1;
    while(!med.eof())
    {

        med.getline(name,50,'|');
        med.getline(expiery_date,30,'|');
        med.getline(price,10,'|');
        med.getline(quantity,10,'|');
        med.getline(shelf,10);

        if(strcmp(name,S_name)==0)
        {
            cout<<"enter the new value: ";
            cin.ignore();
            if(num==1)
                cin.getline(name,50);
            else if(num==2)
                cin.getline(expiery_date,30);
            else if(num==3)
                cin.getline(price,10);
            else if(num==4)
                cin.getline(quantity,10);
            else
                cin.getline(shelf,10);

            temp<<name<<'|'<<expiery_date<<'|'<<price<<'|'<<quantity<<'|'<<shelf<<'\n';
            f=0;
        }
        else
            temp<<name<<'|'<<expiery_date<<'|'<<price<<'|'<<quantity<<'|'<<shelf<<'\n';

    }
    if(f==1)
        cout<<"the medicine is Not found !!!\n";

    temp.close();
    med.close();

    med.open("medicine.txt", ios::out);
    temp.open("temp.text", ios::in);

    while(!temp.eof())
    {

        temp.getline(name,50,'|');
        temp.getline(expiery_date,30,'|');
        temp.getline(price,10,'|');
        temp.getline(quantity,10,'|');
        temp.getline(shelf,10);

        med<<name<<'|'<<expiery_date<<'|'<<price<<'|'<<quantity<<'|'<<shelf<<'\n';
    }
    temp.close();
    med.close();
    remove("temp.txt");
    cout<<"\n done !!\n";
}

void display_m()
{
    fstream med;
    med.open("medicine.txt", ios::in);

    char name[50],expiery_date[30],price[10],quantity[10],shelf[10];

    cout<<"\n**************************\n";
    cout<<"Name\t"<<"Expiery_date\t"<<"Price\t"<<"Quantity\t"<<"Shelf"<<endl;
    while(!med.eof())
    {
        med.getline(name,50,'|');
        med.getline(expiery_date,30,'|');
        med.getline(price,10,'|');
        med.getline(quantity,10,'|');
        med.getline(shelf,10);
        cout<<name<<"\t"<<expiery_date<<"\t\t"<<price<<"\t"<<quantity<<"\t\t"<<shelf<<endl;
    }
    cout<<"**************************\n";

    med.close();
}

void search_m()
{
    fstream med;
    med.open("medicine.txt",ios::in);

    char name[50],expiery_date[30], S_name[50],price[10],quantity[10],shelf[10];

    cout<<"\nEnter the name of medicine : ";
    cin.ignore();
    cin.getline(S_name,50);

    bool f=1;
    while(!med.eof())
    {

        med.getline(name,50,'|');
        med.getline(expiery_date,30,'|');
        med.getline(price,10,'|');
        med.getline(quantity,10,'|');
        med.getline(shelf,10);

        if(strcmp(name,S_name)==0)
        {
            cout<<"\n**************************\n";
            cout<<"Name : "<<name<<endl;
            cout<<"Expiery date : "<<expiery_date<<endl;
            cout<<"Price : "<<price<<endl;
            cout<<"Quantity : "<<quantity<<endl;
            cout<<"Shelf : "<<shelf<<endl;
            cout<<"**************************\n\n";
            f=0;
            break;
        }
    }
    if(f==1)
    {
        cout<<"Not found !!!\n";
    }
    med.close();
}

void insert_m()
{
    fstream med;
    med.open("medicine.txt",ios::app);

    char name[50],expiery_date[30],price[10],quantity[10],shelf[10];
    cin.ignore();

    cout<<"\n**************************\n";
    cout<<"Name : ";
    cin.getline(name,50);
    cout<<"Expiery date : ";
    cin.getline(expiery_date,30);
    cout<<"Price : ";
    cin.getline(price,10);
    cout<<"Quantity : ";
    cin.getline(quantity,10);
    cout<<"Shelf : ";
    cin.getline(shelf,10);

    med<<name<<'|'<<expiery_date<<'|'<<price<<'|'<<quantity<<'|'<<shelf<<'\n';
    cout<<"\ndone !!\n**************************\n\n";

    med.close();
}
int main()
{
    cout<< "*************** Welcome to pharmacy program ***************\n";
    bool flag=true;
    while(flag==true)
    {
point:

        cout <<"\nInsert : 1 \nSearch : 2 \nDisplay :3 \nUpdate : 4 \nDelete : 5 \nChoose your operation : ";
        char c;
        cin>> c;
        cout<<endl;
        switch(c)
        {
        case '1':
            insert_m();
            break;
        case '2':
            search_m();
            break;
        case '3':
            display_m();
            break;
        case '4':
            update_m();
            break;
        case '5':
            delete_m();
            break;
        default:
        {
            cout<<"\nenter right number please !!\n\n";
            goto point;
        }
        }
point2:
        cout<<"IF you want to complete press (Y)\nIf you want to finish press (N)\n\n";
        char letter;
        cin>>letter;
        if(letter=='N' || letter=='n')
            flag=false;
        else if(letter=='Y' || letter=='y')
            flag=true;
        else
        {
            cout<<"\npress right character !!\n";
            goto point2;
        }
    }
    return 0;
}
