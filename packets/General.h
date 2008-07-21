/*  EVEmu: EVE Online Server Emulator
  
  **************************************************************
  This file is automatically generated, DO NOT EDIT IT DIRECTLY.
  **************************************************************
  
  (If you need to customize an object, you must copy that object
  into another source file, and give up the ability to generate it)
  
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; version 2 of the License.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY except by those people which sell it, which
  are required to give you total support for your newly bought product;
  without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __General_h__
#define __General_h__

#include <string>
#include <vector>
#include <map>
#include "../common/common.h"
#include "../common/logsys.h"
#include "../common/PyRep.h"



class util_Row {
public:
	util_Row();
	~util_Row();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepObject **packet);
	PyRepObject *Encode();
	PyRepObject *FastEncode();
	util_Row *Clone() const;
	void CloneFrom(const util_Row *from);
	
	/* object of type util.Row */
	std::vector<std::string>	header;
	PyRepList	line;


};


class util_Rowset {
public:
	util_Rowset();
	~util_Rowset();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepObject **packet);
	PyRepObject *Encode();
	PyRepObject *FastEncode();
	util_Rowset *Clone() const;
	void CloneFrom(const util_Rowset *from);
	
	/* object of type util.Rowset */
	std::vector<std::string>	header;
	std::string	rowclass;
	PyRepList	lines;


};


class util_IndexRowset {
public:
	util_IndexRowset();
	~util_IndexRowset();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepObject **packet);
	PyRepObject *Encode();
	PyRepObject *FastEncode();
	util_IndexRowset *Clone() const;
	void CloneFrom(const util_IndexRowset *from);
	
	/* object of type util.IndexRowset */
	std::vector<std::string>	header;
	std::string	rowclass;
	std::string	idName;
	std::map<uint32, PyRep *>	items;


};

	/*  this object is not really an object type on live, just convenience here  */

class util_Tupleset {
public:
	util_Tupleset();
	~util_Tupleset();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	util_Tupleset *Clone() const;
	void CloneFrom(const util_Tupleset *from);
	
	std::vector<std::string>	header;
	PyRepList	lines;


};


class list_rowset {
public:
	list_rowset();
	~list_rowset();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	list_rowset *Clone() const;
	void CloneFrom(const list_rowset *from);
	
	/*  0  */
	std::vector<std::string>	header;
	/*  1  */
	/*  each element of this list is a list itself, with one element per element in header  */
	PyRepList	lines;


};

	/*  This should prolly find a new home some day, as its really a detail of the marshalling procedure  */

class dbutil_RowList_header {
public:
	dbutil_RowList_header();
	~dbutil_RowList_header();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	dbutil_RowList_header *Clone() const;
	void CloneFrom(const dbutil_RowList_header *from);
	
	std::string	type;
	PyRep		*packed_header;
	std::vector<std::string>	columns;


};


class dbutil_RowDict_header {
public:
	dbutil_RowDict_header();
	~dbutil_RowDict_header();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	dbutil_RowDict_header *Clone() const;
	void CloneFrom(const dbutil_RowDict_header *from);
	
	std::string	type;
	PyRep		*packed_header;
	std::vector<std::string>	columns;
	std::string	key;


};

	/*  
empty calls:
CallPing
CallGetPostAuthenticationMessage
CallGetCharactersToSelect
CallGetCharCreationInfo
CallGetAttributeTypes
CallShipGetInfo
CallCharGetInfo
CallGetMyKillRights
CallGetBookmarks
CallGetChannels
CallGetInitialState
CallGetMyMessages
CallGetFactionInfo
CallGetStuckSystems
CallGetOwnerNoteLabels
CallGetStationItemBits
CallGetStationExtraInfo
CallGetCorporateStationInfo
CallGetCorporation
CallList (inventory)
CallGetAgents
CallGetGuests
 */

class CallGetMultiOwnersEx {
public:
	CallGetMultiOwnersEx();
	~CallGetMultiOwnersEx();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallGetMultiOwnersEx *Clone() const;
	void CloneFrom(const CallGetMultiOwnersEx *from);
	
	/*  0  */
	std::vector<uint32>	entities;


};


class RspGetMultiOwnersEx {
public:
	RspGetMultiOwnersEx();
	~RspGetMultiOwnersEx();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetMultiOwnersEx *Clone() const;
	void CloneFrom(const RspGetMultiOwnersEx *from);
	
	/*  0  */
	list_rowset	rowset;


};


class CallMachoResolveObject {
public:
	CallMachoResolveObject();
	~CallMachoResolveObject();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallMachoResolveObject *Clone() const;
	void CloneFrom(const CallMachoResolveObject *from);
	
	/*  0  */
	PyRep		*entitySpec;
	/*  1  */
	uint32		justQuery;


};


class RspMachoResolveObject {
public:
	RspMachoResolveObject();
	~RspMachoResolveObject();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspMachoResolveObject *Clone() const;
	void CloneFrom(const RspMachoResolveObject *from);
	
	/*  0  */
	uint32		nodeID;


};


