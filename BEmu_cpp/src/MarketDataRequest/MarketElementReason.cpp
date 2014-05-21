﻿//------------------------------------------------------------------------------
// <copyright project="BEmu_cpp" file="src/MarketDataRequest/MarketElementReason.cpp" company="Jordan Robinson">
//     Copyright (c) 2013 Jordan Robinson. All rights reserved.
//
//     The use of this software is governed by the Microsoft Public License
//     which is included with this distribution.
// </copyright>
//------------------------------------------------------------------------------

#include "MarketDataRequest/MarketElementReason.h"
#include "MarketDataRequest/MarketElementInt.h"
#include "MarketDataRequest/MarketElementString.h"

#include "Types/IndentType.h"
#include "Types/RandomDataGenerator.h"

namespace BEmu
{
	namespace MarketDataRequest
	{
		MarketElementReason::MarketElementReason(ReasonType::ReasonTypeEnum reasonType)
		{
			if(reasonType == ReasonType::badSecurity)
			{
				std::string source = RandomDataGenerator::RandomString(5);
				std::transform(source.begin(), source.end(), source.begin(), ::tolower);
				std::stringstream ssSource;
				ssSource << source << RandomDataGenerator::RandomInt(9) << '@' << RandomDataGenerator::RandomInt(99);
				this->_source = new MarketElementString("source", ssSource.str());

				this->_errorCode = new MarketElementInt("errorCode", RandomDataGenerator::RandomInt(99));

				this->_category = new MarketElementString("category", "BAD_SEC");
                
				this->_description = new MarketElementString("description", "Invalid security, rcode = -1");
			}
			else if(reasonType == ReasonType::badField)
			{
				std::string source = RandomDataGenerator::RandomString(7);
				std::transform(source.begin(), source.end(), source.begin(), ::tolower);
				std::stringstream ssSource;
				ssSource << source << '@' << RandomDataGenerator::RandomInt(999);
				this->_source = new MarketElementString("source", ssSource.str());

				this->_errorCode = new MarketElementInt("errorCode", RandomDataGenerator::RandomInt(99));

				this->_category = new MarketElementString("category", "BAD_FLD");
				
                this->_description = new MarketElementString("description", "Unknown Field");
			}
		}

		MarketElementReason::~MarketElementReason()
		{
			delete this->_source;
			this->_source = 0;
			
			delete this->_errorCode;
			this->_errorCode = 0;
			
			delete this->_category;
			this->_category = 0;
			
			delete this->_description;
			this->_description = 0;
		}

		Name MarketElementReason::name() const
		{
			return Name("reason");
		}

		size_t MarketElementReason::numValues() const
		{
			return 1;
		}

		size_t MarketElementReason::numElements() const
		{
			return 4;
		}

		SchemaElementDefinition MarketElementReason::elementDefinition() const
		{
			::blpapi_DataType_t dtype = (::blpapi_DataType_t)this->datatype();
			SchemaElementDefinition result(dtype, Name("ErrorInfo"));
			return result;
		}

		bool MarketElementReason::isNull() const
		{
			return false;
		}

		bool MarketElementReason::isArray() const
		{
			return false;
		}

		bool MarketElementReason::isComplexType() const
		{
			return true;
		}

		ElementPtr * MarketElementReason::getElement(const char* name) const
		{
			if(strncmp(name, "source", 7) == 0)
				return this->_source;
			
			else if(strncmp(name, "errorCode", 10) == 0)
				return this->_errorCode;
			
			else if(strncmp(name, "category", 9) == 0)
				return this->_category;
			
			else if(strncmp(name, "description", 12) == 0)
				return this->_description;

			else
				throw elementPtrEx;
		}

		bool MarketElementReason::hasElement(const char* name, bool excludeNullElements) const
		{
			return 
				strncmp(name, "source", 7) == 0 ||
				strncmp(name, "errorCode", 10) == 0 ||
				strncmp(name, "category", 9) == 0 ||
				strncmp(name, "description", 12) == 0;
		}

		int MarketElementReason::getElementAsInt32(const char* name) const
		{
			return this->getElement(name)->getValueAsInt32(0);
		}

		const char* MarketElementReason::getElementAsString(const char* name) const
		{
			return this->getElement(name)->getValueAsString(0);
		}

		std::ostream& MarketElementReason::print(std::ostream& stream, int level, int spacesPerLevel) const
		{
			std::string tabs(IndentType::Indent(level, spacesPerLevel));

			stream << tabs << "reason = {" << std::endl;
			
			this->_source->print(stream, level + 1, spacesPerLevel);
			this->_errorCode->print(stream, level + 1, spacesPerLevel);
			this->_category->print(stream, level + 1, spacesPerLevel);
			this->_description->print(stream, level + 1, spacesPerLevel);

			stream << tabs << '}' << std::endl;

			return stream;
		}

	}
}