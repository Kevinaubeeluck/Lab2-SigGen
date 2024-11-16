module rom #(
    parameter   ADDRESS_WIDTH = 8,
                DATA_WIDTH    = 8
)(
    input logic                     clk,
    input logic [ADDRESS_WIDTH-1:0] addr1,
    input logic [ADDRESS_WIDTH-1:0] addr2,
    output logic [DATA_WIDTH-1:0]   dout1,
    output logic [DATA_WIDTH-1:0]   dout2
);

// Define ROM array
logic [DATA_WIDTH-1:0] rom_array [2**ADDRESS_WIDTH-1:0];

// Load data from sinerom.mem at the start of the simulation
initial begin
    $display("Loading rom.");
    $readmemh("sinerom.mem", rom_array);
end

// Synchronous output
always_ff @(posedge clk) begin
    dout1 <= rom_array[addr1];  // Output for addr1
    dout2 = rom_array[addr2];  // Output for addr2
end

endmodule
