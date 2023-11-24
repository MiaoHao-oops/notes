#!/usr/bin/bash
verilator --cc --exe --build --trace -j 1 -Wall test.cc dut.v
