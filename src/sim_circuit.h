// sim_circuit.h - Johan Smet - BSD-3-Clause (see LICENSE)
//
// instantiation of a circuit description

#ifndef LSIM_SIM_CIRCUIT_H
#define LSIM_SIM_CIRCUIT_H

#include "model_circuit.h"

namespace lsim {

class SimComponent;

class SimCircuit {
public:
    SimCircuit(Simulator *sim, ModelCircuit *circuit_desc);
    ModelCircuit *description() const {return m_circuit_desc;}

    // instantiation
    SimComponent *add_component(ModelComponent *comp);
    node_t add_wire(ModelWire *wire);
    void connect_pins(pin_id_t pin_a, pin_id_t pin_b);
    SimComponent *component_by_id(uint32_t comp_id);

    // name
    void build_name(uint32_t comp_id);
    const char *name() const {return m_name.c_str();}

    // read/write
    Value read_pin(pin_id_t pin_id);
    uint8_t read_nibble(uint32_t comp_id);
    uint8_t read_nibble(const pin_id_container_t &pins);
    uint8_t read_byte(uint32_t comp_id);
    uint8_t read_byte(const pin_id_container_t &pins);
    uint64_t read_pins(const pin_id_container_t &pins);

    void write_pin(pin_id_t pin_id, Value value);
    void write_output_pins(uint32_t comp_id, value_container_t values);
    void write_output_pins(uint32_t comp_id, uint64_t data);
    void write_output_pins(uint32_t comp_id, Value value);

    void write_nibble(const pin_id_container_t &pins, uint8_t data);
    void write_byte(const pin_id_container_t &pins, uint8_t data);
    void write_pins(const pin_id_container_t &pins, const value_container_t &values);
    void write_pins(const pin_id_container_t &pins, uint64_t data);

    node_t pin_node(pin_id_t pin_id);
    bool node_dirty(node_t node_id);

    // get value written to by a specific pin
    Value pin_output(pin_id_t pin_id);
    Value user_value(pin_id_t pin_id);

private: 
    pin_t pin_from_pin_id(pin_id_t pin_id);

private:
    using sim_component_lut_t = std::unordered_map<uint32_t, SimComponent *>; 

private:
    ModelCircuit *    m_circuit_desc;
    Simulator *             m_sim;
    sim_component_lut_t     m_components;
    std::string             m_name;
};


}


#endif // LSIM_SIM_CIRCUIT_H