class CallMachoBindObject_call {
public:
	CallMachoBindObject_call();
	~CallMachoBindObject_call();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallMachoBindObject_call *Clone() const;
	void CloneFrom(const CallMachoBindObject_call *from);
	
	/*  0  */
	std::string	method_name;
	/*  1  */
	PyRepTuple	*arguments;	//due to (somewhat false) sizing constructor, must be dynamic memory.
	/*  2  */
	PyRepDict	dict_arguments;


};


class CallMachoBindObject {
public:
	CallMachoBindObject();
	~CallMachoBindObject();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallMachoBindObject *Clone() const;
	void CloneFrom(const CallMachoBindObject *from);
	
	/*  0  */
	PyRep		*entitySpec;
	/*  1  */
	/*  either 'None', or a CallMachoBindObject_call  */
	PyRep		*call;


};


class BoundObject {
public:
	BoundObject();
	~BoundObject();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepSubStruct **packet);
	PyRepSubStruct *Encode();
	PyRepSubStruct *FastEncode();
	BoundObject *Clone() const;
	void CloneFrom(const BoundObject *from);
	
	/*  0  */
	std::string	bindspec;
	/*  1  */
	uint64		timestamp;


};


class RspMachoBindObject {
public:
	RspMachoBindObject();
	~RspMachoBindObject();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspMachoBindObject *Clone() const;
	void CloneFrom(const RspMachoBindObject *from);
	
	/*  0  */
	/*  0  */
	BoundObject	bind;
	/*  1  */
	PyRep		*call_return;


};


class ErrorResponseBody {
public:
	ErrorResponseBody();
	~ErrorResponseBody();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	ErrorResponseBody *Clone() const;
	void CloneFrom(const ErrorResponseBody *from);
	
	/*  0  */
	uint32		CauseMsgType;
	/*  1  */
	uint32		ErrorCode;
	/*  2  */
	/*  0  */
	PyRep		*payload;


};


class macho_WrongMachoNode {
public:
	macho_WrongMachoNode();
	~macho_WrongMachoNode();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepObject **packet);
	PyRepObject *Encode();
	PyRepObject *FastEncode();
	macho_WrongMachoNode *Clone() const;
	void CloneFrom(const macho_WrongMachoNode *from);
	
	/* object of type macho.WrongMachoNode */
	uint32		nodeID;


};


class macho_MachoException {
public:
	macho_MachoException();
	~macho_MachoException();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	macho_MachoException *Clone() const;
	void CloneFrom(const macho_MachoException *from);
	
	/*  MACHONETMSG_TYPE  */
	uint32		in_response_to;
	/*  MACHONETERR_TYPE  */
	uint32		exception_type;
	/*  substream  */
	PyRep		*payload;


};


class NotifyOnAggressionChange {
public:
	NotifyOnAggressionChange();
	~NotifyOnAggressionChange();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	NotifyOnAggressionChange *Clone() const;
	void CloneFrom(const NotifyOnAggressionChange *from);
	
	/*  0  */
	uint32		integer0;
	/*  1  */
	/*  maps _something_ to a timestamp  */
	std::map<uint32, PyRep *>	entries;


};


class CallGetInventoryFromId {
public:
	CallGetInventoryFromId();
	~CallGetInventoryFromId();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallGetInventoryFromId *Clone() const;
	void CloneFrom(const CallGetInventoryFromId *from);
	
	/*  0  */
	uint32		entityID;
	/*  1  */
	uint32		passive;


};


class RspGetInventoryFromId {
public:
	RspGetInventoryFromId();
	~RspGetInventoryFromId();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetInventoryFromId *Clone() const;
	void CloneFrom(const RspGetInventoryFromId *from);
	
	/*  0  */
	BoundObject	bind;


};


class RspGetMyKillRights {
public:
	RspGetMyKillRights();
	~RspGetMyKillRights();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetMyKillRights *Clone() const;
	void CloneFrom(const RspGetMyKillRights *from);
	
	/*  0  */
	/*  0  */
	PyRepDict	unknown0;
	/*  1  */
	PyRepDict	unknown1;


};


class RspGetInitialState {
public:
	RspGetInitialState();
	~RspGetInitialState();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetInitialState *Clone() const;
	void CloneFrom(const RspGetInitialState *from);
	
	/*  0  */
	util_Rowset	rowset;


};


class CallGetCashBalance {
public:
	CallGetCashBalance();
	~CallGetCashBalance();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallGetCashBalance *Clone() const;
	void CloneFrom(const CallGetCashBalance *from);
	
	/*  0  */
	uint32		isCorpWallet;


};


class RspGetCashBalance {
public:
	RspGetCashBalance();
	~RspGetCashBalance();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetCashBalance *Clone() const;
	void CloneFrom(const RspGetCashBalance *from);
	
	/*  0  */
	double		credits;


};


class RspGetOwnerNoteLabels {
public:
	RspGetOwnerNoteLabels();
	~RspGetOwnerNoteLabels();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetOwnerNoteLabels *Clone() const;
	void CloneFrom(const RspGetOwnerNoteLabels *from);
	
	/*  0  */
	util_Rowset	notes;


};


