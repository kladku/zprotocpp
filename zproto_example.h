
/*  =========================================================================
    zproto_example - zproto example protocol

    Codec header for zproto_example.

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: zproto_example.xml, or
     * The code generation script that built this file: zproto_codec_cpp
    ************************************************************************
    Copyright (C) 2016 the Authors                                         
                                                                           
    Permission is hereby granted, free of charge, to any person obtaining  
    a copy of this software and associated documentation files (the        
    "Software"), to deal in the Software without restriction, including    
    without limitation the rights to use, copy, modify, merge, publish,    
    distribute, sublicense, and/or sell copies of the Software, and to     
    permit persons to whom the Software is furnished to do so, subject to  
    the following conditions:                                              
                                                                           
    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.                 
                                                                           
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF             
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      
    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 
    =========================================================================
*/

#ifndef ZPROTO_EXAMPLE_H_INCLUDED
#define ZPROTO_EXAMPLE_H_INCLUDED

#include <zmq.hpp>
#include <unordered_map>
#include <array>
#include <vector>
#include <iostream>

using frame = zmq::message_t;
using frames = std::vector<frame>;

class buffer
{
public:
    buffer(zmq::message_t &msg)
        : needle_(static_cast<uint8_t*>(msg.data()))
    {}

    template<typename T, std::size_t N>
    friend buffer& operator<<(buffer &b, const std::array<T,N> &host);

    template<typename T>
    friend buffer& operator<<(buffer &b, const T &host);

    template<typename T>
    friend buffer& operator<<(buffer &b, const T *host);

private:
    uint8_t *needle_;
};

template<typename T>
buffer& operator<<(buffer &b, const T &host)
{
    static_assert(sizeof(typename T::value_type) == 1, "Expected byte size");
    b << static_cast<uint32_t>(host.size());
    b.needle_ += 4;
    std::copy(std::begin(host), std::end(host), b.needle_);
    b.needle_ += host.size();
    return b;
}

template<>
buffer& operator<<<uint8_t>(buffer &b, const uint8_t &host)
{
    *b.needle_ = host;
    ++b.needle_;
    return b;
}

template<>
buffer& operator<<<uint16_t>(buffer &b, const uint16_t &host)
{
    b.needle_[0] = (uint8_t)((host >> 8) & 0xFF);
    b.needle_[1] = (uint8_t)((host)      & 0xFF);
    b.needle_ += 2;
    return b;
}

template<>
buffer& operator<<<uint32_t>(buffer &b, const uint32_t &host)
{
    b.needle_[0] = (uint8_t)((host >> 24) & 0xFF);
    b.needle_[1] = (uint8_t)((host >> 16) & 0xFF);
    b.needle_[2] = (uint8_t)((host >>  8) & 0xFF);
    b.needle_[3] = (uint8_t)((host)       & 0xFF);
    b.needle_ += 4;
    return b;
}

template<>
buffer& operator<<<uint64_t>(buffer &b, const uint64_t &host)
{
    b.needle_[0] = (uint8_t)((host >> 56) & 0xFF);
    b.needle_[1] = (uint8_t)((host >> 48) & 0xFF);
    b.needle_[2] = (uint8_t)((host >> 40) & 0xFF);
    b.needle_[3] = (uint8_t)((host >> 32) & 0xFF);
    b.needle_[4] = (uint8_t)((host >> 24) & 0xFF);
    b.needle_[5] = (uint8_t)((host >> 16) & 0xFF);
    b.needle_[6] = (uint8_t)((host >>  8) & 0xFF);
    b.needle_[7] = (uint8_t)((host)       & 0xFF);
    b.needle_ += 8;
    return b;
}

template<>
buffer& operator<<<std::vector<std::string>>(buffer &b, const std::vector<std::string> &host)
{
    b << static_cast<uint32_t>(host.size());
    for (const auto &s : host)
        b << s;
    return b;
}

template<>
buffer& operator<<(buffer &b, const std::unordered_map<std::string, std::string> &host)
{
    b << static_cast<uint32_t>(host.size());
    for (const auto &s : host) {
        b << static_cast<uint8_t>(s.first.size());
        std::copy(std::begin(s.first), std::end(s.first), b.needle_);
        ++b.needle_ += s.first.size();
        b << s.second;
    }
    return b;
}

template<typename T, std::size_t N>
buffer& operator<<(buffer &b, const std::array<T,N> &host)
{
    static_assert(sizeof(T) == 1, "Expected byte size");
    std::copy(std::begin(host), std::end(host), b.needle_);
    b.needle_ += N;
    return b;
}

