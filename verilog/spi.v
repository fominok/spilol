
`timescale 1ns / 1ps

module spi(
    input clk,                 // Тактовый сигнал с процессора
    input miso,                // Master in slave out
    input[7:0] data_in,        // Данные для передачи от процессора
    input ready_send,          // Данные положены в data-in и готовы к отправке
    input rst,
    output reg mosi,           // Master out slave in
    output sclk,               // Тактовый сигнал к рабам
    output ss,                 // Slave select
    output reg[7:0] data_out   // Принятые данные от раба
    );

reg      enabled;
reg[3:0] counter;
reg[7:0] data_in_reg;
reg      clk_tmp = 0;
reg      done;
reg      last_tact;
reg      sclk_p = 0;

assign ss = !(enabled && !done);
assign sclk = sclk_p && !ss;

always @(posedge clk) begin
    clk_tmp <= !clk_tmp;
    if (clk_tmp) begin
        sclk_p <= !sclk_p;
    end
end

always @(posedge sclk_p) begin
   if (rst) begin
       done = 0;
       counter = 0;
   end else if (last_tact) begin
       done = 1;
   end else if (enabled) begin
       if (counter == 0) begin
           counter = 8;
       end
       mosi = data_in_reg[counter - 1];
       counter = counter - 1;
    end
end

always @(negedge sclk_p) begin
    if (rst) begin
        data_out <= 0;
        enabled <= 0;
        data_in_reg <= 0;
        last_tact <= 0;
    end else if (last_tact) begin
        enabled <= 0;
        last_tact <= 0;
    end else if (ready_send && !enabled) begin
        data_in_reg <= data_in;
        enabled <= 1;
    end else if (enabled) begin
        if (counter == 0)
            last_tact <= 1;
        data_out[counter[2:0]] <= miso;
     end
end

endmodule
