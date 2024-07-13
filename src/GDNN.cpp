#include "GDNN.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void GDNN::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_input_length", "i"), &GDNN::get_input_length);
	ClassDB::bind_method(D_METHOD("get_output_length"), &GDNN::get_output_length);
	ClassDB::bind_method(D_METHOD("set_stateful", "stateful"), &GDNN::set_stateful);
	ClassDB::bind_method(D_METHOD("execute", "input"), &GDNN::execute);


	/*BIND_ENUM_CONSTANT(ActivationFunctions::sigmoid);
	BIND_ENUM_CONSTANT(ActivationFunctions::_tanh);
	BIND_ENUM_CONSTANT(CostFunctions::MSE);
	BIND_ENUM_CONSTANT(CostFunctions::log_likelyhood);
	BIND_ENUM_CONSTANT(NN::NeuronTypes::Neuron);
	BIND_ENUM_CONSTANT(NN::NeuronTypes::LSTM);
	BIND_ENUM_CONSTANT(NN::ConnectionTypes::Dense);
	BIND_ENUM_CONSTANT(NN::ConnectionTypes::NEAT);*/
}

GDNN::GDNN()
{

}

GDNN::GDNN(NN n)
{
	this->n = n;
}

size_t GDNN::get_input_length()
{
	return n.get_input_length();
}

size_t GDNN::get_output_length()
{
	return n.get_output_length();
}

void GDNN::set_stateful(bool stateful)
{
	n.stateful = true;
}

PackedFloat32Array GDNN::execute(PackedFloat32Array input)
{
	if (input.size() != get_input_length())
	{
		return PackedFloat32Array();
	}
	data_t* raw_pointer = input.ptrw();
	data_t* raw_output = n.inference_execute(raw_pointer);
	PackedFloat32Array output = to_packed_array(raw_output, get_output_length());
	delete[] raw_output;
	return output;
}