template<>
buffer& operator<<(buffer &b, const std::array<char,256> &host)
{
    std::size_t size = std::strlen(host.data());
    b << (uint8_t)size;
    std::copy(std::begin(host), std::next(std::begin(host), size), b.needle_);
    b.needle_ += size;
    return b;
}

template<>
buffer& operator<<(buffer &b, const char* host)
{
    std::size_t size = std::strlen(host);
    b << (uint8_t)size;
    memcpy(b.needle_, host, size);
    b.needle_ += size;
    return b;
}

class OnScopeExit
{
public:
    OnScopeExit(std::function<void()> f)
        : f_(f) {}

    ~OnScopeExit() {
        if (f_)
            f_();
    }

private:
    std::function<void()> f_;
};

enum MessageId : uint8_t {
    LOG_MESSAGE = 1,
    STRUCTURES_MESSAGE = 2,
    BINARY_MESSAGE = 3,
    TYPES_MESSAGE = 4
};

class MsgLog
{
public:
    MessageId id() const {
        return LOG_MESSAGE;
    }

    bool is_valid() const {
        return is_valid_;
    }
    bool set_is_valid(bool is_valid) {
        is_valid_ = is_valid;
    }

    // Get version
    uint16_t version() const {
        return version_;
    }
    // Get const_host
    const char* const_host() const {
        return const_host_;
    }

    // Get & Set sequence
    uint16_t sequence() const {
        return sequence_;
    }
    void set_sequence(uint16_t sequence) {
        sequence_ = sequence;
    }
    // Get & Set level
    uint8_t level() const {
        return level_;
    }
    void set_level(uint8_t level) {
        level_ = level;
    }
    // Get & Set event
    uint8_t event() const {
        return event_;
    }
    void set_event(uint8_t event) {
        event_ = event;
    }
    // Get & Set node
    uint16_t node() const {
        return node_;
    }
    void set_node(uint16_t node) {
        node_ = node;
    }
    // Get & Set peer
    uint16_t peer() const {
        return peer_;
    }
    void set_peer(uint16_t peer) {
        peer_ = peer;
    }
    // Get & Set time
    uint64_t time() const {
        return time_;
    }
    void set_time(uint64_t time) {
        time_ = time;
    }
    // Get & Set host
    const std::array<char, 256>& host() const {
        return host_;
    }
    void set_host(const std::array<char, 256>& host) {
        host_ = host;
    }
    // Get & Set data
    const std::string& data() const {
        return data_;
    }
    void set_data(const std::string& data) {
        data_ = data;
    }

private:
    bool is_valid_ = false;

    // Get version
    const uint16_t version_ = 3;
    // Get const_host
    const char const_host_[256] = u8"some test data";

    uint16_t sequence_;                   //  sequence
    uint8_t level_;                       //  Log severity level
    uint8_t event_;                       //  Type of event
    uint16_t node_;                       //  Sending node
    uint16_t peer_;                       //  Refers to this peer
    uint64_t time_;                       //  Log date/time
    std::array<char, 256> host_;          //  Originating hostname
    std::string data_;                    //  Actual log message

    friend frames& operator<<(frames&,const MsgLog &);
};

frames& operator<<(frames &f, const MsgLog &m)
{
    OnScopeExit(
        [&m]() {
            if (!m.is_valid())
            std::cout << "MsgLog with id: "
                      << m.id() << "is not valid!";
    });
    size_t frame_size = 0;
    frame_size += 2;            // sequence
    frame_size += 2;            // version
    frame_size += 1;            // level
    frame_size += 1;            // event
    frame_size += 2;            // node
    frame_size += 2;            // peer
    frame_size += 8;            // time
    frame_size += 1 + std::strlen(m.host_.data()); // host
    frame_size += 1 + std::strlen(m.const_host_); // const_host
    frame_size += 4 + m.data_.size(); // data

    frame new_frame(frame_size);
    buffer b(new_frame);
    b << m.sequence_;
    b << m.version_;
    b << m.level_;
    b << m.event_;
    b << m.node_;
    b << m.peer_;
    b << m.time_;
    b << m.host_;
    b << m.const_host_;
    b << m.data_;
    f.emplace_back(std::move(new_frame));
    m.set_is_valid(true);
    return f;
}

class MsgStructures
{
public:
    MessageId id() const {
        return STRUCTURES_MESSAGE;
    }

    bool is_valid() const {
        return is_valid_;
    }
    bool set_is_valid(bool is_valid) {
        is_valid_ = is_valid;
    }


