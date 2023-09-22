#pragma once

#include "Core.hpp"

namespace Coral {

	class Type;
	class Attribute;

	class MethodInfo
	{
	public:
		std::string GetName() const;

		Type GetReturnType() const;
		std::vector<Type> GetParameterTypes() const;

		TypeAccessibility GetAccessibility() const;

		std::vector<Attribute> GetAttributes() const;

	private:
		ManagedHandle m_Handle = nullptr;

		friend class Type;
	};

}
