//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/BloombergTypes/Service.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#include "BloombergTypes/Service.h"
#include "BloombergTypes/Request.h"
#include "BloombergTypes/RequestPtr.h"
#include "BloombergTypes/ServiceRefData.h"

namespace BEmu
{
	Service::Service()
	{
	}

	Request Service::createRequest(const char* operation) const
	{
		ServiceRefData sref;
		RequestPtr* reqP = sref.createRequestPtr(operation);
		Request result(reqP);
		return result;
	}

	const char* Service::name() const
	{
		return 0;
	}
}