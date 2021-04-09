#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <windows.h>
#include <vector>
using namespace std;
string option;
void menu_print();
int hash_func(string data){

    hash<string> hash_code;
    return hash_code(data);

}

class Bank{
    private:
    string card_id;
    int hash_password;
    int balance;
    public:
    Bank(string id,int password , string name_){
        card_id=id;
        hash_password = hash_func(to_string(password));
        name=name_;
    }
    string name;
    string get_card_id(){return card_id;}
    int get_hash_password(){return hash_password;}
    int get_balance(){return balance;}
    void set_card_id(string input){card_id= input;}
    void set_hash_password(int input){hash_password=input;}
    void set_balance(int input){balance=input;}

};
vector <Bank> costumers;
vector <Bank> blocks;
//_____________________________________________________________________________________
void user_menu_print(string name , int id=-1) {
     system("cls");
     system("color 70");
    cout << "_______________________________\n" << "\n         WELCOME  "<<name<<" \n" << "_______________________________\n";
    cout << "\nOPTIONS\n" << " 1- TRANSFER TO CARD \n 2- SHOW BALANCE \n 3- BUY CHARGE \n 4- SHOW INFO \n 5- CHANGE PASSWORD \n 6- SIGN OUT";
    cout << "\n-->";
    cin >> option;

    try
    {
        if (stoi(option) / 1 != stoi(option) || stoi(option) > 6 || stoi(option) < 1)
            throw option;
    }
    catch (...)
    {
        system("cls");
        cout << " \ninvalid input :( \n input should be a number betwean (1-6) \n PRESS ANY KEY TO CONTINUE ->";
        _getch();
        user_menu_print(name,id);
    }
    switch (stoi(option))
    {
        //transfer
    case 1:
    {
        
        string dest_card;
        int money_amount,pass,dest_user;
        bool valid=false;
        system("cls");
        system("color DE");
        cout << "_______________________________\n" << "\n            Transfer \n" << "_______________________________\n";
        cout<<"\n Enter destination Card : ";
        cin>>dest_card;
        for(int i=0;i<costumers.size();i++)
        {
            if(costumers[i].get_card_id() == dest_card)
            {
                dest_user=i;
                valid =true;
                break;
            }
        }
        if(!valid)
        {
            cout<<"\n\n  -- Card Not Avalable --";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            user_menu_print(name,id);

        }
        cout<<"\n Enter Amount (Rial) : ";
        cin>>money_amount;
        if(costumers[id].get_balance()<money_amount)
        {
            cout<<" \n Not Enough Balance ! ";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
            _getch();                                                                                      
            user_menu_print(name,id);                                                                                       
        }

        cout<<"\n Enter password : ";
        cin>>pass;
        if(hash_func(to_string(pass))!=costumers[id].get_hash_password())
            {
                cout<<" \n Wrong password !";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                _getch();                                                                                      
                user_menu_print(name,id);                                                                                        

            }
       costumers[id].set_balance(costumers[id].get_balance()-money_amount);
       costumers[dest_user].set_balance(costumers[dest_user].get_balance()+money_amount);
        cout<<"\n\n  -- DONE --";
        cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
        _getch();
        user_menu_print(name,id);
        break;
    }
    //Balance
    case 2:
    {       
        system("cls");
        system("color B8");
        cout<<"\n Balance : "<<costumers[id].get_balance()<<" Rial";
        cout << " \n\n PRESS ANY KEY TO CONTINUE ->";

        _getch();
        user_menu_print(name,id);

        break;
    }
    //buy charge
    case 3:
    {
        string option;
        cout<<
            "\n Buy charge "
            <<"\n 1- 10000 R"
            <<"\n 2- 20000 R"
            <<"\n 3- 50000 R"
            <<"\n 4- 100000 R"
            <<"\n 5- 200000 R \n ->";
        cin>>option;
        try
        {
            if (stoi(option) / 1 != stoi(option) || stoi(option) > 5 || stoi(option) < 1)
                throw option;
        }
        catch (...)
        {
            system("cls");
            cout << " \ninvalid input :( \n input should be a number betwean (1-5) \n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            user_menu_print(name,id);
        }
        switch (stoi(option))
        {
        case 1:
        {
            int pass;
            cout<<" \n Balance : "<<costumers[id].get_balance() <<" Rial";
            cout<<" \n Enter  Password : ";
            cin>>pass;
            if(hash_func(to_string(pass))!=costumers[id].get_hash_password())
            {
                cout<<" \n Wrong password !";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                _getch();                                                                                      
                user_menu_print(name,id);                                                                                        

            }
            else{
                if(costumers[id].get_balance()<10000)
                {
                    cout<<" \n not enough balance ! ";
                    cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                    _getch();                                                                                      
                    user_menu_print(name,id);                                                                                        

                }
                else
                costumers[id].set_balance(costumers[id].get_balance()-10000);
            }
            break;
        }
        case 2:
        {
            int pass;
            cout<<" \n Balance : "<<costumers[id].get_balance()<<" Rial";
            cout<<" \n Enter  Password : ";
            cin>>pass;
            if(hash_func(to_string(pass))!=costumers[id].get_hash_password())
            {
                cout<<" \n Wrong password !";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                _getch();                                                                                      
                user_menu_print(name,id);                                                                                        

            }
            else{
                if(costumers[id].get_balance()<20000)
                {
                    cout<<" \n not enough balance ! ";
                    cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                    _getch();                                                                                      
                    user_menu_print(name,id);                                                                                        

                }
                else

                costumers[id].set_balance(costumers[id].get_balance()-20000);
            }

             break;
        }
        case 3:
        {
            int pass;
            cout<<" \n Balance : "<<costumers[id].get_balance() << " Rial";
            cout<<" \n Enter  Password : ";
            cin>>pass;
            if(hash_func(to_string(pass))!=costumers[id].get_hash_password())
            {
                cout<<" \n Wrong password !";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                _getch();                                                                                      
                user_menu_print(name,id);                                                                                        

            }
            else{
                if(costumers[id].get_balance()<50000)
                {
                    cout<<" \n not enough balance ! ";
                    cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                    _getch();                                                                                      
                    user_menu_print(name,id);                                                                                        

                }
                else

                costumers[id].set_balance(costumers[id].get_balance()-50000);
            }

             break;
        }
        case 4:
        {
            int pass;
            cout<<" \n Balance : "<<costumers[id].get_balance()<<" Rial";
            cout<<" \n Enter  Password : ";
            cin>>pass;
            if(hash_func(to_string(pass))!=costumers[id].get_hash_password())
            {
                cout<<" \n Wrong password !";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                _getch();                                                                                      
                user_menu_print(name,id);                                                                                        

            }
            else{
                if(costumers[id].get_balance()<100000)
                {
                    cout<<" \n not enough balance ! ";
                    cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                    _getch();                                                                                      
                    user_menu_print(name,id);                                                                                        

                }
                else

                costumers[id].set_balance(costumers[id].get_balance()-100000);
            }

             break;
        }
        case 5:
        {
            int pass;
            cout<<" \n Balance : "<<costumers[id].get_balance()<<" Rial";
            cout<<" \n Enter  Password : ";
            cin>>pass;
            if(hash_func(to_string(pass))!=costumers[id].get_hash_password())
            {
                cout<<" \n Wrong password !";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                _getch();                                                                                      
                user_menu_print(name,id);                                                                                        

            }
            else{
                if(costumers[id].get_balance()<200000)
                {
                    cout<<" \n not enough balance ! ";
                    cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
                    _getch();                                                                                      
                    user_menu_print(name,id);                                                                                        

                }
                else

                costumers[id].set_balance(costumers[id].get_balance()-200000);
            }

             break;
        }

        }

        cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
        _getch();
        user_menu_print(name,id);
        break;
    }
    //info
    case 4:
    {
        system("cls");
        system("color E4");
        cout<<" \ncard owner name : "<<costumers[id].name;
        cout<<" \ncard number : "<<costumers[id].get_card_id();
        cout<<" \naccount balance : "<<costumers[id].get_balance()<<" Rial";
        
        cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
        _getch();
        user_menu_print(name,id);
        break;
    }
    //change pass
    case 5:
    {
        system("Cls");
        system("Color 16");
        int oldpass,newpass;
        cout<<"\nEnter old password : ";
        cin>>oldpass;
        if(hash_func(to_string(oldpass))!=costumers[id].get_hash_password())
        {
            system("cls");
            cout<<"\nold password was not correct !";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
            _getch();                                                                                      
            user_menu_print(name,id);                                                                                        

        }
        cout<<"\nEnter new password : ";
        cin>>newpass;
        costumers[id].set_hash_password(hash_func(to_string(newpass)));
        cout<<" \n-- password is changed --";
        cout << " \n\n PRESS ANY KEY TO CONTINUE ->";                                                   
        _getch();                                                                                      
        user_menu_print(name,id);                                                                                        
        break;                                                                                          

    }
    case 6:
    {
        menu_print();
    }
    }


}


