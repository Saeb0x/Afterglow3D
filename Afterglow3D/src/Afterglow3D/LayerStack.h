#pragma once

#include "Layer.h"

namespace Afterglow3D
{
	class AFTERGLOW3D_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);
		void PushOverlay(Layer* overlayer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator Begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator End() { return m_Layers.end(); }

		inline std::vector<Layer*>& GetLayers() { return m_Layers; }
	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}