module sigdelay #(
    parameter WIDTH = 8
)(
    input logic             clk,
    input logic             rst,
    input logic             en,
    input logic             wr,
    input logic             rd,
    input logic [WIDTH-1:0] mic_signal,
    output logic [WIDTH-1:0] delayed_signal,
    input logic [WIDTH-1:0] offset
);

logic   [WIDTH:0]       count1;
logic   [WIDTH:0]       count2;

counter Mycounter(
    .clk(clk),
    .rst(rst),
    .en(en),
    .offset(offset),
    .count1(count1),
    .count2(count2)
);

dualram Mydualxram(
    .clk(clk),
    .wr_en(wr),
    .rd_en(rd),
    .wr_addr(count1),
    .rd_addr(count2),
    .din(mic_signal),
    .dout(delayed_signal)
);

endmodule
