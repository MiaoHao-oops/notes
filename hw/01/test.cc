#include "Vdut.h"
#include "verilated.h"
#include <verilated_vcd_c.h>

int main(int argc, char **argv) {
    VerilatedContext *contextp = new VerilatedContext;
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    contextp->commandArgs(argc, argv);
    Vdut *top = new Vdut{ contextp };

    // open trace
    Verilated::traceEverOn(true);
    top->trace(m_trace, 99);
    m_trace->open("test.vcd");

    // begin simulation
    int ticks = 0;
    while (!contextp->gotFinish() && ticks < 16) {
        if (ticks % 4 == 0 || ticks % 4 == 1) {
            if (ticks == 4)
                top->A = 1;
            else top->A = 0;
            if (ticks == 1 || ticks == 4 || ticks == 5 || ticks == 8 || ticks == 9)
                top->B = 1;
            else top->B = 0;
            top->clk = 1;
        } else {
            if (ticks == 3)
                top->A = 1;
            else top->A = 0;
            if (ticks == 2 || ticks == 3 || ticks == 6 || ticks == 7)
                top->B = 1;
            else top->B = 0;
            top->clk = 0;
        }
        top->eval();
        m_trace->dump(ticks++);
    }

    m_trace->close();
    delete m_trace;
    delete top;
    delete contextp;
    return 0;
}
