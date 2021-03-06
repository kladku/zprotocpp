/**********************************/
/**           WARNING!           **/
/** This file is auto generated. **/
/**        DO NOT MODIFY         **/
/**********************************/

#include "zprotocpp.h"

unsigned char BaseEvent::id() const {
    return id_;
}
void BaseEvent::set_id(unsigned char id) {
    id_ = id;
}


unsigned char LoginBaseEvent::id() const {
    return id_;
}
void LoginBaseEvent::set_id(unsigned char id) {
    id_ = id;
}

const std::string& LoginBaseEvent::userid() const {
    return userid_;
}
void LoginBaseEvent::set_userid(const std::string &userid) {
    userid_ = userid;
}

const std::string& LoginBaseEvent::passwd() const {
    return passwd_;
}
void LoginBaseEvent::set_passwd(const std::string &passwd) {
    passwd_ = passwd;
}


unsigned char LoginReply::id() const {
    return id_;
}
void LoginReply::set_id(unsigned char id) {
    id_ = id;
}

unsigned int LoginReply::error() const {
    return error_;
}
void LoginReply::set_error(unsigned int error) {
    error_ = error;
}

unsigned int LoginReply::token() const {
    return token_;
}
void LoginReply::set_token(unsigned int token) {
    token_ = token;
}


unsigned char SubscriptionBaseEvent::id() const {
    return id_;
}
void SubscriptionBaseEvent::set_id(unsigned char id) {
    id_ = id;
}

unsigned int SubscriptionBaseEvent::token() const {
    return token_;
}
void SubscriptionBaseEvent::set_token(unsigned int token) {
    token_ = token;
}

const std::string& SubscriptionBaseEvent::userid() const {
    return userid_;
}
void SubscriptionBaseEvent::set_userid(const std::string &userid) {
    userid_ = userid;
}


unsigned char SubscriptionReply::id() const {
    return id_;
}
void SubscriptionReply::set_id(unsigned char id) {
    id_ = id;
}

unsigned int SubscriptionReply::error() const {
    return error_;
}
void SubscriptionReply::set_error(unsigned int error) {
    error_ = error;
}

std::string SubscriptionReply::userid() const {
    return userid_;
}
void SubscriptionReply::set_userid(std::string userid) {
    userid_ = userid;
}


unsigned char Event::id() const {
    return id_;
}
void Event::set_id(unsigned char id) {
    id_ = id;
}

long long int Event::gid() const {
    return gid_;
}
void Event::set_gid(long long int gid) {
    gid_ = gid;
}

unsigned int Event::token() const {
    return token_;
}
void Event::set_token(unsigned int token) {
    token_ = token;
}

const std::string& Event::userid() const {
    return userid_;
}
void Event::set_userid(const std::string &userid) {
    userid_ = userid;
}

const std::vector<unsigned char>& Event::data() const {
    return data_;
}
void Event::set_data(const std::vector<unsigned char> &data) {
    data_ = data;
}


unsigned char EventReply::id() const {
    return id_;
}
void EventReply::set_id(unsigned char id) {
    id_ = id;
}

unsigned int EventReply::error() const {
    return error_;
}
void EventReply::set_error(unsigned int error) {
    error_ = error;
}

long long int EventReply::gid() const {
    return gid_;
}
void EventReply::set_gid(long long int gid) {
    gid_ = gid;
}

unsigned int EventReply::mid() const {
    return mid_;
}
void EventReply::set_mid(unsigned int mid) {
    mid_ = mid;
}



