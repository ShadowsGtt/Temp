#include "../include/Epool.h"

void Epoll::EpollCreate()
{
    _EpollFd = epoll_create(65536);
    if(_EpollFd == -1 ){
        perror("epoll create error");
        exit(-1);
    }
}

void Epoll::EpollAdd(int fd,int epev)
{
    if(fd < 0 ){
        perror("invalid file descriptor");
        return ;
    }

    epoll_event ev;
    ev.data.fd = fd;
    ev.events = epev;
    
    if(epoll_ctl(_EpollFd,EPOLL_CTL_ADD,fd,&ev) == -1){
        perror("epoll add  error");
        return;
    } 
    
    _EpollEvent[fd] = ev;
}

void Epoll::EpollDel(int fd)
{
    if(fd < 0){
        cout<<"invalid file descriptor"<<endl;
        return;
    }

    if(epoll_ctl(_EpollFd,EPOLL_CTL_DEL,fd,&_EpollEvent[fd]) == -1){
        perror("epoll del error");
        return;
    } 
    
    map<int,epoll_event>::iterator it= _EpollEvent.find(fd);
    if(it != _EpollEvent.end())
        _EpollEvent.erase(it);
}

void Epoll::EpollMod(int fd,int epev)
{
    if(fd < 0){
        cout<<"invalid file descriptor"<<endl;
        return;
    }
    
    _EpollEvent[fd].events = epev;

    if(epoll_ctl(_EpollFd,EPOLL_CTL_MOD,fd,&_EpollEvent[fd]) == -1){
        perror("epoll del error");
        return;
    } 
    
    
}
