#include<stdio.h>
#include<string.h>

struct store
{
    char itemname[200];
    char price[100];
    int quantity;
    char pacdate[20];
    char expdate[20];
    int shelfnumber;
};

struct store gs[500];

int total=0; //This global variable counts the number of items in stock

void welcome();
void menu();
void input_item();
void edit();
void display();
void isearch();
void del();
void add_item();
void write_to_file();
void read_from_file();
void exit();


int main()
{
    read_from_file();

    system("color 3b");
    welcome();
    printf("\n\n\t\t\t\tPress any key to continue");
    getch();
    menu();
}

void welcome()
{
    printf("\n\t\t   =====================================================       ");
    printf("\n\t\t      -----               WELCOME               -----          ");
    printf("\n\t\t      --------              TO               --------          ");
    printf("\n\t\t      ---     GROCERY STORE MANAGEMENT SYSTEM     ---          ");
    printf("\n\t\t   ===================================================== \n\n\n\n");
}

void menu()
{
    system("cls");
    printf("\n\n\t\t\t\t====== MAIN MENU ======\n\n\n\n\n\n");

    printf("\t\t\tPress 1 to Input Item\n");
    printf("\t\t\tPress 2 to Edit Item Info.\n");
    printf("\t\t\tPress 3 to Display Stock\n");
    printf("\t\t\tPress 4 to Add an Item\n");
    printf("\t\t\tPress 5 to delete an Item\n");
    printf("\t\t\tPress 6 to search for an Item info.\n");
    printf("\n\n\n\n\n\n\t\tPRESS 0 TO SAVE THE IFORMATIONS and EXIT FROM THE PROGRAM\n\n\t\t\t\t\t");

    int n,i;

    scanf("%d",&n);
    switch(n)
    {
        case 1:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tEnter 1 to Input Item and 0 to return to Main Menu\n\n\t\t\t\t\t\t");
            scanf("%d",&i);
            if(i!=0){ system("cls"); input_item();break;}
            else {system("cls");menu();break;}
        case 2:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tEnter 1 to Edit Item Information and 0 to return to Main Menu\n\n\t\t\t\t\t\t");
            scanf("%d",&i);
            if(i!=0){ system("cls");edit();break;}
            else {system("cls"); menu();break;}
        case 3:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tEnter 1 to Display Stock and 0 to return to Main Menu\n\n\t\t\t\t\t\t");
            scanf("%d",&i);
            if(i!=0){system("cls");display();break;}
            else {system("cls");menu();break;}
        case 4:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tEnter 1 to Add an Item and 0 to return to Main Menu\n\n\t\t\t\t\t\t");
            scanf("%d",&i);
            if(i!=0){system("cls");add_item();break;}
            else {system("cls");menu();break;}
        case 5:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tEnter 1 to DELETE an Item and 0 to return to Main Menu\n\n\t\t\t\t\t\t");
            scanf("%d",&i);
            if(i!=0){system("cls");del();break;}
            else {system("cls");menu();break;}
        case 6:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\t\t\tEnter 1 to search for an Item info. and 0 to return to Main Menu\n\n\t\t\t\t\t\t");
            scanf("%d",&i);
            if(i!=0){system("cls");isearch();break;}
            else {system("cls");menu();break;}
        case 0:
            write_to_file();
            exit();
            break;
        default:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!Invalid input!!!\n\n\t\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
            getch();
            menu();
            break;

    }
}

void input_item()
{
    system("cls");
    printf("\n\t\t\t\t====== INPUT MENU ======\n\n\n");

    printf("\n\n\n\t\t\tEnter Item Name %d: ",total+1);
    scanf("%s",&gs[total].itemname);
    printf("\n\t\t\tEnter Price %d: ",total+1);
    scanf("%s",&gs[total].price);
    printf("\n\t\t\tEnter Quantity %d: ",total+1);
    scanf("%d",&gs[total].quantity);
    printf("\n\t\t\tEnter Packaging Date %d: ",total+1);
    scanf("%s",&gs[total].pacdate);
    printf("\n\t\t\tEnter Expire Date %d: ",total+1);
    scanf("%s",&gs[total].expdate);
    printf("\n\t\t\tEnter Shelf Number %d: ",total+1);
    scanf("%d",&gs[total].shelfnumber);

    total++;

    int n;

    printf("\n\n\n\n\n\n\t\tEnter 0 to return to Main Menu or 1 to Add another Item Info.\n ");
    scanf("%d",&n);

    if(n==1)
    {
        system("cls");
        input_item();
    }
    else if(n==0)
    {
        system("cls");
        menu();
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!Invalid input!!!\n\n\t\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
        getch();
        system("cls");
        menu();

    }

}

