#include "prpch.h"
#include "Layer.h"

namespace Pulsar {
	Layer::Layer(const std::string& name) 
		: m_DebugName(name) { }

	Layer::~Layer() {}
}