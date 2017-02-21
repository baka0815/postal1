////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 RWS Inc, All Rights Reserved
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of version 2 of the GNU General Public License as published by
// the Free Software Foundation
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//
// collision.H
// Project: Nostril (aka Postal)
// 
// History:
//		02/18/97 JMI	Started.
//
//////////////////////////////////////////////////////////////////////////////
//
// Collision functions for postal.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef COLLISION_H
#define COLLISION_H

#include <BLUE/System.h>

///////////////////////////////////////////////////////////////////////////////
// Postal includes.
///////////////////////////////////////////////////////////////////////////////
#include "thing.h"

//////////////////////////////////////////////////////////////////////////////
// Macros.
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Typedefs.
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Protos.
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Inlines/Templates.
//////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Gets then next thing from the specified list that collides with the specified
// region.
////////////////////////////////////////////////////////////////////////////////
template <class Region>	// Must be a type supported by CThing::IsColliding(...)!
bool GetNextCollision(	// Returns true if a collision is found, false otherwise.
	CThing::Things*	pthings,		// In:  List of CThings to search within.
	Region*				pregion,		// In:  Region OR shape to collide with.
	CThing**				ppthing)		// In:  CThing to start with or nullptr to start at beginning.
											// Out: CThing collided with or nullptr.
	{
	bool	bCollision	= false;	// Assume no collision.

	CThing::Things::iterator	i	= pthings->begin();

	// If a beginning was specified . . .
	if (*ppthing != nullptr)
		{
		while (i != pthings->end() && *i != *ppthing)
			{
			i++;
			}

		if (i == pthings->end())
			{
			TRACE("GetNextCollision(): Specified CThing is not in specified list.\n");
			}
		else
			{
			// Move to next after *ppthing.
			i++;
			}
		}

	while (i != pthings->end())
		{
		// If there is a collision . . .
		if ((*i)->IsColliding(pregion) == true)
			{
			// Remember who it was with.
			*ppthing	= *i;
			// Set return value.
			bCollision	= true;
			// Exit loop.
			break;
			}
		
		// Next.
		i++;
		}

	return bCollision;
	}

#endif	// COLLISION_H
//////////////////////////////////////////////////////////////////////////////
// EOF
//////////////////////////////////////////////////////////////////////////////