    // Get & Set sequence
    uint16_t sequence() const {
        return sequence_;
    }
    void set_sequence(uint16_t sequence) {
        sequence_ = sequence;
    }
    // Get & Set aliases
    const std::vector<std::string>& aliases() const {
        return aliases_;
    }
    void set_aliases(const std::vector<std::string>& aliases) {
        aliases_ = aliases;
    }
    // Get & Set headers
    const std::unordered_map<std::string, std::string>& headers() const {
        return headers_;
    }
    void set_headers(const std::unordered_map<std::string, std::string>& headers) {
        headers_ = headers;
    }

private:
    bool is_valid_ = false;


    uint16_t sequence_;                   //  sequence
    std::vector<std::string> aliases_;    //  List of strings
    std::unordered_map<std::string, std::string> headers_;         //  Other random properties

    friend frames& operator<<(frames&,const MsgStructures &);
};

frames& operator<<(frames &f, const MsgStructures &m)
{
    OnScopeExit(
        [&m]() {
            if (!m.is_valid())
            std::cout << "MsgStructures with id: "
                      << m.id() << "is not valid!";
    });
    size_t frame_size = 0;
    frame_size += 2;            // sequence
    frame_size += 4;            // aliases
    for (const auto &s : m.aliases_)
        frame_size += 4 + s.size();
    frame_size += 4;            // headers
    for (const auto &p : m.headers_)
        frame_size += 1 + p.first.size() + 4 + p.second.size();

    frame new_frame(frame_size);
    buffer b(new_frame);
    b << m.sequence_;
    b << m.aliases_;
    b << m.headers_;
    f.emplace_back(std::move(new_frame));
    m.set_is_valid(true);
    return f;
}

class MsgBinary
{
public:
    MessageId id() const {
        return BINARY_MESSAGE;
    }

    bool is_valid() const {
        return is_valid_;
    }
    bool set_is_valid(bool is_valid) {
        is_valid_ = is_valid;
    }


    // Get & Set sequence
    uint16_t sequence() const {
        return sequence_;
    }
    void set_sequence(uint16_t sequence) {
        sequence_ = sequence;
    }
    // Get & Set flags
    const std::array<uint8_t, 4>& flags() const {
        return flags_;
    }
    void set_flags(const std::array<uint8_t, 4>& flags) {
        flags_ = flags;
    }
    // Get & Set public_key
    const std::vector<uint8_t>& public_key() const {
        return public_key_;
    }
    void set_public_key(const std::vector<uint8_t>& public_key) {
        public_key_ = public_key;
    }
    // Get & Set identifier
    const std::array<uint8_t, 16>& identifier() const {
        return identifier_;
    }
    void set_identifier(const std::array<uint8_t, 16>& identifier) {
        identifier_ = identifier;
    }
    // Get & Set address
    const frame& address() const {
        return address_;
    }
    void set_address(const frame& address) {
        address_.rebuild(address.data(), address.size());
    }
    // Get & Set content
    const frames& content() const {
        return content_;
    }
    void set_content(const frames& content) {
        content_.clear();
        for (const auto &f : content)
            content_.emplace_back(frame(f.data(), f.size()));
    }

private:
    bool is_valid_ = false;


    uint16_t sequence_;                   //  sequence
    std::array<uint8_t, 4> flags_;              //  A set of flags
    std::vector<uint8_t> public_key_;     //  Our public key
    std::array<uint8_t, 16> identifier_;  //  Unique identity
    frame address_;                       //  Return address as frame
    frames content_;                      //  Message to be delivered

    friend frames& operator<<(frames&,const MsgBinary &);
};

frames& operator<<(frames &f, const MsgBinary &m)
{
    OnScopeExit(
        [&m]() {
            if (!m.is_valid())
            std::cout << "MsgBinary with id: "
                      << m.id() << "is not valid!";
    });
    size_t frame_size = 0;
    frame_size += 2;            // sequence
    frame_size += 4;            // flags
    frame_size += 4 + m.public_key_.size();  // public_key
    frame_size += 16;           // identifier

    frame new_frame(frame_size);
    buffer b(new_frame);
    b << m.sequence_;
    b << m.flags_;
    b << m.public_key_;
    b << m.identifier_;
    f.emplace_back(std::move(new_frame));
    f.emplace_back(frame(m.address_.data(), m.address_.size()));
    for (auto &mf : m.content_)
        f.emplace_back(frame(mf.data(), mf.size()));
    m.set_is_valid(true);
    return f;
}

