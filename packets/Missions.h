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

#ifndef __Missions_h__
#define __Missions_h__

#include <string>
#include <vector>
#include <map>
#include "../common/common.h"
#include "../common/logsys.h"
#include "../common/PyRep.h"


	/*  this object is not really an object type on live, just convenience here  */

class DoAction_Dialogue_Item {
public:
	DoAction_Dialogue_Item();
	~DoAction_Dialogue_Item();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	DoAction_Dialogue_Item *Clone() const;
	void CloneFrom(const DoAction_Dialogue_Item *from);
	
	uint32		actionID;
	std::string	actionText;


};


class DoAction_Result {
public:
	DoAction_Result();
	~DoAction_Result();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	DoAction_Result *Clone() const;
	void CloneFrom(const DoAction_Result *from);
	
	/*  this is the main text  */
	std::string	agentSays;
	/*  this is a list of DoAction_Dialogue_Item  */
	PyRepList	dialogue;
	uint32		loyaltyPoints;


};


class JournalDetails_Mission_Item {
public:
	JournalDetails_Mission_Item();
	~JournalDetails_Mission_Item();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	JournalDetails_Mission_Item *Clone() const;
	void CloneFrom(const JournalDetails_Mission_Item *from);
	
	/*  states: 0,1: not accepted, >1: accepted  */
	uint32		missionState;
	/*  really a soft boolean  */
	uint32		importantMission;
	std::string	missionType;
	std::string	missionName;
	uint32		agentID;
	uint64		expirationTime;
	PyRepList	bookmarks;


};


class JournalDetails_Offer_Item {
public:
	JournalDetails_Offer_Item();
	~JournalDetails_Offer_Item();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	JournalDetails_Offer_Item *Clone() const;
	void CloneFrom(const JournalDetails_Offer_Item *from);
	
	uint32		agentID;
	std::string	offerName;
	/*  LP cost  */
	uint32		loyaltyPoints;
	/*  this might need to be a string  */
	uint64		expirationTime;


};


class JournalDetails_Research_Item {
public:
	JournalDetails_Research_Item();
	~JournalDetails_Research_Item();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	JournalDetails_Research_Item *Clone() const;
	void CloneFrom(const JournalDetails_Research_Item *from);
	
	uint32		agentID;
	/*  field  */
	uint32		typeID;
	/*  points per day  */
	double		ppd;
	/*  current points  */
	double		points;


};


class GetMyJournalDetails_Result {
public:
	GetMyJournalDetails_Result();
	~GetMyJournalDetails_Result();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	GetMyJournalDetails_Result *Clone() const;
	void CloneFrom(const GetMyJournalDetails_Result *from);
	
	/*  this is a list of JournalDetails_Mission_Item  */
	PyRepList	missions;
	/*  this is a list of JournalDetails_Offer_Item  */
	PyRepList	offers;
	/*  this is a list of JournalDetails_Research_Item  */
	PyRepList	research;


};

	/*  may be preceeded by an
OnRemoteMessage: ('AgtMissionOfferWarning', {} )  */

class OnAgentMissionChange_Args {
public:
	OnAgentMissionChange_Args();
	~OnAgentMissionChange_Args();
	
	void Dump(LogType type, const char *pfx = "") const;
	bool Decode(PyRep **packet);	//consumes packet
	bool Decode(PyRepTuple **packet);
	PyRepTuple *Encode();
	PyRepTuple *FastEncode();
	OnAgentMissionChange_Args *Clone() const;
	void CloneFrom(const OnAgentMissionChange_Args *from);
	
	std::string	action;
	/*  seen 'offered'  */
	uint32		missionID;


};



#endif


