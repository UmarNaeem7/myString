// mystring (class).cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class myString
{
private:
	char* str;
	int length;
public:
	myString()
	{
		str = NULL;
		length = 0;
	}
	myString(const char* istr)
	{
		length = strlen(istr);
		str = new char[length + 1];
		strcpy(str,istr);
	}
    myString operator+(const char* istr)
    {
        myString ans;
        ans.length=length+strlen(istr);
        ans.str=new char[ans.length+1];
        strcpy(ans.str,str);
        strcpy(ans.str+length,istr);  //?
        return ans;
    }
    myString operator+(const myString &obj)
    {
        myString ans;
        ans.length=length+obj.length;
        ans.str=new char[ans.length+1];
        strcpy(ans.str,str);
        strcpy(ans.str+length,obj.str);
        return ans;
    }
    myString(const myString & obj)
    {
        str=new char[obj.length+1];
        strcpy(str,obj.str);
        length=obj.length;
    }
    const myString& operator=(const myString &obj)
    {
        if (str!=NULL)
            delete[]str;
        str=new char[obj.length+1];
        strcpy(str,obj.str);
        length=obj.length;
        return *this;
    }
    int size()
    {
        return length;
    }
    char& operator [](int i)
    {
        str[i]='x';
        return str[i];
    }
    ~myString()
    {
        if (str!=NULL)
        {
            delete [] str;
        }
    }
    friend ostream& operator<<(ostream &out,myString &obj);
    friend myString operator+(char* ptr,const myString &obj);
};

myString operator+(char* ptr,const myString &obj)
{
    int length=strlen(ptr);
    myString ans;
    ans.length==obj.length+length;
    ans.str=new char[ans.length];
    strcpy(ans.str,ptr);
    strcpy(ans.str+length,obj.str);
    return ans;
}

ostream& operator<<(ostream &out,myString &obj)
{
    out<<obj.str;
    return out;
}

class Employee
{
private:
    myString name;  //composition:object of 1 type is contained in another type
    myString dept;
    float sal;
    int scale;
    bool gender;
public:
    Employee(const myString &n,const myString &d,float s,int sc,bool g)
    :name(n),dept(d),sal(s),scale(sc),gender(g)   //member initialization list
    {
    }
};

class Manager
{
private:
    Employee e; //the emp part of manager
    bool executive;
    int strength;
public:
    Manager(const Employee &em,bool ex,int s)
    :e(em),executive(ex),strength(s)
    {
    }
};

class Worker
{
private:
    Employee e;
    myString* projects;
    int nprjs;
public:
    Worker(const Employee &em,myString *p,int n)
    :e(em),nprjs(n)
    {
        projects=new myString[n];
        for (int i=0;i<n;i++)
        {
            projects[i]=p[i];
        }
    }
    ~Worker()
    {
        if (projects!=NULL)
            delete [] projects;
    }
};

int main()
{
	/*myString s = "Hello World!", t = "How's it going?", u;
	myString w=s+" ";
	w=w+t;

	cout<<"The string after concatenation is:";
	cout<<w<<endl;

	cout<<"The number of times character 'e' appears in the string w is:";
	int count=0;
	for (int i=0;i<w.size();i++)
    {
        if (w[i]=='e')
            count++;
    }
    cout<<count<<endl;

    //slightly different concatenation
    u="I'm saying that "+s;
    cout<<u<<endl;*/
    //Employee e("Usama Khan","HR++",200000,2,false);
    Manager m(Employee("Usama Khan","HR++",200000,2,false),true,50); //explicitly invoking Employee for 1 line
    myString prjs[]={"CPEC","Orange line","paragon"};
    Worker w(Employee("Usama Khan","HR++",200000,2,false),prjs,3);
    return 0;
}

