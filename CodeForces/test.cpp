using namespace std;
#include <iostream>
#include<bits/stdc++.h>
class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge){
        if(initialAge<0){
            cout<<"Age is not valid, setting age to 0.";
        age=0;}
        else
        {
            age=initialAge;
        }
    }

    void Person::amIOld(){
        if(age<13)
            cout<<"\nYou are young.";
        else if(age<18)
            cout<<"\nYou are a teenager.";
        else
            cout<<"\nYou are old.";
    }

    void Person::yearPasses(){
        age++;

    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}