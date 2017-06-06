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

-- ***************************************************************************
-- This file contains a Vhdl test bench template that is freely editable to   
-- suit user's needs .Comments are provided in each section to help the user  
-- fill out necessary details.                                                
-- ***************************************************************************
-- Generated on "06/06/2017 18:06:47"
                                                            
-- Vhdl Test Bench template for design  :  mux
-- 
-- Simulation tool : ModelSim-Altera (VHDL)
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY mux_vhd_tst IS
END mux_vhd_tst;
ARCHITECTURE mux_arch OF mux_vhd_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL A0 : STD_LOGIC;
SIGNAL A1 : STD_LOGIC;
SIGNAL B0 : STD_LOGIC;
SIGNAL B1 : STD_LOGIC;
SIGNAL out0 : STD_LOGIC;
SIGNAL out1 : STD_LOGIC;
SIGNAL sel : STD_LOGIC;
COMPONENT mux
	PORT (
	A0 : IN STD_LOGIC;
	A1 : IN STD_LOGIC;
	B0 : IN STD_LOGIC;
	B1 : IN STD_LOGIC;
	out0 : OUT STD_LOGIC;
	out1 : OUT STD_LOGIC;
	sel : IN STD_LOGIC
	);
END COMPONENT;
BEGIN
	i1 : mux
	PORT MAP (
-- list connections between master ports and signals
	A0 => A0,
	A1 => A1,
	B0 => B0,
	B1 => B1,
	out0 => out0,
	out1 => out1,
	sel => sel
	);
init : PROCESS                                               
-- variable declarations                                     
BEGIN                                                        
        -- code that executes only once  
	
	sel <= '0';
	A0 <= '0';
	B0 <= '0';
	A1 <= '1';
	B1 <= '0';
	wait for 30 ns;
	
	sel <= '0';
	A0 <= '0';
	B0 <= '1';
	A1 <= '0';
	B1 <= '1';
	wait for 30 ns;
	
	sel <= '1';
	A0 <= '0';
	B0 <= '1';
	A1 <= '0';
	B1 <= '0';
	wait for 30 ns;
	
	sel <= '1';
	A0 <= '0';
	B0 <= '1';
	A1 <= '0';
	B1 <= '1';
	wait for 30 ns;
	
		  
WAIT;                                                       
END PROCESS init;                                           
always : PROCESS                                              
-- optional sensitivity list                                  
-- (        )                                                 
-- variable declarations                                      
BEGIN                                                         
        -- code executes for every event on sensitivity list  
WAIT;                                                        
END PROCESS always;                                          
END mux_arch;
