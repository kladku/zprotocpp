/**********************************/
/**           WARNING!           **/
/** This file is auto generated. **/
/**        DO NOT MODIFY         **/
/**********************************/

#ifndef _ZPROTOCPP_H_
#define _ZPROTOCPP_H_

#include <string>
#include <vector>

enum ClassId {
    BaseEvent_Class = 1,
    LoginBaseEvent_Class = 2,
    LoginReply_Class = 3,
    SubscriptionBaseEvent_Class = 4,
    SubscriptionReply_Class = 5,
    Event_Class = 6,
    EventReply_Class = 7
};

class BaseEvent
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

private:
    unsigned char id_;
};

class LoginBaseEvent
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

    const std::string& userid() const;
    void set_userid(const std::string &userid);

    const std::string& passwd() const;
    void set_passwd(const std::string &passwd);

private:
    unsigned char id_;
    std::string userid_;
    std::string passwd_;
};

class LoginReply
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

    unsigned int error() const;
    void set_error(unsigned int error);

    unsigned int token() const;
    void set_token(unsigned int token);

private:
    unsigned char id_;
    unsigned int error_;
    unsigned int token_;
};

class SubscriptionBaseEvent
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

    unsigned int token() const;
    void set_token(unsigned int token);

    const std::string& userid() const;
    void set_userid(const std::string &userid);

private:
    unsigned char id_;
    unsigned int token_;
    std::string userid_;
};

class SubscriptionReply
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

    unsigned int error() const;
    void set_error(unsigned int error);

    std::string userid() const;
    void set_userid(std::string userid);

private:
    unsigned char id_;
    unsigned int error_;
    std::string userid_;
};

class Event
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

    long long int gid() const;
    void set_gid(long long int gid);

    unsigned int token() const;
    void set_token(unsigned int token);

    const std::string& userid() const;
    void set_userid(const std::string &userid);

    const std::vector<unsigned char>& data() const;
    void set_data(const std::vector<unsigned char> &data);

private:
    unsigned char id_;
    long long int gid_;
    unsigned int token_;
    std::string userid_;
    std::vector<unsigned char> data_;
};

class EventReply
{
public:
    unsigned char id() const;
    void set_id(unsigned char id);

    unsigned int error() const;
    void set_error(unsigned int error);

    long long int gid() const;
    void set_gid(long long int gid);

    unsigned int mid() const;
    void set_mid(unsigned int mid);

private:
    unsigned char id_;
    unsigned int error_;
    long long int gid_;
    unsigned int mid_;
};


#endif // _ZPROTOCPP_H_