void edit()
{
    system("cls");
    printf("\n\n\t\tEnter the item number you want to edit: ");

    int i;
    scanf("%d",&i);

    if(total==0)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!!There is no item to edit!!!\n\n\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
        getch();
        menu();
    }

    else if(i>total)
    {

        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t!!!There isn't any item of that number!!!\n\n\t\t\t\t\tPress any key to go back\n\t\t\t\t\t\t");
        getch();
        edit();

    }
    else
    {
       system("cls");

       int j=i-1;

       printf("\n\n\n\n\t\t\tEnter 1 to change name of item %d\n",i);
       printf("\n\t\t\tEnter 2 to change price of item %d\n",i);
       printf("\n\t\t\tEnter 3 to change quantity of %d\n",i);
       printf("\n\t\t\tEnter 4 to change packaging date of item %d\n",i);
       printf("\n\t\t\tEnter 5 to change expire date of item %d\n",i);
       printf("\n\t\t\tEnter 6 to change shelf number of item %d\n\t\t\t",i);

       int k;
       scanf("%d",&k);

       switch(k)
       {
         case 1:
                    system("cls");
                    printf("\n\n\n\tEnter the name of item %d: ",i);
                    scanf("%s",&gs[j].itemname);
                    break;

         case 2:
                    system("cls");
                    printf("\n\n\tEnter the price of item %d: ",i);
                    scanf("%s",&gs[j].price);
                    break;

         case 3:
                    system("cls");
                    printf("\n\n\tEnter the quantity of item %d: ",i);
                    scanf("%d",&gs[j].quantity);
                    break;

         case 4:
                    system("cls");
                    printf("\n\n\tEnter the packaging date of item %d: ",i);
                    scanf("%s",&gs[j].pacdate);
                    break;

         case 5:
                    system("cls");
                    printf("\n\n\tEnter the expire date of item: ",i);
                    scanf("%s",&gs[j].expdate);
                    break;

         case 6:
                    system("cls");
                    printf("\n\n\tEnter the shelf number of item %d: ",i);
                    scanf("%d",&gs[j].shelfnumber);
                    break;

         default:   system("cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!Invalid input!!!\n\n\t\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
                    getch();
                    menu();
                    break;
        }

    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThe item info has been edited successfully\n\t\t\t\t\t\t");
    getch();
    menu();
}

void display()
{
    system("cls");
    printf("\n\tIf you want to see a particular item info. enter 1 Or enter 0 to see all item info.: ");

    int i;
    scanf("%d",&i);

    if(total==0)
    {
           system("cls");
           printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!!There is no item to display!!!\n\n\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
           getch();
           menu();
    }
    else if(i==0)
    {
        system("cls");
        int k,q;

        printf("\n\n\n\t\t\t\tTotal Number of items = %d\n\n\n",total);

        for(k=0;k<total;k++)
        {

            printf("\n\n\n\t\t\t\t%d.\n\n\t\t\t\t\tItem name: %s",k+1,gs[k].itemname);
            printf("\n\t\t\t\t\tPrice: %s",gs[k].price);
            printf("\n\t\t\t\t\tQuantity: %d",gs[k].quantity);
            printf("\n\t\t\t\t\tPackaging Date: %s",gs[k].pacdate);
            printf("\n\t\t\t\t\tExpire Date: %s",gs[k].expdate);
            printf("\n\t\t\t\t\tShelf Number: %d",gs[k].shelfnumber);

        }
    }
    else
    {
        OUT:
        system("cls");
        printf("\n\tEnter the item number you want to see: ");

        int j,n;
        scanf("%d",&n);

        if(n>total)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!Invalid input!!!\n\n\t\t\t\t\tPress any key to go back\n\t\t\t\t\t\t");
            getch();
            goto OUT;
        }

        j=n-1;

        printf("\n\n\n\t\t\t\t%d.\n\n\t\t\t\t\tItem name: %s",n,gs[j].itemname);
        printf("\n\t\t\t\t\tPrice: %s",gs[j].price);
        printf("\n\t\t\t\t\tQuantity: %d",gs[j].quantity);
        printf("\n\t\t\t\t\tPackaging Date: %s",gs[j].pacdate);
        printf("\n\t\t\t\t\tExpire Date: %s",gs[j].expdate);
        printf("\n\t\t\t\t\tShelf Number: %d",gs[j].shelfnumber);
    }

    printf("\n\n\n\n\n\n\n\n\t\t\tEnter 0 to return to menu or 1 to display stock: ");

    int m;
    scanf("%d",&m);

    if(m==0)
    {
        menu();
    }
    else if(m==1)
    {
     display();
    }
    else
    {
       system("cls");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!Invalid input!!!\n\n\t\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
       getch();
       menu();
    }
}

