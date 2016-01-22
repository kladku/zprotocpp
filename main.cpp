/**********************************/
/**           WARNING!           **/
/** This file is auto generated. **/
/**        DO NOT MODIFY         **/
/**********************************/

#include "zprotocpp.h"
#include <iostream>

int main()
{
    std::cout << "TEST zprotocpp\n";
    {
        std::cout << "Testing Class BaseEvent\n";
        BaseEvent baseevent;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        baseevent.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << baseevent.id();
        if(baseevent.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }
    {
        std::cout << "Testing Class LoginBaseEvent\n";
        LoginBaseEvent loginbaseevent;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        loginbaseevent.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << loginbaseevent.id();
        if(loginbaseevent.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property userid\n";
        std::string userid = "sample string";
        loginbaseevent.set_userid(userid);
        std::cout << "Expected: " << userid
               << "\nReturned:    " << loginbaseevent.userid();
        if(loginbaseevent.userid() == userid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property passwd\n";
        std::string passwd = "sample string";
        loginbaseevent.set_passwd(passwd);
        std::cout << "Expected: " << passwd
               << "\nReturned:    " << loginbaseevent.passwd();
        if(loginbaseevent.passwd() == passwd)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }
    {
        std::cout << "Testing Class LoginReply\n";
        LoginReply loginreply;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        loginreply.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << loginreply.id();
        if(loginreply.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property error\n";
        unsigned int error = 42;
        loginreply.set_error(error);
        std::cout << "Expected: " << error
               << "\nReturned:    " << loginreply.error();
        if(loginreply.error() == error)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property token\n";
        unsigned int token = 42;
        loginreply.set_token(token);
        std::cout << "Expected: " << token
               << "\nReturned:    " << loginreply.token();
        if(loginreply.token() == token)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }
    {
        std::cout << "Testing Class SubscriptionBaseEvent\n";
        SubscriptionBaseEvent subscriptionbaseevent;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        subscriptionbaseevent.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << subscriptionbaseevent.id();
        if(subscriptionbaseevent.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property token\n";
        unsigned int token = 42;
        subscriptionbaseevent.set_token(token);
        std::cout << "Expected: " << token
               << "\nReturned:    " << subscriptionbaseevent.token();
        if(subscriptionbaseevent.token() == token)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property userid\n";
        std::string userid = "sample string";
        subscriptionbaseevent.set_userid(userid);
        std::cout << "Expected: " << userid
               << "\nReturned:    " << subscriptionbaseevent.userid();
        if(subscriptionbaseevent.userid() == userid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }
    {
        std::cout << "Testing Class SubscriptionReply\n";
        SubscriptionReply subscriptionreply;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        subscriptionreply.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << subscriptionreply.id();
        if(subscriptionreply.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property error\n";
        unsigned int error = 42;
        subscriptionreply.set_error(error);
        std::cout << "Expected: " << error
               << "\nReturned:    " << subscriptionreply.error();
        if(subscriptionreply.error() == error)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property userid\n";
        std::string userid = "sample string";
        subscriptionreply.set_userid(userid);
        std::cout << "Expected: " << userid
               << "\nReturned:    " << subscriptionreply.userid();
        if(subscriptionreply.userid() == userid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }
    {
        std::cout << "Testing Class Event\n";
        Event event;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        event.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << event.id();
        if(event.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property gid\n";
        long long int gid = 42;
        event.set_gid(gid);
        std::cout << "Expected: " << gid
               << "\nReturned:    " << event.gid();
        if(event.gid() == gid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property token\n";
        unsigned int token = 42;
        event.set_token(token);
        std::cout << "Expected: " << token
               << "\nReturned:    " << event.token();
        if(event.token() == token)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property userid\n";
        std::string userid = "sample string";
        event.set_userid(userid);
        std::cout << "Expected: " << userid
               << "\nReturned:    " << event.userid();
        if(event.userid() == userid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property data\n";
        std::vector<unsigned char> data = { 4, 2, 3 };
        event.set_data(data);
        if(event.data() == data)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }
    {
        std::cout << "Testing Class EventReply\n";
        EventReply eventreply;
        std::cout << "Testing property id\n";
        unsigned char id = 42;
        eventreply.set_id(id);
        std::cout << "Expected: " << id
               << "\nReturned:    " << eventreply.id();
        if(eventreply.id() == id)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property error\n";
        unsigned int error = 42;
        eventreply.set_error(error);
        std::cout << "Expected: " << error
               << "\nReturned:    " << eventreply.error();
        if(eventreply.error() == error)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property gid\n";
        long long int gid = 42;
        eventreply.set_gid(gid);
        std::cout << "Expected: " << gid
               << "\nReturned:    " << eventreply.gid();
        if(eventreply.gid() == gid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
        std::cout << "Testing property mid\n";
        unsigned int mid = 42;
        eventreply.set_mid(mid);
        std::cout << "Expected: " << mid
               << "\nReturned:    " << eventreply.mid();
        if(eventreply.mid() == mid)
            std::cout << "\nPASS\n";
        else
            std::cout << "FAIL\n";
    }

    return 0;
}
