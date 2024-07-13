#pragma once

#include <godot_cpp/classes/object.hpp>
#include "GDNN.h"

#include "NN_constructor.h"

namespace godot {
	class GDNN_constructor : public Object
	{
		GDCLASS(GDNN_constructor, Object)

	private:
		NN_constructor constructor;

	protected:
		static void _bind_methods();

	public:
		GDNN_constructor();
		GDNN_constructor* append_layer(size_t connections, size_t neurons, size_t neuron_count, size_t activation);
		GDNN* construct(size_t input_length, bool stateful = true);
	};
}
