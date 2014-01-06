/**
 * SigConnection.h
 * This file is part of YateBTS
 *
 * Declaration for Signaling socket connection
 *
 * Yet Another Telephony Engine - a fully featured software PBX and IVR
 * Copyright (C) 2004-2014 Null Team
 *
 * This software is distributed under multiple licenses;
 * see the COPYING file in the main directory for licensing
 * information for this specific distribution.
 *
 * This use of this software may be subject to additional restrictions.
 * See the LEGAL file in the main directory for details.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef SIGCONNECTION_H
#define SIGCONNECTION_H

#include <sys/types.h>

namespace Connection {

class SigConnection
{
public:
    enum Primitive {
	SigL3Message      =   0, // Connection related L3 message
	SigConnLost       =   1, // Connection to UE lost
	SigConnRelease    =   2, // Request to release a connection
	SigHandshake      = 128, // Initial handshake
	SigHeartbeat      = 255  // Idle heartbeat message
    };
    static bool initialize(int fileDesc, unsigned char ident = 0);
    static bool start();
    static bool send(Primitive prim, unsigned char info = 0);
    static bool send(Primitive prim, unsigned char info, unsigned int id);
    static bool send(Primitive prim, unsigned char info, unsigned int id, const void* data, size_t len);
private:
    static bool send(const void* buffer, size_t len);
    static void process(Primitive prim, unsigned char info);
    static void process(Primitive prim, unsigned char info, const unsigned char* data, size_t len);
    static void process(Primitive prim, unsigned char info, unsigned int id);
    static void process(Primitive prim, unsigned char info, unsigned int id, const unsigned char* data, size_t len);
    static void* run(void*);
};

}; // namespace Connection

#endif /* SIGCONNECTION_H */

/* vi: set ts=8 sw=4 sts=4 noet: */
