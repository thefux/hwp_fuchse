-- Copyright (C) 2016  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Intel and sold by Intel or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 16.1.0 Build 196 10/24/2016 SJ Lite Edition"

-- DATE "06/06/2017 17:04:35"

-- 
-- Device: Altera EP4CE22F17C6 Package FBGA256
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	hard_block IS
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic
	);
END hard_block;

-- Design Ports Information
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_C1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_D2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_H1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_H2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_F16,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


ARCHITECTURE structure OF hard_block IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~padout\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~padout\ : std_logic;
SIGNAL \~ALTERA_DATA0~~padout\ : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_DATA0~~ibuf_o\ : std_logic;

BEGIN

ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
END structure;


LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	fulladder2bit IS
    PORT (
	sum0 : OUT std_logic;
	carryIN : IN std_logic;
	A0 : IN std_logic;
	B0 : IN std_logic;
	sum1 : OUT std_logic;
	A1 : IN std_logic;
	B1 : IN std_logic;
	carryOUT : OUT std_logic
	);
END fulladder2bit;

-- Design Ports Information
-- sum0	=>  Location: PIN_K1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- sum1	=>  Location: PIN_K2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carryOUT	=>  Location: PIN_L1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- carryIN	=>  Location: PIN_L2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A0	=>  Location: PIN_L3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B0	=>  Location: PIN_J1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- B1	=>  Location: PIN_G2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- A1	=>  Location: PIN_J2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF fulladder2bit IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_sum0 : std_logic;
SIGNAL ww_carryIN : std_logic;
SIGNAL ww_A0 : std_logic;
SIGNAL ww_B0 : std_logic;
SIGNAL ww_sum1 : std_logic;
SIGNAL ww_A1 : std_logic;
SIGNAL ww_B1 : std_logic;
SIGNAL ww_carryOUT : std_logic;
SIGNAL \sum0~output_o\ : std_logic;
SIGNAL \sum1~output_o\ : std_logic;
SIGNAL \carryOUT~output_o\ : std_logic;
SIGNAL \carryIN~input_o\ : std_logic;
SIGNAL \A0~input_o\ : std_logic;
SIGNAL \B0~input_o\ : std_logic;
SIGNAL \inst|inst4~0_combout\ : std_logic;
SIGNAL \A1~input_o\ : std_logic;
SIGNAL \B1~input_o\ : std_logic;
SIGNAL \inst|inst2~0_combout\ : std_logic;
SIGNAL \inst1|inst4~combout\ : std_logic;
SIGNAL \inst1|inst2~0_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

sum0 <= ww_sum0;
ww_carryIN <= carryIN;
ww_A0 <= A0;
ww_B0 <= B0;
sum1 <= ww_sum1;
ww_A1 <= A1;
ww_B1 <= B1;
carryOUT <= ww_carryOUT;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X0_Y12_N9
\sum0~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst|inst4~0_combout\,
	devoe => ww_devoe,
	o => \sum0~output_o\);

-- Location: IOOBUF_X0_Y12_N2
\sum1~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|inst4~combout\,
	devoe => ww_devoe,
	o => \sum1~output_o\);

-- Location: IOOBUF_X0_Y11_N9
\carryOUT~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst1|inst2~0_combout\,
	devoe => ww_devoe,
	o => \carryOUT~output_o\);

-- Location: IOIBUF_X0_Y11_N1
\carryIN~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_carryIN,
	o => \carryIN~input_o\);

-- Location: IOIBUF_X0_Y10_N22
\A0~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A0,
	o => \A0~input_o\);

-- Location: IOIBUF_X0_Y15_N8
\B0~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B0,
	o => \B0~input_o\);

-- Location: LCCOMB_X1_Y15_N16
\inst|inst4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst|inst4~0_combout\ = \carryIN~input_o\ $ (\A0~input_o\ $ (\B0~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010101011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \carryIN~input_o\,
	datac => \A0~input_o\,
	datad => \B0~input_o\,
	combout => \inst|inst4~0_combout\);

-- Location: IOIBUF_X0_Y15_N1
\A1~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_A1,
	o => \A1~input_o\);

-- Location: IOIBUF_X0_Y23_N15
\B1~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_B1,
	o => \B1~input_o\);

-- Location: LCCOMB_X1_Y15_N10
\inst|inst2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst|inst2~0_combout\ = (\carryIN~input_o\ & ((\A0~input_o\) # (\B0~input_o\))) # (!\carryIN~input_o\ & (\A0~input_o\ & \B0~input_o\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \carryIN~input_o\,
	datac => \A0~input_o\,
	datad => \B0~input_o\,
	combout => \inst|inst2~0_combout\);

-- Location: LCCOMB_X1_Y15_N20
\inst1|inst4\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|inst4~combout\ = \A1~input_o\ $ (\B1~input_o\ $ (\inst|inst2~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001100101100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A1~input_o\,
	datab => \B1~input_o\,
	datad => \inst|inst2~0_combout\,
	combout => \inst1|inst4~combout\);

-- Location: LCCOMB_X1_Y15_N22
\inst1|inst2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \inst1|inst2~0_combout\ = (\A1~input_o\ & ((\B1~input_o\) # (\inst|inst2~0_combout\))) # (!\A1~input_o\ & (\B1~input_o\ & \inst|inst2~0_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \A1~input_o\,
	datab => \B1~input_o\,
	datad => \inst|inst2~0_combout\,
	combout => \inst1|inst2~0_combout\);

ww_sum0 <= \sum0~output_o\;

ww_sum1 <= \sum1~output_o\;

ww_carryOUT <= \carryOUT~output_o\;
END structure;