//________________________________________________________________
void menu_print() {
     system("cls");
     system("color 07");

    cout << "_______________________________\n" << "\n            ATM \n" << "_______________________________\n";
    cout << "\nOPTIONS\n" << " 1- REGISTER \n 2- LOGIN \n ";
    cout << "\n-->";
    cin >> option;

    try
    {
        if (stoi(option) / 1 != stoi(option) || stoi(option) > 2 || stoi(option) < 1)
            throw option;
    }
    catch (...)
    {
        system("cls");
        cout << " \ninvalid input :( \n input should be a number betwean (1-2) \n PRESS ANY KEY TO CONTINUE ->";
        _getch();
        menu_print();
    }
    switch (stoi(option))
    {
        //register
    case 1:
    {
        string name;
        string card;
        int pass;
        system("cls");
        system("color 17");
        cout << "_______________________________\n" << "\n            Register \n" << "_______________________________\n";
        cout<<"\n  Enter your Name: ";
        cin>>name;
        cout<<"\n  Enter your card number (12 digits number only): ";
        cin>>card;
        cout<<"\n  Enter your password (number only) : ";
        cin>>pass;
        bool duplicate =false;
        for(int i=0;i<costumers.size();i++)
        {
            if(costumers[i].get_card_id() == card )
            {
                duplicate =true;
                break;
            }
        }
        if(duplicate)
        {
            cout<<"\n\n  -- card number already exists ! --";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            menu_print();

        }
        else{
            Bank* obj = new Bank(card,pass,name);
            costumers.push_back(*obj);
            int costumer_id = costumers.size()-1;
            cout<<"\n\n  -- DONE --";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            user_menu_print(name,costumer_id);
        }
        break;
    }
    //login
    case 2:
    {   
        int error_count=0;
        int costumer_id;
        string name;
        string card;
        int pass;
        system("cls");
        system("color 20");
        cout << "_______________________________\n" << "\n            LogIn \n" << "_______________________________\n";
        cout<<"Enter card number : ";
        cin>>card;
        cout<<"Enter password : ";
        cin>>pass;
        pass = hash_func(to_string(pass));
        bool valid=0 , pass_valid=0,card_valid=0;
        for(int i=0;i<costumers.size();i++)
        {
            if(costumers[i].get_card_id() == card && (costumers[i].get_hash_password()==pass))
            {
                name = costumers[i].name;
                pass_valid=true;
                card_valid=true;
                valid =true;
                costumer_id=i;
                break;
            }
            else if (costumers[i].get_card_id() == card && !(costumers[i].get_hash_password()==pass))
            {
                card_valid=true;
                costumer_id=i;
                pass_valid=0;
                costumer_id=i;
                break;
            }
            
            card_valid=false;
        }
        if(valid){
            cout<<"\n\n -- Valid input . Done.. --";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            user_menu_print(name,costumer_id);
        }
        else if (!card_valid){
            cout<<"\n\nuser not found ! ";
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            menu_print();

        }
        else if(!pass_valid){
            error_count++;
            cout<<"\n\n Wrong Password ! ";
            cout<<"\nEnter password : ";
            cin>>pass;
            if (costumers[costumer_id].get_hash_password()==pass)
            {
                cout<<"\n\n -- Valid input . Done.. --";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
                _getch();
                user_menu_print(name,costumer_id);

            }
            error_count++;
            cout<<"\n\n Wrong Password ! ";
            cout<<"\nEnter password : ";
            cin>>pass;
            if (costumers[costumer_id].get_hash_password()==pass)
            {
                cout<<"\n\n -- Valid input . Done.. --";
                cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
                _getch();
                user_menu_print(name,costumer_id);

            }
            error_count++;
            cout<<"\n\n Wrong Password ! ";
            cout<<"\n --  Account Has Been Blocked ! --";
            blocks.push_back(costumers[costumer_id]);
            costumers.erase(costumers.begin()+costumer_id);
            cout << " \n\n PRESS ANY KEY TO CONTINUE ->";
            _getch();
            menu_print();

        }

        break;
    }

    }


}