class RspGetStationItemBits {
public:
	RspGetStationItemBits();
	~RspGetStationItemBits();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetStationItemBits *Clone() const;
	void CloneFrom(const RspGetStationItemBits *from);
	
	/*  0  */
	/*  0  */
	uint32		integer0;
	/*  1  */
	uint32		integer1;
	/*  2  */
	uint32		integer2;
	/*  3  */
	uint32		integer3;
	/*  4  */
	uint32		integer4;


};


class RspGetGuests {
public:
	RspGetGuests();
	~RspGetGuests();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	RspGetGuests *Clone() const;
	void CloneFrom(const RspGetGuests *from);
	
	/*  0  */
	std::vector<uint32>	guests;


};


class CallGetMessageDetails {
public:
	CallGetMessageDetails();
	~CallGetMessageDetails();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallGetMessageDetails *Clone() const;
	void CloneFrom(const CallGetMessageDetails *from);
	
	/*  0  */
	uint32		channelID;
	/*  1  */
	uint32		messageID;


};


class CallMarkMessagesRead {
public:
	CallMarkMessagesRead();
	~CallMarkMessagesRead();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallMarkMessagesRead *Clone() const;
	void CloneFrom(const CallMarkMessagesRead *from);
	
	/*  0  */
	/*  0  */
	uint32		messageID;


};


class SessionChangeNotification {
public:
	SessionChangeNotification();
	~SessionChangeNotification();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	SessionChangeNotification *Clone() const;
	void CloneFrom(const SessionChangeNotification *from);
	
	/*  0  */
	/*  0  */
	uint32		clueless;
	/*  1  */
	PyRepDict	changes;
	/*  1  */
	/*  this is actually optional...  */
	std::vector<uint32>	nodesOfInterest;


};


class ServerNotification {
public:
	ServerNotification();
	~ServerNotification();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	ServerNotification *Clone() const;
	void CloneFrom(const ServerNotification *from);
	
	/*  0  */
	/*  0  */
	uint32		unknown;
	/*  1  */
	/*  0  */
	std::string	boundID;
	uint64		timestamp;
	/*  1  */
	std::string	method;
	/*  2  */
	PyRepTuple	*arguments;	//due to (somewhat false) sizing constructor, must be dynamic memory.
	/*  3  */
	std::map<std::string, PyRep *>	keywords;
	/*  1  */


};


class Call_SingleIntegerArg {
public:
	Call_SingleIntegerArg();
	~Call_SingleIntegerArg();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_SingleIntegerArg *Clone() const;
	void CloneFrom(const Call_SingleIntegerArg *from);
	
	uint32		arg;


};


class Call_SingleRealArg {
public:
	Call_SingleRealArg();
	~Call_SingleRealArg();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_SingleRealArg *Clone() const;
	void CloneFrom(const Call_SingleRealArg *from);
	
	double		arg;


};


class Call_TwoIntegerArgs {
public:
	Call_TwoIntegerArgs();
	~Call_TwoIntegerArgs();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_TwoIntegerArgs *Clone() const;
	void CloneFrom(const Call_TwoIntegerArgs *from);
	
	uint32		arg1;
	uint32		arg2;


};


class Call_PointArg {
public:
	Call_PointArg();
	~Call_PointArg();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_PointArg *Clone() const;
	void CloneFrom(const Call_PointArg *from);
	
	double		x;
	double		y;
	double		z;


};


class Call_SingleBoolArg {
public:
	Call_SingleBoolArg();
	~Call_SingleBoolArg();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_SingleBoolArg *Clone() const;
	void CloneFrom(const Call_SingleBoolArg *from);
	
	bool		arg;


};


class Call_SingleStringArg {
public:
	Call_SingleStringArg();
	~Call_SingleStringArg();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_SingleStringArg *Clone() const;
	void CloneFrom(const Call_SingleStringArg *from);
	
	std::string	arg;


};


class Call_SingleArg {
public:
	Call_SingleArg();
	~Call_SingleArg();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_SingleArg *Clone() const;
	void CloneFrom(const Call_SingleArg *from);
	
	PyRep		*arg;


};


class Call_SingleIntList {
public:
	Call_SingleIntList();
	~Call_SingleIntList();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Call_SingleIntList *Clone() const;
	void CloneFrom(const Call_SingleIntList *from);
	
	std::vector<uint32>	ints;


};


class CallWarpToStuff {
public:
	CallWarpToStuff();
	~CallWarpToStuff();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	CallWarpToStuff *Clone() const;
	void CloneFrom(const CallWarpToStuff *from);
	
	/*  really this call uses keywords, and I think the item ID just happens to end up in the args as a fluke.  */
	std::string	itemStr;
	uint32		item;


};


class Notify_OnRemoteMessage {
public:
	Notify_OnRemoteMessage();
	~Notify_OnRemoteMessage();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	Notify_OnRemoteMessage *Clone() const;
	void CloneFrom(const Notify_OnRemoteMessage *from);
	
	std::string	msgType;
	std::map<std::string, PyRep *>	args;


};



#endif


