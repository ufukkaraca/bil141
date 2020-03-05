#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//In order to prevent the turkish characters from looking like eccentric symbols, I have added the library locale.h
#include <locale.h>

struct person{
    int year_of_birth;
    struct person* father;
    struct person* mother;
    struct person* significant_other;
    struct person* children[2];
    char* sex;
    char* name;
} typedef Person;

int sexControl(Person p){
    if(strcmp(p.sex, "female")==0)
        return 1;
    else
        return 0;
}

void childAssigner(Person* mother, Person* father, Person* p){
    if(mother->children[0]==NULL && father->children[0]==NULL){
        mother->children[0]=p;
        father->children[0]=p;
        
    }
    else{
        mother->children[1] = p;
        father->children[1] = p; 
    }
}

Person* person_constructor(char *name, int year_of_birth, char *sex){
    Person* p = (Person*)calloc(1, sizeof(Person));
    
    p->children[0]=(Person*)calloc(1, sizeof(Person)); p->children[0]=NULL;
    p->children[1]=(Person*)calloc(1,sizeof(Person)); p->children[1]=NULL;
    
    p->father= (Person*)calloc(1, sizeof(Person)); p->father=(Person*)NULL; 
    p->mother=(Person*)calloc(1, sizeof(Person)); p->mother=(Person*)NULL; 
    p->significant_other=(Person*)calloc(1, sizeof(Person)); p->significant_other=(Person*)NULL;
    p->name = (char*)calloc(1, (strlen(name)+1));
    p->sex = (char*)calloc(1, (strlen(sex)+1));
    p->name = name;
    p->year_of_birth = year_of_birth;
    p->sex = sex;

    return p;
}

void display_person(Person* p){
    printf("================\n");
    printf("Name\t: %s\n", p->name);
    printf("Sex\t: %s\n", p->sex);
    printf("Year\t: %d\n", p->year_of_birth);
    if(p->father!=NULL)
        printf("Father\t: %s\n", p->father->name);
    else{
        printf("Father\t: NA\n");
    }
    if(p->mother!=NULL)
        printf("Mother\t: %s\n", p->mother->name);
    else
        printf("Mother\t: NA\n");
    if(p->significant_other!=NULL)
        printf("Sig.O\t: %s\n", p->significant_other->name);
    else
        printf("Sig.O\t: NA\n");
    if(p->children[0]!=(Person*)NULL)
        printf("Child 1\t: %s\n", p->children[0]->name);
    else
        printf("Child 1\t: NA\n");
    if((p->children[1])!=(Person*)NULL)
        printf("Child 2\t: %s\n", p->children[1]->name);
    else
        printf("Child 2\t: NA\n");
    
}

void display_family(Person* family[], int n){
    int i;
    for(i=0; i<n; i++)
        display_person(family[i]);
}

void marry_them(Person* p1, Person* p2){
    p1->significant_other = p2;
    p2->significant_other = p1;
    if(p1->children[0]!=NULL){
        printf("Ssht %s, just so you know, %s has been married before and has a child.\n", p2->name, p1->name);
        printf("Do you wish to get divorced? Just write 'yes' or 'no'.");
        char* divorce;
        gets(divorce);
        if(strcmp(divorce, "yes")==0){
            p2->significant_other=NULL;
            printf("Divorce successful. You can handle the alimony matter yourselves.");
        }
    }
    if(p2->children[0]!=NULL){
        printf("Ssht %s, just so you know, %s has been married before and has a child.\n", p1->name, p2->name);
        printf("Do you wish to get divorced? Just write 'yes' or 'no'.");
        char* divorce;
        gets(divorce);
        if(strcmp(divorce, "yes")==0){
            p1->significant_other=NULL;
            printf("Divorce successful. You can handle the alimony matter yourselves.");
        }
        
    }
}

Person* birth(char *name, int year_of_birth, char *sex, Person *mother){
    
    Person* p=person_constructor(name, year_of_birth, sex);
    p->mother = mother;
    p->father = mother->significant_other;

    childAssigner(p->mother, p->father, p);

    

    return p;
}

//While constructing the function "sibling" I have proceeded with the assumption that in cases of print==1, the user
//desires to print out the name of the sibling.
Person* sibling(Person p, int print){
    if(strcmp((p.mother->children[0]->name),p.name)==0){
        if(print==1 && p.mother->children[1]!=NULL)
            printf("The sibling of %s is %s.\n", p.name, ((p.mother->children[1]))->name);
        if(p.mother->children[1]!=NULL)
            return p.mother->children[1];
        if(print==1 && p.mother->children[1]==NULL){
            printf("%s has no siblings. S/he will get all the money from her/his parents, ", p.name);
            printf("but won't ever learn how it feels to have a sibling who backs you at all times. :(\n");
        }
        if(p.mother->children[1]==NULL)
            return NULL;
    }
    
    if(strcmp((p.mother->children[1]->name),p.name)==0){
        if(print==1)
            printf("The sibling of %s is %s.\n", p.name, ((p.mother->children[0]))->name);
        return p.mother->children[0];
    }
}

