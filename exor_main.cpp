#include <systemc.h>

#include "stim.h"
#include "exor.h"
#include "mon.h"

int sc_main(int, char**)
{
    sc_signal<bool> sigA, sigB, sigZ;
    
    sc_clock clock("Clk", 10, SC_NS, 0.5);

    sc_trace_file *wf = sc_create_vcd_trace_file("trace");
    sc_trace(wf, sigA, "A");
    sc_trace(wf, sigB, "B");
    sc_trace(wf, sigZ, "Z");

    stim Stim1("Stimulus");
    Stim1.A(sigA);
    Stim1.B(sigB);
    Stim1.Clk(clock);

    exor DUT("exor");
    DUT.A(sigA);
    DUT.B(sigB);
    DUT.Z(sigZ);

    Monitor mon("Monitor");
    mon.A(sigA);
    mon.B(sigB);
    mon.Z(sigZ);
    mon.Clk(clock);

    sc_start();  // run forever
    sc_close_vcd_trace_file(wf);
    return 0;
}
