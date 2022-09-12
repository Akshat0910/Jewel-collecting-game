#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include <cstdlib>

using namespace std;

/* 
    
       INSTRUCTION
       1.A -- Move Left
       2.D -- Move right 
       3.S -- Move down
       4.W -- Move up
       5.Q -- Quit
   
*/

int boundary(int x,int y,int *posx,int *posy,int *enx,int *eny,int moves,int *energy,int *jewel,int *newgm,int h,int l){
    int i,j;
    for(i=-1;i<=h;i++){                                  // for height of box
        for(j=-1;j<=l;j++){                             // for width of box
            if(i==-1 || i==h || j==-1 ||j==l) {        
                 cout<<"#";
            }
            else{
                if(i==y && j==x )
                {
                	cout<<"P";
                	for(int k=0;k<4;k++)
					{
                		if(posx[k]==x && posy[k]==y){
                			posx[k]=-1;
                			posy[k]=-1;
                			(*jewel)++;
                			(*newgm)++;
						}
					}
						for(int k=0;k<2;k++)
					{
                		if(enx[k]==x && eny[k]==y){
                			enx[k]=-1;
                			eny[k]=-1;
                			(*energy)+=10;
						}
					}
				
					
				}
                
                else{
                    if(i==posy[0] && j==posx[0])
                    cout<<"J";
                    else if(i==posy[1] && j==posx[1])
                    cout<<"J";
                    else if(i==posy[2] && j==posx[2])
                    cout<<"J";
                    else if(i==posy[3] && j==posx[3])
                    cout<<"J";
                    else if(j==enx[0] && i==eny[0])
                    cout<<"E";
                    else if(j==enx[1] && i==eny[1])
                    cout<<"E";
                    else
                    cout<<" ";
            }
            }    
        }
        cout<<"\n";
    }
    
    cout<<"\n\nNUMBER OF MOVES:"<<moves<<endl;
    cout<<"ENERGY LEFT:"<<*energy<<endl;
    cout<<"NUMBER OF JEWEL:"<<*jewel<<endl;
    
    return 0;
}


int movement(int *x,int *y,char key,int *moves, int *energy,int *flag,int h,int l){                                // movement of player
 
    static int step=0;
    	if(step ==5){
    		step=0;
    		(*energy)--;
    		cout<<step;
		}
    
    switch(key){
    	
    	

        case 'a':                      if((*x)!=0)
                                        {
                                        	(*x)--;
                                             (*moves)++;  
                                             step++;
										}
										break;
        case 'd':                      if(*(x)!=l-1)
                                        {
                                        	(*x)++;
                                        	(*moves)++;
                                        	step++;
										} 
                                        break;
        case 's':                       if((*y)!=h-1)
                                         {
                                         	(*y)++;
                                         	(*moves)++;
                                         	step++;
										 } 
                                        break;
        case 'w':                       if((*y)!=0)
                                        {
                                        	(*y)--;
                                        	(*moves)++;
                                        	step++;
									    }
                                        break;
        case 'q':                       
                                        *flag = 1;
                                        break;  

    }
    return 0;
}
 
int main(){

    system("cls");

    int x=0,y=0;                      // position of person
    int h = 10, l = 50;
    int jewelx[4]={0};                // x coordinate of jewel
    int jewely[4]={0};                // y coordinate of jewel

    srand(time(0));

    for(int i=0;i<4;i++){
        jewelx[i] = rand()%l;         
        jewely[i] = rand()%h;
    }
    int energyx[2]={0};                // x coordinate of energy
    int energyy[2]={0};                // y coordinate of energy

    for(int i=0;i<2;i++){
        energyx[i] = rand()%l;
        energyy[i] = rand()%h;

    }
    int moves=0,energy = 10;
    int jewel = 0;
    int newgm = 0;
    int flag = 0;
 
    boundary(x,y,jewelx,jewely,energyx,energyy,moves,&energy,&jewel,&newgm,h,l);
    char ch;
    while (1)
    {
        if(kbhit()){
            system("cls");
            ch = getch();
            movement(&x,&y,ch,&moves,&energy,&flag,h,l);
            if(flag==1 || energy<=0)
			{
				cout<<"!!!!!THANKS FOR PLAYING!!!!!"<<endl;
                cout<<"TOTAL JEWELS COLLECTED:"<<jewel<<endl;
                cout<<"NO. OF MOVES:"<<moves<<endl;
				
				
                break;	
			}
            boundary(x,y,jewelx,jewely,energyx,energyy,moves,&energy,&jewel,&newgm,h,l);
            if(newgm == 4)
            {
            	newgm=0;
            	h=h+5;
            	l=l+5;
            	 for(int i=0;i<4;i++)
				 {
            	 	
                   jewelx[i] = rand()%l;         
                   jewely[i] = rand()%h;
                 }
                 
                 for(int i=0;i<2;i++)
				 {
				 	
                  energyx[i] = rand()%l;
                  energyy[i] = rand()%h;

                 }
            	
			}

        }
    }
    

    

      getch();
      return 0;

}
