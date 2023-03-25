#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct items
{
    char a[30][50];
    int qua[30];
    float price[30];
}i;

void add_to_cart(int);
void cart();
void initialize();
void inventory();
void item_display(int flag,int j);
void main_menu();
void bill( );
void welcome();

void initialize()
{
    strcpy(i.a[0],"Butter");
    strcpy(i.a[1],"Bread");
    strcpy(i.a[2],"Peanut Butter");
    strcpy(i.a[3],"Milk");
    strcpy(i.a[4],"Eggs");
    strcpy(i.a[5],"Spices");
    strcpy(i.a[6],"Olive Oil");
    strcpy(i.a[7],"Soft drink");
    strcpy(i.a[8],"Juice");
    strcpy(i.a[9],"Energy drink");
    strcpy(i.a[10],"Flour");
    strcpy(i.a[11],"Tooth Brush");
    strcpy(i.a[12],"Chips");
    strcpy(i.a[13],"Biscuits");
    strcpy(i.a[14],"Pet food");
    strcpy(i.a[15],"Ketchup");
    strcpy(i.a[16],"Mustard");
    strcpy(i.a[17],"Cheese");
    strcpy(i.a[18],"Banana chips");
    strcpy(i.a[19],"Peanuts");
    strcpy(i.a[20],"Brush");
    strcpy(i.a[21],"Jam");
    strcpy(i.a[22],"Pickle");
    strcpy(i.a[23],"Popcorn");
    strcpy(i.a[24],"Snacks");
    strcpy(i.a[25],"Chocolate");
    strcpy(i.a[26],"Cornflakes");
    strcpy(i.a[27],"Battery");
    strcpy(i.a[28],"Mayonnaise");
    strcpy(i.a[29],"Toothpaste");
    i.price[0]=48;
    i.price[1]=30;
    i.price[2]=65;
    i.price[3]=50;
    i.price[4]=7;
    i.price[5]=15;
    i.price[6]=70;
    i.price[7]=25;
    i.price[8]=30;
    i.price[9]=99;
    i.price[10]=80;
    i.price[11]=25;
    i.price[12]=20;
    i.price[13]=10;
    i.price[14]=85;
    i.price[15]=40;
    i.price[16]=45;
    i.price[17]=40;
    i.price[18]=35;
    i.price[19]=30;
    i.price[20]=15;
    i.price[21]=30;
    i.price[22]=45;
    i.price[23]=20;
    i.price[24]=75;
    i.price[25]=20;
    i.price[26]=45;
    i.price[27]=8;
    i.price[28]=25;
    i.price[29]=75;
    for(int j=0;j<30;j++)
        i.qua[j]=0;
}
void main_menu()
{
    int a;
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t  ********* MAIN MENU *********\n");
    printf("\t\t\t\t\t  | 1. Go to INVENTORY        |\n");
    printf("\t\t\t\t\t  | 2. Go to CART             |\n");
    printf("\t\t\t\t\t  | 3. EXIT                   |\n");
    printf("\t\t\t\t\t  *****************************");
    printf("\n\t\t\t\t\t   Enter choice : ");

    label:
    scanf("%d",&a);
    switch(a)
    {
        case 1:inventory();
            break;
        case 2:cart();
            break;
        case 3:exit(0);
            break;
        default:{ printf("\t\t\t\t\t   Enter a valid choice : ");
        goto label; }

    }
}
void inventory()
{
    int n,j,flag;
    char s[25];
    system("cls");
    printf("\n\t\t******INVENTORY******");
    printf("\n\t\t    LIST OF ITEMS\n");
    printf("\n|^^^^^^^|^^^^^^^^^^^^^^^^^^^^^^^|^^^^^^^^^^^^^^^^^^^^^^^|");
    printf("\n| S.NO.\t| NAME       \t\t| PRICE(per piece)      |\n");
    printf("|-------|-----------------------|-----------------------|\n");
    for(j=0;j<15;j++)
    {
        int x;
        for(x=0;i.a[j][x];x++);
        if(x<7)
            printf("| %d.\t| %s       \t\t| Rs %.2f/pc\t\t|\n",j+1,i.a[j],i.price[j]);
        else
            printf("| %d.\t| %s\t\t| Rs %.2f/pc\t\t|\n",j+1,i.a[j],i.price[j]);
    }
    printf("|       |                       |                       |\n");
    printf("| 0.\t| SEARCH FOR MORE       |                       |\n");
    printf("|_______|_______________________|_______________________|\n");
    printf("Enter item number : ");
    label:
    scanf("%d",&n);

    if(n==0)
    {
        int z,flag=0;
        printf("SEARCH : ");
        scanf("%s",&s);
        system("cls");
        for(j=0;j<30;j++)
        {
            z=(strcmp(i.a[j],s));
            if(z==0)
            {
                item_display(1,j);
                flag=1;
                break;
            }

        }
        if(flag==0)
        {
                item_display(0,j);
        }
    }
    else if(n>0 && n<16)
    {
        system("cls");
        item_display(1,n-1);
    }
    else
    {
        printf("Enter a valid choice : ");
        goto label;
    }
}
void item_display(int flag,int j)
{
    int n;
    if(flag==1)
    {
        printf("\n\t\t\tProduct: %s",i.a[j]);
        printf("\n\t\t\tPrice: %.2f\n\n",i.price[j]);
        printf("|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|^^^^^^^^^^^^^^^^^^^^^^^|\n");
        printf("|\tADD TO CART\t\t\t|\tPRESS 1\t\t|\n");
        printf("|\tReturn to INVENTORY\t\t|\tPRESS 2\t\t|\n");
        printf("|\tReturn to MAIN MENU\t\t|\tPRESS 3\t\t|\n");
        printf("|\tCheck CART\t\t\t|\tPRESS 4\t\t|\n");
        printf("|_______________________________________|_______________________|\n");
        label:
        scanf("%d",&n);
        switch(n)
        {
            case 1:add_to_cart(j);
                break;
            case 2:inventory();
                break;
            case 3:main_menu();
                break;
            case 4:cart();
            default:{ printf("Enter a valid choice : ");
                    goto label; }
        }

    }
    else if(flag==0)
    {
        printf("NOT AVAILABLE\n");
        printf("Returning to INVENTORY");
        getch();
        system("cls");
        inventory();
    }
}
void add_to_cart(int j)
{
    system("cls");
    int q,n;
    printf("\n\t\t\tProduct: %s\n\t\t\tPrice: %.2f\n\n\t\t Enter quantity: ",i.a[j],i.price[j]);
    scanf("%d",&q);
    i.qua[j] += q;
    printf("\n\n1.Go To Cart\n2.Go To INVENTORY\n3.Go To Main Menu\n");
    label:
    scanf("%d",&n);
    switch(n)
    {
        case 1:cart();
            break;
        case 2:inventory();
            break;
        case 3:main_menu();
            break;
        default:{ printf("Enter a valid choice : ");
                goto label; }
    }
}
void cart()
{
    system("cls");
    printf("\n\t\t\tCART\n");
    int l=1,n;
    printf("\n _______ _______________________ _______________ _______________");
    printf("\n| S.No\t| Product\t\t| Price(in Rs)\t| Quantity\t|");
    printf("\n|-------|-----------------------|---------------|---------------|");
    for(int k=0;k<30;k++)
    {
        if(i.qua[k]!=0)
        {
            int ll=0;
            for(ll;i.a[k][ll]!='\0';ll++);
            if(ll<7)
                printf("\n| %d.\t| %s  \t\t| %.2f\t\t| %d\t\t|",l,i.a[k],i.price[k],i.qua[k]);
            else
                printf("\n| %d.\t| %s\t\t| %.2f\t\t| %d\t\t|",l,i.a[k],i.price[k],i.qua[k]);
            l++;
        }
    }
    printf("\n|_______|_______________________|_______________|_______________|");
    printf("\n\n1.Go To INVENTORY\n2.Go To Main Menu\n3.Go to BILL\n");
    label:
    scanf("%d",&n);
    switch(n)
    {
        case 1:inventory();
            break;
        case 2:main_menu();
            break;
        case 3:bill();
            break;
        default:{ printf("Enter a valid choice : ");
                goto label; }
    }
}

