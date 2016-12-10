#include<stdio.h>
#include<stdlib.h>




/////////// world definition //////////////////////////////////////////////////

	struct world
	{
		int a[200][200],b[200][200];
		int w,l;
		int birth[9];
		int surv[9];
	};
	typedef struct world world;





//////////////////////////////////////////////////////////////////////////////
///////////// seeder ////////////////////////////////////////////////////////


	int seeder(world *x)
	{	
		int i,j,k,ww,ll;
		ww=x->w;
		ll=x->l;
		k=0;
		char c[10000];
		scanf("%s",c);
		for(i=0;i<ll;i++)
		for(j=0;j<ww;j++)
		{	if(c[k]=='.')x->a[i][j]=0;
			else x->a[i][j]=1;
			k++;
		}




	return 0;
	}



/////////// initialising //////////////////////////////////////////////////////

	int init(world *x,char bir[],char sur[])
	{	int i,j,ll,ww;
		x->w=ww=130;
		x->l=ll=40;
		for(i=0;i<ll;i++)
		for(j=0;j<ww;j++)
		x->a[i][j]=x->b[i][j]=0;

		for(i=0;i<9;i++)
		x->birth[i]=x->surv[i]=0;


//		x->birth[3]=1;
//		x->surv[2]=x->surv[3]=1;
//x->a[5][4]=1;		
//x->a[6][5]=1;
//x->a[7][5]=1;
//x->a[7][4]=1;		
//x->a[7][3]=1;



		for(i=0;i<9;i++)
		{x->birth[i]=bir[i]-48;x->surv[i]=sur[i]-48;}

//		for(i=1;i<9;i++)
//printf("%d",x->surv[i]);
	return 0;
	}

///////////////////////////////////////////////////////////////////////////////


///////////// print ///////////////////////////////////////////////////////////

	int print( world *x)
	{
		int i,j,ll,ww;
		ll=x->l;
		ww=x->w;
		
		for(i=0;i<ll;i++)
		{	
			printf("\t");
			for(j=0;j<ww;j++)
			if(x->a[i][j]==1)printf("*");
			else printf(" ");
			printf("\n");
		}
	return 0;
	}
///////////////////// update ///////////////////////////////////

	int update( world*x)
	{
		int i,j,ll,ww,s,ii;
		ll=x->l;
		ww=x->w;
		for(i=0;i<ll;i++)
		for(j=0;j<ww;j++)
		{
		s=0;
		s=(x->a[(i+ll-1)%ll][(j+ww-1)%ww])+(x->a[(i+ll-1)%ll][(j)%ww])+(x->a[(i+ll-1)%ll][(j+1)%ww]);
		s+=(x->a[(i)%ll][(j+ww-1)%ww])+(x->a[(i)%ll][(j+1)%ww]);
		s+=(x->a[(i+1)%ll][(j+ww-1)%ww])+(x->a[(i+1)%ll][(j)%ww])+(x->a[(i+1)%ll][(j+1)%ww]);

		if(x->a[i][j]==1)
			{
						
			if(x->surv[s]==1)
				x->b[i][j]=1;
			else x->b[i][j]=0;
			}
		else
			{

			if(x->birth[s])x->b[i][j]=1;
			else x->b[i][j]=0;
			}
		
		}
		
		for(i=0;i<ll;i++)
		for(j=0;j<ww;j++)
		x->a[i][j]=x->b[i][j];

	return 0;
	}
////////////////////////////////////////////////////////////


/////////// delaying //////////////////////////////////////


	int delay()
	{
		int i,j,k;
		for(i=0;i<10000;i++)
		for(j=0;j<5000;j++)
		k=0;
		return 0;
	}

////////////////////////////////////////////////////////////
	

	int fileinp(world *x)
	{

		char c[10000];
		scanf("%s",c);

		int i,j,k;
		i=j=k=0;
		while(i<40||j<130)
		{
			j%=130;
			k++;
			if(c[k]=='#')
				continue;
			
			if(c[k]=='.')
				{x->a[i][j]=0;j++;}
			else if(c[k]=='*')
				{x->a[i][j]=1;j++;}
			if(c[k+1]=='#')
				i++;
							
			


		}

	return 0;
	}
////////////////////////////////////////////////////////////
	int main(int n,char *ar[])
	{
		world y;
		world *x;
		x=&y;
		init(x,ar[1],ar[2]);
		fileinp(x);

	
		

		while(1==1)
		{
		delay();
		print(x);
		update(x);
		}
	return 0;
	}