int main(){
    Bank newobj  ("6362141080842012",25637,"Ali");
    Bank newobj2 ("6362141080842098",98728,"mike");
    Bank newobj3 ("6362141080843453",19836,"josh");
    Bank newobj4 ("6362141080845434",17834,"john");
    Bank newobj5 ("6362141080849812",28945,"walter");
    Bank newobj6 ("6362141080841428",98638,"hamond");
    Bank newobj7 ("6362141080842111",14523,"james");
    Bank newobj8 ("6362141080842432",47837,"ron");
    Bank newobj9 ("6362141080848767",47826,"hull");
    Bank newobj10("6362141080849854",37846,"brad");
    Bank aaa("123",123,"hello");

    newobj.set_balance(170000);
    newobj2.set_balance(50000);
    newobj3.set_balance(17000);
    newobj4.set_balance(30000);
    newobj5.set_balance(1700000);
    newobj6.set_balance(230000);
    newobj7.set_balance(120000);
    newobj8.set_balance(10000);
    newobj9.set_balance(450000);
    newobj10.set_balance(760000);

    costumers.push_back(aaa);
    costumers.push_back(newobj);
    costumers.push_back(newobj2);
    costumers.push_back(newobj3);
    costumers.push_back(newobj4);
    costumers.push_back(newobj5);
    costumers.push_back(newobj6);
    costumers.push_back(newobj7);
    costumers.push_back(newobj8);
    costumers.push_back(newobj9);
    costumers.push_back(newobj10);

    menu_print();
}
