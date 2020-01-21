#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
int main(){
	const int high=20;
	const int l=20;
	out:char a[high][l]={ "#####    ",
						  "#   #    ",
						  "# @ # ###",
						  "# @ # #&#",//o=[7][3]
						  "### ###&#",
						  " ##    &#",
						  " # @ #  #",
						  " #  o####",
						  " #####   ", };
	int x=4,y=7,b=1;
	while(1)
	{
		if(a[3][7]==' '){
			a[3][7]='&';
		}
		if(a[4][7]==' '){
			a[4][7]='&';
		}
		if(a[5][7]==' '){
			a[5][7]='&';
		}
		system("cls");
		printf("");
		printf("");
		for(b=0;b<=8;b++){
			puts(a[b]);
		}
		if(a[3][7]=='@'&&a[4][7]=='@'&&a[5][7]=='@'){
			break;
		}
		char d;
		d=getch();
		switch(d){
			case 'r':{
				goto out;
			}
			case 'w':{
				if(a[y-1][x]=='@'&&(a[y-2][x]==' '||a[y-2][x]=='&')){
					a[y-1][x]=' ';
					a[y-2][x]='@';
				}
				if(a[y-1][x]!='#'){
					if((a[y-1][x]=='@'&&a[y-2][x]=='@')||(a[y-1][x]=='@'&&a[y-2][x]=='#')){
						continue;
					}
					a[y][x]=' ';
					y--;
					a[y][x]='o';
				}
				break;
			}
			case 's':{
				if(a[y+1][x]=='@'&&(a[y+2][x]==' '||a[y+2][x]=='&')){
					a[y+1][x]=' ';
					a[y+2][x]='@';
				}
				if(a[y+1][x]!='#'){
					if((a[y+1][x]=='@'&&a[y+2][x]=='@')||(a[y+1][x]=='@'&&a[y+2][x]=='#')){
						continue;
					}
					a[y][x]=' ';
					y++;
					a[y][x]='o';
				}
				break;
			}
			case 'a':{
				if(a[y][x-1]=='@'&&(a[y][x-2]==' '||a[y][x-2]=='&')){
					a[y][x-1]=' ';
					a[y][x-2]='@';
				}
				if(a[y][x-1]!='#'){
					if((a[y][x-1]=='@'&&a[y][x-2]=='@')||(a[y][x-1]=='@'&&a[y][x-2]=='#')){
						continue;
					}
					a[y][x]=' ';
					x--;
					a[y][x]='o';
				}
				break;
			}
			case 'd':{
				if(a[y][x+1]=='@'&&(a[y][x+2]==' '||a[y][x+2]=='&')){
					a[y][x+1]=' ';
					a[y][x+2]='@';
				}
				if(a[y][x+1]!='#'){
					if((a[y][x+1]=='@'&&a[y][x+2]=='@')||(a[y][x+1]=='@'&&a[y][x+2]=='#')){
						continue;
					}
					a[y][x]=' ';
					x++;
					a[y][x]='o';
				}
				break;
			}
		}
	}
	printf("you win");
}

