#ifndef absp
#define absp
#include <arpa/inet.h>  //inet_addr define
//#include <ext/stdio_filebuf.h>
//#include <stdio.h>  //printf()
//#include <unistd.h>  //close(), fread()
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

class AbstractPeer{
        public:
        AbstractPeer()=default;///<Конструктор без параметров  \param void
        virtual void createSocket()=0;///<Прообраз функции создания сокета для инициализации клиента/сервера. Запись в переменную sock \param void  \return void
        virtual void connectInit(const char* addr)=0;///<Запись в переменную addres и подготовка соединения \param void  \return void
        virtual void connectInit()=0;///\param void  \return void
        virtual void selinit()const=0;///<\param void  \return void
        virtual void sel()const=0;///<\param void  \return void
        virtual void conn()const=0;///<\param void  \return void
        virtual void sendmes()const=0;///<\param void  \return void
        /**
         \brief Конструктор с параметрами
         
         \param _sock
         \param _addres
         \return конструкторы ничего не возвращают
         */

        //Peer(int _sock, struct sockaddr_in _addres):sock(_sock), addres(_addres){}
        int sock;///<Переменная для хранения сокета
        struct sockaddr_in addres;///<Структура для хранения адреса и типа узла
        char buffer[MAXLINE]={0};///<Хранит сообщение
        fd_set read_fd={0};///<Массив дескрапторов для храненния сокета

        

};





/*
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

*/
#endif
