#pragma once

#include "Core.hpp"

namespace Coral {

	class Type;

	class Attribute
	{
	public:
		Type GetType() const;

		template<typename TReturn>
		TReturn GetFieldValue(std::string_view InFieldName)
		{
			TReturn result;
			GetFieldValueInternal(InFieldName, &result);
			return result;
		}

	private:
		void GetFieldValueInternal(std::string_view InFieldName, void* OutValue) const;

	private:
		ManagedHandle m_Handle = nullptr;

		friend class MethodInfo;
		friend class FieldInfo;
		friend class PropertyInfo;
	};

}