void del()
{
    system("cls");
    printf("\n\n\n\tEnter the item number you want to delete: ");

    int d,i,j;
    scanf("%d",&d);

    if(total==0)
        {
           system("cls");
           printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!!There is no item left to delete!!!\n\n\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
           getch();
           menu();
        }
    else if(d>total)
        {
           system("cls");
           printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!!There isn't any item of that number!!!\n\n\t\t\t\tPress any key to go back\n\t\t\t\t\t\t");
           getch();
           del();
        }

    else{

            for(i=d;i<total;i++)
            {
                gs[i-1]=gs[i];
            }
            total--;

            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tThe item has been deleted successfully\n\n\t\t\t\tPress any key to go back to the main menu\n\t\t\t\t\t\t");
            getch();
            menu();
        }

}


void add_item()
{
    system("cls");
    printf("\n\n\tEnter the position where you want to add a new item: ");

    int a,i;
    scanf("%d",&a);

    if(a>total)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t!!!You can't add an item into that position!!!\n\n\t\t\t\tPress any key to go back\n\t\t\t\t\t\t");
            getch();
            add_item();
        }
    else{

          for(i=total;i>=a;i--)
          {
             gs[i]=gs[i-1];
          }

          total++;

        }

     int j=a-1;

    printf("\n\n\n\t\t\tEnter Item Name %d: ",a);
    scanf("%s",&gs[j].itemname);
    printf("\n\t\t\tEnter Price %d: ",a);
    scanf("%s",&gs[j].price);
    printf("\n\t\t\tEnter Quantity %d: ",a);
    scanf("%d",&gs[j].quantity);
    printf("\n\t\t\tEnter Packaging Date %d: ",a);
    scanf("%s",&gs[j].pacdate);
    printf("\n\t\t\tEnter Expire Date %d: ",a);
    scanf("%s",&gs[j].expdate);
    printf("\n\t\t\tEnter Shelf Number %d: ",a);
    scanf("%d",&gs[j].shelfnumber);

     getch();
     menu();
}


void isearch()
{
    system("cls");

    char siname[200];
    int i,j,k,counter=0;

    printf("\n\t\tType the item name you wish to search: ");
    scanf("%s",&siname);

    j = strlen(siname);

    for(i=0;i<total;i++)
    {
        if(j == strlen(gs[i].itemname))
        {
            for(k=0;k<=j;k++)
                {
                    if (siname[k] == gs[i].itemname[k])
                            {

                                counter++;

                                if(counter == j)
                                {
                                    printf("\n\n\n\t\t\t\t%d.\n\n\t\t\t\t\tItem name: %s",i+1,gs[i].itemname);
                                    printf("\n\t\t\t\t\tPrice: %s",gs[i].price);
                                    printf("\n\t\t\t\t\tQuantity: %d",gs[i].quantity);
                                    printf("\n\t\t\t\t\tPackaging Date: %s",gs[i].pacdate);
                                    printf("\n\t\t\t\t\tExpire Date: %s",gs[i].expdate);
                                    printf("\n\t\t\t\t\tShelf Number: %d",gs[i].shelfnumber);

                                }

                            }
                }
        }

    }

    int n;

    printf("\n\n\n\t\tEnter 1 to search for another item or 0 to return to the Main Menu: ");
    scanf("%d",&n);

    if(n==1)
    {
        isearch();
    }
    else if(n==0)
    {
        menu();
    }
    else
    {
       system("cls");
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t!!!Invalid input!!!\n\n\t\t\t\tPress any key to go back to the Main Menu\n\t\t\t\t\t\t");
       getch();
       menu();
    }

}

void write_to_file()
{
    FILE *fp;
    fp = fopen("grocery store.txt","w");

    int i;

    fprintf(fp,"\n\n%d\n\n",total);

    for(i=0;i<total;i++)
    {

        fprintf(fp,"\n%s\n",gs[i].itemname);
        fprintf(fp,"\n%s\n",gs[i].price);
        fprintf(fp,"\n%d\n",gs[i].quantity);
        fprintf(fp,"\n%s\n",gs[i].pacdate);
        fprintf(fp,"\n%s\n",gs[i].expdate);
        fprintf(fp,"\n%d\n",gs[i].shelfnumber);

    }

    fclose(fp);

    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tItem informations were saved successfully\n\n\t\t\t\t\t");
    getch();
}

void read_from_file()
{
    FILE *fp;
    fp = fopen("grocery store.txt","r");

    int i;
    fscanf(fp,"%d",&total);

    for(i=0;i<total;i++)
    {
        fscanf(fp,"%s",&gs[i].itemname);
        fscanf(fp,"%s",&gs[i].price);
        fscanf(fp,"%d",&gs[i].quantity);
        fscanf(fp,"%s",&gs[i].pacdate);
        fscanf(fp,"%s",&gs[i].expdate);
        fscanf(fp,"%d",&gs[i].shelfnumber);

    }

    fclose(fp);
}
