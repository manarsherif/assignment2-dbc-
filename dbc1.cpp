# assignment2-dbc-
#include <iostream>
#include <string>
#include "dbc.h"

using namespace std;

class Dictionary 
{
private:
	string names[100];
	string emails[100];
	int size;
public:
	Dictionary()
	{
		size =0;
	}
	private:
	bool check_fn(string n){
		for (int i = 0; i < size; i++)
		{
			if(names[i]==n)
				return true;
		}
		return false;
	}

public:
	void Add(string name,string email)
	{   INVARIANT0(size >= 0 &&size<=99);
		REQUIRE0(email[size-4]=='.');
		REQUIRE0(email[size-3]=='c');
		REQUIRE0(email[size-2]=='o');
		REQUIRE0(email[size-1]=='m');
		REQUIRE0(email.find('@')!=0);
		REQUIRE0(!check_fn(name));

		names[size] = name;
		emails[size] = email;
		size++;
		ENSURE0(name.compare(names[size])==0);
		ENSURE0(email.compare(emails[size])==0);
		ENSURE0(check_fn(name));
		INVARIANT0(size >= 0 &&size<=99);
	}

	void Remove(string name)
	{
		// a simple example on removing array of numbers
		// if the array is  {1,5,3,4,2,6,7,8,9,10}
		// and its size is 10 elements
		// and i want to remove entry "2"
		// i'll find its index first through the following code segment
		REQUIRE0(check_fn(name));//lazem eli hashelo ykon mawgod 
		int indextoberemoved;

		for(int i =0;i<size;i++)
		{
			if(names[i] == name)
			{
				indextoberemoved = i;
				break;
			}
		}
		// then i'll move all elements after that index backword one step
		// and with decrementing the size, this is equivalent to removing that element
		size--;
		for(int i = indextoberemoved;i<size;i++)
		{
			names[i] = names[i+1];
			emails[i] = emails[i+1];
		}
		ENSURE0(check_fn(name)==false);
	}
	void printentries()
	{
		for(int i =0;i<size;i++)
		{
			cout<<"Entry #"<<i+1<<":"<<endl<<names[i]<<": "<<emails[i]<<endl;
		}
	}
};


void main()
{  
	try{
	Dictionary x;

	x.Add("omar","omar@live.com");
	x.Add("hassan","hassan@live.com");

	cout<<"Before Deleting Hassan"<<endl;
	x.printentries();
	x.Remove("hassan");
	cout<<"After Deleting Hassan"<<endl;
	x.printentries();
	system("pause");
	} 
	catch(DesignByContractException e){
		cout<<(string)e;
	}
}