void display_uncles(Person p){
    Person father=*p.father;
    Person mother=*p.mother;

    if(father.mother!=NULL){
        if(sibling(father,0)!=NULL && sexControl(*sibling(father, 0))==0){
        Person uncle = *sibling(father, 0);
        printf("Amca adi: %s.\n", uncle.name);
        }
    }
    
    if(mother.mother!=NULL){
        if(sibling(mother,0)!=NULL && sexControl(*sibling(mother, 0))==0){
        Person uncle = *sibling(mother, 0);
        printf("Dayi adi: %s.\n", uncle.name);
        }
    }   
    

    //Eniþte kimdir? Bu yýllardýr süregelen ve TDK'nin bile net bir cevap vermediði bir soru.
    //Bu ödev için, Eniþte={Halanýn Eþi, Teyzenin Eþi, Kýz Kardeþin Eþi} olarak alýnmýþtýr.
    if(p.father->mother!=NULL){
        if(sibling(*p.father,0)->significant_other!=NULL && sexControl(*sibling(*p.father,0)->significant_other)==0){
            Person uncle = *sibling(*p.father,0)->significant_other;
            printf("Baba tarafindan eniste adi: %s.\n", uncle.name);
        }
    }
    if(p.mother->mother!=NULL){
        if(sibling(*p.mother,0)->significant_other!=NULL && sexControl(*sibling(*p.mother,0)->significant_other)==0){
            Person uncle = *sibling(*p.mother,0)->significant_other;
            printf("Anne tarafindan eniste adi: %s.\n", uncle.name);
        }
    }
    if(sibling(p,0)!=NULL){
        if(sibling(p, 0)->significant_other!=NULL && sexControl(*sibling(p, 0)->significant_other)==0){
            Person uncle = *sibling(p, 0)->significant_other;
            printf("Kardes uzerinden enistenin adi: %s.\n", uncle.name);
        }
    }
}

void display_aunts(Person p){

    if(p.father->mother!=NULL){
        if(sibling(*p.father, 0)!=NULL && sexControl(*sibling(*p.father, 0))==1)
            printf("Hala adi: %s.\n", sibling(*p.father, 0)->name);
    }

    if(p.mother->mother!=NULL){
        if(sibling(*p.mother, 0)!=NULL && sexControl(*sibling(*p.mother, 0))==1)
            printf("Teyze adi: %s.\n", sibling(*p.mother, 0)->name);
    }
    
    //Peki yenge kimdir?
    //Bu ödev için, Yenge={Amcanýn Eþi, Dayýnýn Eþi, Erkek Kardeþin Eþi} olarak alýnmýþtýr.
    if(p.mother->mother!=NULL){
        if(sibling(*p.mother, 0)->significant_other!=NULL && sexControl(*sibling(*p.mother, 0)->significant_other)==1)
            printf("Anne tarafindan yenge adi: %s.\n", sibling(*p.mother, 0)->significant_other->name);
    }
    if(p.father->mother!=NULL){
        if(sibling(*p.father, 0)->significant_other!=NULL && sexControl(*sibling(*p.father, 0)->significant_other)==1)
            printf("Baba tarafindan yenge adi: %s.\n", sibling(*p.father, 0)->significant_other->name);
    }
    if(sibling(p,0)!=NULL){
        if(sibling(p, 0)->significant_other!=NULL && sexControl(*sibling(p, 0)->significant_other)==0){
            Person yenge = *sibling(p, 0)->significant_other;
            printf("Kardes uzerinden yengenin adi: %s.\n", yenge.name);
        }
    }
}


int main(){
    setlocale(LC_ALL, "Turkish");
    
    Person* p1 = person_constructor("Abbas", 1970, "male");     Person* p2 = person_constructor("Sýdýka", 1970, "female");     marry_them(p1, p2); 
    
    Person* p3 = person_constructor("Pýnar", 1990, "female");     Person* p4 = birth("Siamak", 1990, "male", p2);   marry_them(p3, p4); 
    
    Person* p5 = birth("Güzide", 1990, "female", p2);     Person* p6 = person_constructor("Fatih", 1990, "male");     marry_them(p5, p6); 
 
    Person* p7 = birth("Berkecan", 2010, "male", p3);     Person* p8 = birth("Ekinsu", 2010, "female", p3);     Person* p9 = birth("Caným", 2010, "female", p5); 
 
    Person* family[9] = {p1, p2, p3, p4, p5, p6, p7, p8, p9};

    display_person(p1); 
    display_family(family, 9);
    sibling(*p7, 1);
    display_uncles(*p7);
    display_aunts(*p9);

    printf("I have completed all of my fundamentally required tasks. Would you like to perform another task?\n");
    char task[10];
    gets(task);
    if(strcmp(task, "yes")==0)
        printf("Due to a technical failure, I am not able to provide you with any assistance for the time being. Estimated Date of Completion For Repairs: 19.12.2120. Have a great day.");

    else
        printf("It was fructiferous getting to know you and your family. Have a great day :)");
    
    return 0;
}