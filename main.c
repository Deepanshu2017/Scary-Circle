/*
 * File    :    main.c
 * Author  :    Deepanshu Thakur
 * Author  :    Harshit Parakh
 * Version :    1.0
 * Created on October 18, 2014, 2:21 AM
 */


/*
 * This is a doubly circular link-list!
 */


#include<stdio.h>
#include<malloc.h>


struct node   //Declaring a user defined variable named node
{
    float info;
    struct node *link;
    struct node *link2;
};

int main(int argc, char** argv)
{

    float Test_cases=0;

    printf("\n**********//// THE MAGIC BEGAINS NOW! ;) ////**********\n");

    printf("Enter how many times you want to run program: ");
    scanf("%f",&Test_cases);
    while(Test_cases--){

   /*
    * Creating and Initializing variables of type node,integer and float point
    */

    struct node *root,*n,*temp,*k,*p;
    float i=0, j=0, Starting_Value=0, Last_Value=0, Choosen_Value=0, Per_Value=0;
    int My_Choice=0,Clock_Choice=0, flag=0;

    root=NULL; //Initializing root with NULL

    printf("\nSuppose these is a monster who kills every nth person standing in a circle\n");
    printf("Suppose you can start a circle of people with any integer number you want!\n");

    /*
     * I am supposing that you want to start a circle with number other
     * than 1 but if you want to start a circle with number 1 simply
     * give input of a equal to 1
     */

    printf("So give the staring number\n");
    scanf("%f",&Starting_Value);

    /*
     * Now give the end point of the Circle!
     */


    printf("Now give me the last number of the circle ;)\n");
    scanf("%f",&Last_Value);

    /*
     * Now in this loop node type variable containing information part and
     * location part (link part) will be initialized with numbers from a to b
     * and the total number of node created will be equal to the total number
     * of inputs!
     */

    for(i=Starting_Value; i<=Last_Value; i++)
    {
        n=(struct node *)malloc(sizeof(struct node));
        n->info=i;
        n->link=NULL;
        if(root==NULL)
        {
            root=n;
            root->link2=NULL;
        }
        else
	{
            n->link2=temp;
            temp->link=n;
        }
        temp=n;
    }

    root->link2=n;
    n->link=root;

    /*
     * With these statements I have made link-list circular!
     * So now starting node have the address of the last node!
     */


    printf("Please enter the value of the nth person\n");
    scanf("%f",&Per_Value);

    /*
     * This will be the value of n (the person number to be killed)
     */

    printf("\n");

    printf("How you want monster to kill person..?\n");
    printf("Press: \n");
    printf("1. Clockwise \n");
    printf("2. Anti-clockwise \n");
    printf("Enter your choice:\n");
    scanf("%d",&Clock_Choice);

    /*
     * This will be the value which decide the loop will run Clockwise
     * or Anti-Clockwise
     */

    printf("Very good! Keep it up. You played very well\n");
    printf("The game is not yet over !!\n");
    printf("Choose a position for you in the circle \n");
    printf("Lets see I will kill you or you will be the safe person\n");

    scanf("%d",&My_Choice);
    Per_Value = Per_Value-1;
    Choosen_Value = Last_Value-Starting_Value+1;


    if(Clock_Choice==2)
    {
        while(Choosen_Value > Per_Value)
        {
            for(i=0; i<Per_Value; i++)
            {
                if(i == Per_Value-1)
                	p=root;
                root = root->link2;
            }
            p->link2 = root->link2;
            root = p->link2;
            Choosen_Value--;
        }

        k = root;
        if(My_Choice == root->info)
        	flag=1;
        printf("The value is %0.f\n",root->info);
        root = root->link2;
        while(root!=k)
        {
            printf("The value is %0.f\n",root->info);
            if(My_Choice==root->info)
        	flag=1;
            root=root->link2;
        }
    }

    else
    {
        while(Choosen_Value > Per_Value)
        {
            for(i=0; i<Per_Value; i++)
            {
                if(i==Per_Value-1)
                    p=root;
                root=root->link;
            }
            p->link=root->link;
            root=p->link;
            Choosen_Value--;
        }

        k=root;
        if(My_Choice==root->info)
           flag=1;
        printf("The value is %0.f\n",root->info);
        root=root->link;
        while(root!=k)
        {
            printf("The value is %0.f\n",root->info);
            if(My_Choice==root->info)
                flag=1;
            root=root->link;
        }
    }


    if(flag==1)
        printf("\nMy bad luck you win\n");
    else
        printf("\nYou have eaten by me\n");
    free(n);
    }
    printf("GAME OVER");
    printf("Thanks for playing and showing your intrest!");
    return 0;
}

//end of game!
