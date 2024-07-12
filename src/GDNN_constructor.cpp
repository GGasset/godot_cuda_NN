#include "GDNN_constructor.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDNN_constructor::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("append_layer", "connections", "neurons", "neuron_count", "activation"), &GDNN_constructor::append_layer);
	ClassDB::bind_method(D_METHOD("construct", "input_length", "stateful"), &GDNN_constructor::construct);
}

GDNN_constructor::GDNN_constructor()
{
	constructor = NN_constructor();
}

GDNN_constructor GDNN_constructor::append_layer(NN::ConnectionTypes connections, NN::NeuronTypes neurons, size_t neuron_count, ActivationFunctions activation)
{
	constructor.append_layer(connections, neurons, neuron_count, activation);
}

GDNN GDNN_constructor::construct(size_t input_length, bool stateful)
{
	return GDNN(constructor.construct(input_length, stateful));
}
