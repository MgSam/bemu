//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/IntradayTickRequest/ElementIntradayTickDataTuple3.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#include "bemu_headers.h"
#include "BloombergTypes\Name.h"

#pragma once

namespace BEmu
{
	namespace IntradayTickRequest
	{
		class ElementIntradayTickDataTuple3
		{
			private:
				std::string _item1;
				double _item2;
				int _item3;

				ElementIntradayTickDataTuple3(std::string item1, double item2, int item3);

			public:
				std::string item1() const;
				double item2() const;
				int item3() const;

				friend class EventIntradayTick;
				friend class ElementIntradayTickDataArray;
		};
	}
}