/**********************************/
/**           WARNING!           **/
/** This file is auto generated. **/
/**        DO NOT MODIFY         **/
/**********************************/

#include "zprotocpp.h"

BaseEvent::BaseEvent()
{
}

BaseEvent::~BaseEvent()
{
}

unsigned char BaseEvent::id() const {
    return id_;
}
void BaseEvent::set_id(unsigned char id) {
    id_ = id;
}


LoginBaseEvent::LoginBaseEvent()
{
}

LoginBaseEvent::~LoginBaseEvent()
{
}

unsigned char LoginBaseEvent::id() const {
    return id_;
}
void LoginBaseEvent::set_id(unsigned char id) {
    id_ = id;
}

std::string LoginBaseEvent::userid() const {
    return userid_;
}
void LoginBaseEvent::set_userid(std::string userid) {
    userid_ = userid;
}

std::string LoginBaseEvent::passwd() const {
    return passwd_;
}
void LoginBaseEvent::set_passwd(std::string passwd) {
    passwd_ = passwd;
}


LoginReply::LoginReply()
{
}

LoginReply::~LoginReply()
{
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


SubscriptionBaseEvent::SubscriptionBaseEvent()
{
}

SubscriptionBaseEvent::~SubscriptionBaseEvent()
{
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

std::string SubscriptionBaseEvent::userid() const {
    return userid_;
}
void SubscriptionBaseEvent::set_userid(std::string userid) {
    userid_ = userid;
}


SubscriptionReply::SubscriptionReply()
{
}

SubscriptionReply::~SubscriptionReply()
{
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


Event::Event()
{
}

Event::~Event()
{
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

std::string Event::userid() const {
    return userid_;
}
void Event::set_userid(std::string userid) {
    userid_ = userid;
}

std::vector<unsigned char> Event::data() const {
    return data_;
}
void Event::set_data(std::vector<unsigned char> data) {
    data_ = data;
}


EventReply::EventReply()
{
}

EventReply::~EventReply()
{
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


