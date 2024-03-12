from __future__ import annotations

import unittest

from qiskit import QuantumCircuit, QuantumRegister

from mqt.ddsim import HybridCircuitSimulator, HybridMode


class MQTStandaloneHybridSimulatorTest(unittest.TestCase):
    def setUp(self) -> None:
        q = QuantumRegister(4)
        circ = QuantumCircuit(q)
        circ.h(q)
        circ.cz(3, 1)
        circ.cz(2, 0)
        circ.measure_all(inplace=True)
        self.circuit = circ
        self.non_zeros_in_matrix = 16

    def test_standalone_amplitude_mode(self) -> None:
        sim = HybridCircuitSimulator(self.circuit, mode=HybridMode.amplitude)
        result = sim.simulate(2048)
        assert len(result.keys()) == self.non_zeros_in_matrix

    def test_standalone_amplitude_mode_with_seed(self) -> None:
        sim = HybridCircuitSimulator(self.circuit, seed=1337, mode=HybridMode.amplitude)
        result = sim.simulate(2048)
        assert len(result.keys()) == self.non_zeros_in_matrix

    def test_standalone_dd_mode(self) -> None:
        sim = HybridCircuitSimulator(self.circuit, mode=HybridMode.DD)
        result = sim.simulate(2048)
        assert len(result.keys()) == self.non_zeros_in_matrix

    def test_standalone_dd_mode_with_seed(self) -> None:
        sim = HybridCircuitSimulator(self.circuit, seed=1337, mode=HybridMode.DD)
        result = sim.simulate(2048)
        assert len(result.keys()) == self.non_zeros_in_matrix
