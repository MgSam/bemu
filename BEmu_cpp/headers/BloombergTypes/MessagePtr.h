//------------------------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="headers/BloombergTypes/MessagePtr.h" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------------------------

#include "bemu_headers.h"
#include "BloombergTypes\Name.h"
#include "BloombergTypes\Datetime.h"
#include "BloombergTypes\CorrelationId.h"
#include "BloombergTypes\ElementPtr.h"

#pragma once

namespace BEmu
{
	class Message;

	//See my explanation of the RequetPtr class for an explanation of this class
	class MessagePtr
	{
		private:
			CorrelationId _correlationId;
			Name _messageType;
			//Service _service;

		protected:
			MessagePtr(const Name& messageType, CorrelationId* corr);

		public:

			class MessageException: public std::exception
			{
				virtual const char* what() const throw()
				{
					return "My exception happened";
				}
			} messageEx;

			CorrelationId correlationId() const;
			Name messageType() const;
			virtual const char* topicName() const;
			//Service service() const;
			const ElementPtr * getElement(const Name& name) const;
			virtual const ElementPtr * getElement(const char* name) const;
			virtual const ElementPtr * asElement() const;
			bool hasElement(const Name& name, bool excludeNullElements=false) const;
			virtual bool hasElement(const char* name, bool excludeNullElements=false) const;
			virtual int numElements() const;
			
			bool getElementAsBool(const char* name) const;
			int getElementAsInt32(const char* name) const;
			long getElementAsInt64(const char* name) const;
			float getElementAsFloat32(const char* name) const;
			double getElementAsFloat64(const char* name) const;
			Datetime getElementAsDatetime(const char* name) const;
			const char* getElementAsString(const char* name) const;

			virtual std::ostream& print(std::ostream& stream, int level = 0, int spacesPerLevel = 4) const;

			friend class Message;
	};

	inline std::ostream& operator<< (std::ostream& out, const MessagePtr& msg)
	{
		msg.print(out);
		return out;
	}
}