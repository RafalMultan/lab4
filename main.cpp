#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
void bywords(int n);
int find(int n,int k=1)
{
	
	
	bool _isCorrect=true;
	unsigned long long result=n*k;
	while(result)
	{
		if((result)%10>1)_isCorrect=false;
		result/=10;
		
	}
	if(_isCorrect)return k;
		else find(n,++k);
	
}



int main(int argc, char *argv[])
{
	printf("podaj liczbe od 0 do milion\n");
	int n=atoi(argv[1]);
	bywords(find(n));
}


void bywords(int n)
{
	std::string jednosci[]={"jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"};
	std::string nastki[]={"jedenascie","dwanascie","trzynascie","czternascie","pietnascie","szesnascie","siedemnascie","osiemnascie","dziewietnascie"};
	std::string dziesiatki[]={"dziesiec","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiecdziesiat"};
	std::string setki[]={"sto","dwiescie","trzysta","czterysta","piecset","szescset","siedemset","osiemset","dziewiescset"};
	std::string thousand[]={"tysiac","tysiace","tysiace","tysiace","tysiecy","tysiecy","tysiecy","tysiecy","tysiecy","milion"};
	int rest;
	std::vector<string> results;
	int counter=0;
	while(n)
	{
		if(n==1000000)
		{
			results.push_back("milion ");
			break;
		}
		rest=n%10;
		if(n%100>10 && n%100<20)
			{
				rest=n%100;
				if(!counter)results.push_back(nastki[rest-11]);
				else results.push_back(nastki[rest-11]+" tysiecy");
				n=n/100;
				rest=n%10;
				if(rest)results.push_back(setki[rest-1]);
				n=n/10;
					counter++;
			}
		else 
		{
			if(rest)
			{
				if(!counter)results.push_back(jednosci[rest-1]);
				else results.push_back(jednosci[rest-1]+" "+thousand[rest-1]);
				n=n/10;
				rest=n%10;
				
			}
				else 
					{
						n=n/10;
						rest=n%10;
						if(counter)results.push_back("tysiecy");
					}
			if(rest)
			{
				results.push_back(dziesiatki[rest-1]);
				n=n/10;
				rest=n%10;
			}
				else 
					{
						n=n/10;
						rest=n%10;
					}
			if(rest)
			{
				results.push_back(setki[rest-1]);
				n=n/10;
			}
				else 
					{
						n=n/10;
						rest=n%10;
					}
		}
				counter++;
		
		//cout<<results[results.size()-1]<<" ";
	}
	for(int i=results.size()-1;i>=0;i--)
		cout<<results[i]<<" ";
	cout<<endl;
	
}