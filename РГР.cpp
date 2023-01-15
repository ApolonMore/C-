#include <iostream> 
#include <fstream>
#include <string>
using namespace std;
class Tcompany{
    protected:
    string surname,name,otch,mes,price;
    public:
    virtual void create(const string sur, const string na,const string ot,const string m, const string pr){ 
        surname=sur;
        name=na;
        otch=ot;
        mes=m;
        price=pr;
    }
    virtual void create(const char* sur,const char* na,const char* ot,const char* m, const char* pr){
        surname=sur;
        name=na;
        otch=ot;
        mes=m;
        price=pr;
    }
    virtual void print()=0;
    virtual void fout()=0;
    virtual void f()=0;
};
class Tclient: public Tcompany{
    public:
    void print(){ // Вывод всех заказов в консоль
        cout<<"ФИО: "<<surname<<" "<<name<<" "<<otch<<" "<<endl<<"Адрес: "<<mes<<endl<<"Цена: "<<price<<endl;
    }
    void f(){ // Очищение файла
        ofstream fout("cpp.txt", ios::out);
        fout.close();
    }
    void fout(){ // Сохранинение заказов в файл
        setlocale(LC_ALL,"RUSSIAN");
        ofstream fout("cpp.txt", ofstream::app);
        fout<<surname<<endl<<name<<endl<<otch<<endl<<mes<<endl<<price<<endl;
        fout.close();
    }
};
class fabrika{ // Создание заказа и его добавление в массив
    public:
    Tcompany* create(const char* nm,const char* snm, const char* ot, const char* m,const char* pr){
        string nm1,snm1,ot1,m1,pr1;
        nm1=nm;
        snm1=snm;
        ot1=ot;
        m1=m;
        pr1=pr;
        return create(nm1,snm1,ot1,m1,pr1);
    }
    Tcompany* create(string nm, string snm, string ot, string m, string pr){
        Tcompany *res=NULL;
        res=new Tclient;
        res->create(nm,snm,ot,m,pr);
        return res;
    }
};
class controller { 
    private:
    bool work;
    public:
    fabrika CleaningCompany;
    int l=0;
    Tcompany ** companies=new Tcompany*[100]; // Создаю массив из 100 элементов, просто выбрал это число
    controller(){
        work = 1;
    }
    bool getWork(){
        return work;
    }
    void showMenu(){ // Основная консоль, с которой мы будем взаимодействовать
        cout<<"Заказы клининговой компании"<<endl<<endl;
        cout<<"1 - Добавить Заказ"<<endl;
        cout<<"2 - Удалить Заказ"<<endl;
        cout<<"3 - Отредактировать Заказ"<<endl;
        cout<<"4 - Вывести все Заказы"<<endl;
        cout<<"5 - Сохранить все Заказы в файл"<<endl;
        cout<<"6 - Считать все Заказы из файла"<<endl;
        cout<<"0 - Выйти"<<endl;
        cout<<"Ваш выбор: ";
        
        while (getMenuItem()==-1);
    }
    int getMenuItem(){ // Возникает при вводе какого-то числа из списка
        string n,s,o,m,pr;
        int k,i,a,g=0;
        char c;
        cin>>c;
        system("clear"); // Очищение консоли
        
        if (c=='1'){ // Добавление заказа
            cout<<"Количество вводимых Заказов: ";cin>>k;
            a=l+k;
            for (l;l<a;l++){
                cout<<"Введите фамилию Клиента: " ;cin>>s;
                cout<<"Введите имя Клиента: ";cin>>n;
                cout<<"Введите отчество Клиента: ";cin>>o;
                cout<<"Введите место заказа Клиента(Вводить через _, а не пробел): ";cin>>m;
                cout<<"Стоимость заказа: ";cin>>pr;
                cout<<endl;
                companies[l]=CleaningCompany.create(s,n,o,m,pr);
            }
            return 1;
        }
        else if(c=='2'){ // Удаление заказа
            cout<<"Введите номер Заказа, который хотите удалить"<<endl<<"Если хотите отменить удаление, то введите 0"<<endl<<"Ваш выбор: ";cin>>k;
            if (k==0){
                cout<<endl;
                return 2;
            }
            else if (k>l){
                cout<<endl;
                return 2;
            }
            else{
                k--;
                l--;
                for (k;k<l;k++){
                    companies[k]=companies[k+1];
                }
                cout<<"Заказ успешно удалён"<<endl<<endl;
            }
            return 2;
        }
        else if (c=='3'){ // Редактирование заказа
            cout<<"Введите номер Заказа, который хотите отредактировать"<<endl<<"Если хотите отменить редактирование, то введите 0"<<endl<<"Ваш выбор: ";cin>>k;
            if (k==0){
                cout<<endl;
                return 3;
            }
            else if (k>l){

                cout<<"Такого заказа нет"<<endl<<endl;
                return 3;
            }
            else{
                k--;
                cout<<"Введите фамилию Клиента: " ;cin>>s;
                cout<<"Введите имя Клиента: ";cin>>n;
                cout<<"Введите отчество Клиента: ";cin>>o;
                cout<<"Введите место заказа Клиента(Вводить через _, а не пробел): ";cin>>m;
                cout<<"Стоимость заказа: ";cin>>pr;
                cout<<endl;
                companies[k]=CleaningCompany.create(s,n,o,m,pr);
                cout<<"Заказ успешно отредактирован"<<endl<<endl;
            }
            return 3;
        }
        else if(c=='4'){ // Вывод заказов
            for (i=0;i<l;i++){
                cout<<"Заказ "<<i+1<<endl;
                companies[i]->print();
                cout<<endl;
            }
            return 4;
        }
        else if(c=='5'){ // Сохранение заказов в файл
            companies[0]->f();
            for (i=0;i<l;i++){
                companies[i]->fout();
            }
            cout<<"Заказы успешно перенесены в файл"<<endl<<endl;
            return 5;
        }
        else if(c=='6'){ // Считывание заказов из файла
            fstream fin;
            fin.open("cpp.txt", ios::in);
    
            if (!fin.is_open()) {
                cout<<"Файл не может быть открыт"<<endl<<endl;
            }
            else if (l==0){
                while (fin>>s && fin>>n && fin>>o && fin>>m && fin>>pr){
                    a=l+1;
                        for (l;l<a;l++){ // Добавил сюда для того, чтобы работало создание, без него не хотело работать
                            companies[g]=CleaningCompany.create(s,n,o,m,pr);
                        }
                    g++;
                }
                cout<<"Файл успешно считан"<<endl<<endl;
            }
            else{ // Всё ломалось при повторной попытке загрузки из файла, поэтому сделал так
                cout<<"Файл может быть считан только в пустое хранилище"<<endl<<endl;
            }
            fin.close();
            return 6;
        }
        else if(c=='0'){ // Выход из консоли
            work=0;
            cout<<"Удачного дня!!!";
            return 0;
        }
        else{
            return -1;
        }
    };
};
int main()
{
    controller ctrl; // Запуск консоли
    while(ctrl.getWork())
        ctrl.showMenu();
    return 0;
}