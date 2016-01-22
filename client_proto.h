/**********************************/
/**           WARNING!           **/
/** This file is auto generated. **/
/**        DO NOT MODIFY         **/
/**********************************/

#ifndef _CLIENT_PROTO_H_
#define _CLIENT_PROTO_H_

#include <string>
#include <vector>

enum ClassId {
    Envelope_Class = 1,
    LoginForm_Class = 2,
    LoginReply_Class = 3,
    SubscriptionForm_Class = 4,
    SubscriptionReply_Class = 5,
    Message_Class = 6,
    MessageReply_Class = 7
};

class Envelope
{
public:
    Envelope();
    ~Envelope();

    unsigned char id() const;
    void set_id(unsigned char id);

private:
    unsigned char id_;

};

class LoginForm
    : public Envelope
{
public:
    LoginForm();
    ~LoginForm();

    const std::string& userid() const;
    void set_userid(const std::string& userid);

    const std::string& passwd() const;
    void set_passwd(const std::string& passwd);

private:
    std::string userid_;
    std::string passwd_;

};

class LoginReply
    : public Envelope
{
public:
    LoginReply();
    ~LoginReply();

    unsigned int error() const;
    void set_error(unsigned int error);

    unsigned int token() const;
    void set_token(unsigned int token);

private:
    unsigned int error_;
    unsigned int token_;

};

class SubscriptionForm
    : public Envelope
{
public:
    SubscriptionForm();
    ~SubscriptionForm();

    unsigned int token() const;
    void set_token(unsigned int token);

    const std::string& userid() const;
    void set_userid(const std::string& userid);

private:
    unsigned int token_;
    std::string userid_;

};

class SubscriptionReply
    : public Envelope
{
public:
    SubscriptionReply();
    ~SubscriptionReply();

    unsigned int error() const;
    void set_error(unsigned int error);

    std::string userid() const;
    void set_userid(std::string userid);

private:
    unsigned int error_;
    std::string userid_;

};

class Message
    : public Envelope
{
public:
    Message();
    ~Message();

    long long int gid() const;
    void set_gid(long long int gid);

    unsigned int token() const;
    void set_token(unsigned int token);

    const std::string& userid() const;
    void set_userid(const std::string& userid);

    const std::vector<unsigned char>& data() const;
    void set_data(const std::vector<unsigned char>& data);

private:
    long long int gid_;
    unsigned int token_;
    std::string userid_;
    std::vector<unsigned char> data_;

};

class MessageReply
    : public Envelope
{
public:
    MessageReply();
    ~MessageReply();

    unsigned int error() const;
    void set_error(unsigned int error);

    long long int gid() const;
    void set_gid(long long int gid);

    unsigned int mid() const;
    void set_mid(unsigned int mid);

private:
    unsigned int error_;
    long long int gid_;
    unsigned int mid_;

};


#endif // _CLIENT_PROTO_H_

