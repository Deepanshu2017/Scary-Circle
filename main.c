/* 
 * File    :    main.c
 * Author  :    Deepanshu Thakur and Harshit Parakh
 * Version :    1.0
 * Created on October 18, 2014, 2:13 AM
 */

#include<stdio.h>
#include<malloc.h>


struct node  //Declaring a user defined variable named node 
{
    float info;
    struct node *link;
};

int main(int argc, char** argv)
{ 
    
    /*
     * Creating and Initializing variables of type node,integer and float point 
     */
    
    struct node *root,*n,*temp,*k,*p;
    float i=0,j=0,a=0,b=0,c=0,value=0;
    int ch,flag=0;
    
    root=NULL; //Initializing root with NULL
    
    printf("\n**********//// THE MAGIC BEGAINS NOW! ;) ////**********\n");
    printf("\nSuppose these is a monster who kills every nth person standing in a circle\n");
    printf("Suppose you can start a circle of people with any integer number you want!\n");
    
    /*
     * I am supposing that you want to start a circle with number other
     * than 1 but if you want to start a circle with number 1 simply
     * give input of a equal to 1 
     */
    
    printf("So give the staring number\n"); 
    scanf("%f",&a);
    
    /*
     * Now give the end point of the Circle!
     */
    
    
    printf("Now give me the last number of the circle ;)\n");
    scanf("%f",&b);
    
    /*
     * Now in this loop node type variable containing information part and
     * location part (link part) will be initialized with numbers from a to b
     * and the total number of node created will be equal to the total number
     * of inputs!
     */
    
    for(i=a;i<=b;i++)
    {
        n=(struct node *)malloc(sizeof(struct node));
        n->info=i;
        n->link=0;
        
        if(root==0)
        {
            k=n;
            root=n;
        }
        
        else
            temp->link=n;
        temp=n;
    }
    
    
    
    n->link=root;  
    /*
    * With this statement I have made link-list circular!
    * So now starting node have the address of the last node!
    */
    
    
    printf("Please enter the value of the nth person\n");
    scanf("%f",&value); 
    /*
     *This will be the value of n (the person number to be killed)
    */
    
    printf("\n");
    printf("Very good! ;) Keep it You played very well\n");
    printf("Now I will play a game with you\n");
    printf("Choose a position for you before getting the result\n");
    printf("Lets see I wll kill you or you will be the safe person\n");
    scanf("%d",&ch);
    value=value-1;
    c=b-a+1;
    while(c>value)
    {
        for(i=0;i<value;i++)
        {
            if(i==value-1)
            p=root;
            root=root->link; 
        }
        p->link=root->link;
        root=p->link;
        c--;
    }
    
    k=root;
    if(ch==root->info)
    flag=1;
    printf("The value is %0.f\n",root->info);
    root=root->link;
    while(root!=k)
    {
        printf("The value is %0.f\n",root->info);
        if(ch==root->info)
        flag=1;
        root=root->link;
    }
    
    if(flag==1)
        printf("\nMy bad luck you win\n");
    else
        printf("\nYou have eaten by me ;)\n");
    return 0;
}

//end of game
