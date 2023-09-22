#include "MethodInfo.hpp"
#include "CoralManagedFunctions.hpp"
#include "Type.hpp"
#include "Attribute.hpp"

namespace Coral {

	std::string MethodInfo::GetName() const
	{
		return s_ManagedFunctions.GetMethodInfoNameFptr(&m_Handle).ToString();
	}

	Type MethodInfo::GetReturnType() const
	{
		Type returnType;
		s_ManagedFunctions.GetMethodInfoReturnTypeFptr(&m_Handle, &returnType.m_TypePtr);
		returnType.RetrieveName();
		return returnType;
	}

	std::vector<Type> MethodInfo::GetParameterTypes() const
	{
		int32_t parameterCount;
		s_ManagedFunctions.GetMethodInfoParameterTypesFptr(&m_Handle, nullptr, &parameterCount);
		std::vector<TypeId> parameterTypes(parameterCount);
		s_ManagedFunctions.GetMethodInfoParameterTypesFptr(&m_Handle, parameterTypes.data(), &parameterCount);

		std::vector<Type> result(parameterTypes.size());
		for (size_t i = 0; i < parameterTypes.size(); i++)
		{
			result[i].m_TypePtr = parameterTypes[i];
			result[i].RetrieveName();
		}

		return result;
	}

	TypeAccessibility MethodInfo::GetAccessibility() const
	{
		return s_ManagedFunctions.GetMethodInfoAccessibilityFptr(&m_Handle);
	}

	std::vector<Attribute> MethodInfo::GetAttributes() const
	{
		int32_t attributeCount;
		s_ManagedFunctions.GetMethodInfoAttributesFptr(&m_Handle, nullptr, &attributeCount);
		std::vector<ManagedHandle> attributeHandles(attributeCount);
		s_ManagedFunctions.GetMethodInfoAttributesFptr(&m_Handle, attributeHandles.data(), &attributeCount);

		std::vector<Attribute> result(attributeHandles.size());
		for (size_t i = 0; i < attributeHandles.size(); i++)
			result[i].m_Handle = attributeHandles[i];

		return result;
	}

}
