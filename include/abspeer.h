#ifndef absp
#define absp
#include <arpa/inet.h>  //inet_addr define
//#include <ext/stdio_filebuf.h>
//#include <stdio.h>  //printf()
//#include <unistd.h>  //close(), fread()
#include "client.h"
#include "server.h"
#define MAXLINE 1024

/**
 *\file abspeer.h
 *\author Денис Вергун
 *\brief Файл содержит описание наследуемого абстрактного класса 
 *\version
 *\date 27-06-2023
 *
 *
 */






///\brief Абстрактный узел связи. 
/**
Вводим определение узла связи Peer.
Создает интерфейс для наследующих классов клиета и сервера.
Содержит виртуальные функции создания сокета, соединения, основного цикла.
*/

class Client;
class Peer{
        public:
        Peer()=default;///<Конструктор без параметров  \param void
        virtual void createSocket(Client& client)=0;///<Прообраз функции создания сокета для инициализации клиента/сервера. Запись в переменную sock \param void  \return void
        //virtual void connectInit_(const char* addr)=0;///<Запись в переменную addres и подготовка соединения \param void  \return void
        //virtual void connectInit_()=0;///\param void  \return void
        //void selinit();///<\param void  \return void
        //void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void
        /**
         \brief Конструктор с параметрами
         
         \param _sock
         \param _addres
         \return конструкторы ничего не возвращают
         */

        //Peer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}
        //int sock;///<Переменная для хранения сокета
        //struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        //char buffer[MAXLINE]={0};///<Хранит сообщение
        //fd_set read_fd={0};///<Массив дескрапторов для храненния сокета

        

};




class ClientStrategy;
class Client:public Peer{
        public:
        //Client();
        //Client(const char* addr);
        Client(std::unique_ptr<ClientStrategy> strategy):clie(std::move(strategy)){}
        void createSocket(Client &client) override{
        
        //clie->createSocket(*this);

        }; 
        //void connectInit(const char* addr);
        //void connectInit();
        //private:
        //void selinit(); 
        //void sel();
        //void conn();
        //void sendmes();
        std::unique_ptr<ClientStrategy> clie;
        int sock;///<Переменная для хранения сокета
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета
};








class ClientStrategy{
        public:  
        //virtual ClientStrategy(){};
        virtual void createSocket(Client &client) = 0;
        //void connectInit_(const char* addr)override{connectInit(addr);};
        //void connectInit_()override{connectInit();};
	//void selinit();///<\param void  \return void
        ///void sel();///<\param void  \return void
        //void conn();///<\param void  \return void
        //void sendmes();///<\param void  \return void

};

class Server_:public Peer, public Server{
        public:  
        Server_(){};
        //void createSocket_()override{createSocket();};
	//void connectInit_(const char* addr)override{connectInit(addr);};
	//void connectInit_()override{};
	void selinit();///<\param void  \return void
        void sel();///<\param void  \return void
        void conn();///<\param void  \return void
        void sendmes();///<\param void  \return void



};

class TestClient:public ClientStrategy{

        
//void createSocket(Client const& client)const override;
void createSocket(Client &client)override
{

        client.sock=socket(AF_INET, SOCK_STREAM, 0);
        if(client.sock)
        std::cout << typeid(client).name() << " fd " << client.sock << std::endl;
        else
        std::cout << "creation socket error" << std::endl;





}


};



#endif
