#pragma once 

#include "Core.h"
#include "Events/Event.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API Layer
	{
	public:
		Layer(const std::string & = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& e) {};

		inline const std::string& GetName() const { return m_Name; }
	protected:
		std::string m_Name;
	};
}

