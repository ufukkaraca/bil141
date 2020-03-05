#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* ownerName;
    char* password;
    int amount;
    int accountCreationYear;
}Account;

typedef struct{
    char* bankname;
    int maxNumberOfAccounts;
    int curNumberOfAccounts;
    Account* allAccounts[];
}Bank;

Bank* bank_constructor(char* bankName, int maxNumberOfAccounts){
    Bank* banksy = (Bank*)calloc(1, sizeof(Bank));
    banksy->bankname=bankName;
    banksy->maxNumberOfAccounts=maxNumberOfAccounts;
    banksy->curNumberOfAccounts=0;
    int i;
    for(i=0; i<maxNumberOfAccounts; i++){
        banksy->allAccounts[i] = (Account*)calloc(1, sizeof(Account));
    }
    
    return banksy;
}

void bankInfo(Bank* b){
    printf("Name of the bank: %s\n", b->bankname);
    int sum=0; int i;

    for(i=0; i<(b->curNumberOfAccounts); i++){
        sum += b->allAccounts[i]->amount;
    }
    
    printf("Total Capital\t: %d\n", sum);
}

void customerInfo(Bank *b){
    printf("Customer List\t:\n");
    int i;
    for(i=0; i<b->curNumberOfAccounts; i++){
        Account* temp = b->allAccounts[i];
        printf("%s since %d.\n", temp->ownerName, temp->accountCreationYear);
    }
}

int createAccount(Bank* b, char* holderName, char* password, int accountCreationYear){
    if(b->maxNumberOfAccounts==b->curNumberOfAccounts){
        printf("This bank currently does not support the opening of any new accounts.");
        return -1;    
    }
    int accountNumber=b->curNumberOfAccounts;
    b->allAccounts[accountNumber]->ownerName = holderName;
    b->allAccounts[accountNumber]->password = password;
    b->allAccounts[accountNumber]->accountCreationYear = accountCreationYear;
    b->allAccounts[accountNumber]->amount=0;

    b->curNumberOfAccounts+=1;

    return accountNumber;
}

int depositMoney(Bank* b, int accountNumber, int amount){
    b->allAccounts[accountNumber]->amount+=amount;
    return amount;
}

int withdrawMoney(Bank* b, int accountNumber, char* password, int amount){
    if(password!=b->allAccounts[accountNumber]->password){
        printf("Wrong Password!\n");
        return 0;
    }

    else if(amount > b->allAccounts[accountNumber]->amount){
        printf("Insufficient funds!\n");
        return 0;
    }
    else{
    b->allAccounts[accountNumber]->amount-=amount;
    return amount;
    }
}

int transferMoney(Bank* senderBank, int senderAccount, char* senderPassword, Bank* receiverBank, int receiverAccount, int amount){
    int process = withdrawMoney(senderBank, senderAccount, senderPassword, amount);
    if(process==0){
        return 0;
    }
    else{
    receiverBank->allAccounts[receiverAccount]->amount+=process;
    return process;
    }
}

void checkBalance(Bank* b, int accountNumber, char* password){
    if(b->allAccounts[accountNumber]->password!=password){
        printf("Wrong Password!\n");
        return;
    }
    else{
    printf("Account balance: %d\n", b->allAccounts[accountNumber]->amount);
    }
}

int main(){
    Bank* b1 = bank_constructor("BankA", 3);
    Bank* b2 = bank_constructor("BankB", 4);
    int hesap11 = createAccount(b1, "Ahmet", "pass", 1980);
    int hesap12 = createAccount(b1, "Veli", "word", 2000);
    int hesap21 = createAccount(b2, "Mehmet", "sifre", 1990);
    depositMoney(b1, hesap11, 50);
    depositMoney(b1, hesap12, 80);
    transferMoney(b1, hesap11, "hatali", b2, hesap21, 20);
    transferMoney(b1, hesap11, "pass", b2, hesap21, 20);
    withdrawMoney(b1, hesap12, "hatali", 40);
    withdrawMoney(b1, hesap12, "word", 120);
    withdrawMoney(b1, hesap12, "word", 40);
    checkBalance(b1, hesap11, "hatali");
    checkBalance(b1, hesap11, "pass");
    checkBalance(b2, hesap21, "sifre");
    checkBalance(b1, hesap12, "word");
    customerInfo(b1);
    bankInfo(b2);

    return 0;
}