//Latifa
//ID : 160040002
///-------------///
///-------------///
///Logged Tasks ///

void logged_in(){
    system("cls");
    cout<<"\n\t\t------[START NEW GAME]------\n";
    cout<<"\n\t\t          Resume\n";
    cout<<"\n\t\t        View Scores\n";
    cout<<"\n\t\t          Settings\n";
    cout<<"\n\t\t          Sign Out\n\n\t\t\t";

    choice = getch();

    if(choice=='W' || choice=='w'){
        sign_out();
        return;
    }
    else if(choice=='S' || choice=='s'){
        resume();
        return;
    }
    else if(choice==13){

        system("cls");
         cout<<"+--------------------------------+";
         cout<<"\n|             WARNING!          |";
         cout<<"\n|            ---------          |";
         cout<<"\n+--------------------------------+";

         cout<<"\n\nThis option clears all your game  data!";
         cout<<"\nEnter 'Y' for yes or any key to cancel:\n\n\t\t  ";

        choice=getche();
        if(choice=='Y' || choice=='y')
        {
            player[logged_in_id].points=0;
            for(k=0; k<player[logged_in_id].num_qn; k++)
            {
                player[logged_in_id].questions_answered[k]=0;
            }
            player[logged_in_id].num_qn = 0;
            save_data();
             cout<<"\n\n\t    DATA CLEARED\n\n\t\t  ";
            choice=getch();
            resume();
            return;
        }
        else
        {
            resume();
            return;
        }

    }else{
        logged_in();
        return;
    }
}

void resume(){

    system("cls");
     cout<<"\n\t\t       Start New Game\n";
     cout<<"\n\t\t--------[ RESUME ]---------\n";
     cout<<"\n\t\t        View Scores\n";
     cout<<"\n\t\t          Settings\n";
     cout<<"\n\t\t          Sign Out\n\n\t\t";
    choice=getch();

    if(choice=='W' || choice=='w')
    {
        logged_in();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        view_scores();
        return;
    }else if(choice==13){
        play(false);
        resume();
        return;
    }

    else{
        resume();
        return;
    }

}

void view_scores(){

    system("cls");
     cout<<"\n\t\t       Start New Game\n";
     cout<<"\n\t\t          Resume  \n";
     cout<<"\n\t\t------[ VIEW SCORES ]------\n";
     cout<<"\n\t\t          Settings\n";
     cout<<"\n\t\t          Sign Out\n\n\t\t";
    choice=getch();

    if(choice=='W' || choice=='w')
    {
        resume();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        settings();
        return;
    }else if(choice == 13){
        load_data();
        system("cls");
         cout<<"+-----------------------------------+";
         cout<<"\n|            YOUR SCORES            |";
         cout<<"\n|           -------------           |";
         cout<<"\n+-----------------------------------+";


         cout<<"\n\n   TOTAL  POINTS        :  " << player[logged_in_id].points;
         cout<<"\n   No.    OF QUESTIONS  :  "<<player[logged_in_id].num_qn<<"\n\n\t\t";
        choice = getch();
        resume();
        return;
    }else{
        view_scores();
        return;
    }

}

void settings(){

    system("cls");
     cout<<"\n\t\t       Start New Game\n";
     cout<<"\n\t\t          Resume  \n";
     cout<<"\n\t\t        View Scores\n";
     cout<<"\n\t\t--------[ SETTINGS ]--------\n";
     cout<<"\n\t\t          Sign Out\n\n\t\t";

    choice=getch();
    if(choice=='W' || choice=='w')
    {
        view_scores();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        sign_out();
        return;
    }else if(choice == 13){

SETTINGS:
        load_data();
        system("cls");
         cout<<"+-----------------------------------+";
         cout<<"\n|             SETTINGS              |";
         cout<<"\n|           -------------           |";
         cout<<"\n+-----------------------------------+";
         cout<<"\n\n  1. CHANGE SECRET KEY ";
         cout<<"\n  2. RESTORE ACCOUNT ";
         cout<<"\n  3. DELETE THIS ACCOUNT";
         cout<<"\n  4. BACK\n\n\t\t";

        do{
            choice = getch();
        }while(choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != 27);

        if(choice == '1'){
            system("cls");
             cout<<"+-----------------------------------+";
             cout<<"\n|        ENTER  NEW  SECRET KEY     |";
             cout<<"\n|           -------------           |";
             cout<<"\n+-----------------------------------+\n\n\t";
            gets(player[logged_in_id].key);
            save_data();
             cout<<"\n\nYour Key was updated to[ " << player[logged_in_id].key << "] successfully!\n\n\t\t";
            choice = getch();
            goto SETTINGS;
        }
        else if(choice == '2'){


            system("cls");
            cout<<"+--------------------------------+";
            cout<<"\n|             WARNING!            |";
            cout<<"\n|            ----------           |";
            cout<<"\n+--------------------------------+";

            cout<<"\n\nThis option clears all your game's  data!";
            cout<<"\nEnter 'Y' for Yes or any key to cancel:\n\n\t\t  ";

            choice=getche();
            if(choice=='Y' || choice=='y')
            {
                player[logged_in_id].points=0;
                for(k=0; k<player[logged_in_id].num_qn; k++)
                {
                    player[logged_in_id].questions_answered[k]=0;
                }
                player[logged_in_id].num_qn = 0;
                save_data();
                cout<<"\n\n\t    DATA CLEARED\n\n\t\t  ";
                choice=getch();
                goto SETTINGS;
            }
            else
            {
                goto SETTINGS;
            }

        }else if(choice == '3'){

            system("cls");
            cout<<"+--------------------------------+";
            cout<<"\n|             WARNING!            |";
            cout<<"\n|            ----------           |";
            cout<<"\n+--------------------------------+";

            cout<<"\n\nAre you sure you want to DELETE this account?";
            cout<<"\nEnter 'Y' for Yes or any key to cancel:\n\n\t\t  ";

            choice=getche();
            if(choice=='Y' || choice=='y')
            {
                player[logged_in_id].display=0;
                save_data();
                load_data();
                cout<<"\n\n\t    Account Deleted\n\n\t\t  ";
                choice=getch();
                demo();
                return;
            }
            else
            {
                goto SETTINGS;
            }

        }else{
            settings();
            return;
        }
    }else{
        settings();
        return;
    }

}

void sign_out(){
    system("cls");
    cout<<"\n\t\t       Start New Game\n";
    cout<<"\n\t\t          Resume  \n";
    cout<<"\n\t\t        View Scores\n";
    cout<<"\n\t\t          Settings\n";
    cout<<"\n\t\t--------[ SIGN OUT ]---------\n\n\t\t";
    choice=getch();



    if(choice=='W' || choice=='w')
    {
        settings();
        return;
    }
    else if(choice=='S' || choice=='s')
    {
        logged_in();
        return;
    }else if(choice == 13){

            system("cls");
            cout<<"+--------------------------------+";
            cout<<"\n|             WARNING!            |";
            cout<<"\n|            ----------           |";
            cout<<"\n+--------------------------------+";

            cout<<"\n\nAre you sure you want to sign out?!";
            cout<<"\nEnter 'Y' for Yes or any key to cancel:\n\n\t\t  ";

            choice=getche();
            if(choice=='Y' || choice=='y')
            {
                demo();
                return;
            }
            else
            {
                sign_out();
                return;
            }

    }else{
        sign_out();
        return;
    }
}


///-------------///
///-------------///