class MsgTypes
{
public:
    MessageId id() const {
        return TYPES_MESSAGE;
    }

    bool is_valid() const {
        return is_valid_;
    }
    bool set_is_valid(bool is_valid) {
        is_valid_ = is_valid;
    }


    // Get & Set sequence
    uint16_t sequence() const {
        return sequence_;
    }
    void set_sequence(uint16_t sequence) {
        sequence_ = sequence;
    }
    // Get & Set client_forename
    const std::array<char, 256>& client_forename() const {
        return client_forename_;
    }
    void set_client_forename(const std::array<char, 256>& client_forename) {
        client_forename_ = client_forename;
    }
    // Get & Set client_surname
    const std::array<char, 256>& client_surname() const {
        return client_surname_;
    }
    void set_client_surname(const std::array<char, 256>& client_surname) {
        client_surname_ = client_surname;
    }
    // Get & Set client_mobile
    const std::array<char, 256>& client_mobile() const {
        return client_mobile_;
    }
    void set_client_mobile(const std::array<char, 256>& client_mobile) {
        client_mobile_ = client_mobile;
    }
    // Get & Set client_email
    const std::array<char, 256>& client_email() const {
        return client_email_;
    }
    void set_client_email(const std::array<char, 256>& client_email) {
        client_email_ = client_email;
    }
    // Get & Set supplier_forename
    const std::array<char, 256>& supplier_forename() const {
        return supplier_forename_;
    }
    void set_supplier_forename(const std::array<char, 256>& supplier_forename) {
        supplier_forename_ = supplier_forename;
    }
    // Get & Set supplier_surname
    const std::array<char, 256>& supplier_surname() const {
        return supplier_surname_;
    }
    void set_supplier_surname(const std::array<char, 256>& supplier_surname) {
        supplier_surname_ = supplier_surname;
    }
    // Get & Set supplier_mobile
    const std::array<char, 256>& supplier_mobile() const {
        return supplier_mobile_;
    }
    void set_supplier_mobile(const std::array<char, 256>& supplier_mobile) {
        supplier_mobile_ = supplier_mobile;
    }
    // Get & Set supplier_email
    const std::array<char, 256>& supplier_email() const {
        return supplier_email_;
    }
    void set_supplier_email(const std::array<char, 256>& supplier_email) {
        supplier_email_ = supplier_email;
    }

private:
    bool is_valid_ = false;


    uint16_t sequence_;                   //  sequence
    std::array<char, 256> client_forename_;  //  Given name
    std::array<char, 256> client_surname_;  //  Family name
    std::array<char, 256> client_mobile_;  //  Mobile phone number
    std::array<char, 256> client_email_;  //  Email address
    std::array<char, 256> supplier_forename_;  //  Given name
    std::array<char, 256> supplier_surname_;  //  Family name
    std::array<char, 256> supplier_mobile_;  //  Mobile phone number
    std::array<char, 256> supplier_email_;  //  Email address

    friend frames& operator<<(frames&,const MsgTypes &);
};

frames& operator<<(frames &f, const MsgTypes &m)
{
    OnScopeExit(
        [&m]() {
            if (!m.is_valid())
            std::cout << "MsgTypes with id: "
                      << m.id() << "is not valid!";
    });
    size_t frame_size = 0;
    frame_size += 2;            // sequence
    frame_size += 1 + std::strlen(m.client_forename_.data()); // client_forename
    frame_size += 1 + std::strlen(m.client_surname_.data()); // client_surname
    frame_size += 1 + std::strlen(m.client_mobile_.data()); // client_mobile
    frame_size += 1 + std::strlen(m.client_email_.data()); // client_email
    frame_size += 1 + std::strlen(m.supplier_forename_.data()); // supplier_forename
    frame_size += 1 + std::strlen(m.supplier_surname_.data()); // supplier_surname
    frame_size += 1 + std::strlen(m.supplier_mobile_.data()); // supplier_mobile
    frame_size += 1 + std::strlen(m.supplier_email_.data()); // supplier_email

    frame new_frame(frame_size);
    buffer b(new_frame);
    b << m.sequence_;
    b << m.client_forename_;
    b << m.client_surname_;
    b << m.client_mobile_;
    b << m.client_email_;
    b << m.supplier_forename_;
    b << m.supplier_surname_;
    b << m.supplier_mobile_;
    b << m.supplier_email_;
    f.emplace_back(std::move(new_frame));
    m.set_is_valid(true);
    return f;
}


#endif
