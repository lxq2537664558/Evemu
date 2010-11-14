/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of EVEmu: EVE Online Server Emulator
    Copyright 2006 - 2008 The EVEmu Team
    For the latest information visit http://evemu.mmoforge.org
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
    Author:     Bloody.Rabbit
*/

#include "CommonPCH.h"

#include "mt/Condition.h"
#include "time/TimeMgr.h"
#include "time/Timespec.h"

/*************************************************************************/
/* Mt::Condition                                                         */
/*************************************************************************/
void Mt::Condition::Signal()
{
#ifdef WIN32
    DWORD code = mCondition.Signal();
    assert( ERROR_SUCCESS == code );
#else /* !WIN32 */
    int code = mCondition.Signal();
    assert( 0 == code );
#endif /* !WIN32 */
}

void Mt::Condition::Broadcast()
{
#ifdef WIN32
    DWORD code = mCondition.Broadcast();
    assert( ERROR_SUCCESS == code );
#else /* !WIN32 */
    int code = mCondition.Broadcast();
    assert( 0 == code );
#endif /* !WIN32 */
}

void Mt::Condition::Wait( Mutex& mutex )
{
#ifdef WIN32
    DWORD code = mCondition.Wait( mutex.mCriticalSection );
    assert( ERROR_SUCCESS == code );
#else /* !WIN32 */
    int code = mCondition.Wait( mutex.mMutex );
    assert( 0 == code );
#endif /* !WIN32 */
}

void Mt::Condition::TimedWait( Mutex& mutex, const Time::Msec& timeout )
{
#ifdef WIN32
    DWORD code = mCondition.Wait( mutex.mCriticalSection, timeout );
    assert( ERROR_SUCCESS == code );
#else /* !WIN32 */
    int code = mCondition.TimedWait( mutex.mMutex, sTimeMgr.nowUnix() + timeout );
    assert( 0 == code );
#endif /* !WIN32 */
}
