#pragma once

#include <godot_cpp/classes/object.hpp>
#include "GDNN.h"

#include "NN_constructor.h"
#include "NN.h"

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
		GDNN_constructor append_layer(NN::ConnectionTypes connections, NN::NeuronTypes neurons, size_t neuron_count, ActivationFunctions activation = ActivationFunctions::sigmoid);
		GDNN construct(size_t input_length, bool stateful = true);
	};
}