void bill()
{
    system("cls");
    int l=1;
    float fee,total=0,subtotal=0,sum=0;
    printf("\t\t\t\t\t BILL\n");
    printf("\n*********************************************************************************************************");
    printf("\n*  S.No\t Product\t Price\t Quantity\t Subtotal\t Convenience Fee\t Total\t\t*");
    printf("\n*                                                                                                       *");
    for(int k=0;k<30;k++)
    {
        if(i.qua[k]!=0)
        {
             subtotal=(i.price[k]*i.qua[k]);
             fee=0.025*subtotal;
             total=subtotal+fee;

            int ll=0;
            for(ll;i.a[k][ll]!='\0';ll++);
            if(ll<7)
                printf("\n*  %d.\t %s\t\t %.2f\t %d\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t*",l,i.a[k],i.price[k],i.qua[k],subtotal,fee,total);
            else
                printf("\n*  %d.\t %s\t %.2f\t %d\t\t %.2f\t\t %.2f\t\t\t %.2f\t\t*",l,i.a[k],i.price[k],i.qua[k],subtotal,fee,total);
            l++;
            sum=sum+total;
        }
    }
    printf("\n*                                                                                                       *");
    printf("\n*********************************************************************************************************");
    printf("\n\t\t\t\t\t\t\t\t\t  Convenience Fee: 2.5%%");
    printf("\n\n\t\t\t\t\t\t\t\t\t  Total Amount = %.2f Rs.",sum);
    getch();
    printf("\n\n\n\n\t\t\t\tThanks For Shopping With Us!!");
    getch();
    exit(0);
}
void welcome()
{
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t   Welcome to \n");
    printf("\n\t\t\t\t   ###    ##   ##    ###    #####  ####  ##    #");
    printf("\n\t\t\t\t  #   #   # # # #   #   #      #  #    # # #   #");
    printf("\n\t\t\t\t #######  #  #  #  #######    #   #    # #  #  #");
    printf("\n\t\t\t\t#       # #     # #       #  #    #    # #   # #");
    printf("\n\t\t\t\t#       # #     # #       # #####  ####  #    ## (III copy)");
    printf("\n\t\t\t\t                        _ _ _ _");
    printf("\n\t\t\t\t  **                        **/");
    printf("\n\t\t\t\t    ***                   ** /");
    printf("\n\t\t\t\t       *****         *****  /");
    printf("\n\t\t\t\t            *********");
    getch();
    system("cls");
}

void main()
{
    welcome();
    initialize();
    main_menu();
}
