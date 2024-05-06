#include<iostream>
#include<cstring>
#include<cstdlib>
#define SIZE 1200
using namespace std;
class Student
{
private :
    char *name;
    int id, credit;
    float cgpa;
public :
    Student(char *nam, int a, int cs, float cg);
    ~Student()
    {
        free(name);
    }
    void showInfo();
    void change(char *nam);
    void change(int a);
    void addTermResult(int cs, float cg);
};
Student :: Student(char *nam, int a, int cs, float cg)
{
    name = (char*)malloc(strlen(nam)+1);
    strcpy(name, nam);
    id = a;
    credit = cs;
    cgpa = cg;
}
void Student :: change(char *nam)
{
    free(name);
    name = (char*)malloc(strlen(nam)+1);
    strcpy(name, nam);
}
void Student :: change(int a)
{
    id = a;
}
void Student :: showInfo()
{
    cout << "Name : " << name <<", Id : "<< id <<", Credit Completed: "<< credit <<", Cgpa: "<<cgpa << endl;
}
void Student :: addTermResult(int cs, float cg)
{
    cgpa = (cgpa*credit + cs*cg)/(credit + cs);
    credit+= cs;
}

class Batch
{
private :
    int N = 0;
    Student *st;
public :
    Batch();
    void addStudent(Student &stu);
    void showAllStudents();
    ~Batch()
    {
        free(st);
    }
};
Batch :: Batch()
{
    st = (Student*)malloc(SIZE*sizeof(Student));
}
void Batch :: addStudent(Student &stu)
{
    st[N] = stu;
    N++;
}
void Batch :: showAllStudents()
{
    for(int i = 0; i<N; i++)
    {
        (st + i)->showInfo();
    }
}


int main()
{
    Student s1("Tamim Iqbal", 1905131, 39, 3.56);
    Student s2("Liton Das", 1905150, 39, 3.52);
    s1.showInfo();
    cout<<"Changing the name of s1"<<endl;
    s1.change("Tamim Iqbal Khan");
    s1.showInfo();
    cout<<"Changing the id of s2"<<endl;
    s2.change(1905149);
    s2.showInfo();
    cout<<"Adding a term result of s1"<<endl;
    s1.addTermResult(19, 3.85);
    s1.showInfo();
    Batch b;
    b.addStudent(s1);
    b.addStudent(s2);
    cout<<"Printing the list of students of the batch b"<<endl;
    b.showAllStudents();
}

