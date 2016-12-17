
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
    output reg[7:0] data_out,  // Принятые данные от раба
    output busy                // Идёт транзакция по SPI
    );

reg      enabled;
reg[3:0] counter;
reg[2:0] pos_ctr;
reg[2:0] neg_ctr;
reg[7:0] data_in_reg;
reg      clk_tmp = 0;
reg      done;
reg      last_tact;
reg      sclk_p = 0;

assign ss = !enabled;
assign sclk = !clk || ss;
assign busy = enabled;

always @(negedge clk) begin
    if (enabled) begin
        data_out[pos_ctr] <= miso;
        if (pos_ctr == 0)
            done <= 1;
        neg_ctr <= pos_ctr - 1;
    end else done <= 0;
end

always @(posedge clk) begin
    if (rst) begin
        data_out <= 0;
        enabled <= 0;
        data_in_reg <= 0;
        mosi <= 0;
    end else if (ready_send && !enabled) begin
        data_in_reg <= data_in;
        mosi <= data_in[7];
        pos_ctr <= 7;
        enabled <= 1;
    end else if (enabled) begin
        if (done) begin
            enabled <= 0;
        end else begin
            pos_ctr <= neg_ctr;
            mosi <= data_in[neg_ctr];
        end
     end
end

endmodule
